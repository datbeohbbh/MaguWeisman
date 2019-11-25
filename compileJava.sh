#!/bin/bash

cur_directory=$PWD
compile_directory=$cur_directory/srcJava
out_directory=$cur_directory/outJava

mkdir -p $cur_directory/outJava

javac -d $out_directory $compile_directory/*.java

chmod -R +x $out_directory/*

