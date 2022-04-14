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



string add(string a, string b){
    string res = "";
    if(a.length() > b.length()) swap(a,b);
    reverse(all(a));
    reverse(all(b));
    int carry = 0;
    for(int i = 0; i< b.size(); i++){
        int currRes = 0;
        if(i<a.size()){
            currRes += a[i] - '0';
        }
        currRes += b[i] - '0';
        currRes += carry;
        carry = currRes/10;
        res.push_back(currRes%10 + '0');
    }
    if(carry != 0){
        res.push_back(carry + '0');
    }
    reverse(all(res));
    return res;
}

string multiply(string a, string b){
    string res = "";
    if(a.length() > b.length()) swap(a,b);
    reverse(all(a));
    reverse(all(b));
    string totalSum = "0";
    for(int i = 0; i<a.size(); i++){
        string zeros(i, '0');
        string res = "";
        int x = a[i] - '0';
        int carry = 0;
        for(int j = 0; j<b.size(); j++){
            int y = b[j] - '0';
            int currRes = x * y + carry;
            res.push_back(currRes%10 + '0');
            carry = currRes/10;
        }
        while(carry){
            res.push_back(carry%10 + '0');
            carry/=10;
        }
        reverse(all(res));
        res+=zeros;
        totalSum = add(totalSum, res);
    }
    return totalSum;
}

string solve(string nums){
    string num1 = "";
    string num2 = "";
    int n = nums.size();
    int i = 0;
    for(; i < n-1; i+=2){
        char a = nums[i];
        char b = nums[i+1];
        if(a == b){
            num1.push_back(nums[i]);
            num2.push_back(nums[i+1]);
        }
        else{
            num1.push_back(a);
            num2.push_back(b);
            string tempRes1 = multiply(num1,num2);
            num1.pop_back();
            num2.pop_back();
            num1.push_back(b);
            num2.push_back(a);
            string tempRes2 = multiply(num1,num2);
            if(tempRes2 < tempRes1){
                num1.pop_back();
                num2.pop_back();
                num1.push_back(a);
                num2.push_back(b);
            }
        }
    }
    if(i == n-1){
        char a = nums[i];
        num1.push_back(a);
        string tempRes1 = multiply(num1,num2);
        num1.pop_back();
        num2.push_back(a);
        string tempRes2 = multiply(num1,num2);
        if(tempRes2 < tempRes1){
            num2.pop_back();
            num1.push_back(a);
        }
    }
    return multiply(num1,num2);
}

int32_t main()
{
    string nums;
    for(int i = 1; i<=9; i++){
        int x;
        cin>>x;
        string curr(x, i+'0');
        nums+=curr;
    }
    reverse(all(nums));

    cout<<solve(nums)<<endl;
}


//https://mendo.mk/Task.do?id=153
