/*
1
4
6 2
4 3
2 6
1 5
*/
#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int countBridge(int);
bool myComp(pii, pii);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << countBridge(n) << endl;
    }
    return 0;
}

bool myComp(pii a, pii b){
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int countBridge(int n){
    pii arr[n];
    int load[n];

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
        load[i] = 1;
    }
    sort(arr, arr + n, myComp);
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++){
            bool a = arr[i].first < arr[j].first;
            bool b = arr[i].second < arr[j].second;
            if(((a && b) || (!a && !b)) && load[j] + 1 > load[i])
                load[i] = load[j] + 1;
        }
    return *max_element(load, load + n);
}
