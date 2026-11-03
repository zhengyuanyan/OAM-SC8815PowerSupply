# This script is just a template and has to be copied and modified per project
# This script should be called from .vscode/tasks.json with
#
#   scripts/Build-Release.ps1            - for Beta builds
#   scripts/Build-Release.ps1 Release    - for Release builds
#
# {
#     "label": "Build-Release",
#     "type": "shell",
#     "command": "scripts/Build-Release.ps1 Release",
#     "args": [],
#     "problemMatcher": [],
#     "group": "test"
# },
# {
#     "label": "Build-Beta",
#     "type": "shell",
#     "command": "scripts/Build-Release.ps1 ",
#     "args": [],
#     "problemMatcher": [],
#     "group": "test"
# }

# set product names, allows mapping of (devel) name in Project to a more consistent name in release
# $settings = scripts/OpenKNX-Build-Settings.ps1

# execute generic pre-build steps
../OGM-Common/scripts/setup/reusable/Build-Release-Preprocess.ps1 $args[0]
if (!$?) { exit 1 }

# ---------------------------------------------------------------------------------------
# Project local additions (after the generic preprocess):
#
# 1) The preprocess runs 'create' itself, which overwrites src/<releaseName>.debug.xml
#    with UNPATCHED texts and (re)builds release/<targetName>.knxprod from it. The xml
#    that ends up in the shipped release is release/data/<targetName>.xml (copied from
#    the debug xml, later rebuilt by release/ETS-Applikation/Build-knxprod.ps1), so all
#    of them have to be patched again - see scripts/EtsUiPatch.ps1 / EtsUiPatches.json.
# 2) The preprocess MOVES src/<releaseName>.baggages to release/data/. Copy it back,
#    otherwise the normal (dev) OpenKNXproducer run fails afterwards.
#
# Note: <releaseName> is "<sourceName>" without an argument (Beta) and
#       "<sourceName>-<releaseIndication>" with one (e.g. "Release").
# ---------------------------------------------------------------------------------------
. "$PSScriptRoot/EtsUiPatch.ps1"

$settings = & "$PSScriptRoot/OpenKNX-Build-Settings.ps1" $args[0]
$releaseName = $settings.releaseName
$targetName = $settings.targetName

$debugXmlPath = "src/$releaseName.debug.xml"
if (Test-Path $debugXmlPath) { Invoke-EtsUiPatch -Path $debugXmlPath | Out-Null }

$releaseXmlPath = "release/data/$targetName.xml"
if (Test-Path $releaseXmlPath) {
  Invoke-EtsUiPatch -Path $releaseXmlPath | Out-Null

  # the knxprod created by the preprocess still contains the unpatched texts -> rebuild it
  if (Test-Path "release/$targetName.knxprod") {
    $producer = "~/bin/OpenKNXproducer.exe"
    if ($IsMacOS -or $IsLinux) { $producer = "/usr/local/bin/OpenKNXproducer" }
    if (Test-Path $producer) {
      Write-Host "rebuilding release/$targetName.knxprod from the patched xml" -ForegroundColor Green
      Push-Location "release/data"
      try   { & $producer knxprod --NoXsd "--Output=../$targetName.knxprod" "$targetName.xml" }
      finally { Pop-Location }
    }
  }
}

if ((Test-Path "release/data/$targetName.baggages") -and -not (Test-Path "src/$releaseName.baggages")) {
  Copy-Item "release/data/$targetName.baggages" "src/$releaseName.baggages" -Recurse
  Write-Host "restored src/$releaseName.baggages (was moved by the preprocess)" -ForegroundColor Green
}

# build firmware
lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_AB_SMARTHOUSE_BPS_REG4 firmware-AB-SmartHouse-BusPowerSupply-REG6 uf2
if (!$?) { exit 1 }

# execute generic post-build steps
../OGM-Common/scripts/setup/reusable/Build-Release-Postprocess.ps1 $args[0]
if (!$?) { exit 1 }
