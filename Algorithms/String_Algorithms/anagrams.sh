# Follwing function does:
# Removal of all alphanumerics, Convert all lowercase to uppercase, Sort the string
preprocessing() {
   fold -w1 <<< "${1//[^[:alnum:]]/}" | tr '[:upper:]' '[:lower:]' | sort | tr -d '\n'
}

# function to check if given 2 arguments are anagrams
isAnagram() {
   a=$(preprocessing "$1")
   b=$(preprocessing "$2")
   [[ $a = $b ]] && echo "Strings $1 and $2 are Anagrams to each other" || echo "String $1 and $2 are not Anagrams";
}

echo "Enter two Strings: "
read a
read b
isAnagram $a $b
