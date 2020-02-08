#include<bits/stdc++.h>
using namespace std;

int max_Books(int[], int, int);

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        int arr[n];

        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << max_Books(arr, n, k) << endl;
    }
    return 0;
}

int max_Books(int a[], int n, int k){
    int max_value = INT_MIN, max_here=0;

    for(int i = 0; i < n; i++){
        if(a[i] > k){
            a[i] = INT_MIN;
        }
    }
    for(int i = 0; i < n; i++){
        max_here += a[i];
        if(max_value < max_here){
            max_value = max_here;
        }
        if(max_here < 0){
            max_here = 0;
        }
    }
    return max_value;
}
