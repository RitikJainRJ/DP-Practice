/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost
of minimum cost path to reach (m, n) from (0, 0). Each cell of the matrix represents a cost to traverse
through that cell. Total cost of a path to reach (m, n) is sum of all the costs on that path (including
both source and destination). You can only traverse down, right and diagonally lower cells from a given cell,
i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed.
*/
#include<bits/stdc++.h>
using namespace std;

int minCost(int, int);
int min(int, int, int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << minCost(n, m) << endl;
    }
    return 0;
}

int minCost(int n, int m){
    int arr[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int i = 1; i < n; i++)
        arr[i][0] = arr[i][0] + arr[i - 1][0];
    for(int i = 1; i < m; i++)
        arr[0][i] = arr[0][i] + arr[0][i - 1];
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++){
            arr[i][j] = arr[i][j] + min(arr[i][j - 1], arr[i - 1][j - 1], arr[i - 1][j]);
        }
    return arr[n - 1][m - 1];
}

int min(int x, int y, int z){
    int m = INT_MAX;
    if(m > x)
        m = x;
    if(m > y)
        m = y;
    if(m > z)
        m = z;
    return m;
}
