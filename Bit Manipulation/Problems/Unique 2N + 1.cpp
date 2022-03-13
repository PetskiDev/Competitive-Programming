#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int allXor = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        allXor ^= x;
    }
    cout << allXor << endl;
}
