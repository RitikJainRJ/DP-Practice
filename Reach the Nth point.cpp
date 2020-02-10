#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
	ll t, n;

	cin >> t;
	while(t--){
        cin >> n;
        ll arr[n + 1];
        arr[0] = 1;
        arr[1] = 1;
        for(ll i = 2; i <= n; i++)
            arr[i] = arr[i - 1] + arr[i - 2];
        cout << arr[n] << endl;
	}
	return 0;
}
