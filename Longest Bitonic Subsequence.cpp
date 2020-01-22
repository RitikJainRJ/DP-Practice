#include<bits/stdc++.h>
using namespace std;

int lbs(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << lbs(n) << endl;
    }
    return 0;
}

int lbs(int n){
    int arr[n], load1[n], load2[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        load1[i] = 1;
        load2[i] = 1;
    }
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && load1[j] + 1 > load1[i])
                load1[i] = load1[j] + 1;
        }
    for(int i = n - 2; i >= 0; i--)
        for(int j = n - 1; j > i; j--){
            if(arr[i] > arr[j] && load2[j] + 1 > load2[i])
                load2[i] = load2[j] + 1;
        }
    for(int i = 0; i < n; i++)
        load1[i] = load1[i] + load2[i] - 1;
    return *max_element(load1, load1 + n);
}
