#include<bits/stdc++.h>
using namespace std;

int kadanesAlgo(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << kadanesAlgo(n) << endl;
    }
    return 0;
}

int kadanesAlgo(int n){
    int arr[n], sum = 0, max_sum = 0, flag = 0;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0)
            sum = 0;
        if(max_sum < sum){
            max_sum = sum;
            flag = 1;
        }
    }
    if(flag == 0)
        return *max_element(arr, arr + n);
    return max_sum;
}
