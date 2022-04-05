#define int long long


#include<bits/stdc++.h>
using namespace std;


int modul = 1e9;

struct Matrix
{
    vector<vector<int>> m;
    int n;
    Matrix(int n)
    {
        m.resize(n,vector<int>(n));
        this->n = n;
    }
    void setIdentity()
    {
        for(int i = 0; i < n; i++)
        {
            m[i][i] = 1;
        }
    }

    void  print()
    {
        cout<<endl;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                cout<<m[i][j] << " ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    Matrix operator* (Matrix x)
    {
        Matrix res(n);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                for(int k = 0; k<n; k++)
                {
                    res.m[i][j] += (m[i][k] * x.m[k][j]) % modul;
                    res.m[i][j] %= modul;
                }
            }
        }
        return res;
    }
};





int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        vector<int> b(k);
        for(int &x : b) cin>>x;
        vector<int> c(k);
        for(int &x : c) cin>> x;

        int n;
        cin>>n;
        if(n<=k) {
            cout<< b[n-1] << endl;
            continue;
        }
        n-=k;
        Matrix T(k);
        for(int i = 0; i<k; i++){
            T.m[0][i] = c[i];
        }
        for(int i = 1; i<k; i++){
            T.m[i][i-1] = 1;
        }

        Matrix res(k);
        res.setIdentity();


        while(n){

            if(n&1) res = res*T;
            T = T*T;
            n>>=1;

        }
        int total = 0;
        for(int i = 0; i<k; i++){
            total+= b[k-i-1] * res.m[0][i];
            total%= 1000000000;
        }
        cout<<total<<endl;

    }

}
