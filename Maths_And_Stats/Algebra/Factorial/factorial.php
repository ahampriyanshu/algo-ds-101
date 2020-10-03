<html>  
<head>  
<title>Factorial Program using loop in PHP</title>  
</head>  
<body>  
<form method="post">  
    Enter the Number:<br>  
    <input type="number" name="number" id="number">  
    <input type="submit" name="submit" value="Submit" />  
</form>  
<?php   
    function fact ($n)  
    {  
        if($n <= 1)   
        {  
            return 1;  
        }  
        else   
        {  
            return $n * fact($n - 1);  
        }  
    }  
    if($_POST){  
        $fact = 1;  
        //getting value from input text box 'number'  
        $number = $_POST['number'];  
        echo "Factorial of $number:<br><br>";  
        echo fact($number) . "<br>";  
    }  
?>  
</body>  
</html>  