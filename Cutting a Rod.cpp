#include<bits/stdc++.h>
using namespace std;

int maxProfit(int);
int _maxProfit(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << _maxProfit(n) << endl;
    }
    return 0;
}

int _maxProfit(int n){
    int p[n], arr[n + 1];

    for(int i = 0; i < n; i++)
        cin >> p[i];
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i <= j)
                arr[j] = max(arr[j], p[i - 1] + arr[j - i]);
        }
    }
    return arr[n];
}

int maxProfit(int n){
    int p[n], arr[n + 1][n + 1];

    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0)
                arr[i][j] = 0;
            else if(i > j)
                arr[i][j] = arr[i - 1][j];
            else
                arr[i][j] = max(arr[i - 1][j], p[i - 1] + arr[i][j - i]);
        }
    }
    return arr[n][n];
}
