
#include <iostream>
#include<nmmintrin.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	auto totalC1 = 0;
	auto totalC2 = 0;
	for (int i = 0; i < 10000000; i++) {
		auto c = clock();
		_mm_popcnt_u32(n);
		auto c2 = clock();
		totalC1 += c2 - c;
		
		int temp = n;
		int cnt = 0;
		auto c3 = clock();
		while (temp) {
			cnt++;
			temp &= (temp - 1);
		}
		auto c4 = clock();
		totalC2 += c4 - c3;
	}
	cout << endl;
	cout << "Builtin fucntion time: " << totalC1 << endl;
	cout << "User Built funciton: " << totalC2 << endl;
}
