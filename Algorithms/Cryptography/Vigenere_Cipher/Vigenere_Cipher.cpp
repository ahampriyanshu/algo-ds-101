#include <algorithm>
#include <cctype>
#include <string>

/**
 * Returns the mathematical (unsigned) modulus
 * @param x number
 * @param div divisor
 * @return the unsigned modulus x % div
 */
unsigned positive_modulo(const int x, const int div)
{
	return (x % div + div) % div;
}

/**
 * Returns, wheter character is a letter of the alphabet
 * @param ch character
 * @return true if ch is a letter. false otherwise
 */
bool is_letter(const unsigned char ch)
{
	bool result = false;
	if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z'))
		result = true;

	return result;
}

/**
 * Encrypts a string using Vigenere cipher
 * @input plaintext plaintext
 * @input keyword keyword
 * @return the encrypted plaintext
 */
std::string encrypt_vigenere(const std::string &plaintext, const std::string &keyword)
{
	std::string ciphertext(plaintext);
	std::string cleanKeyword(keyword);

	ciphertext.erase(std::remove_if(ciphertext.begin(), ciphertext.end(), [](const unsigned char ch){ return !is_letter(ch); }), ciphertext.end());
	cleanKeyword.erase(std::remove_if(cleanKeyword.begin(), cleanKeyword.end(), [](const unsigned char ch){ return !is_letter(ch); }), cleanKeyword.end());

	for (size_t i = 0; i < ciphertext.size(); ++i)
	{
		ciphertext[i] = toupper(ciphertext[i]);
		cleanKeyword[i] = toupper(cleanKeyword[i]);

		// shift by corresponding character of keyword
		ciphertext[i] = positive_modulo((ciphertext[i] - 'A' + (cleanKeyword[i%keyword.size()] - 'A')), ('Z' - 'A' + 1)) + 'A';
	}

	return ciphertext;
}

/**
 * Decrypts a string using Vigenere cipher
 * @input ciphertext ciphertext
 * @input keyword keyword
 * @return the decrypted ciphertext
 */
std::string decrypt_vigenere(const std::string &ciphertext, const std::string &keyword)
{
	std::string plaintext(ciphertext);
	std::string cleanKeyword(keyword);

	plaintext.erase(std::remove_if(plaintext.begin(), plaintext.end(), [](const unsigned char ch){ return !is_letter(ch); }), plaintext.end());
	cleanKeyword.erase(std::remove_if(cleanKeyword.begin(), cleanKeyword.end(), [](const unsigned char ch){ return !is_letter(ch); }), cleanKeyword.end());

	for (size_t i = 0; i < plaintext.size(); ++i)
	{
		plaintext[i] = toupper(plaintext[i]);
		cleanKeyword[i] = toupper(cleanKeyword[i]);

		// shift by corresponding character of keyword
		plaintext[i] = positive_modulo((plaintext[i] - 'A' - (cleanKeyword[i%keyword.size()] - 'A')), ('Z' - 'A' + 1)) + 'A';
	}

	return plaintext;
}


// Test section:

#include <iostream>

using namespace std;

int main()
{
	string plaintext;
	string keyword;

	cout << "Enter plaintext:" << endl;
	getline(cin, plaintext);

	cout << endl << "Enter keyword:" << endl;
	getline(cin, keyword);

	string ciphertext = encrypt_vigenere(plaintext, keyword);

	cout << endl << "Ciphertext:" << endl
		 << ciphertext << endl;

	string decryptedtext = decrypt_vigenere(ciphertext, keyword);

	cout << endl << "Decrypted text:" << endl
		 << decryptedtext << endl;

	return 0;
}
