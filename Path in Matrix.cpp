#include<bits/stdc++.h>
using namespace std;

int maxPath(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << maxPath(n) << endl;
    }
    return 0;
}

int maxPath(int n){
    int mat[n][n], max;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];
    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++){
            max = INT_MIN;
            if(max < mat[i - 1][j])
                max = mat[i - 1][j];
            if(j + 1 < n && max < mat[i - 1][j + 1])
                max = mat[i - 1][j + 1];
            if(0 <= j - 1 && max < mat[i - 1][j - 1])
                max = mat[i - 1][j - 1];
            mat[i][j] = mat[i][j] + max;
        }
    return *max_element(&mat[n - 1][0], &mat[n - 1][n - 1] + 1);
}
