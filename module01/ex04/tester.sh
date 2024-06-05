#!/bin/bash

make && clear
# Replace with the name of your binary
BIN=SedSucks
echo -e "first\trow\nsecond\trow, second\tcolumn\nthird\trow, second\tcolumn, third\tcolumn\nfourth\trow, second\tcolumn, third\tcolumn, fourth\tcolumn\nlast\trow, second\tcolumn, third\tcolumn, fourth\tcolumn, last\tcolumn" > test.txt

echo -e "\e[1;32mFile Created\e[0m"
cat test.txt

echo

echo -e "\e[1;32mTest 1: Replace character 'w' for 'L'\e[0m"
./$BIN test.txt "w" "L" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/w/L/g' test.txt
sed 's/w/L/g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

echo -e "\e[1;32mTest 2: Replace 'row' for 'line'\e[0m"
./$BIN test.txt "row" "line" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/row/line/g' test.txt
sed 's/row/line/g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

echo -e "\e[1;32mTest 2: Replace 'column' for 'grid'\e[0m"
./$BIN test.txt "column" "grid" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/column/grid/g' test.txt
sed 's/column/grid/g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

echo -e "\e[1;32mTest 3: Replace 'apple' for 'orange'\e[0m"
./$BIN test.txt "apple" "orange" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/apple/orange/g' test.txt
sed 's/apple/orange/g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

echo -e "\e[1;32mTest 3: Replace 'row' for 'row'\e[0m"
./$BIN test.txt "row" "row" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/row/row/g' test.txt
sed 's/row/row/g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

echo -e "\e[1;32mTest 3: Replace 'column' for 'column'\e[0m"
./$BIN test.txt "column" "column" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/column/column/g' test.txt
sed 's/column/column/g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

echo -e "\e[1;32mTest 4: Replace 'row' for 'a longer string to replace original string'\e[0m"
./$BIN test.txt "row" "a longer string to replace original string" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/row/a longer string to replace original string/g' test.txt
sed 's/row/a longer string to replace original string/g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

echo -e "\e[1;31mTest 5: Invalid file\e[0m"
./$BIN invalid_file "line" "a longer string to replace line"
echo -e "\e[0;33msed:\e[0m"
sed 's/row/a longer string to replace line/g' invalid_file

echo

echo -e "\e[1;31mTest 6: 4 arguments\e[0m"
./$BIN test.txt "row" "column" "column"

echo

echo -e "\e[1;31mTest 7: 2 arguments\e[0m"
./$BIN test.txt

echo

echo -e "\e[1;31mTest 8: First string is empty\e[0m"
./$BIN test.txt "" "sentence"
echo -e "\e[0;33msed:\e[0m"
sed 's//sentence/g' test.txt

echo

echo -e "\e[1;31mTest 9: Both strings are empty\e[0m"
./$BIN test.txt "" ""
echo -e "\e[0;33msed:\e[0m"
sed 's///g' test.txt

echo

echo -e "\e[1;32mTest 9: Second string is empty Str1('column') Str2('')\e[0m"
./$BIN test.txt "column" "" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/column//g' test.txt
sed 's/column//g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

echo -e "\e[1;32mTest 10: Test infinite loop\e[0m"
./$BIN test.txt "column" "column break" && cat test.txt.replace
echo -e "\e[0;33msed:\e[0m"
sed 's/column/column break/g' test.txt
sed 's/column/column break/g' test.txt > sed.replace
cmp -s sed.replace test.txt.replace || echo -e "\e[1;31mError: Output of the files are different!\e[0m"

echo

rm -f test.txt test.txt.replace sed.replace
