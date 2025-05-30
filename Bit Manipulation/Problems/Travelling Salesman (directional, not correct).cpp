
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dist;

vector<vector<int>> dp;
int minCostCycle(int currCity, int visitedBitmask, int totalDist, int starting){
    if(visitedBitmask == (1<<n)-1 && dist[currCity][starting] != -1){
        return totalDist + dist[currCity][starting];
    }
    if(dp[currCity][visitedBitmask] != INT_MIN) return dp[currCity][visitedBitmask];
    int ans = INT_MAX;
    for(int i = 0; i<n; i++){
        int mask = (1<<i);
        if(dist[currCity][i] != -1 && (mask&visitedBitmask) == 0){
            ans = min(ans, minCostCycle(i, visitedBitmask|mask, totalDist+dist[currCity][i], starting));
        }
    }
    if(ans == INT_MAX) ans = -1;
    dp[currCity][visitedBitmask] =  ans;
    return ans;
}

int main() {
    cin>>n;
    int m;
    cin>>m;
    dist.resize(n, vector<int>(n, -1));
    dp.resize(n, vector<int>((1<<n),INT_MIN));
    for(int i =0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        dist[u][v] = w;
    }
    int best = INT_MAX;
    for(int i = 0; i<n; i++){
        dp.assign(n, vector<int>((1<<n),INT_MIN));
        int currRes = minCostCycle(i, (1<<i) , 0, i);
        if(currRes != -1) best = min(currRes, best);
    }
    if(best == INT_MAX) cout<<-1<<endl;
    else cout<<best<<endl;
}
