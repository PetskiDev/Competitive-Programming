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


int v[4][5];
int n,m;

bool possible(int i, int j, int turn, vector<vector<bool>> vis, int left){
    if(left == 0) return true;
    if(turn%2 == 0){
        for(int newI = 0; newI < n; newI++){
            if(newI != i && v[newI][j] == 1 && !vis[newI][j]){
                vis[newI][j] = true;
                if(possible(newI, j, turn+1, vis, left-1)){
                    return true;
                }
                vis[newI][j] = false;
            }
        }
    }
    else{
        for(int newJ = 0; newJ < m; newJ++){
            if(newJ != j && v[i][newJ] == 1 && !vis[i][newJ]){
                vis[i][newJ] = true;
                if(possible(i, newJ, turn+1, vis, left-1)){
                    return true;
                }
                vis[i][newJ] = false;
            }
        }
    }
    return false;
}

int32_t main()
{
    cin>>n>>m;
    int cnt = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>v[i][j];
            if(v[i][j] == 1) cnt++;
        }
    }
    bool isPossible = false;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(v[i][j] == 1){
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                vis[i][j] = true;
                if(possible(i,j,1,vis, cnt -1 )){
                    isPossible = true;
                    break;
                }
            }
        }
    }
    if(isPossible) cout<<"DA"<<endl;
    else cout<<"NE"<<endl;



}

//https://mendo.mk/Task.do?id=786
