#include<bits/stdc++.h>
using namespace std;

int maxSubDiv(int, int);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cout << maxSubDiv(n, k) << endl;
    }
    return 0;
}

int maxSubDiv(int n, int k){
    int arr[n], curr_sum = 0, max = INT_MIN;
    unordered_multimap<int, int> um;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        um.insert({curr_sum % k, i});
        if(curr_sum % k == 0){
            int temp = i + 1;
            if(max < temp)
                max = temp;
        }
        auto itr = um.equal_range(curr_sum % k);
        for(auto it = itr.first; it != itr.second; it++){
            int temp = i - it->second;
            if(max < temp)
                max = temp;
        }
    }
    if(max == INT_MIN)
        return 0;
    return max;
}
