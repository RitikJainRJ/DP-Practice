#include<bits/stdc++.h>
using namespace std;

int eggDrop(int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << eggDrop(n, k) << endl;
    }
    return 0;
}

int eggDrop(int n, int k){
    int arr[n + 1][k + 1];

    for(int i = 1; i <= n; i++){
        arr[i][0] = 0;
        arr[i][1] = 1;
    }
    for(int i = 2; i <= k; i++)
        arr[1][i] = i;
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= k; j++){
            int min = INT_MAX;
            for(int m = 1; m <= j; m++){
                int temp = 1 + max(arr[i - 1][m - 1], arr[i][j - m]);
                if(temp < min)
                    min = temp;
            }
            arr[i][j] = min;
        }
    }
    return arr[n][k];
}
