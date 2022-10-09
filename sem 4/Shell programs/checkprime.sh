#!/bin/bash

echo "Enter the number"
read number
flag=0
for (( c=2; c < $number / 2; c++ )) do
	if [ $(( $number % c )) == 0 ]; then
		flag=1
		break
	fi
done
if [ $flag == 1 ]; then
	echo "It is a non prime number"
else
	echo "It is a prime number"
fi