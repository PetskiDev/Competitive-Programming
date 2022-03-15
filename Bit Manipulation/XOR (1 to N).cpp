
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin>>n;
    int totalXor = 0;
    for(int i = 1; i<=n; i++){
        int calculatedXor;
        int mod4 = i%4;
        if(mod4 == 0) calculatedXor = i;
        else if(mod4 == 1) calculatedXor = 1;
        else if(mod4 == 2) calculatedXor = i+1;
        else calculatedXor = 0;
        totalXor ^= i;
        cout<< i<< " " <<totalXor << " " << calculatedXor <<endl;
    }
}
