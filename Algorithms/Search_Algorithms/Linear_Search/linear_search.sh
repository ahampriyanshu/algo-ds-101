#!/bin/bash

echo 'Enter the array elements:'
read -a arr

echo 'Enter the element to search for: '
read s

for i in ${arr[@]}; do
        if [ $i -eq $s ]; then
                echo 'Element found!'
                exit 0
        fi
done

echo 'Element not found'
