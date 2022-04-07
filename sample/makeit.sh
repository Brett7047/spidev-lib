#! /bin/bash

cd ..
cd build/
make
sudo make install
cd ..
cd sample
g++ spidev-testcpp.cc -lspidev-lib++
