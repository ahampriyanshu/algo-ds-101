import Foundation

func isAnagram(_ firstWord: String, _ secondWord: String) -> Bool {
    // check length of both words, if length is not the same, they cannot be anagrams
    let firstWordCopy = NSString(string: firstWord).replacingOccurrences(of: " ", with: "").lowercased()
    let secondWordCopy = NSString(string: secondWord).replacingOccurrences(of: " ", with: "").lowercased()
    if firstWordCopy.count != secondWordCopy.count {
        return false;
    }
    return firstWordCopy.sorted().elementsEqual(secondWordCopy.sorted())

}

print("Enter the first word: ")
let firstWord = readLine(strippingNewline: true) ?? ""

print("Enter the second word: ")
let secondWord = readLine(strippingNewline: true) ?? ""

print(isAnagram(firstWord, secondWord))
