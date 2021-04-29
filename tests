#!/bin/bash

files="input.txt empty.txt"

for f in $files; do
echo "Checking file $f."
expec="$(sha512sum $f | cut -d " " -f 1 )"
myout="$(./sha512 $f)"
echo "Expected: " $expec
echo "Output:   " $myout
if [[ $myout == $expec ]]; then
    echo "Pass"
else
    echo "Fail"
fi
done
