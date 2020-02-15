#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll maximizeDot(ll, ll);

int main(){
    ll t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << maximizeDot(n, m) << endl;
    }
    return 0;
}

ll maximizeDot(ll m, ll n){
    ll A[m], B[n], arr[n + 1][m + 1];

    memset(arr, 0, sizeof(arr));
    for(ll i = 0; i < m; i++)
        cin >> A[i];
    for(ll i = 0; i < n; i++)
        cin >> B[i];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= m; j++){
            arr[i][j] = max(A[j - 1] * B[i - 1] + arr[i - 1][j - 1], arr[i][j - 1]);
        }
    }
    return arr[n][m];
}
