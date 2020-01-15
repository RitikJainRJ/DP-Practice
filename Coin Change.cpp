/*
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each
of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. For example, for N = 4 and S
= {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and
S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
So the output should be 5.
*/
#include<bits/stdc++.h>
using namespace std;

int coinChange(int);

int main(){
    int t, m;

    cin >> t;
    while(t--){
        cin >> m;
        cout << coinChange(m) << endl;
    }
    return 0;
}

int coinChange(int m){
    int arr[m], n;

    for(int i = 0; i < m; i++)
        cin >> arr[i];
    cin >> n;
    int sol[m + 1][n + 1];
    for(int i = 0; i <= m; i++)
        sol[i][0] = 1;
    for(int i = 1; i <= n; i++)
        sol[0][i] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            if(arr[i - 1] > j)
                sol[i][j] = sol[i - 1][j];
            else
                sol[i][j] = sol[i - 1][j] + sol[i][j - arr[i - 1]];
        }
    return sol[m][n];
}
