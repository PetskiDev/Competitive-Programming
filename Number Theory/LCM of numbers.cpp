
#include <iostream>
#include <bits/stdc++.h>

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
int main() {
    vector<int> v{2,4,3,10,11};
    cout<<findlcm(v);
}
