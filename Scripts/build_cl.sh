#!/bin/sh

LG='\033[1;32m'
NC='\033[0m' # No Color

cd ../Bin
cmake .. -G "Ninja"
ninja
echo "${LG}Execute GoonBMP${NC}"
./bin/GoonBMP
echo "${LG}Execute GoonMath${NC}"
./bin/GoonMath
echo "${LG}Execute GoonRenderer${NC}"
./bin/GoonRenderer

rm -r ./*
rm -r ./.*