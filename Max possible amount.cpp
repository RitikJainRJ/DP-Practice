#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int maxAmount(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << maxAmount(n) << endl;
    }
    return 0;
}

int maxAmount(int n){
    int arr[n];
    pii load[n][n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        load[i][i] = {arr[i], 0};
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            int a = arr[i] + load[i + 1][j].second;
            int b = arr[j] + load[i][j - 1].second;
            if(a >= b)
                load[i][j] = {a, load[i + 1][j].first};
            else
                load[i][j] = {b, load[i][j - 1].first};
        }
    }
    return load[0][n - 1].first;
}
