<?php
	$x1=readline("Enter first X point :");
	$y1=readline("Enter first Y point :");
	$x2=readline("Enter second X point :");
	$y2=readline("Enter second Y point :");
	
	echo "(".$x1.",".$x2.") (".$y1.",".$y2.")";
	echo "<br>";
	distance($x1,$x2,$y1,$y2);
	
	function distance($x1,$x2,$y1,$y2){
			$d = sqrt(pow($x2-$x1,2)+pow($y2-$y1,2));
			echo "Distance = ".$d;
		}
?>
