#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int maxCoins(int[], int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxCoins(arr, n) << endl;
    }
    return 0;
}

int maxCoins(int A[],int N){
    pii arr[N][N];

    for(int i = 0; i < N; i++)
        arr[i][i] = {A[i], 0};
    for(int l = 2; l <= N; l++){
        for(int i = 0; i < N - l + 1; i++){
            int j = i + l - 1;
            int a = A[i] + arr[i + 1][j].second;
            int b = A[j] + arr[i][j - 1].second;
            if(a > b)
                arr[i][j] = {a, arr[i + 1][j].first};
            else
                arr[i][j] = {b, arr[i][j - 1].first};
        }
    }
    return arr[0][N - 1].first;
}
