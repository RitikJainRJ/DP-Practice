#include<bits/stdc++.h>
using namespace std;

int maxSum(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << maxSum(n) << endl;
    }
	return 0;
}

int maxSum(int n){
    int arr[n + 1];

    arr[0] = 0;
    for(int i = 1; i <= n; i++){
        int a = (i / 2) >= 0 ? arr[i / 2] : 0;
        int b = (i / 3) >= 0 ? arr[i / 3] : 0;
        int c = (i / 4) >= 0 ? arr[i / 4] : 0;
        arr[i] = max(i, a + b + c);
    }
    return arr[n];
}
