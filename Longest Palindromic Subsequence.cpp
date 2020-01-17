#include<bits/stdc++.h>
using namespace std;

int lps(string);

int main(){
    int t;
    string str;

    cin >> t;
    while(t--){
        cin >> str;
        cout << lps(str) << endl;
    }
    return 0;
}

int lps(string str){
    int n = str.length();
    int arr[n][n];

    for(int i = 0; i < n; i++)
        arr[i][i] = 1;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            if(l == 2 && str[i] == str[j])
                arr[i][j] = 2;
            else{
                if(str[i] == str[j])
                    arr[i][j] = 2 + arr[i + 1][j - 1];
                else
                    arr[i][j] = max(arr[i][j - 1], arr[i + 1][j]);
            }
        }
    }
    return arr[0][n - 1];
}
