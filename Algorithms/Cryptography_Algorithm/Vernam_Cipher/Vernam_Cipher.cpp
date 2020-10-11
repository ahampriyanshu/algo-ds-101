#include <cstring>
#include <random>

/**
 * Encrypts/decrypts data using vernam cipher
 * @param[in/out] data data to which Vernam cipher is applied
 * @param[in] key key, is expected to have the same size as data
 * @param[in] size memory size (in bytes) of data
 */
void apply_vernam(void *data, void const * key, const size_t size)
{
	static_assert(sizeof(char) == 1);
	const unsigned sizeTypeSize = sizeof(size_t);

	const size_t numberOfIterations = size / sizeTypeSize;
	size_t *currentDataPosition = static_cast<size_t*>(data);
	size_t const * currentKeyPosition = static_cast<size_t const *>(key);

	for (size_t i = 0; i < numberOfIterations; ++i)
	{
		*currentDataPosition = *currentDataPosition ^ *currentKeyPosition; // XOR
		++currentDataPosition;
		++currentKeyPosition;
	}

	const unsigned numberOfRemainingOperations = size % sizeTypeSize;
	char *currentRemainingDataPosition = reinterpret_cast<char*>(currentDataPosition);
	char const * currentRemainingKeyPosition = reinterpret_cast<char const *>(currentKeyPosition);

	for (unsigned i = 0; i < numberOfRemainingOperations; ++i)
	{
		*currentRemainingDataPosition = *currentRemainingDataPosition ^ *currentRemainingKeyPosition; // XOR
		++currentRemainingDataPosition;
		++currentRemainingKeyPosition;
	}

	return;
}

/** Generates a random uniformly distributed key. The key has to be allocated with at least size byte of memory.
 * @param[out] key generated key
 * @param[in] size size of key
 */
void generate_key(void *key, const size_t size)
{
	std::random_device rd;
	std::uniform_real_distribution<double> distribution(0.0, 0.1);

	const unsigned doubleSize = sizeof(double);

	const size_t numberOfIterations = size / doubleSize;

	double *currentKeyPosition = static_cast<double*>(key);

	for (size_t i = 0; i < numberOfIterations; ++i)
	{
		*currentKeyPosition = distribution(rd);
		++currentKeyPosition;
	}

	const unsigned numberOfRemainingOperations = size % doubleSize;
	char * currentRemainingKeyPosition = reinterpret_cast<char*>(currentKeyPosition);

	for (unsigned i = 0; i < numberOfRemainingOperations; ++i)
	{
		const double randomNumber = distribution(rd);
		memcpy(currentRemainingKeyPosition, &randomNumber, sizeof(char));
		++currentRemainingKeyPosition;
	}

	return;
}

// Test section:

#include <iostream>

using namespace std;

int main()
{
	string data;

	cout << "Enter plaintext:" << endl;
	getline(cin, data);

	// Generate random key:
	string key(data);
	generate_key(&key[0], sizeof(char)*key.size());

	cout << "Random key:" << endl
	     << key << endl;

	apply_vernam(&data[0], &key[0], sizeof(char)*data.size());

	cout << endl << "Ciphertext:" << endl
		 << data << endl;

	apply_vernam(&data[0], &key[0], sizeof(char)*data.size());

	cout << endl << "Decrypted text:" << endl
		 << data << endl;

	return 0;
}
