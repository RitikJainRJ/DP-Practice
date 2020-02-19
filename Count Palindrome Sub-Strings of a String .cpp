#include<bits/stdc++.h>
using namespace std;

int countPalin(string, int);

int main(){
    int t, n;
    string str;

    cin >> t;
    while(t--){
        cin >> n >> str;
        cout << countPalin(str, n) << endl;
    }
	return 0;
}

int countPalin(string str, int n){
    bool arr[n][n];
    int count = 0;

    for(int i = 0; i < n; i++)
        arr[i][i] = true;
    for(int l = 2; l <= n; l++){
        for(int i = 0; i < n - l + 1; i++){
            int j = i + l - 1;
            if(l == 2){
                if(str[i] == str[j]){
                    arr[i][j] = true;
                    count++;
                }
                else
                    arr[i][j] = false;
            }
            else{
                if(str[i] != str[j])
                    arr[i][j] = false;
                else{
                    if(arr[i + 1][j - 1] == true){
                        arr[i][j] = true;
                        count++;
                    }
                    else
                        arr[i][j] = false;
                }
            }
        }
    }
    return count;
}
