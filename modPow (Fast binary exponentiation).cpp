#include <iostream>
#include <bits/stdc++.h>

int binaryPow(int a, int b){
    int res = 1;
    while(b>0){
        if(b&1){
            res*=a;
        }
        b>>=1;
        a*=a;
    }
    return res;
}
int binaryPow(int a, int b, int m){
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res % m;
}


int32_t main()
{
     cout<<binaryPow(123,44223, 1e9+7);
}
