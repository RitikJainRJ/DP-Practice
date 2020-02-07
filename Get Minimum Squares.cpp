#include<bits/stdc++.h>
using namespace std;

int minSumSquare(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << minSumSquare(n) << endl;
    }
    return 0;
}

int minSumSquare(int n){
    int m = sqrt(n);
    int arr[n + 1];

    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 1)
                arr[j] = j;
            else if(j >= i * i)
                arr[j] = min(arr[j], 1 + arr[j - i * i]);
        }
    }
    return arr[n];
}
