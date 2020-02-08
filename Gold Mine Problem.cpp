#include<bits/stdc++.h>
using namespace std;

int maxGold(int, int);

int main(){
	int t, n, m;

	cin >> t;
	while(t--){
        cin >> n >> m;
        cout << maxGold(n, m) << endl;
	}
	return 0;
}

int maxGold(int n, int m){
    int arr[n][m], ma = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int c = 1; c < m; c++){
        for(int r = 0; r < n; r++){
            int a = (r - 1 < 0) ? 0 : arr[r - 1][c - 1];
            int b = arr[r][c - 1];
            int d = (r + 1 >= n) ? 0 : arr[r + 1][c - 1];
            arr[r][c] += max({a, b, d});
        }
    }
    for(int i = 0; i < n; i++)
        if(ma < arr[i][m - 1])
            ma = arr[i][m - 1];
    return ma;
}
