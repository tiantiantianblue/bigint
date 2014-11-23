#!/bin/bash
clang++ -std=c++11 -Wall bigint.cc test.cc
./a.out <nozero.txt >1
python test.py <nozero.txt >2
diff 1 2
