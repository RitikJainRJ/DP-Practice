#include<bits/stdc++.h>
using namespace std;

int maxValue(int, int);

int main(){
    int t, n, w;

    cin >> t;
    while(t--){
        cin >> n >> w;
        cout << maxValue(n, w) << endl;
    }
    return 0;
}

int maxValue(int n, int w){
    int val[n], wei[n], arr[w + 1];

    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < n; i++)
        cin >> val[i];
    for(int i = 0; i < n; i++)
        cin >> wei[i];
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= w; j++){
            if(j >= wei[i])
                arr[j] = max(arr[j], val[i] + arr[j - wei[i]]);
        }
    }
    return arr[w];
}
