#include <iostream>

using namespace std;



int main() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < (1 << n); i++) {
        string res = "";
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) res.push_back(s[j]);
        }
        cout << res << endl;
    }
}
