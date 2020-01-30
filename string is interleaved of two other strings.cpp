#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string, string, string);

int main(){
    int t;
    string A, B, C;

    cin >> t;
    while(t--){
        cin >> A >> B >> C;
        cout << isInterleave(A, B, C) << endl;
    }
    return 0;
}

bool isInterleave(string A, string B, string C){
    int l1 = A.length(), l2 = B.length(), l3 = C.length();
    bool arr[l1 + 1][l2 + 1];

    memset(arr, false, sizeof(arr));
    arr[0][0] = true;
    for(int i = 1, k = 0; i <= l2; i++, k++)
        if(C[k] == B[i - 1] && arr[0][i - 1] == true)
            arr[0][i] = true;
    for(int i = 1, k = 0; i <= l1; i++, k++)
        if(C[k] == A[i - 1] && arr[i - 1][0] == true)
            arr[i][0] = true;
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(C[i + j - 1] == B[j - 1] && C[i + j - 1] == A[i - 1])
                arr[i][j] = arr[i - 1][j] || arr[i][j - 1];
            else if(C[i + j - 1] == A[i - 1])
                arr[i][j] = arr[i - 1][j];
            else if(C[i + j - 1] == B[j - 1])
                arr[i][j] = arr[i][j - 1];
        }
    }
    return arr[l1][l2];
}
