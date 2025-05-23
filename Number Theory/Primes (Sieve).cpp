#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bitset<1000000> prime;
void SieveOfEratosthenes(int num)
{
    prime.set();
    prime[1] = 0;
    for (int i = 2; i*i <= num; i++)
    {
        if (prime[i])
        {
            for (int j = i*i; j <= num; j += i)
                prime[j] = 0;
        }
    }
}

int main()
{
    SieveOfEratosthenes(1000000);
}
