#!/bin/sh

LG='\033[1;32m'
NC='\033[0m' # No Color

mkdir ../Bin
cd ../Bin
cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Debug
ninja
echo "${LG}Execute GoonBMP${NC}"
./bin/GoonBMP
echo "Program exit with return code : " $?
echo "${LG}Execute GoonMath${NC}"
./bin/GoonMath
echo "Program exit with return code : " $?
echo "${LG}Execute GoonRenderer${NC}"
./bin/GoonRenderer
echo "Program exit with return code : " $?

rm -r ../Bin/*
rm -r ../Bin/.*