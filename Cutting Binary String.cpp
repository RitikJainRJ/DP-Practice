#include<bits/stdc++.h>
using namespace std;

int cutString(string, int, int, int);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << cutString(str, 0, 0, str.length() - 1) << endl;
    }
}

int cutString(string str, int p, int value, int n){
    if(n == -1){
        if(value % 5 == 0){
            return 0;
        }
        else
            return INT_MIN;
    }
    value += pow(2, p) * (str[n] - '0');
    if(value % 5 == 0 && value != 0){
        int a = max(cutString(str, p + 1, value, n - 1), 1 + cutString(str, 0, 0, n - 1));
        return a;
    }
    else{
        return cutString(str, p + 1, value, n - 1);
    }
}
