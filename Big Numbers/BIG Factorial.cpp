

#include <iostream>
#include <bits/stdc++.h>

string bigMult(string n1, int a){
    string res = "";
    reverse(n1.begin(), n1.end());
    int carry = 0;
    for(char c : n1){
        int cNum = c - '0';
        int currRes = cNum*a + carry;
        res.push_back((currRes%10) + '0');
        carry = currRes/10;
    }
    if(carry){
        string carryRes = to_string(carry);
        reverse(carryRes.begin(), carryRes.end());
        res += carryRes;
    }
    reverse(res.begin(), res.end());
    return res;

}

string bigFact(int n){
    string currRes = "1";
    for(int i = 2; i<=n; i++){
        currRes = bigMult(currRes, i);
    }

    return currRes;
}


int32_t main()
{
    cout<<bigFact(7000);
}
