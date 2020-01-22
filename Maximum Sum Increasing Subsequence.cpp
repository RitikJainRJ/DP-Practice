#include<bits/stdc++.h>
using namespace std;

int msis(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << msis(n) << endl;
    }
    return 0;
}

int msis(int n){
    int arr[n], store[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        store[i] = arr[i];
    }
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && store[j] + arr[i] > store[i])
                store[i] = store[j] + arr[i];
        }
    return *max_element(store, store + n);
}
