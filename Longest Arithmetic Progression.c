#include<bits/stdc++.h>
using namespace std;

int lap(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << lap(n) << endl;
	}
	return 0;
}

int lap(int n){
    int arr[n], m = 0;
    unordered_map<int, int> um[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            int d = arr[i] - arr[j];
            if(um[j].find(d) == um[j].end()){
                um[i][d] = max(um[i][d], 1 + um[j][d]);
            }
            else{
                um[i][d] = max(um[i][d], 1 + um[j][d]);
            }
            if(um[i][d] > m)
                m = um[i][d];
        }
    }
    return m + 1;
}
