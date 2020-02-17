#include<bits/stdc++.h>
using namespace std;

int maxProfit(int, int);

int main(){
    int t, k, n;

    cin >> t;
    while(t--){
        cin >> k >> n;
        cout << maxProfit(n, k) << endl;
    }
    return 0;
}

int maxProfit(int n, int k){
    int arr[n], load[k + 1][n + 1];

    memset(load, 0, sizeof(load));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i <= k; i++){
        for(int j = 2; j <= n; j++){
            int temp = INT_MIN;
            for(int m = 1; m < j; m++)
                temp = max(temp, arr[j - 1] - arr[m - 1] + load[i - 1][m - 1]);
            load[i][j] = max(load[i][j - 1], temp);
        }
    }
    return load[k][n];
}
