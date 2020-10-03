<?php

function isPalindrome($str) {
    if (strtolower($str) === strtolower(strrev($str))) {
        return $str .": is a palindrome \n";
    }
    return $str .": is not a palindrome \n";
}

echo isPalindrome('data');
echo isPalindrome('madaM');
echo isPalindrome('owo');
