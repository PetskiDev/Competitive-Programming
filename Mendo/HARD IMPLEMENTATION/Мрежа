#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <cstdint>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <math.h>
#include <algorithm>
#include <string>
#include <numeric>
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define NITRO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//#define mod 1000000007
#define ll long long
#define workWithFiles freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout)
const long double pi = 3.14159265359;
#define debug1(a) cout<<#a<<" = "<<(a)<<endl;
#define debug2(a,b) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<endl;
#define debug3(a,b,c) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<endl;
#define debug4(a,b,c,d) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<endl;
#define debug5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<", "<<#b<<" = "<<(b)<<", "<<#c<<" = "<<(c)<<", "<<#d<<" = "<<(d)<<", "<<#e<<" = "<<(e)<<endl;
#include <nmmintrin.h>



#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getRow(int x){
    int currRow = 1;
    int currMax = 1;
    while(currMax < x){
        currRow++;
        currMax+=currRow;
    }
    return currRow;
}

bool columnLeft(int x, int y){
    int increment = getRow(x);
    while(x<y){
        x+=increment;
        increment++;
    }
    if(x == y) return true;
    else return false;

}
bool columnRight(int x, int y){
    int increment = getRow(x) + 1;
    while(x<y){
        x+=increment;
        increment++;
    }
    if(x == y) return true;
    else return false;

}
void downRight(int &x, int len){
    int increment = getRow(x) + 1;
    for(int i = 0; i<len; i++){
        x+=increment;
        increment++;
    }
}
void downLeft(int &x, int len){
    int increment = getRow(x);
    for(int i = 0; i<len; i++){
        x+=increment;
        increment++;
    }
}
void upRight(int &x, int len){
    int increment = getRow(x) - 1;
    for(int i = 0; i<len; i++){
        x-=increment;
        increment--;
    }
}
void upLeft(int &x, int len){
    int increment = getRow(x);
    for(int i = 0; i<len; i++){
        x-=increment;
        increment--;
    }
}
void checkTriangle(vector<int> &points){
    int row1 = getRow(points[0]);
    int row2 = getRow(points[1]);
    int row3 = getRow(points[2]);
    bool isTriangle = false;
    if(row1 == row2){
        int start = points[0];
        downRight(start, points[1] - points[0]);
        if(start == points[2]) isTriangle = true; //upsideDown Triange
    }
    else if(row2 == row3){
        int x = points[1];
        upRight(x, points[2] - points[1]);
        if(x == points[0]) isTriangle = true;
    }
    if(isTriangle) cout<<"TRIAGOLNIK"<<endl;
    else cout<<"NISTO"<<endl;

}
void checkFour(vector<int> &points){
    int row1 = getRow(points[0]);
    int row2 = getRow(points[1]);
    int row3 = getRow(points[2]);
    int row4 = getRow(points[3]);
    bool ans = false;
    if(row1 == row2 && row3 == row4){
        int len = points[1] - points[0];
        vector<int> newPoints;
        int starting = points[0];
        newPoints.push_back(starting);
        starting+=len;
        newPoints.push_back(starting);
        if(columnLeft(points[0], points[2])){
            downLeft(starting, len);
        }
        else if(columnRight(points[0], points[2])) {
            downRight(starting, len);
        }
        newPoints.push_back(starting);
        starting-=len;
        newPoints.push_back(starting);
        sort(all(newPoints));
        if(equal(all(newPoints),all(points))) ans = true;
    }
    else if(row2 == row3){
        int len = points[2] - points[1];
        vector<int> newPoints;
        int starting = points[0];
        newPoints.push_back(starting);
        downLeft(starting, len);
        newPoints.push_back(starting);
        downRight(starting, len);
        newPoints.push_back(starting);
        upRight(starting, len);
        newPoints.push_back(starting);
        sort(all(newPoints));
        if(equal(all(newPoints),all(points))) ans = true;
    }
    if(ans) cout<<"PARALELOGRAM"<<endl;
    else cout<<"NISTO"<<endl;

}

void checkSix(vector<int> &points){
    int starting = points[0];
    bool valid = false;
    if(getRow(points[0]) == getRow(points[1])){
        int len = points[1] - points[0];
        vector<int> newPoints;
        newPoints.push_back(starting);
        starting += len;
        newPoints.push_back(starting);
        downRight(starting, len);
        newPoints.push_back(starting);
        downLeft(starting, len);
        newPoints.push_back(starting);
        starting-=len;
        newPoints.push_back(starting);
        upLeft(starting, len);
        newPoints.push_back(starting);
        sort(all(newPoints));
        if(equal(all(newPoints), all(points))) valid = true;
    }
    if(valid) cout<<"SESTOAGOLNIK"<<endl;
    else cout<<"NISTO"<<endl;


}
int32_t main()
{
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int type;
        cin>>type;
        vector<int> points(type);
        for(int &x : points) cin>>x;
        sort(all(points));
        bool res;
        if(type == 3) checkTriangle(points);
        else if(type == 4) checkFour(points);
        else if(type == 6) checkSix(points);
        else{
            cout<<"NISTO"<<endl;
            continue;
        }
    }
}

//https://mendo.mk/Task.do?id=22
