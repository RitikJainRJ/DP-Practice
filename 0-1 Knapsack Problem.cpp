#include<bits/stdc++.h>
using namespace std;

int wholeKnapsack(int, int);

int main(){
    int t, n, w;

    cin >> t;
    while(t--){
        cin >> n >> w;
        cout << wholeKnapsack(n, w) << endl;
    }
    return 0;
}

int wholeKnapsack(int n, int w){
    int pi[n], wi[n];
    int arr[n + 1][w + 1];

    for(int i = 0; i < n; i++)
        cin >> pi[i];
    for(int i = 0; i < n; i++)
        cin >> wi[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j<= w; j++){
            if(i == 0 || j == 0)
                arr[i][j] = 0;
            else if(wi[i - 1] > j)
                arr[i][j] = arr[i - 1][j];
            else
                arr[i][j] = max(arr[i - 1][j], pi[i - 1] + arr[i - 1][j - wi[i - 1]]);
        }
    }
    return arr[n][w];
}
