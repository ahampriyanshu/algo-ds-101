<?php
function Gauss_Easter($year){
	$a = fmod($year,19);
	$b = fmod($year,4);
	$c = fmod($year,7);
	$p = floor($year/100);
	$q = floor((13+8*$p)/25);
	$m = fmod((15-$q+$p-($p/4)),30);
	$n = fmod(4+$p-($p/4),7);
	$d = fmod((19*$a+$m),30);
	$e = fmod($n+2*$b+4*$c+6*$d,7);
	$days = 22+$d+$e;

	if($d==29 && $e==6){
		echo $year."April 19";
	}
	elseif($d==28 && $e==6){
		echo $year."April 18";
	}
	else{
		if($days>31){
			echo $year."-April-".($days-31);
		}
		else{
			echo $year."-March-".$days;
		}
	}
}
//Example Case
echo Gauss_Easter(2020);
