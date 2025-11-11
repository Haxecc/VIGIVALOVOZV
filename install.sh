#!/usr/bin/env bash

echo "START BUILDING"
mkdir build
cd build
cmake ..
cmake --build .
mv VISIVALOVOZV ..
echo -e "\033[0;32mBUILDING DONE\033[0m"
