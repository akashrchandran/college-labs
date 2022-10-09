#!/bin/bash

echo "Enter a number to check"
read number
if [ $(($number % 2)) == 0 ]; then
	echo "number is even"
else
	echo "Number is odd"
fi