#!/bin/bash

INPUTS=(
    './computor "2 * X^2 + 2 * X^1 + 5 * X^0 = 0 * X^0"'
    './computor "5 * X^2 + 3 * X^1 + 7 * X^0 = 2 * X^0"'
    './computor "4 * X^2 + 8 * X^1 + 4 * X^0 = 2 * X^1 + 2 * X^0"'
    './computor "3 * X^2 + 7 * X^1 + 9 * X^0 = 4 * X^1 + 1 * X^0"'
    './computor "6 * X^2 + 2 * X^1 + 8 * X^0 = 3 * X^2 + 5 * X^1 + 2 * X^0"'
    './computor "10 * X^2 + 5 * X^1 + 2 * X^0 = 4 * X^2 + 1 * X^1 + 6 * X^0"'
    './computor "7 * X^2 + 4 * X^1 + 3 * X^0 = 2 * X^2 + 9 * X^1 + 8 * X^0"'
    './computor "8 * X^2 + 6 * X^1 + 5 * X^0 = 3 * X^1 + 1 * X^0"'
    './computor "9 * X^2 + 2 * X^1 + 10 * X^0 = 4 * X^2 + 7 * X^1 + 2 * X^0"'
    './computor "12 * X^2 + 8 * X^1 + 4 * X^0 = 6 * X^2 + 4 * X^1 + 2 * X^0"'

    './computor "1 * X^2 + 2 * X^1 + 1 * X^0 = 5 * X^0"'
    './computor "1 * X^2 - 4 * X^1 + 4 * X^0 = 2 * X^0"'
    './computor "2 * X^2 + 4 * X^1 + 6 * X^0 = 1 * X^2 + 2 * X^1 + 3 * X^0"'
    './computor "5 * X^2 + 10 * X^1 + 5 * X^0 = 2 * X^2 + 4 * X^1 + 2 * X^0"'
    './computor "3 * X^2 + 6 * X^1 + 8 * X^0 = 1 * X^2 + 2 * X^1 + 5 * X^0"'

    './computor "2 * X^3 + 5 * X^2 + 3 * X^1 + 7 * X^0 = 1 * X^3 + 2 * X^2 + 4 * X^1 + 2 * X^0"'
    './computor "4 * X^4 + 2 * X^3 + 7 * X^2 + 5 * X^1 + 1 * X^0 = 2 * X^4 + 3 * X^3 + 2 * X^2 + 1 * X^0"'
    './computor "6 * X^2 + 3 * X^3 + 8 * X^1 + 4 * X^0 = 2 * X^3 + 1 * X^2 + 5 * X^1 + 7 * X^0"'
    './computor "10 * X^2 + 4 * X^0 + 3 * X^1 = 5 * X^1 + 9 * X^0"'
    './computor "7 * X^2 + 2 * X^0 + 4 * X^1 = 3 * X^2 + 8 * X^0 + 1 * X^1"'

    './computor "100 * X^2 + 20 * X^1 + 1 * X^0 = 50 * X^1 + 10 * X^0"'
    './computor "50 * X^2 + 100 * X^1 + 25 * X^0 = 10 * X^2 + 20 * X^1 + 5 * X^0"'
    './computor "1000 * X^2 + 1 * X^1 + 100 * X^0 = 500 * X^2 + 2 * X^1 + 50 * X^0"'

    './computor "1 * X^2 + 1 * X^1 + 1 * X^0 = 2 * X^1 + 3 * X^0"'
    './computor "2 * X^2 + 3 * X^1 + 4 * X^0 = 1 * X^1 + 2 * X^0"'
    './computor "5 * X^2 - 2 * X^1 + 9 * X^0 = 3 * X^1 - 1 * X^0"'
    './computor "8 * X^2 - 4 * X^1 + 2 * X^0 = 2 * X^2 + 6 * X^1 - 4 * X^0"'
)

: > computor_test_results.txt

for cmd in "${INPUTS[@]}"; do
    echo "========================================" | tee -a computor_test_results.txt
    echo "$cmd" | tee -a computor_test_results.txt
    echo "========================================" | tee -a computor_test_results.txt
    eval "$cmd" 2>&1 | tee -a computor_test_results.txt
    echo | tee -a computor_test_results.txt
done

echo "Results saved to computor_test_results.txt"