<?php
function cipher(string $str, int $key)
{   
    $k = $key % 26;

    $input = array_map(function($char){
        return ord($char);
    }, str_split($str));
    
    $res = array_map(function($char) use($k){
        //capital letters
        if($char > 64 && $char < 91)
        {
            return chr(65 + ($char + $k) % 65 % 26);
        }
        else if($char > 96 && $char < 123)
        {
            return chr(97 + ($char + $k) % 97 % 26);
        }
        else
        {
            return chr($char);
        }
    }, $input);

    return implode($res);
}

?>
