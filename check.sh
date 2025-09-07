#!/bin/bash

# Script to check correctness of C++ programs
# Compiles each question*.cpp and runs the executable
# Validates output against expected results from files

echo "Checking C++ programs for correctness..."
echo "=========================================="

correct_count=0
total_count=0

# Test cases for each question
test_cases=("a" "b")

# Check if a specific file is provided as argument
if [ $# -eq 1 ]; then
    file="$1"
    if [[ "$file" =~ question([1-5])\.cpp ]]; then
        i="${BASH_REMATCH[1]}"
        files_to_check=("$file")
    else
        echo "Invalid file: $file. Must be question1.cpp to question5.cpp"
        exit 1
    fi
else
    # No argument, check all
    files_to_check=("question1.cpp" "question2.cpp" "question3.cpp" "question4.cpp" "question5.cpp")
fi

for file in "${files_to_check[@]}"
do
    if [[ "$file" =~ question([1-5])\.cpp ]]; then
        i="${BASH_REMATCH[1]}"
    fi
    exe="question${i}"

    if [ -f "$file" ]; then
        echo "Checking $file..."
        echo "-------------------"

        # Compile with warnings
        if g++ -Wall -Wextra -o "$exe" "$file" 2>&1; then
            echo "✓ Compilation successful."

            question_correct=true

            for test_case in "${test_cases[@]}"
            do
                echo "  Testing case $test_case..."

                # Run and capture output, passing input file as argument
                if [ -f "test_data/input${i}${test_case}.txt" ]; then
                    ./"$exe" "test_data/input${i}${test_case}.txt" > output.txt 2>&1
                    exit_code=$?
                else
                    echo "  ✗ Input file test_data/input${i}${test_case}.txt not found."
                    question_correct=false
                    continue
                fi

                if [ $exit_code -eq 0 ]; then
                    echo "  ✓ Execution successful."

                    # Compare actual output with expected from file
                    if [ -f "test_data/output${i}${test_case}.txt" ]; then
                        if diff -w "test_data/output${i}${test_case}.txt" output.txt > /dev/null; then
                            echo "  ✓ Output matches expected result for case $test_case."
                        else
                            echo "  ✗ Output does not match expected result for case $test_case."
                            echo "    Expected:"
                            cat "test_data/output${i}${test_case}.txt" | sed 's/^/      /'
                            echo "    Actual:"
                            cat output.txt | sed 's/^/      /'
                            question_correct=false
                        fi
                    else
                        echo "  ✗ Expected output file test_data/output${i}${test_case}.txt not found."
                        question_correct=false
                    fi
                else
                    echo "  ✗ Execution failed with exit code $exit_code."
                    echo "    Output:"
                    cat output.txt | sed 's/^/    /'
                    question_correct=false
                fi
            done

            if [ "$question_correct" = true ]; then
                echo "  $file: CORRECT"
                correct_count=$((correct_count + 1))
            else
                echo "  $file: INCORRECT"
            fi

            total_count=$((total_count + 1))

            # Clean up
            rm -f "$exe" output.txt
        else
            echo "✗ Compilation failed."
            echo "  $file: INCORRECT"
            total_count=$((total_count + 1))
        fi
    else
        echo "✗ $file not found."
        echo "  $file: INCORRECT"
        total_count=$((total_count + 1))
    fi
    echo ""
done

echo "=========================================="
echo "Summary: $correct_count/$total_count programs are correct."
echo "Checking complete."
