#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
PATTERN="Hello"
TEST_FILE="file.txt test.txt test2.txt"
FLAGS="-i -v -c -l -o -s -h -n"

echo "" > log.txt

echo "TEST1" >> log.txt
for var in $FLAGS
do
          TEST1="$var $PATTERN $TEST_FILE"
          echo "$TEST1" >> log.txt
          ./s21_grep $TEST1 > s21_grep.txt
          grep $TEST1 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS" >> log.txt
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

echo "" >> log.txt

echo "TEST2" >> log.txt
for var1 in $FLAGS
do
    for var2 in $FLAGS
    do
          TEST2="$var1 $var2 $PATTERN $TEST_FILE"
          echo "$TEST2" >> log.txt
          ./s21_grep $TEST2 > s21_grep.txt
          grep $TEST2 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS" >> log.txt
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
    done
done

echo "" >> log.txt

echo "TEST3" >> log.txt
for var in $FLAGS
do
          TEST3="$var -e $PATTERN $TEST_FILE"
          echo "$TEST3" >> log.txt
          ./s21_grep $TEST3 > s21_grep.txt
          grep $TEST3 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS" >> log.txt
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

echo "" >> log.txt

echo "TEST4" >> log.txt
for var1 in $FLAGS
do
    for var2 in $FLAGS
    do
          TEST4="$var1 $var2 -e $PATTERN $TEST_FILE"
          echo "$TEST4" >> log.txt
          ./s21_grep $TEST4 > s21_grep.txt
          grep $TEST4 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS" >> log.txt
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
    done
done

echo "" >> log.txt

echo "TEST5" >> log.txt
for var in $FLAGS
do
          TEST5="$var -f $TEST_FILE"
          echo "$TEST5" >> log.txt
          ./s21_grep $TEST5 > s21_grep.txt
          grep $TEST5 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS" >> log.txt
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
done

echo "" >> log.txt

echo "TEST6" >> log.txt
for var1 in $FLAGS
do
    for var2 in $FLAGS
    do
          TEST6="$var1 $var2 -f $TEST_FILE"
          echo "$TEST6" >> log.txt
          ./s21_grep $TEST6 > s21_grep.txt
          grep $TEST6 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Files s21_grep.txt and grep.txt are identical" ]
            then
              echo "SUCCESS" >> log.txt
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL" >> log.txt
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt
    done
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"