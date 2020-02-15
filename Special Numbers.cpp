#include<bits/stdc++.h>
using namespace std;

int base6(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << base6(n) << endl;
    }
    return 0;
}

int base6(int n){
    vector<int> vec;

    for(int i = 0; i < 6; i++)
        vec.push_back(i);
    for(int i = 1; i < n; i++)
        for(int j = 0; j <= 5; j++){
            if(vec[i] * 10 + vec[j] != 0)
                vec.push_back(vec[i] * 10 + vec[j]);
        }
    return vec[n - 1];
}
