
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> dist;

vector<vector<int>> dp;
int minCostCycle(int currCity, int visitedBitmask, int totalDist){
    if(visitedBitmask == (1<<n)-1){
        return totalDist + dist[currCity][0];
    }
    if(dp[currCity][visitedBitmask] != -1) return dp[currCity][visitedBitmask];
    int ans = INT_MAX;
    for(int i = 0; i<n; i++){
        int mask = (1<<i);
        if((mask&visitedBitmask) == 0){
            ans = min(ans, minCostCycle(i, visitedBitmask|mask, totalDist+dist[currCity][i]));
        }
    }
    dp[currCity][visitedBitmask] =  ans;
    return ans;
}

int main() {
    cin>>n;
    dist.resize(n, vector<int>(n));
    dp.resize(n, vector<int>((1<<n),-1));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>dist[i][j];
        }
    }
    cout<<minCostCycle(0, 1, 0);
}
