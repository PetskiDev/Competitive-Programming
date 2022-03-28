#include<bits/stdc++.h>
using namespace std;

int fastMult(int a, int b){
    int res = 0;
    while(b){
        if(b&1)
            res = (res + a);
        a = (2 * a);
        b>>=1;
    }
    return res;
}

int fastMult(int a, int b, int m){
    int res = 0;
    while(b){
        if(b&1)
            res = (res + a) % m;
        a = (2 * a) % m;
        b>>=1;
    }
    return res;
}

int32_t main()
{
    cout<< modMult(100,23, 30);
}
