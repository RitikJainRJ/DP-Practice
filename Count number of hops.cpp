#include<bits/stdc++.h>
using namespace std;

int countHop(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << countHop(n) << endl;
    }
    return 0;
}

int countHop(int n){
    int arr[n + 1];

    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    return arr[n];
}
