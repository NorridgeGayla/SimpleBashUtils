#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""

EXE_FILE="../../build/my_cat"
LOG_FILE=""

if [[ ! -f $EXE_FILE ]]
then
  echo "$EXE_FILE don't exist" >&2
  exit 1
fi

TEST_FILE="./test/bytes.txt"
FLAGS="-b -e -n -s -t -v -E -T --number-nonblank --number --squeeze-blank -r"

rm -f ./test/log.txt

exec 1>./test/log.txt
exec 2> /dev/null

echo ""

echo "TEST1"
for var in $FLAGS
do
          TEST1="$var $TEST_FILE"
          echo "$TEST1"
          $EXE_FILE $TEST1 > my_cat.txt
          cat $TEST1 > cat.txt
          DIFF_RES="$(diff -s my_cat.txt cat.txt)"
          if [ "$DIFF_RES" == "Files my_cat.txt and cat.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm my_cat.txt cat.txt
done

echo ""
echo "TEST2"
echo "incorrect file"
for var in $FLAGS
do
          TEST2="$var incorrect_file.txt"
          echo "$TEST2"
          $EXE_FILE $TEST2 > my_cat.txt
          cat $TEST2 > cat.txt
          DIFF_RES="$(diff -s my_cat.txt cat.txt)"
          if [ "$DIFF_RES" == "Files my_cat.txt and cat.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm my_cat.txt cat.txt
done

echo ""
echo "TEST3"
echo "without flags"
TEST3="$TEST_FILE"
echo "$TEST3"
$EXE_FILE $TEST3 > my_cat.txt
cat $TEST3 > cat.txt
DIFF_RES="$(diff -s my_cat.txt cat.txt)"
if [ "$DIFF_RES" == "Files my_cat.txt and cat.txt are identical" ]
  then
    echo "SUCCESS"
    (( COUNTER_SUCCESS++ ))
  else
    echo "FAIL"
    (( COUNTER_FAIL++ ))
fi
rm my_cat.txt cat.txt

echo ""
echo "TEST4"
echo "some files"
for var in $FLAGS
do
          TEST4="$var $TEST_FILE $TEST_FILE"
          echo "$TEST4"
          $EXE_FILE $TEST4 > my_cat.txt
          cat $TEST4 > cat.txt
          DIFF_RES="$(diff -s my_cat.txt cat.txt)"
          if [ "$DIFF_RES" == "Files my_cat.txt and cat.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm my_cat.txt cat.txt
done

echo ""
echo "TEST5"
echo "file + incorrect file + file"
for var in $FLAGS
do
          TEST5="$var $TEST_FILE incorrect_file.txt $TEST_FILE"
          echo "$TEST5"
          $EXE_FILE $TEST5 > my_cat.txt
          cat $TEST5 > cat.txt
          DIFF_RES="$(diff -s my_cat.txt cat.txt)"
          if [ "$DIFF_RES" == "Files my_cat.txt and cat.txt are identical" ]
            then
              echo "SUCCESS"
              (( COUNTER_SUCCESS++ ))
            else
              echo "FAIL"
              (( COUNTER_FAIL++ ))
          fi
          rm my_cat.txt cat.txt
done

echo ""
echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"