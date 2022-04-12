#include<bits/stdc++.h>
using namespace std;

int findlcm(vector<int> arr)
{
    int n = arr.size();
    int ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (__gcd(arr[i], ans)));
    return ans;
}


int numDivisible(int l,int r, vector<int> arr){
    int m = arr.size();
    int ans = 0;
    for(int i = 1; i<(1<<m); i++){
        vector<int> currSubset;
        for(int j = 0; j<m; j++){
            if(i&(1<<j)) currSubset.push_back(arr[j]);
        }
        int lcm =  findlcm(currSubset);
        int divisible = (r/lcm - l/lcm);
        if(l%lcm == 0) divisible++;
        if(bitset<32>(i).count() % 2 == 1) ans+=divisible;
        else ans-=divisible;
    }
    return ans;
}
