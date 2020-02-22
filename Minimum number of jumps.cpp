#include<bits/stdc++.h>
using namespace std;

int minSteps(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << minSteps(n) << endl;
    }
    return 0;
}

int minSteps(int n){
    int arr[n], load[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    load[0] = 0;
    for(int i = 1; i < n; i++){
        load[i] = INT_MAX;
        for(int j = 0; j < i; j++){
            if(i <= j + arr[j] && load[j] + 1 < load[i])
                load[i] = load[j] + 1;
        }
    }
    if(load[n - 1] == INT_MAX || load[n - 1] < 0)
       return -1;
    return load[n - 1];
}
