#include<bits/stdc++.h>
#define NE -1
using namespace std;

void wordWrap(int);
int printSol(int[], int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        wordWrap(n);
        cout << endl;
    }
    return 0;
}

void wordWrap(int n){
    int arr[n], extra[n + 1][n + 1], lc[n + 1][n + 1], w;
    int c[n + 1], p[n + 1];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> w;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(i == j)
                extra[i][j] = w - arr[i - 1];
            else if(i < j)
                extra[i][j] = (extra[i][j - 1] - 1) - arr[j - 1];
            else
                extra[i][j] = -1;
        }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            if(extra[i][j] < 0)
                lc[i][j] = NE;
            else if(extra[i][j] >= 0 && j == n)
                lc[i][j] = 0;
            else
                lc[i][j] = extra[i][j] * extra[i][j];
        }
    c[0] = 0;
    for(int j = 1; j <= n; j++){
        int min = INT_MAX;
        int mi;
        for(int i = 1; i <= j; i++){
            if(lc[i][j] == NE)
                continue;
            int temp = c[i - 1] + lc[i][j];
            if(temp < min){
                min = temp;
                mi = i;
            }
        }
        c[j] = min;
        p[j] = mi;
    }
    printSol(p, n);
}

int printSol(int p[], int n){
    int k;
    if(p[n] == 1)
        k = 1;
    else
        k = printSol(p, p[n] - 1) + 1;
    cout << p[n] << " " << n << " ";
    return k;
}
