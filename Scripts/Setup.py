#!/usr/bin/env python3
import sys
import subprocess
import os
from pathlib import Path

# Project root is the parent of the Scripts directory
PROJECT_ROOT = Path(__file__).parent.resolve().parent
VENV_DIR = PROJECT_ROOT / "venv"

def run(cmd):
    subprocess.check_call(cmd, shell=True)

def create_venv():
    if not VENV_DIR.exists():
        print(f"Creating virtual environment at {VENV_DIR} ...")
        subprocess.check_call([sys.executable, "-m", "venv", str(VENV_DIR)])
    # determine venv python path
    if os.name == "nt":
        venv_python = VENV_DIR / "Scripts" / "python.exe"
    else:
        venv_python = VENV_DIR / "bin" / "python"
    return str(venv_python)

def install_packages_in_venv(venv_python, packages):
    print(f"Installing packages in venv ({venv_python}): {packages}")
    subprocess.check_call([venv_python, "-m", "pip", "install", "--upgrade", "pip"])
    subprocess.check_call([venv_python, "-m", "pip", "install"] + packages)

def cleanup():
    temp_paths = [
        PROJECT_ROOT / "Velt" / "vendor" / "VulkanSDK" / "VulkanSDK.exe",
        PROJECT_ROOT / "Velt" / "vendor" / "VulkanSDK" / "VulkanSDK.dmg",
        PROJECT_ROOT / "Velt" / "vendor" / "VulkanSDK" / "vulkan-sdk.tar.gz"
    ]
    for p in temp_paths:
        if p.exists():
            p.unlink()
            print(f"Removed temporary file: {p}")

def running_in_venv():
    if os.environ.get("Velt_IN_VENV") == "1":
        return True

    try:
        venv_dir = VENV_DIR.resolve()
        if Path(sys.prefix).resolve() == venv_dir:
            return True
    except Exception:
        pass

    try:
        exec_path = Path(sys.executable).resolve()
        if venv_dir in exec_path.parents:
            return True
    except Exception:
        # last-resort substring check
        if str(sys.executable).startswith(str(VENV_DIR)):
            return True

    return False

def main():
    print("=== Velt Setup ===")

    if not running_in_venv():
        venv_python = create_venv()
        install_packages_in_venv(venv_python, ["requests", "fake_useragent", "colorama"])
        new_env = os.environ.copy()
        new_env["Velt_IN_VENV"] = "1"
        print("Re-executing setup.py inside the virtual environment...")
        os.execve(venv_python, [venv_python, str(Path(__file__).resolve())] + sys.argv[1:], new_env)

    import CheckPython
    import Vulkan

    try:
        CheckPython.ValidatePackages()
    except Exception as e:
        print(f"Warning: ValidatePackages raised: {e}")

    if not Vulkan.ensure_vulkan():
        print("Vulkan SDK setup failed or canceled.")
        sys.exit(1)

    print("Updating Git submodules...")
    run("git submodule update --init --recursive")

    print("\nSetup completed successfully!")

    cleanup()

if __name__ == "__main__":
    main()