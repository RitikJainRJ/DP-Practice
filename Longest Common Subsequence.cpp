#include<bits/stdc++.h>
using namespace std;

int lcs(string, string, int, int);

int main(){
    int t, a, b;
    string s1 , s2;

    cin >> t;
    while(t--){
        cin >> a >> b;
        cin >> s1 >> s2;
        cout << lcs(s1, s2, a, b) << endl;
    }
    return 0;
}

int lcs(string s1, string s2, int l1, int l2){
    int arr[l1 + 1][l2 + 1];

    for(int i = 0; i <= l1; i++)
        arr[i][0] = 0;
    for(int i = 0; i <= l2; i++)
        arr[0][i] = 0;
    for(int i = 1; i <= l1; i++){
        for(int j = 1; j <= l2; j++){
            if(s1[i] == s2[j])
                arr[i][j] = 1 + arr[i - 1][j - 1];
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    return arr[l1][l2];
}
