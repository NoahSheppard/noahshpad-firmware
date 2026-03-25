#/bin/bash

cmake .. -DTARGET_PLATFORM=desktop -G Ninja -DCMAKE_C_COMPILER=gcc-13 -DCMAKE_CXX_COMPILER=g++-13
ninja 