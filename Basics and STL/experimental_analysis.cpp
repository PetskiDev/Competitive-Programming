
#include <iostream>
using namespace std;

int main() {
    auto start_time = clock();
    //the code is here
    long long x = 0;
    for (int i = 0; i < 10000000; i++) {
        x += i;
        x %= 3;
    }
    cout << x << endl;
    auto end_time = clock();

    cout << end_time - start_time << endl;
}
