#include<bits/stdc++.h>
using namespace std;

int maxMoney(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << maxMoney(n) << endl;
    }
    return 0;
}

int maxMoney(int n){
    int arr[n], load[n];

    memset(load, 0, sizeof(load));
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    load[0] = arr[0];
    load[1] = max(arr[0], arr[1]);
    for(int i =2; i < n; i++)
        load[i] = max(arr[i] + load[i - 2], load[i - 1]);
    return load[n - 1];
}
