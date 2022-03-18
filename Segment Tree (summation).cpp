#include <iostream>
#include <bits/stdc++.h>


using namespace std;
struct segmentTree{
    //SUMMATION TREE
    int n;
    vector<int> st;
    segmentTree(int n){
        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x) - 1;
        this->n = n;
        st.resize(max_size, 0);
    }
    void build(int startRange, int endRange, int currNode,  vector<int> const &v){
        if(startRange == endRange){
            st[currNode] = v[startRange];
            return;
        }
        int mid = (startRange + endRange) / 2;
        build(startRange, mid, currNode*2 + 1, v);
        build(mid+1, endRange, currNode*2 + 2, v);

        st[currNode] = st[currNode*2 + 1] + st[currNode*2 + 2];
    }
    void build(vector<int>const &v){
        build(0,n-1,0, v);
    }

    int query(int startRange, int endRange, int l, int r, int currNode){
        if(endRange < l || startRange > r) return 0;

        if(startRange >= l && endRange <= r) return st[currNode];

        int mid = (startRange + endRange) / 2;

        return (query(startRange, mid, l, r, currNode*2 + 1) + query(mid+1, endRange, l, r, currNode*2 + 2));

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

        st[currNode] = st[currNode* 2 + 1] + st[currNode* 2 + 2];
    }
    void update(int index, int val){
        update(0, n-1, 0, index, val);
    }
};



int main()
{
    vector<int> v{1,2,4,3,5,10,1};
    segmentTree tree(v.size());
    tree.build(v);
    cout<<tree.query(3,7) << endl;
    tree.update(4,100);
    cout<<tree.query(3,7) << endl;
    tree.update(5,2);
    cout<<tree.query(3,7) << endl;
}
