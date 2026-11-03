<#
    OpenKNXproducer wrapper for this project.

    Problem
    -------
    The ParameterTypes PT-ModuleSelector / PT-ModuleSelectorWithChannels are injected by
    OpenKNXproducer itself ("Generating ConfigTransfer extensions..."). Their placeholder
    entry "Bitte waehlen..." is hard coded in the tool (ExtendedEtsSupport.cs,
    GenerateModuleSelector) and can NOT be overridden by any project or module XML.

    Solution
    --------
      1. run "create" exactly as before (debug xml + knxprod + include/knxprod.h)
      2. patch the generated src/<Project>.debug.xml in place (text literal only)
         -> the release flow (Build-Release-Preprocess.ps1) copies exactly this file to
            release/data/<Name>.xml and rebuilds the knxprod from it, so it is covered too
      3. rebuild src/<Project>.knxprod from the patched xml using the "knxprod" verb
         (this also regenerates M-00FA.signature - do NOT patch inside the .knxprod zip)

    Why a temp copy in step 3
    -------------------------
    The "knxprod" verb looks for the Baggages directory next to the xml file, using the xml
    base name ("<base>.baggages"). The debug xml is named "<Project>.debug.xml", so it would
    look for "<Project>.debug.baggages". Therefore the patched xml and the baggages folder
    are copied into a temp folder under matching names.

    NOTE: ASCII only on purpose - PowerShell 5.1 reads BOM-less .ps1 files using the ANSI
    code page, so the two non-ASCII literals below are built from char codes.
#>

param(
    [string]$XmlFile    = "src/BusPowerSupply.xml",
    [string]$HeaderFile = "include/knxprod.h"
)

$ErrorActionPreference = "Stop"
$rc = 1

# ---- configuration -------------------------------------------------------------------
# the UI text patches live in scripts/EtsUiPatch.ps1 (shared with Build-Release.ps1)
. "$PSScriptRoot/EtsUiPatch.ps1"

# ---- locate the tool -----------------------------------------------------------------
$producer = "~/bin/OpenKNXproducer.exe"
if ($IsMacOS -or $IsLinux) { $producer = "/usr/local/bin/OpenKNXproducer" }
if (-not (Test-Path $producer)) {
    Write-Host "OpenKNXproducer not found at $producer" -ForegroundColor Red
    Write-Host "see https://github.com/OpenKNX/OpenKNX/wiki/Installation-of-OpenKNX-tools"
    exit 1
}

$root     = (Get-Location).Path
$xmlPath  = Join-Path $root $XmlFile
if (-not (Test-Path $xmlPath)) { Write-Host "xml file not found: $xmlPath" -ForegroundColor Red; exit 1 }

$srcDir   = Split-Path $xmlPath
$base     = [System.IO.Path]::GetFileNameWithoutExtension($xmlPath)   # e.g. BusPowerSupply
$debugXml = Join-Path $srcDir "$base.debug.xml"
$baggages = Join-Path $srcDir "$base.baggages"
$knxprod  = Join-Path $srcDir "$base.knxprod"

# ---- 1. create (unchanged behaviour) -------------------------------------------------
& $producer create --Debug --HeaderFileName $HeaderFile $XmlFile
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }
if (-not (Test-Path $debugXml)) { Write-Host "debug xml was not created: $debugXml" -ForegroundColor Red; exit 1 }

# ---- 2. patch the generated debug xml in place ---------------------------------------
$hits = Invoke-EtsUiPatch -Path $debugXml
if ($hits -eq 0) {
    Write-Host "nothing to patch - text not found (did the tool change its wording?)" -ForegroundColor Yellow
    Write-Host "keeping the knxprod written by 'create'" -ForegroundColor Yellow
    exit 0
}

# ---- 3. rebuild the knxprod from the patched xml -------------------------------------
$tmp = Join-Path ([System.IO.Path]::GetTempPath()) ("knxprod-" + [guid]::NewGuid().ToString("N"))
New-Item -ItemType Directory -Path $tmp | Out-Null
try {
    Copy-Item $debugXml (Join-Path $tmp "$base.xml")
    if (Test-Path $baggages) { Copy-Item $baggages (Join-Path $tmp "$base.baggages") -Recurse }

    Push-Location $tmp
    try {
        & $producer knxprod --NoXsd "--Output=$knxprod" "$base.xml"
        $rc = $LASTEXITCODE
    } finally {
        Pop-Location
    }
} finally {
    Remove-Item $tmp -Recurse -Force -ErrorAction SilentlyContinue
}

if ($rc -ne 0) { Write-Host "knxprod verb failed with exit code $rc" -ForegroundColor Red; exit $rc }
Write-Host "created $knxprod" -ForegroundColor Blue
exit 0
