#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int optimalGame(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
        cin >> n;
        cout << optimalGame(n) << endl;
	}
	return 0;
}

int optimalGame(int n){
    int arr[n];
    pii load[n][n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++)
        load[i][i] = {arr[i], 0};
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            int a, b;
            if(arr[i] + load[i + 1][j].second > arr[j] + load[i][j - 1].second){
                a = arr[i] + load[i + 1][j].second;
                b = load[i + 1][j].first;
            }
            else{
                a = arr[j] + load[i][j - 1].second;
                b = load[i][j - 1].first;
            }
            load[i][j] = {a, b};
        }
    }
    return load[0][n - 1].first;
}
