#include <iostream>
using namespace std;


bool isOdd(int n){
    //exploiting the property of binary numbers
    //every binary number if in the last posisiton is 1 it is odd
    //1&n gives us the last position
    return (1&n);
}

int getIthBit(int n, int i){
    int mask = (1<<i);
    return (n&mask)>0? 1 : 0;
}

void clearIthBit(int &n, int i){
    int mask =  (~(1<<i)); // all ones except 0 in the ith position
    n = (mask & n);
}

void setIthBit(int &n, int i){
    int mask = (1<<i);
    n = (mask | n);
}

void updateIthBit(int &n, int i, int val){
    clearIthBit(n,i);
    int mask = (i<<val); //if val == 0 mask = 0
    n = (mask | n);
}

void clearLastIBits(int &n, int i){
    int mask = ((~0)<<i);
    //WE CAN ALSO DO (-1<<I) BECAUSE OF SIGNED INT
    // -1 IS ALL ONES
    n = (mask & n);


    //alternate approach is
    //mask = ~((1<<(i+1))-1) 1111100000
}

void clearRange(int &n, int i, int j){
    int maskA = (~0)<<(j+1);
    int maskB = (1<<(i-1)) - 1;
    int mask = (maskA | maskB);
    n = (n & mask);
}

bool isPowerOf2(int n){
    return !((n)&(n-1));

    //power of 2 is any number 1...00000
    // power of 2 minus 1 is 000111111
    // n& n-1 always gives 0 if it is power of 2

    //THIS TRICK IS ALSO USED IN countBitsTrick();
}
bool isPowerOfFour(int n) {
    if(n<=0) return false;
    return (((n & (n-1)) == 0) && ((n & 0x55555555)));
}


int countBits(int n){
    int cnt = 0;
    while(n){
        cnt+=(1&n);
        n = (n>>1);
    }
    return cnt;
}

int countBitsTrick(int n){
    int cnt = 0;
    while(n){
        cnt++;
        n = n & (n-1);
    }
    return cnt;
}

string convertToBinary(int n){
    string res;
    while(n){
        if(n&1) res.push_back('1');
        else res.push_back('0');
        n = n >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n = 9; //1001
    int m = 5; //101
    cout << n << "&" << m << " = " << (n&m) << endl; //0001 = 1  AND  (1 if both bits are 1)
    cout << n << "|" << m << " = " << (n|m) << endl; //1101 = 13  OR   (1 if eather bits are 1)
    cout << n << "^" << m << " = " << (n^m) << endl; //1001 = 12  XOR   (1 if the bits are different)
    cout << "~n = " << ~n << endl; //flips all bits (~0 = -1 because of 2s compliment)
    cout << "(n<<2) = " << (n<<2) <<endl; // left shift(1001<<2) = (100100) (all bits to the left by x)
    //BITSHIFT TO THE LEFT IS N*(2^x)
    cout << "(n>>2) = " << (n>>2) <<endl; // left shift(1001>>2) = (000010) (all bits to the right by x)
    //BITSHIFT TO THE RIGHT IS N/(2^x)

    cout << n << (isOdd(n)? " is odd" : " is even") << endl;  //example of bit manipulation usage

    cout << getIthBit(n, 2) << endl; //get the I-th bit from right to left

    clearIthBit(n, 0);
    cout << n << endl; // clearing the last bit results in 9-1 = 8

    setIthBit(n,1);
    cout << n << endl; // setting the second bit results in 1010 = 10

    n = 126; //111111
    clearLastIBits(n,2); //111100
    cout << n << endl;

    clearRange(n, 4,6);
    cout << n << endl;    //000100  = 12   CLEARED FORM 4 TO 6

    n = 32;
    cout << n << (isPowerOf2(n)? " is power of 2" : " is not power of 2") << endl;

    cout << n << (isPowerOfFour(n)? " is power of 4" : " is not power of 4") << endl;

    cout << n << " has " << countBitsTrick(n) << " bits." << endl;
    // N & (N-1) ALWAYS REMOVES THE LAST SET BIT

    cout<< n << " to binary is " << convertToBinary(n) << endl;

}
