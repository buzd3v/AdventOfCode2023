# Define parameters
param (
    [string]$directory,
    [string]$filename
)

Write-Host "Dir $directory"
Write-Host "Filename: $filename"

# Define colors
$GREEN = [consolecolor]::Green
$RED = [consolecolor]::Red
$NC = [consolecolor]::Gray

Write-Host $directory

$fileToModify = "CMakeLists.txt"
$lineNumber = 5

# Replace backslashes with double backslashes or forward slashes
$directory = $directory.Replace('\', '/')

# The new content to replace the old line with.
$newContent = "add_executable(dsa $directory$filename)"

Write-Host $newContent

# Use Get-Content and Set-Content to replace the specified line.
$content = Get-Content $fileToModify
$content[$lineNumber - 1] = $newContent
$content | Set-Content $fileToModify

Write-Host "Build program" -ForegroundColor $RED
cd build
cmake ..
cmake --build .
cd .. 
Write-Host "Run program" -ForegroundColor $GREEN
Write-Host "----------------------------------------------------" -ForegroundColor $GREEN
./build/dsa.exe