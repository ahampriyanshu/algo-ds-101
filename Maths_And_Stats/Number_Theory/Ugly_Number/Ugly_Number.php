<?php
    //Check if the request has a number
    if (isset($_REQUEST['number'])) {
        $number = $_REQUEST['number'];
    }
    else {
        //Set random number
        $number = random_int(-10000, 10000);
    }
    
    echo "Number: ".$number;
    //Check if the number is ugly
    $isUglyNumber = checkUglyNumber($number);
    if($isUglyNumber){
        echo " is an Ugly Number";
    }
    else {
        echo " is not an Ugly Number";
    }
    

    //Function that checks if a number is ugly
    function checkUglyNumber($number) {
        if ($number<=1) {
            return false;
        }
        elseif ($number==2) {
            return true;
        }
        elseif ($number==3) {
            return true;
        }
        elseif ($number==5) {
            return true;
        }
        elseif ($number%2==0) {
            return checkUglyNumber($number/2);
        }
        elseif ($number%3==0) {
            return checkUglyNumber($number/3);
        }
        elseif ($number%5==0) {
            return checkUglyNumber($number/5);
        }
        else {
            return false;
        }
    }