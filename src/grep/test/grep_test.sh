#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""

EXE_FILE="../../build/my_grep"

if [[ ! -f $EXE_FILE ]]
then
  echo "$EXE_FILE don't exist" >&2
  exit 1
fi

PATTERN="Hello"
TEST_FILE="./test/file.txt ./test/test.txt ./test/test2.txt"
FLAGS="-i -v -c -l -o -s -h -n"

rm -f ./test/log.txt

exec 1>./test/log.txt
exec 2> /dev/null

echo ""

echo "TEST1"
for var in $FLAGS
do
          TEST1="$var $PATTERN $TEST_FILE"
          echo "$TEST1"
          $EXE_FILE $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

echo ""

echo "TEST2"
for var1 in $FLAGS
do
    for var2 in $FLAGS
    do
          TEST2="$var1 $var2 $PATTERN $TEST_FILE"
          echo "$TEST2"
          $EXE_FILE $TEST2 > s21_grep.txt
          grep $TEST2 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
    done
done

echo ""

echo "TEST3"
for var in $FLAGS
do
          TEST3="$var -e $PATTERN $TEST_FILE"
          echo "$TEST3"
          $EXE_FILE $TEST3 > s21_grep.txt
          grep $TEST3 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

echo ""

echo "TEST4"
for var1 in $FLAGS
do
    for var2 in $FLAGS
    do
          TEST4="$var1 $var2 -e $PATTERN $TEST_FILE"
          echo "$TEST4"
          $EXE_FILE $TEST4 > s21_grep.txt
          grep $TEST4 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
    done
done

echo ""

echo "TEST5"
for var in $FLAGS
do
          TEST5="$var -f $TEST_FILE"
          echo "$TEST5"
          $EXE_FILE $TEST5 > s21_grep.txt
          grep $TEST5 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

echo ""

echo "TEST6"
for var1 in $FLAGS
do
    for var2 in $FLAGS
    do
          TEST6="$var1 $var2 -f $TEST_FILE"
          echo "$TEST6"
          $EXE_FILE $TEST6 > s21_grep.txt
          grep $TEST6 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
    done
done

echo ""

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"