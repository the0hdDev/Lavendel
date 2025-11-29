#!/bin/bash

echo "=== Lavendel Setup (Linux/macOS) ==="

if ! command -v python3 &> /dev/null
then
    echo "Python was not found. Please install Python"
    exit 1
fi

echo "Setting"

echo "Running setup.py ..."
python3 setup.py

echo "Setup completed."
