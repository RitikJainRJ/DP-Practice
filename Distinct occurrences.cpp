int subsequenceCount(string S, string T){
    int n = T.length(), m = S.length();
    int arr[n + 1][m + 1];

    for(int i = 0; i <= m; i++)
        arr[0][i] = 1;
    for(int i = 1; i <= n; i++)
        arr[i][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(T[i - 1] == S[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + arr[i][j - 1];
            else
                arr[i][j] = arr[i][j - 1];
        }
    }
    return arr[n][m];
}
