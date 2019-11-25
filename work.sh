#!/bin/bash

cur_directory=$PWD

bash $cur_directory/compileJava.sh
bash $cur_directory/compileCpp.sh

echo "Enter number of tests : "
read NUM_TESTS

bash $cur_directory/run_tests.sh $NUM_TESTS
