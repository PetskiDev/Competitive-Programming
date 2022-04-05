#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixMult(vector<vector<int>> v1, vector<vector<int>> v2){
    vector<vector<int>> res(2,vector<int>(2, 0));
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            for(int temp = 0; temp<2; temp++){
                res[i][j] += v1[i][temp] * v2[temp][j];
            }
        }
    }
    return res;

}

void  print(vector<vector<int>> v){
    cout<<endl;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            cout<<v[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int fib(int n){
    if(n<=2) return 1;
    int b = n-2;

    vector<vector<int>> res = {{1,0},{0,1}};
    vector<vector<int>> a  = {{1,1},{1,0}};


    while(b){
        if(b&1){
            res = matrixMult(res, a);
        }
        print(a);
        a = matrixMult(a,a);
        b>>=1;
    }
    return res[0][0] + res[0][1];





}

int32_t main()
{
    cout << fib(35);
}
