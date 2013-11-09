#!/bin/bash
# filename: random.sh
# usage: bash random.sh <number>
if [ $# != 1 ]; then
	echo "usage: bash random.sh <number>"
	exit 1
fi
echo $1
for ((i=1; i<=$1; i++)); do
	echo -n $(($RANDOM-32767/2)) " "
done
echo ""
echo "Generate $1 random number totally !!!" >&2
