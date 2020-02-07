#include<bits/stdc++.h>
using namespace std;

void minCoins(int);

int main() {
    int t, n;

    cin >> t;
    while(t--) {
        cin >> n;
        minCoins(n);
        cout << endl;
    }
    return 0;
}

void minCoins(int n) {
    int d[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int arr[11][n + 1];
    vector<int> vec;

    for(int i = 1; i <= n; i++)
        arr[0][i] = INT_MAX;
    for(int i = 0; i <= 10; i++)
        arr[i][0] = 0;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= n; j++){
            if(j < d[i - 1]){
                arr[i][j] = arr[i - 1][j];
            }
            else if(j - d[i - 1] >= 0)
                arr[i][j] = min(arr[i - 1][j], 1 + arr[i][j - d[i - 1]]);
            else
                arr[i][j] = arr[i - 1][j];
        }
    }
    int i = 10, j = n;
    while(j > 0){
        while(arr[i][j] == arr[i - 1][j])
            i--;
        vec.push_back(d[i - 1]);
        j = j - d[i - 1];
    }
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}
