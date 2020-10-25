<?php 

function KMPSearch($pat, $txt) 
{ 
	$M = strlen($pat); 
	$N = strlen($txt); 

	$lps=array_fill(0,$M,0); 

	computeLPSArray($pat, $M, $lps); 

	$i = 0; // index for txt[] 
	$j = 0; // index for pat[] 
	while ($i < $N) { 
		if ($pat[$j] == $txt[$i]) { 
			$j++; 
			$i++; 
		} 

		if ($j == $M) { 
			printf("Pattern Found at index ".($i - $j)."\n"); 
			$j = $lps[$j - 1]; 
		} 

		else if ($i < $N && $pat[$j] != $txt[$i]) { 
			if ($j != 0) 
				$j = $lps[$j - 1]; 
			else
				$i = $i + 1; 
		} 
	} 
} 

function computeLPSArray($pat, $M, &$lps) 
{ 
	$len = 0; 

	$lps[0] = 0; // lps[0] is always 0 

	$i = 1; 
	while ($i < $M) { 
		if ($pat[$i] == $pat[$len]) { 
			$len++; 
			$lps[$i] = $len; 
			$i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			if ($len != 0) { 
				$len = $lps[$len - 1]; 

			} 
			else // if (len == 0) 
			{ 
				$lps[$i] = 0; 
				$i++; 
			} 
		} 
	} 
} 

	$txt = readline("Enter text : "); 
	$pat = readline("Enter pattern : "); 
	KMPSearch($pat, $txt); 
	
?> 
