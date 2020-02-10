#include<bits/stdc++.h>
using namespace std;

int maxSum(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << maxSum(n) << endl;
    }
    return 0;
}

int maxSum(int n){
    int arr[2][n], maxarr[n], load[n];
    int sum1, sum2;

    memset(load, 0, sizeof(load));
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        maxarr[i] = max(arr[0][i], arr[1][i]);
    load[0] = maxarr[0];
    load[1] = max(maxarr[0], maxarr[1]);
    for(int i = 2; i < n; i++){
        load[i] = max(load[i - 1], maxarr[i] + load[i - 2]);
    }
    return load[n - 1];
}
