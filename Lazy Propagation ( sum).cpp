#include <iostream>
#include <bits/stdc++.h>


using namespace std;
struct segmentTree{
    //SUMMATION TREE
    int n;
    vector<int> st;
    vector<int> lazySt;
    segmentTree(int n){
        int x = (int)(ceil(log2(n)));
        int max_size = 2*(int)pow(2, x) - 1;
        this->n = n;
        st.resize(max_size, 0);
        lazySt.resize(max_size, 0);
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
        build(0,n - 1,0, v);
    }

    int query(int startRange, int endRange, int l, int r, int currNode){
        if(endRange < l || startRange > r) return 0;  // non overlapping

        if(lazySt[currNode] != 0){
            st[currNode] += lazySt[currNode]*(endRange - startRange + 1);
            if(startRange != endRange){
                lazySt[2*currNode + 1] += lazySt[currNode];
                lazySt[2*currNode + 2] += lazySt[currNode];
            }
            lazySt[currNode] = 0;
        }

        if(startRange >= l && endRange <= r) return st[currNode];

        int mid = (startRange + endRange) / 2;

        return (query(startRange, mid, l, r, currNode*2 + 1) + query(mid+1, endRange, l, r, currNode*2 + 2));

    }

    int query(int l, int r){
        return query(0, n-1, l, r, 0);
    }


    void update(int startRange, int endRange, int currNode, int l, int r, int val){
        if(startRange > r || endRange < l){
            return;
        }
        cout<<startRange << " " << endRange<<endl;
        if(lazySt[currNode] != 0){
            st[currNode] += lazySt[currNode]*(endRange - startRange + 1);
            if(startRange != endRange){
                lazySt[2*currNode + 1] += lazySt[currNode];
                lazySt[2*currNode + 2] += lazySt[currNode];
            }
            lazySt[currNode] = 0;
        }
        if(startRange >= l && endRange <= r){
            st[currNode] += val*(endRange - startRange + 1);
            if(startRange != endRange){
                lazySt[2* currNode + 1] += val;
                lazySt[2* currNode + 2] += val;
            }
            return;
        }

        int mid = (startRange+endRange) / 2;
        update(startRange, mid, currNode * 2 + 1, l, r, val);
        update(mid + 1, endRange, currNode * 2 + 2, l, r, val);

        st[currNode] =  st[currNode*2 + 1] + st[currNode * 2 + 2];

    }
    void update(int l, int r, int val){
        update(0, n-1, 0, l, r, val);
    }
};


int main()
{
    vector<int> v{1,2,4,3,5,10,1};
    segmentTree tree(v.size());
    tree.build(v);
    cout<<tree.query(3,7) << endl;
    tree.update(4, 5,1000);
    cout<<tree.query(3,7) << endl;
    tree.update(1,5,10);
    cout<<tree.query(3,6) << endl;
}
