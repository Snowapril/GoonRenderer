#!/bin/sh

LG='\033[1;32m'
NC='\033[0m' # No Color

mkdir ../Bin
cd ../Bin
cmake .. -G "Ninja" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS=-pg -DCMAKE_EXE_LINKER_FLAGS=-pg -DCMAKE_SHARED_LINKER_FLAGS=-pg
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

gprof -b ./bin/GoonRenderer > ../Scripts/GoonRenderer.txt

if [ "$1" = "-r" ]
then
    rm -r ../Bin/*
    rm -r ../Bin/.*
else
    cp bin/* ../Scripts
fi