#include<bits/stdc++.h>
using namespace std;

int largestSquare(int, int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << largestSquare(n, m) << endl;
    }
    return 0;
}

int largestSquare(int n, int m){
    int arr[n][m], max = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        if(arr[i][0] == 1)
            max = 1;
    for(int i = 0; i < m; i++)
        if(arr[0][i] == 1)
            max = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(arr[i][j] != 0 && arr[i - 1][j - 1] != 0 && arr[i - 1][j] != 0 && arr[i][j - 1] != 0)
                arr[i][j] = 1 + min({arr[i - 1][j - 1], arr[i - 1][j], arr[i][j - 1]});
            if(max < arr[i][j])
                max = arr[i][j];
        }
    }
    return max;
}
