#include<bits/stdc++.h>
using namespace std;

int optimalBST(int);
int sum(int[], int, int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << optimalBST(n) << endl;
    }
    return 0;
}

int optimalBST(int n){
    int arr[n], freq[n], load[n + 1][n + 1];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        cin >> freq[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            load[i][j] = 0;
    for(int i = 1; i <= n; i++)
        load[i][i] = freq[i - 1];
    for(int l = 2; l <= n; l++){
        for(int i = 1; i <= n - l + 1; i++){
            int j = i + l - 1;
            int min = INT_MAX, temp;
            for(int r = i; r <= j; r++){
                int a = r - 1 >= 0 ? load[i][r - 1] : 0;
                int b = r + 1 <= n ? load[r + 1][j] : 0;
                temp = a + b;
                if(min > temp)
                    min = temp;
            }
            load[i][j] = sum(freq, i - 1, j - 1) + min;
        }
    }
    return load[1][n];
}

int sum(int arr[], int i, int j){
    int sum = 0;
    for(int k = i; k <= j; k++)
        sum += arr[k];
    return sum;
}
