function groupAnagrams(stringValue) {
    //create dictionary object to keep track of which strings are made up of which letters

    let anagrams = {};

    for (let str of stringValue) {
        // loop through strings and  sort them alphabetically
        let letters = str.split("").sort().join("");

        //if the sorted string already exists as a key on the dictionary, push string 
        if (anagrams[letters])
            anagrams[letters].push(str)

        //else it as a key to the dictionary
        else
            anagrams[letters] = [str]
    }
    // use objects.values on the dictionary to return all values as an array
    return Object.values(anagrams);
};

//Test
let array = []
let array_len = parseInt(prompt("Input number of words in string array:"))
for(var i =0; i< array_len; i++){
    let word = prompt("Enter a word");
    array.push(word)
}
console.log(groupAnagrams(array))
