#!/usr/bin/env bash

echo "START BUILDING"
cmake --build build/
mv build/VISIVALOVOZV .
echo -e "\033[0;32mBUILDING DONE\033[0m"
