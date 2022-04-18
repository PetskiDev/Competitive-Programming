#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> v){
    int n = v.size();
    vector<int> dp(n, 1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<i; j++){
            if(v[j] < v[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp.begin(), dp.end());
}


int32_t main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x : v) cin>> x;
    cout<<"Longest Increasing Subsequence = " << lis(v);
}
