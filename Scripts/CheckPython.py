import subprocess
import sys
import os
import importlib.util
from pathlib import Path

VENV_DIR = Path(__file__).parent.resolve().parent / "venv"

def CreateVirtualEnv():
    if not VENV_DIR.exists():
        print(f"Creating virtual environment at {VENV_DIR} ...")
        subprocess.check_call([sys.executable, "-m", "venv", str(VENV_DIR)])
    if os.name == "nt":
        venv_python = VENV_DIR / "Scripts" / "python.exe"
    else:
        venv_python = VENV_DIR / "bin" / "python"
    return str(venv_python)

def InstallPackage(package, python_exe=None):
    python_to_use = python_exe or sys.executable
    subprocess.check_call([python_to_use, "-m", "pip", "install", package])

def ValidatePackage(package, python_exe=None):
    if importlib.util.find_spec(package) is None:
        print(f"Installing {package}...")
        InstallPackage(package, python_exe=python_exe)

def ValidatePackages(python_exe=None):
    packages = ["requests", "fake_useragent", "colorama"]
    for pkg in packages:
        ValidatePackage(pkg, python_exe=python_exe)