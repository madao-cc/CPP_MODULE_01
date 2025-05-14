#!/bin/bash
#
# checker.sh for CPP_MODULE_01 ex04 ("Sed is for losers")
#

EXEC=./ex04
RED='\033[0;31m'; GREEN='\033[0;32m'; NC='\033[0m'
fail=0

# ————————————————————————————————
# PRECHECKS
# ————————————————————————————————
if [ ! -x "$EXEC" ]; then
  echo -e "${RED}✗ Error: '$EXEC' not found or not executable.${NC}"
  exit 1
fi

cleanup() {
  rm -f input_*.txt input_*.txt.replace expected_*.tmp
}
trap cleanup EXIT

# ————————————————————————————————
# HELPER FUNCTIONS
# ————————————————————————————————
# Print a header for a test
header() {
  echo -e "\n--- Test: $1 ---"
}

# Run an error-handling test: capture stderr & exit code
run_error_test() {
  desc="$1"; shift
  header "$desc"
  echo "Command: $EXEC $*"
  out=$("$EXEC" "$@" 2>&1)
  rc=$?
  echo "Expected: non-zero exit"
  echo -e "Actual:   exit code $rc"
  [ -n "$out" ] && echo "Output:   $out"
  if [ $rc -ne 0 ]; then
    echo -e "${GREEN}PASS${NC}"
  else
    echo -e "${RED}FAIL${NC}"
    fail=1
  fi
}

# Run a functional replace test: show before, sed-expected, your output
run_replace_test() {
  desc="$1"; infile="$2"; s1="$3"; s2="$4"
  header "$desc"
  echo "Input file ($infile):"
  sed -n '1,10p' "$infile" | sed 's/^/  /'
  echo "Replace '$s1' → '$s2'"
  "$EXEC" "$infile" "$s1" "$s2"
  echo

  # Build expected
  sed "s|${s1}|${s2}|g" "$infile" > expected_$$.tmp

  echo "Expected output (first 10 lines):"
  sed -n '1,10p' expected_$$.tmp | sed 's/^/  /'
  echo "Your output (first 10 lines):"
  sed -n '1,10p' "${infile}.replace" | sed 's/^/  /'

  if diff -q expected_$$.tmp "${infile}.replace" >/dev/null; then
    echo -e "${GREEN}PASS${NC}"
  else
    echo -e "${RED}FAIL (mismatch)${NC}"
    diff -u expected_$$.tmp "${infile}.replace" | sed 's/^/    /'
    fail=1
  fi
  rm -f expected_$$.tmp
}

# ————————————————————————————————
# ERROR‐HANDLING TESTS
# ————————————————————————————————
echo "=== Error‐handling tests ==="
run_error_test "no arguments"
run_error_test "only 1 argument" foo
run_error_test "only 2 arguments" foo bar
run_error_test "nonexistent file" nofile.txt a b

# unreadable file
echo "X" > input_unreadable.txt
chmod 000 input_unreadable.txt
run_error_test "unreadable input file" input_unreadable.txt a b
chmod 644 input_unreadable.txt

run_error_test "empty s1 string" input_unreadable.txt "" z

# ————————————————————————————————
# FUNCTIONAL TESTS
# ————————————————————————————————
echo -e "\n=== Functional tests ==="
# prepare inputs
echo -n > input_1.txt
echo "foo bar foo"        > input_2.txt
echo "aba baby aba"       > input_3.txt
echo "nothing here"       > input_4.txt
echo "same same same"     > input_5.txt
echo "bananana"           > input_6.txt

run_replace_test "empty file → replace 'a'→'b'" input_1.txt a b
run_replace_test "simple replace 'foo'→'baz'" input_2.txt foo baz
run_replace_test "remove 'aba'" input_3.txt aba ""
run_replace_test "no occurrences of 'XYZ'" input_4.txt XYZ Y
run_replace_test "s1 == s2 (no-op)" input_5.txt same same
run_replace_test "overlap test 'ana'→'X'" input_6.txt ana X

# ————————————————————————————————
# SUMMARY
# ————————————————————————————————
echo
if [ $fail -eq 0 ]; then
  echo -e "${GREEN}All tests passed! 🎉${NC}"
  exit 0
else
  echo -e "${RED}Some tests FAILED.${NC}"
  exit 1
fi
