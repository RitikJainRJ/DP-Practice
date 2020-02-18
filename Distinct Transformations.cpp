#include<bits/stdc++.h>
using namespace std;

int distTrans(string, string);

int main(){
    int t;
    string A, B;

    cin >> t;
    while(t--){
        cin >> A >> B;
        cout << distTrans(A, B) << endl;
    }
    return 0;
}

int distTrans(string A, string B){
    int n = A.length(), m = B.length();
    int arr[n + 1][m + 1];

    for(int i = 0; i <= n; i++)
        arr[i][0] = 1;
    for(int i = 1; i <= m; i++)
        arr[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(A[i - 1] == B[j - 1])
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            else
                arr[i][j] = arr[i - 1][j];
        }
    }
    return arr[n][m];
}
