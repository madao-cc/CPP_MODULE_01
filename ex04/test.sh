#!/bin/bash

# Compile the program (adjust flags or source filename if needed)
g++ -Wall -Wextra -Werror main.cpp -o tester
if [ $? -ne 0 ]; then
	echo "Compilation failed."
	exit 1
fi

# -------- Test 1: Incorrect number of arguments --------
echo "Test 1: Incorrect number of arguments"
./tester > test_output.txt 2>&1
if grep -q "usage: replace <file> old_word new_word" test_output.txt; then
	echo "Test 1 passed. ✅"
else
	echo "Test 1 failed. ❌"
fi

# -------- Test 2: File not found --------
echo "Test 2: File not found"
./tester non_existing.txt hello hi > test_output.txt 2>&1
if grep -q "Error: file not found" test_output.txt; then
	echo "Test 2 passed. ✅"
else
	echo "Test 2 failed. ❌"
fi

# -------- Test 3: Empty search string --------
echo "Test 3: Empty search string"
# Create an empty test file (or any file, content is irrelevant for this test)
echo "Dummy content" > testfile.txt
./tester testfile.txt "" hi > test_output.txt 2>&1
if grep -q "Error: old_word cannot be empty" test_output.txt; then
	echo "Test 3 passed. ✅"
else
	echo "Test 3 failed. ❌"
fi

# -------- Test 4: Valid replacement with multiple occurrences --------
echo "Test 4: Valid replacement (multiple occurrences)"
echo "Hello world. Hello again!" > testfile.txt
./tester testfile.txt Hello Hi
if [ -f "testfile.txt.replace" ]; then
	output=$(cat testfile.txt.replace)
	expected="Hi world. Hi again!"
	if [ "$output" == "$expected" ]; then
		echo "Test 4 passed. ✅"
	else
		echo "Test 4 failed: Output did not match expected. ❌"
		echo "Expected: $expected"
		echo "Got: $output"
	fi
else
	echo "Test 4 failed: Output file not created."
fi

# -------- Test 5: No occurrence of search string --------
echo "Test 5: No occurrence of search string"
echo "This is a test file with no match." > testfile.txt
./tester testfile.txt Hello Hi
if [ -f "testfile.txt.replace" ]; then
	output=$(cat testfile.txt.replace)
	expected=$(cat testfile.txt)
	if [ "$output" == "$expected" ]; then
		echo "Test 5 passed. ✅"
	else
		echo "Test 5 failed: Output does not match original file. ❌"
	fi
else
	echo "Test 5 failed: Output file not created."
fi

# -------- Test 6: Newline preservation --------
echo "Test 6: Newline preservation"
# Create a file with several lines, ensuring newline at the end
printf "Line1\nLine2\nLine3\n" > testfile.txt
./tester testfile.txt Line Replaced
if [ -f "testfile.txt.replace" ]; then
	output=$(cat testfile.txt.replace)
	expected="Replaced1
Replaced2
Replaced3
"
	# We check if each line begins with "Replaced" (not using numeric replacement here)
	if grep -q "^Replaced1" testfile.txt.replace && grep -q "^Replaced2" testfile.txt.replace && grep -q "^Replaced3" testfile.txt.replace; then
		echo "Test 6 passed. ✅"
	else
		echo "Test 6 failed: Newline or content mismatch. ❌"
	fi
else
	echo "Test 6 failed: Output file not created."
fi

# Cleanup temporary files
rm -f testfile.txt testfile.txt.replace test_output.txt tester

echo "All tests completed."