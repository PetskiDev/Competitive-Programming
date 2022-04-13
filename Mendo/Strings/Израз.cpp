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

using namespace std;

vector<int> lengths(string& s){
    int currLen = 0;
    s.push_back(' ');
    int n = s.length();
    string newStr = "";
    vector<int> res;
    for(int i = 0; i<n; i++){
        if(s[i] == '?'){
            currLen++;
        }
        else {
            if(currLen != 0) res.push_back(currLen);
            currLen = 0;
        }
        if(s[i] == '?'){
            if(s[i+1] != '?') newStr.push_back('x');
        }
        else{
            newStr.push_back(s[i]);
        }
    }

    s = newStr;
    s.pop_back();

    return res;

}

void putMarks(string& s){
    int n = s.length();
    string newStr = "";
    for(int i = 0; i<n; i++){
        if(s[i] != 'x') newStr.push_back(s[i]);
        else{
            if(i == 0 || s[i-1] == '('){
                newStr.push_back('+');
            }
            newStr.push_back('x');
        }
    }
    s = newStr;
}

void switchMarks(string& s, int l, int r){
    int n = s.length();
    for(int i = l; i<r; i++){
        if(s[i] == 'x'){
            if(s[i-1] == '+') s[i-1] = '-';
            else s[i-1] = '+';
        }
    }
}

bool removeBracket(string& s){
    auto b = s.find(')');
    if(b == string::npos) return false;
    int firstPos = b;
    while (s[firstPos] != '(') firstPos--;
    int secondPos = b;
    if(s[firstPos - 1] == '-') switchMarks(s, firstPos, secondPos);
    s.erase(b,1);
    s.erase(firstPos-1,2);
    return true;
}

int32_t main()
{
    string s;
    cin>>s;
    string nums;
    cin>>nums;
    vector<int> num;
    for(int i = 0; i<nums.length(); i++){
        num.push_back(nums[i]-'0');
    }
    vector<int> xLen = lengths(s);
    putMarks(s);
    while(removeBracket(s));
    vector<int> vMinus;
    vector<int> vPlus;



    for(int i = 0; i < s.length(); i+=2){
        if(s[i] == '-') {
            int currLen =  xLen[i/2];
            for(int i = 0; i<currLen; i++){
                vMinus.push_back(pow(10,i));
            }
        }
        else {
            int currLen =  xLen[i/2];
            for(int i = 0; i<currLen; i++){
                vPlus.push_back(pow(10,i));
            }
        }
    }
    sort(rall(vMinus));
    sort(rall(vPlus));
    sort(all(num));
    int currIndex = 0;
    int totalRes = 0;
    for(int x : vMinus){
        totalRes -= (x * num[currIndex]);
        currIndex++;
    }
    currIndex = num.size()-1;
    for(int x : vPlus){
        totalRes += (x*num[currIndex]);
        currIndex--;
    }
    cout<<totalRes<<endl;

}

//https://mendo.mk/Task.do?id=153
