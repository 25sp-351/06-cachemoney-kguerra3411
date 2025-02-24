#!/bin/bash

make

run_test() {
    input=$1
    expected_output=$2

    actual_output=$(echo $input | ./output)
    if [ "$actual_output" == "$expected_output" ]; then
        echo "Test passed: $input"
    else
        echo "Test failed: $input"
        echo "Expected: $expected_output"
        echo "Got: $actual_output"
    fi
}

# Basics
run_test 0 "0 = zero dollars and zero cents"
run_test 123 "123 = one dollars and twenty three cents"

# Big
run_test 1000000000 "1000000000 = ten million  dollars and zero cents"
run_test 1234567890 "1234567890 = twelve million three hundred forty five thousand six hundred seventy eight dollars and ninety cents"

# Weird 
run_test -1 "Error: Negative numbers are not allowed. Please enter a valid number."
run_test 999999999 "999999999 = nine million nine hundred ninety nine thousand nine hundred ninety nine dollars and ninety nine cents"

make clean