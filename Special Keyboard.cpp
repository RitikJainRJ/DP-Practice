#include<bits/stdc++.h>
using namespace std;

int specialKeyboard(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << specialKeyboard(n) << endl;
    }
    return 0;
}

int specialKeyboard(int n){
    int arr[n + 1];

    if(n <= 6)
        return n;
    for(int i = 0; i <= 6; i++)
        arr[i] = i;
    for(int i = 7; i <= n; i++){
        arr[i] = i;
        for(int j = i - 3, k = 2; j >= 0; j--, k++){
            arr[i] = max(arr[i], k * arr[j]);
        }
    }
    return arr[n];
}
