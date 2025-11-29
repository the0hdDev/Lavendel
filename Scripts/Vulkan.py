import os
import platform
from pathlib import Path
from Utils import DownloadFile, YesOrNo

VULKAN_VERSION = "1.4.328.1"

def get_vulkan_sdk_path():
    return os.environ.get("VULKAN_SDK")

def check_vulkan_sdk():
    sdk = get_vulkan_sdk_path()
    if sdk and Path(sdk).exists():
        print(f"Vulkan SDK found at {sdk}")
        return True
    print("Vulkan SDK not found.")
    return False

def install_vulkan_sdk():
    system = platform.system()
    sdk_path = Path("Lavendel/vendor/VulkanSDK")
    sdk_path.mkdir(parents=True, exist_ok=True)

    if system == "Windows":
        url = f"https://sdk.lunarg.com/sdk/download/{VULKAN_VERSION}/windows/VulkanSDK-{VULKAN_VERSION}-Installer.exe"
        local_path = sdk_path / "VulkanSDK.exe"
    elif system == "Darwin":
        url = f"https://sdk.lunarg.com/sdk/download/{VULKAN_VERSION}/mac/vulkan-sdk-{VULKAN_VERSION}.dmg"
        local_path = sdk_path / "VulkanSDK.dmg"
    elif system == "Linux":
        url = f"https://sdk.lunarg.com/sdk/download/{VULKAN_VERSION}/linux/vulkan-sdk-{VULKAN_VERSION}.tar.gz"
        local_path = sdk_path / "vulkan-sdk.tar.gz"
    else:
        print("Unsupported OS for Vulkan SDK download.")
        return False

    print(f"Downloading Vulkan SDK to {local_path} ...")
    DownloadFile(url, local_path)
    print("Manual installation may be required after download.")
    return True

def ensure_vulkan():
    if check_vulkan_sdk():
        return True
    if YesOrNo("Do you want to download and install Vulkan SDK?"):
        return install_vulkan_sdk()
    return False
