#!/bin/bash
echo $0 with $# args: "$*"
index=1

for arg in $*
do
	echo Argument ${index} is: ${arg}
	let "index+=1"
done
exit
