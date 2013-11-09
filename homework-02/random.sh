#!/bin/bash
# filename: random.sh
# usage: bash random.sh <number>
if [ $# != 2 ]; then
	echo "usage: bash random.sh <number> <number>"
	exit 1
fi
echo $1","
echo $2","
for ((i=1; i<=$1; i++)); do
	for((j=1; j<=$2; j++)); do
		if [ $j != $2 ]; then
			echo -n $(($RANDOM-32767/2))","
		else
		  echo $(($RANDOM-32767/2))
		fi
	done
done
echo "Generate $1 * $2 random number totally !!!" >&2
