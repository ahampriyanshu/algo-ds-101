#include <bits/stdc++.h>
using namespace std;

int calculate_Y(int x, vector<int> &poly)
{
    int y = 0;
    int temp = 1;
    for (auto coeff : poly)
    {
        y = (y + (coeff * temp));
        temp = (temp * x);
    }
    return y;
}

void secret_sharing(int S, vector<pair<int, int>> &points,
                    int N, int K)
{
    vector<int> poly(K);
    poly[0] = S;

    for (int j = 1; j < K; ++j)
    {
        int p = 0;
        while (p == 0)
            p = (rand() % 997);
        poly[j] = p;
    }
    for (int j = 1; j <= N; ++j)
    {
        int x = j;
        int y = calculate_Y(x, poly);
        points[j - 1] = {x, y};
    }
}

struct fraction
{
    int num, den;
    fraction(int n, int d)
    {
        num = n, den = d;
    }

    void reduce_fraction(fraction &f)
    {
        int gcd = __gcd(f.num, f.den);
        f.num /= gcd, f.den /= gcd;
    }

    fraction operator*(fraction f)
    {
        fraction temp(num * f.num, den * f.den);
        reduce_fraction(temp);
        return temp;
    }

    fraction operator+(fraction f)
    {
        fraction temp(num * f.den + den * f.num, den * f.den);
        reduce_fraction(temp);
        return temp;
    }
};

int Generate_Secret(int x[], int y[], int M)
{

    fraction ans(0, 1);
    for (int i = 0; i < M; ++i)
    {
        fraction l(y[i], 1);
        for (int j = 0; j < M; ++j)
        {
            if (i != j)
            {
                fraction temp(-x[j], x[i] - x[j]);
                l = l * temp;
            }
        }
        ans = ans + l;
    }
    return ans.num;
}

void solve(int S, int N, int K)
{
    vector<pair<int, int>> points(N);
    secret_sharing(S, points, N, K);
    int M = 2;
    if (M < K)
    {
        cout << "Points are less than threshold " << K << " Points Required" << endl;
    }

    int *x = new int[M];
    int *y = new int[M];

    for (int i = 0; i < M; ++i)
    {
        x[i] = points[i].first;
        y[i] = points[i].second;
    }

    cout << "Your Secret Code is " << Generate_Secret(x, y, M) << endl;
}

int main()
{
    int S, N;
    printf("Enter the Secret Code\n");
    scanf("%d", &S);
    printf("Enter the number of Parts\n");
    scanf("%d", &N);
    solve(S, N, 2);
    return 0;
}
