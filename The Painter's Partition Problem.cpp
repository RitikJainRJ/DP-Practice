#include<bits/stdc++.h>
using namespace std;

int paintersTime(int, int);
int sum(int[], int, int);

int main(){
    int t, k, n;

    cin >> t;
    while(t--){
        cin >> k >> n;
        cout << paintersTime(k, n) << endl;
    }
    return 0;
}

int sum(int arr[], int a, int b){
    int res = 0;
    for(int i = a; i <= b; i++)
        res += arr[i];
    return res;
}

int paintersTime(int k, int n){
    if(k >= n)
        k = n;
    int arr[n], load[k + 1][n + 1];

    memset(load, 0, sizeof(load));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i <= n; i++)
        load[1][i] = arr[i - 1] + load[1][i - 1];
    for(int i = 1; i <= k; i++)
        load[i][1] = arr[0];
    for(int i = 2; i <= k; i++){
        for(int j = 2; j <= n; j++){
            load[i][j] = INT_MAX;
            for(int m = 1; m <= j; m++){
                int temp = max(load[i - 1][m], sum(arr, m, j - 1));
                if(temp < load[i][j])
                    load[i][j] = temp;
            }
        }
    }
    return load[k][n];
}
