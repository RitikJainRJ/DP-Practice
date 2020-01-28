#include<bits/stdc++.h>
using namespace std;

int waySum(int, int, int);

int main(){
	int t, m, n, x;

	cin >> t;
	while(t--){
        cin >> m >> n >> x;
        cout << waySum(m, n, x) << endl;
	}
	return 0;
}

int waySum(int m, int n, int x){
    int arr[n + 1][x + 1];

    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= x && i <= m; i++)
        arr[1][i] = 1;
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= x; j++){
            for(int k = 1; k <= m && k < j; k++)
                arr[i][j] += arr[i - 1][j - k];
        }
    return arr[n][x];
}
