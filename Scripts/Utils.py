import sys
import time
from pathlib import Path

def DownloadFile(url, filepath):
    try:
        import requests
    except ImportError:
        print("The 'requests' package is not installed in the current Python environment.")
        print("Please run the setup script so it creates the virtualenv and installs dependencies, or install 'requests' manually.")
        raise

    Path(filepath).parent.mkdir(parents=True, exist_ok=True)
    with open(filepath, 'wb') as f:
        print(f"Downloading {url} ...")
        response = requests.get(url, stream=True)
        total = response.headers.get('content-length')
        if total is None:
            f.write(response.content)
        else:
            downloaded = 0
            total = int(total)
            startTime = time.time()
            chunk = max(int(total/1000), 1024*1024)
            for data in response.iter_content(chunk_size=chunk):
                downloaded += len(data)
                f.write(data)
                done = int(50*downloaded/total)
                percentage = (downloaded / total) * 100
                elapsedTime = time.time() - startTime
                avgKBPerSecond = (downloaded / 1024) / elapsedTime if elapsedTime > 0 else 0
                avgSpeedString = '{:.2f} KB/s'.format(avgKBPerSecond)
                if avgKBPerSecond > 1024:
                    avgMBPerSecond = avgKBPerSecond / 1024
                    avgSpeedString = '{:.2f} MB/s'.format(avgMBPerSecond)
                sys.stdout.write('\r[{}{}] {:.2f}% ({})     '.format('█' * done, '.' * (50-done), percentage, avgSpeedString))
                sys.stdout.flush()
    sys.stdout.write('\n')

def YesOrNo(prompt="[Y/N]: "):
    while True:
        reply = str(input(prompt)).lower().strip()
        if reply.startswith('y'):
            return True
        if reply.startswith('n'):
            return False