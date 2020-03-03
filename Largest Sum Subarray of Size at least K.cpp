#include<bits/stdc++.h>
using namespace std;

int largestSumAtleast(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << largestSumAtleast(n) << endl;
    }
    return 0;
}

int largestSumAtleast(int n){
    int arr[n], load[n], k, sum = 0, curr_sum;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    load[0] = arr[0];
    curr_sum = arr[0];
    for(int i = 1; i < n; i++){
        curr_sum = max(arr[i], curr_sum + arr[i]);
        load[i] = curr_sum;
    }
    for(int i = 0; i < k; i++)
        sum += arr[i];
    int result = sum;
    for(int i = k; i < n; i++){
        sum = sum + arr[i] - arr[i - k];
        result = max(result, sum);
        result = max(result, sum + load[i - k]);
    }
    return result;
}
