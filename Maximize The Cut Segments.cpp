#include<bits/stdc++.h>
using namespace std;

int maxSegment(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << maxSegment(n) << endl;
    }
    return 0;
}

int maxSegment(int n){
    int arr[3], table[n + 1];

    for(int i = 0; i < 3; i++)
        cin >> arr[i];
    sort(arr, arr + 3);
    table[0] = 0;
    for(int i = 1; i <= n; i++){
        int max = INT_MIN;
        int a = (i - arr[0]) >= 0 ? table[i - arr[0]] : INT_MIN;
        if(max < a)
            max = a;
        int b = (i - arr[1]) >= 0 ? table[i - arr[1]] : INT_MIN;
        if(max < b)
            max = b;
        int c = (i - arr[2]) >= 0 ? table[i - arr[2]] : INT_MIN;
        if(max < c)
            max = c;
        table[i] = 1 + max;
    }
    return table[n];
}
