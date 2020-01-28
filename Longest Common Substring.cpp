#include<bits/stdc++.h>
using namespace std;

int lcs(string, string, int, int);

int main(){
    int t, n, m;
    string X, Y;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> X >> Y;
        cout << lcs(X, Y, n, m) << endl;
    }
    return 0;
}

int lcs(string X, string Y, int n, int m){
    int arr[n + 1][m + 1], result = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0)
                arr[i][j] = 0;
            else if(X[i - 1] == Y[j - 1]){
                arr[i][j] = 1 + arr[i - 1][j - 1];
                if(result < arr[i][j])
                    result = arr[i][j];
            }
            else if(X[i - 1] != Y[j - 1])
                arr[i][j] = 0;
        }
    }
    return result;
}
