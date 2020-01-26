#include<bits/stdc++.h>
using namespace std;

string isPartition(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << isPartition(n) << endl;
    }
    return 0;
}

string isPartition(int n){
    int arr[n], sum = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum % 2 != 0)
        return "NO";
    sum /= 2;
    bool load[n + 1][sum + 1];
    for(int i = 0; i <= n; i++)
        load[i][0] = true;
    for(int i = 1; i <= sum; i++)
        load[0][i] = false;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= sum; j++){
            load[i][j] = load[i - 1][j];
            if(j - arr[i - 1] >= 0)
                load[i][j] = load[i][j] || load[i - 1][j - arr[i - 1]];
        }
    if(load[n][sum] == true)
        return "YES";
    else
        return "NO";
}
