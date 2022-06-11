#include <iostream>
using namespace std;

struct dsuStructure {
	int n;
	vector<int> parent;
	vector<int> depth;
	dsuStructure() {
		n = 100001;
		parent.resize(n, -1);
		depth.resize(n, 1);
	}
	dsuStructure(int x) {
		n = x;
		parent.resize(n, -1);
		depth.resize(n, 1);
	}
	int numOfSets() {
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (parent[i] == -1) res++;
		}
		return res;
	}

	int findSet(int x) {
		if (parent[x] == -1) return x;
		return parent[x] = findSet(parent[x]); // PATH COMPRESSION
	}

	void unionSet(int a, int b) {
		int s1 = findSet(a);
		int s2 = findSet(b);
		if (s1 != s2) {
			if (depth[s1] > depth[s2]) { //UNION BY RANK
				swap(s1, s2);
			}
			parent[s1] = s2;
			if(depth[s1] == depth[s2]) depth[s2]++; // can be done with depth and with size
			//size[s2] += size[s1]; - if we do it by size
		}
	}

	bool sameSet(int a, int b) {
		int s1 = findSet(a);
		int s2 = findSet(b);
		return s1 == s2;
	}
};
