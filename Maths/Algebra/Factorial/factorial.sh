#!/bin/bash
# Usage: factorial [n]

factorial=1

if [ $# -eq 1 ]; then
	n=$1
	while [ $n -gt 0 ]; do
		factorial=$(( $n * $factorial ))
		n=$(( $n - 1 ))
	done
	echo $factorial
else
	echo "Usage: $0 [n]"
fi
