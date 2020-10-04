function palindromeCheck(word)
{
  var length = word.length;
  
  for(var i = 0; i < length/2; i++)
  {
    if(word[i] !== word[length - 1 - i])
    {
      return false;
    }
  }
  
  return true
}

console.log(palindromeCheck("Hello"));
console.log(palindromeCheck("kayak"));