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
#define mod 1000000007
#define ll long long
#define workWithFiles freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
const long double pi = 3.14159265359;
#define debug1(a) cout<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<", "<<#e<<" = "<<(e)<<endl;

#define int long long

using namespace std;

//bool inside(int row, int col) { return (row <= x && row >= 0 && col <= y && col >= 0); }
bool compPair(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	return p1.second < p2.second;
}
uint64_t modPow(uint64_t a, uint64_t b, uint64_t m = mod) {
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


int main() {
}
