#include<bits/stdc++.h>
using namespace std;

int shortCS(string, string);

int main(){
    int t;
    string str1, str2;

    cin >> t;
    while(t--){
        cin >> str1 >> str2;
        cout << shortCS(str1, str2) << endl;
    }
    return 0;
}

int shortCS(string str1, string str2){
    int n = str1.length(), m = str2.length();
    int arr[n + 1][m + 1];

    for(int i = 0; i <= n; i++)
        arr[i][0] = i;
    for(int i = 0; i <= m; i++)
        arr[0][i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i - 1] == str2[j - 1])
                arr[i][j] = 1 + arr[i - 1][j - 1];
            else
                arr[i][j] = 1 + min(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    return arr[n][m];
}
