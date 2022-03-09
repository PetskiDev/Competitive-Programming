#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - k;
    while (left < right) {
        int mid = (left + right) / 2;
        if (abs(x - arr[mid]) > abs(arr[mid + k] - x))
            left = mid + 1;
        else
            right = mid;
    }
    return vector<int>(arr.begin() + left, arr.begin() + left + k); 
} 
