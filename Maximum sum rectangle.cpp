/*
1
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
*/
#include<bits/stdc++.h>
using namespace std;

int maxRec(int, int);
int kadanesAlgo(int[], int);

int main(){
    int t, n, m;

    cin >> t;
    while(t--){
        cin >> n >> m;
        cout << maxRec(n, m) << endl;
    }
    return 0;
}

int maxRec(int n, int m){
    int arr[n][m], load[n];
    int max_sum = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];
    for(int l = 0; l < m; l++){
        for(int i = 0; i < n; i++)
            load[i] = 0;
        for(int r = l; r < m; r++){
            for(int i = 0; i < n; i++)
                load[i] += arr[i][r];
            int temp = kadanesAlgo(load, n);
            if(temp > max_sum){
                max_sum = temp;
            }
        }
    }
    return max_sum;
}

int kadanesAlgo(int arr[], int n){
    int max_sum = INT_MIN, sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum < 0)
            sum = 0;
        if(max_sum < sum){
            max_sum = sum;
        }
    }
    return max_sum;
}
