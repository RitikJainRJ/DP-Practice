#include<bits/stdc++.h>
using namespace std;

int countString(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << countString(n) << endl;
    }
    return 0;
}

int _cs(int n, int countB, int countC, int arr[][2][3]){
    if(countB < 0 || countC < 0) return 0;
    if(n == 0) return 1;
    if(countB == 0 && countC == 0) return 1;

    if(arr[n][countB][countC] != -1)
        return (arr[n][countB][countC]);
    int res = _cs(n - 1, countB, countC, arr);
    res += _cs(n - 1, countB - 1, countC, arr);
    res += _cs(n - 1, countB, countC - 1, arr);
    arr[n][countB][countC] = res;
    return res;
}

int countString(int n){
    int arr[n + 1][2][3];

    memset(arr, -1, sizeof(arr));
    return _cs(n, 1, 2, arr);
}
