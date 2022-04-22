#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string>
#include <numeric>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define NITRO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//#define mod 1000000007
#define ll long long
#define workWithFiles freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
const long double pi = 3.14159265359;
#define debug1(a) cout<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<", "<<#e<<" = "<<(e)<<endl;
#include <nmmintrin.h>



#include <iostream>
#include <bits/stdc++.h>

#define int long long

using namespace std;

int getDiff(string s1, string s2){
    bitset<63> b1(s1);
    bitset<63> b2(s2);
    return b1.to_ullong() - b2.to_ullong();
}

int32_t main() {
    int s, n;
    cin>>s>>n;
    int len1 = floor(log2(s)) + 1;
    int len2 = floor(log2(n)) + 1;
    if(len1 == len2)
    {
        cout<< ceil((n-s) / 2.0);
        return 0;
    }
    bitset<63> b1(s);
    bitset<63> b2(n);

    string s1 = b1.to_string();
    string s2 = b2.to_string();
    s1 = s1.substr(s1.size() - len1, len1);
    s2 = s2.substr(s2.size() - len2, len1);

    int minRes = ceil((n-s)/2.0);

    if(getDiff(s2,s1) >= 0){
        int x = getDiff(s2,s1);
        int currRes = ceil(x/2.0);
        if(x == 0){
            currRes = 0;
        }
        int oneCnt = count(all(s2),'1');
        currRes+= (b2.count() - oneCnt);
        currRes += len2 - s2.size();
        minRes =  min(minRes, currRes);
    }
    s2 = b2.to_string();
    s2 = s2.substr(s2.size() - len2, len1 + 1);
    int x = getDiff(s2,s1);
    int currRes = ceil(x/2.0);
    int oneCnt = count(all(s2),'1');
    currRes += (b2.count() - oneCnt);
    currRes+= len2 - s2.size();
    minRes =  min(minRes, currRes);

    cout<<minRes<<endl;



}

//https://mendo.mk/User_Submission.do?id=420018
