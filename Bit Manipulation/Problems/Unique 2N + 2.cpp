#include <iostream>
#include <vector>

using namespace std;


int getIthBit(int n, int i) {
    int mask = (1 << i);
    return (n & mask) > 0 ? 1 : 0;
}


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int allXor = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        allXor = allXor ^ v[i];
    }
    int temp = allXor;
    int pos = 0;
    while (temp) {
        if (temp & 1) break;
        pos++;
        temp = temp >> 1;
    }
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (getIthBit(v[i], pos)) a = a ^ v[i];
    }
    int b = allXor ^ a;
    cout << a << " " << b << endl;
}
