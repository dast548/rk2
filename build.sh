#!/bin/bash
set -e

echo "=== Configuring ==="
cmake -S . -B build --fresh \
    -DCPACK_GENERATOR=DEB \
    -DBUILD_TESTS=ON \
    -DCMAKE_BUILD_TYPE=Debug

echo "=== Building ==="
cmake --build build

echo "=== Testing ==="
ctest --test-dir build --output-on-failure

echo "=== Packaging ==="
cmake --build build --target package

echo "=== Done! DEB package: ==="
ls build/*.deb
