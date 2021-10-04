#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iomanip>
using namespace std;

#define LIMIT 10000

int log_power(int n, int p, int mod)
{
    int result = 1;
    for (; p; p >>= 1)
    {
        if (p & 1)
            result = (1LL * result * n) % mod;
        n = (1LL * n * n) % mod;
    }
    return result;
}

bool new_func(int n)
{
    bool ok = true;

    for (int i = 1; i <= 5 && ok; i++) {
        int a = rand() + 1;
        int result = log_power(a, n - 1, n);
        ok &= (result == 1);
    }

    return ok;
}

int generate_prime()
{
    int generated = rand() % LIMIT;
    while (!new_func(generated))
        generated = rand() % LIMIT;
    return generated;
}

int gcd(int a, int b)
{
    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int generate_coprime(int n)
{
    int generated = rand() % LIMIT;
    while (gcd(n, generated) != 1)
        generated = rand() % LIMIT;
    return generated;
}

pair<int, int> euclid_extended(int a, int b) {
    if(!b) {
        return {1, 0};
    }

    auto result = euclid_extended(b, a % b);
    return { result.second, result.first - (a / b) * result.second };
}

int modular_inverse(int n, int mod)
{
    int inverse = euclid_extended(n, mod).first;
    while(inverse < 0)
        inverse += mod;
    return inverse;
}

typedef pair<int, int> PublicKey;
typedef pair<int, int> PrivateKey;

struct Keys
{
    PublicKey public_key;
    PrivateKey private_key;
};

Keys generate_keys()
{
    Keys result;

    int p, q;

    p = generate_prime();
    q = generate_prime();

    int n = p * q;
    int phi = (p -1) * (q - 1);
    int e = generate_coprime(phi);

    result.public_key =  make_pair(n, e);

    int d = modular_inverse(e, phi);

    result.private_key = make_pair(n, d);

    return result;
}

int encrypt(PublicKey key, int value)
{
    return log_power(value, key.second, key.first);
}

int decrypt(PrivateKey key, int value)
{
    return log_power(value, key.second, key.first);
}

int main()
{
    string s;
    srand(time(NULL));

    Keys keys = generate_keys();

    cout << "Public key: " << keys.public_key.first << " " << keys.public_key.second << "\n";
    cout << "Private key: " << keys.private_key.first << " " << keys.private_key.second << "\n";
    cout << "Enter your message\n";
    cin >> s;
    int len = s.size();

    cout << "Initial string: " << s << "\n";
    int enc[100] = {0};
    int dec[100] = {0};

    for (int i = 0; i < len; i++)
        enc[i] = encrypt(keys.public_key, s[i]);

    for (int i = 0; i < len; i++)
        dec[i] = decrypt(keys.private_key, enc[i]);
    cout << "Encrypted string\n";
    for(int i = 0; i < len; i++)
        cout << (int)enc[i];
    cout << "\n";
    cout << "Decrypted string: \n";
    for (int i = 0; i < len; i++)
        cout << (char)dec[i];
    cout << "\n";

    return 0;
}
