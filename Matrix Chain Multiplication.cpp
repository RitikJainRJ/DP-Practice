#include<bits/stdc++.h>
using namespace std;

int matrixChainMulti(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << matrixChainMulti(n) << endl;
    }
    return 0;
}

// for simplicity we use extra row and column

int matrixChainMulti(int n){
    int arr[n][n], p[n];

    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 1; i < n; i++)
        arr[i][i] = 0;
    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            int min = INT_MAX;
            for(int k = i; k < j; k++){
                int temp = arr[i][k] + arr[k + 1][j] + p[i - 1]*p[k]*p[j];
                if(min > temp)
                    min = temp;
            }
            arr[i][j] = min;
        }
    }
    return arr[1][n - 1];
}
