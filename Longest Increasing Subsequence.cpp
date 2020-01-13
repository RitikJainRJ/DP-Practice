#include<bits/stdc++.h>
using namespace std;

int lis(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << lis(n) << endl;
    }
    return 0;
}

int lis(int n){
    int arr[n], look_up[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        look_up[i] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && look_up[j] + 1 > look_up[i])
                look_up[i] = look_up[j] + 1;
        }
    }
    return *max_element(look_up, look_up + n);
}
