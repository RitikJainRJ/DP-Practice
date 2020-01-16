#include<bits/stdc++.h>
#define ll unsigned long long
#define MAX 1000000007
using namespace std;

ll nCr(ll, ll);
int _nCr(int, int);

int main(){
    ll t, n, r;

    cin >> t;
    while(t--){
        cin >> n >> r;
        cout << _nCr(n, r) << endl;
    }
    return 0;
}

int _nCr(int n, int r){
    if(n < r)
        return 0;
    int c[r + 1];
    memset(c, 0, sizeof(c));
    c[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = min(i, r); j > 0; j--)
            c[j] = c[j - 1] + c[j];
    return c[r];
}

ll nCr(ll n, ll r){
    ll c[n + 1][r + 1];

    if(n < r)
        return 0;

    for(ll i = 0; i <= n; i++)
        for(ll j = 0; j <= min(i, r); j++){
            if(i == j || j == 0)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MAX;
        }
    return c[n][r];
}
