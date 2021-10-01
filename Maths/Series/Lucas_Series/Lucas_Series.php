<?php
function Lucas_Number($n){
	$counter = 0;
	$x = 2; //Represent Ln //L stands for Lucas Number
	$y = 1; //Represent Ln+1
	$z = 0; //Represent Ln+2

	echo $x.", ";
	echo $y.", ";

	while($counter < $n-2){
		$z = $x + $y;
		$x = $y;
		$y = $z;
		$counter++;
		echo $z;
		if($counter==$n-2){
			break;
		}
		else{
			echo ", ";
		}
	}
}

//Example Case
echo Lucas_Number(5);

?>
