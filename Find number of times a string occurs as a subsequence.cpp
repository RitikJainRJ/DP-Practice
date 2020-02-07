#include<bits/stdc++.h>
using namespace std;

int countSubSeq(string, string, int, int);

int main(){
    int t, n, m;
    string s1, s2;

    cin >> t;
    while(t--){
        cin >> n >> m >> s1 >> s2;
        cout << countSubSeq(s1, s2, n, m) << endl;
    }
    return 0;
}

int countSubSeq(string s1, string s2, int n, int m){
    int arr[m + 1][n + 1];

    for(int i = 0; i <= n; i++)
        arr[0][i] = 1;
    for(int i = 1; i <= m; i++)
        arr[i][0] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            arr[i][j] = (s2[i - 1] == s1[j - 1]) ? arr[i - 1][j - 1] + arr[i][j - 1] : arr[i][j - 1];
    return arr[m][n];
}
