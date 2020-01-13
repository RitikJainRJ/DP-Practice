#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> um;

int findUgly(int);
int isUgly(int);
int maxDivide(int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << findUgly(n) << endl;
    }
    return 0;
}

int findUgly(int n){
    int i = 1;
    int count = 1;

    while (n > count){
        i++;
        if (isUgly(i))
            count++;
    }
    return i;
}

int maxDivide(int a, int b)
{
    while (a%b == 0)
        a = a/b;
    return a;
}

int isUgly(int no){
    if(um.find(no) != um.end())
        return um[no];
    int temp = no;
    temp = maxDivide(temp, 2);
    temp = maxDivide(temp, 3);
    temp = maxDivide(temp, 5);
    if(temp == 1){
        um[no] = 1;
        return 1;
    }
    else{
        um[no] = 0;
        return 0;
    }
}
