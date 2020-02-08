#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll nCatalan(ll);

ll arr[101];
ll l = 1;

int main(){
	ll t, n;

	cin >> t;
	while(t--){
        cin >> n;
        cout << nCatalan(n) << endl;
	}
	return 0;
}

ll nCatalan(ll n){
    arr[0] = 1;
    arr[1] = 1;
    if(n <= l)
        return arr[n];
    for(ll i = 2; i <= n; i++){
        arr[i] = 0;
        for(ll j = 0; j < i; j++){
            arr[i] += arr[j] * arr[i - j - 1];
        }
    }
    l = n;
    return arr[n];
}
