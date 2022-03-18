#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct segmentTree{
    int n;
    vector<int> st;
    segmentTree(int n){
        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x) - 1;
        this->n = n;
        st.resize(max_size, INT_MAX);
    }
    void build(int startRange, int endRange, int currNode,  vector<int> const &v){
        if(startRange == endRange){
            st[currNode] = v[startRange];
            return;
        }
        int mid = (startRange + endRange) / 2;
        build(startRange, mid, currNode*2 + 1, v);
        build(mid+1, endRange, currNode*2 + 2, v);

        st[currNode] = min(st[currNode*2 + 1], st[currNode*2 + 2]);
    }
    void build(vector<int>const &v){
        build(0,n-1,0, v);
    }

    int query(int startRange, int endRange, int l, int r, int currNode){
        if(endRange < l || startRange > r) return INT_MAX;

        if(startRange >= l && endRange <= r) return st[currNode];

        int mid = (startRange + endRange) / 2;

        return min(query(startRange, mid, l, r, currNode*2 + 1), query(mid+1, endRange, l, r, currNode*2 + 2));

    }

    int query(int l, int r){
        return query(0, n-1, l, r, 0);
    }


    void update(int startRange, int endRange, int currNode, int index, int val){
        if(startRange == endRange){
            st[currNode] = val;
            return;
        }
        int mid = (startRange + endRange) / 2;
        if(index <= mid){
            update(startRange, mid, currNode*2+1, index, val);
        }
        else{
            update(mid+1, endRange, currNode*2+2, index, val);
        }

        st[currNode] = min(st[currNode* 2 + 1], st[currNode* 2 + 2]);
    }
    void update(int index, int val){
        update(0, n-1, 0, index, val);
    }
};

vector<int>solve(int n, vector<int>a, vector<vector<int>> queries){
    segmentTree tree(n);
    tree.build(a);
    vector<int> res;
    for(auto x : queries){
        if(x[0] == 1){
            tree.update(x[1] - 1,x[2]);
        }
        else res.push_back(tree.query(x[1]-1, x[2]-1));
    }
    return res;
}

int main()
{
    vector<int> a {3,2,4,5,1,1,5,3};
    vector<vector<int>> query {{1, 4, 10},{2, 1,5},{1, 5,7},{2, 3,5}};
    for(int x : solve(a.size(), a, query)) cout<< x << " ";
}

