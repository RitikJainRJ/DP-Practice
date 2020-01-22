#include<bits/stdc++.h>
using namespace std;

int palinPart(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << palinPart(str) << endl;
    }
    return 0;
}

int palinPart(string str){
    int n = str.length();
    int arr[n];
    bool isPal[n][n];

    for(int i = 0; i < n; i++)
        isPal[i][i] = true;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            if(l == 2)
                isPal[i][j] = (str[i] == str[j]);
            else
                isPal[i][j] = (str[i] == str[j]) && isPal[i + 1][j - 1];
        }
    }
    for(int i = 0; i < n; i++){
        if(isPal[0][i] == true)
            arr[i] = 0;
        else{
            arr[i] = INT_MAX;
            for(int j = 0; j < i; j++){
                if(isPal[j + 1][i] == true && 1 + arr[j] < arr[i])
                    arr[i] = 1 + arr[j];
            }
        }
    }
    return arr[n - 1];
}
