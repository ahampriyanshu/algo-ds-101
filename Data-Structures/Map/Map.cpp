#include<iostream>
#include<stdio.h>
#include <string.h>
#include <memory.h>
using namespace std;
#define MAX_KEY 64
#define MAX_DATA 128
#define MAX_TABLE 4096

typedef struct HashMap
{
  char key[MAX_KEY + 1];
  char data[MAX_DATA + 1];
};

HashMap tb[MAX_TABLE];

unsigned long hashCreateTableRow(const char *str);
int find(const char *key, char *data);
int add(const char *key, char *data);

int main(int argc, char* argv[])
{
int T, N, Q;

freopen("CreateHashMap.txt", "r", stdin);
cin >> T;

for (int test_case = 1; test_case <= T; test_case++)
{
    memset(tb, 0, sizeof(tb));
    cin >> N;
    char k[MAX_KEY + 1];
    char d[MAX_DATA + 1];

    for (int i = 0; i < N; i++)
    {
        cin >> k >> d;
        add(k, d);
    }

    cout << "#" << test_case << " " << endl;

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        char k[MAX_KEY + 1];
        char d[MAX_DATA + 1];

        cin >> k;
        if (find(k, d))
        {
            cout << d << endl;
        }
        else
        {
            cout << "not find" << endl;
        }
    }
}
return 0;
}


unsigned long hashCreateTableRow(const char *str)
{
unsigned long hash = 5381;
int c;

while (c = *str++)
{
    hash = (((hash << 5) + hash) + c) % MAX_TABLE;
}

return hash % MAX_TABLE;
}

int find(const char *key, char *data)
{
unsigned long h = hashCreateTableRow(key);
int cnt = MAX_TABLE;
int step = 1;

while (tb[h].key[0] != 0 && cnt--)
{
    if (strcmp(tb[h].key, key) == 0)
    {
        strcpy(data, tb[h].data);
        return 1;
    }
    h = (h + 1) % MAX_TABLE;
}
return 0;
}

int add(const char *key, char *data)
{
unsigned long h = hashCreateTableRow(key);
int step = 1;
int i = 0;

while (tb[h].key[0] != 0)
{
    if (strcmp(tb[h].key, key) == 0)
    {
        return 0;
    }

    h = (h + 1) % MAX_TABLE;
}
strcpy(tb[h].key, key);
strcpy(tb[h].data, data);
return 1;
}