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



struct node {
    bool isWord = false;
    int activeVal = 0;
    node* next[26];
    node() {
        for (int i = 0; i < 26; i++) next[i] = NULL;
    }
};

struct trie {
    node* root = NULL;
    trie() {
        root = new node();
    }

    void insert(string s) {
        node* currPtr = root;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            int curr = s[i] - 'a';
            
            if (currPtr->next[curr] == NULL) {
                currPtr->next[curr] = new node();
            }
            currPtr = currPtr->next[curr];
        }
        currPtr->isWord = true;
    }

    bool search(string s) {
        node* currPtr = root;
        int n = s.length();
        bool isWord = true;
        for (int i = 0; i < n; i++) {
            int curr = s[i] - 'a';

            if (currPtr->next[curr] == NULL) {
                isWord = false;
                break;
            }
            currPtr = currPtr->next[curr];
        }
        return (isWord && currPtr->isWord == true);
    }
};

int32_t main()
{
    int n;
    cin >> n;
    trie tr;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        tr.insert(s);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (tr.search(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

