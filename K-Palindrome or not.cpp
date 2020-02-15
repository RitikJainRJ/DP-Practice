#include<bits/stdc++.h>
using namespace std;

bool isKpalin(string, int, int);

int main(){
    int t, n, k;
    string str;

    cin >> t;
    while(t--){
        cin >> n >> k >> str;
        cout << isKpalin(str, n, k) << endl;
    }
    return 0;
}

bool isKpalin(string str, int n, int k){
    int arr[n][n];

    for(int i = 0; i < n; i++)
        arr[i][i] = 0;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            if(l == 2)
                arr[i][j] = (str[i] == str[j]) ? 0 : 1;
            else{
                if(str[i] == str[j])
                    arr[i][j] = arr[i + 1][j - 1];
                else
                    arr[i][j] = 1 + min(arr[i][j - 1], arr[i + 1][j]);
            }
        }
    }
    if(arr[0][n - 1] <= k)
        return true;
    else
        return false;
}
