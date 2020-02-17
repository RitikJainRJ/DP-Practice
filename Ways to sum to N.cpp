#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll waysN(ll, ll);

int main(){
    ll t, m, n;

    cin >> t;
    while(t--){
        cin >> m >> n;
        cout << waysN(m, n) << endl;
    }
    return 0;
}

ll waysN(ll m, ll n){
    ll arr[n + 1], A[m];

    memset(arr, 0, sizeof(arr));
    for(ll i = 0; i < m; i++)
        cin >> A[i];
    arr[0] = 1;
    for(ll j = 1; j <= n; j++){
        for(ll i = 0; i < m; i++){
            if(j >= A[i])
                arr[j] += (arr[j - A[i]] % 1000000007);
        }
    }
    return arr[n] % 1000000007;
}
