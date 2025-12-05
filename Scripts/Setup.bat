@echo off
echo === Velt Setup (Windows) ===

python --version >nul 2>&1
if errorlevel 1 (
    echo Python was not found. Please install Python and add it to PATH.
    pause
    exit /b
)

echo Running setup.py ...
python setup.py

echo.
echo Setup completed.
pause
