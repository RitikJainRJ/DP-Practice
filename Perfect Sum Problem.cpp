#include<bits/stdc++.h>
using namespace std;

int perfectSum(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << perfectSum(n) << endl;
    }
    return 0;
}

int perfectSum(int n){
    int arr[n], sum;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> sum;
    int load[n + 1][sum + 1];
    for(int i = 0; i <= n; i++)
        load[i][0] = 1;
    for(int i = 1; i <= sum; i++)
        load[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(j >= arr[i - 1])
                load[i][j] = load[i - 1][j] + load[i - 1][j - arr[i - 1]];
            else
                load[i][j] = load[i - 1][j];
        }
    }
    return load[n][sum];
}
