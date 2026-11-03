# Shared helper for this project: patches the UI texts that OpenKNXproducer
# hard codes into the generated ETS xml.
#
# Currently patched (see scripts/EtsUiPatches.json):
#   - "Bitte waehlen..."  -> PT-ModuleSelector / PT-ModuleSelectorWithChannels (tool hard coded)
#   - "Diese Applikation ... passen nicht zusammen." -> tool template Message VersionMismatch
#   - "Kein gueltiger/vollstaendiger OpenKNX-ConfigTransfer-String ..." -> UCT Message
#
# This file is ASCII only on purpose: PowerShell 5.1 reads BOM-less .ps1 files using
# the ANSI code page, which would corrupt non-ASCII literals. The replacements
# therefore live in the UTF-8 json file and are read explicitly as UTF-8.
#
# Usage:
#   . "$PSScriptRoot/EtsUiPatch.ps1"
#   Invoke-EtsUiPatch -Path "src/BusPowerSupply.debug.xml"

$script:EtsUiPatches = $null
$script:EtsUiPatchFile = Join-Path $PSScriptRoot "EtsUiPatches.json"
if (Test-Path $script:EtsUiPatchFile) {
    $script:EtsUiPatches = ConvertFrom-Json ([System.IO.File]::ReadAllText($script:EtsUiPatchFile, [System.Text.Encoding]::UTF8))
} else {
    Write-Host "  patch: patch table not found: $script:EtsUiPatchFile" -ForegroundColor Yellow
}

function Invoke-EtsUiPatch {
    param(
        [Parameter(Mandatory = $true)][string]$Path
    )

    if (-not (Test-Path -Path $Path)) {
        Write-Host "  patch: file not found, skipped: $Path" -ForegroundColor Yellow
        return 0
    }

    $content = [System.IO.File]::ReadAllText($Path, [System.Text.Encoding]::UTF8)

    $hits = 0
    foreach ($patch in $script:EtsUiPatches) {
        if ([string]::IsNullOrEmpty($patch.search)) { continue }
        if ($content.Contains($patch.search)) {
            $hits += ([regex]::Matches($content, [regex]::Escape($patch.search))).Count
            $content = $content.Replace($patch.search, $patch.replace)
        }
    }

    if ($hits -eq 0) {
        Write-Host "  patch: nothing to patch in $Path" -ForegroundColor DarkGray
        return 0
    }
    # keep the file UTF-8 with BOM, as written by the producer
    [System.IO.File]::WriteAllText($Path, $content, (New-Object System.Text.UTF8Encoding($true)))
    Write-Host "  patch: replaced $hits UI text(s) in $Path" -ForegroundColor Green
    return $hits
}
