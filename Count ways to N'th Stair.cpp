#include<bits/stdc++.h>
using namespace std;

int nthStairs(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << nthStairs(n) << endl;
    }
    return 0;
}

int nthStairs(int n){
    int arr[n + 1];

    memset(arr, 0, sizeof(arr));
    arr[0] = 1;
    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= n; j++)
            if(i <= j)
                arr[j] += arr[j - i];
    return arr[n];
}
