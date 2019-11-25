#!/bin/bash

cur_directory=$PWD
execute_cpp=$cur_directory/outCpp/main
execute_java=$cur_directory/outJava
test_directory=$cur_directory/runTests
input=$test_directory/test.inp
output=$test_directory/test.out

touch $input $output

g++ $test_directory/check.cpp -o $test_directory/check -std=c++14
g++ $test_directory/gentest.cpp -o $test_directory/gentest -std=c++14

generate=$test_directory/gentest
checker=$test_directory/check

NUM_TESTS=$1

for (( i=0; i < $NUM_TESTS; i++ ))
do
	$generate $input
	outCpp=$($execute_cpp < $input)
	outJava=$(cd $execute_java && java Main < $input)
	echo $outCpp > $output
	echo $outJava >> $output

	echo "TEST $i :"
	cat $input
	echo
	echo "OUTPUT TEST $i : "
	echo $outCpp
	echo $outJava
	echo

	verdict=$($checker < $output)
	if [ "$verdict" == "WA" ];
	then 
		echo "WRONG ANSWER TEST $i"
		exit 0
	else 
		echo "PASS TEST $i"
	fi
done

echo "------------------------SUCCESS--------------------------"

