#!/bin/bash

cur_directory=$PWD
compile_directory=$cur_directory/srcCpp
out_directory=$cur_directory/outCpp

mkdir -p $out_directory

g++ $compile_directory/main.cpp -o $out_directory/main -std=c++14


