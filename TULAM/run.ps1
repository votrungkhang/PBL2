param(
    [switch]$BuildOnly
)

$ErrorActionPreference = "Stop"
Set-Location -LiteralPath $PSScriptRoot

$compiler = Get-Command g++ -ErrorAction SilentlyContinue
if ($null -eq $compiler) {
    Write-Error "Khong tim thay g++; hay cai MinGW-w64 va them g++ vao PATH."
    exit 1
}

$sourceFiles = @(
    Get-ChildItem -Path $PSScriptRoot -Recurse -File -Filter *.cpp |
        ForEach-Object { $_.FullName }
)
if ($sourceFiles.Count -eq 0) {
    Write-Error "Khong tim thay file .cpp nao trong thu muc TULAM."
    exit 1
}

$outputDirectory = Join-Path $env:TEMP "TULAM-build"
New-Item -ItemType Directory -Path $outputDirectory -Force | Out-Null
$executablePath = Join-Path $outputDirectory "main.exe"

& $compiler.Source -std=c++14 -Wall -Wextra -Wpedantic `
    -I $PSScriptRoot @sourceFiles -o $executablePath
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

Write-Output "Build thanh cong."
if ($BuildOnly) {
    exit 0
}

& $executablePath
exit $LASTEXITCODE
