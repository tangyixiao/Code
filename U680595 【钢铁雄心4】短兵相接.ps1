Set-Location $PSScriptRoot

$gen = ".\gen.exe"
$std = ".\std.exe"
$dataDir = "data"
$cases = 20

if (!(Test-Path $gen)) { Write-Host "Error: gen.exe not found!"; pause; exit }
if (!(Test-Path $std)) { Write-Host "Error: std.exe not found!"; pause; exit }

if (!(Test-Path $dataDir)) { New-Item -ItemType Directory -Path $dataDir | Out-Null }

Write-Host "Generating $cases test cases..."

for ($i = 1; $i -le $cases; $i++) {
    # 分档数据范围
    if ($i -le 5)          { $maxN=10; $maxM=10; $maxHp=100; $maxAtk=50 }
    elseif ($i -le 10)     { $maxN=1000; $maxM=1000; $maxHp=100000; $maxAtk=100000 }
    elseif ($i -le 15)     { $maxN=50000; $maxM=50000; $maxHp=100000000; $maxAtk=100000000 }
    else                   { $maxN=200000; $maxM=200000; $maxHp=1000000000; $maxAtk=1000000000 }

    $seed = $i % 1000000
    $num = "{0:D2}" -f $i       # 补零到两位数
    $inFile = "$dataDir\$num.in"
    $outFile = "$dataDir\$num.out"

    Write-Host "[$i/$cases] Creating $inFile (N<=$maxN, M<=$maxM, hp<=$maxHp, atk<=$maxAtk)"

    # 生成输入文件
    & $gen $maxN $maxM $maxHp $maxAtk $seed > $inFile
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Error: gen.exe failed for case $i"
        pause
        exit
    }

    # 用标程生成输出文件
    Get-Content $inFile | & $std > $outFile
    if ($LASTEXITCODE -ne 0) {
        Write-Host "Error: std.exe failed for case $i"
        pause
        exit
    }
}

Write-Host "`nAll $cases test cases successfully generated in '$dataDir' folder."
pause