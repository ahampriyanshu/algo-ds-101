#include<bits/stdc++.h>
using namespace std;

char letterconverter(int number)
{
    return 'A' + (number-10);
}

int main()
{
    vector<int> primes;
    int num, flag, x, base2, i, upto;

    // Take input from user
    cout << "Find prime numbers upto : ";
    cin >> upto;

    for(num = 2; num <= upto; num++)
    {
        flag = 0;
        for(i = 2; i <= (num / 2); i++)
        {
            if(num % i == 0) {
                flag = 1;
                break;
            }
        }
        
        // If the number is prime then store it in primes vector
        if(flag == 0)
            primes.push_back(num);
    }
    
    // Printing all primes between [2, N]
    cout << endl << "All prime numbers upto " << upto << " are : " << endl;
    for(i=0; i<primes.size(); i++)
    {
        cout<<primes[i]<<" ";
    }
    cout<<"\n";

    cout << "What base do you want it to be?\n";
    cin>>base2;
  
    for (int j =0; j<primes.size(); j++)
    {
        string temp = "";
        num = primes[j];
        while(num > 0)
        {
            x = num % base2;
            if(x <= 9)
            {
                temp += to_string(x);
            }
            else
            {
                temp += letterconverter(x);
            }
                
            num /= base2;
        
        }
        reverse(temp.begin(), temp.end());
        cout<<temp<<" ";
    }
}