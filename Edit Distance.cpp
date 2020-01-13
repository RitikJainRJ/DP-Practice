#include<bits/stdc++.h>
using namespace std;

void editDistance(string, string, int, int);

int main(){
    int t, p, q;
    string s1, s2;

    cin >> t;
    while(t--){
        cin >> p >> q >> s1 >> s2;
        editDistance(s1, s2, p, q);
        cout << endl;
    }
    return 0;
}

void editDistance(string s1, string s2, int l1, int l2){
    int arr[l1 + 1][l2 + 1];

    for(int i = 0; i <= l1; i++)
        arr[i][0] = i;
    for(int i = 0; i <= l2; i++)
        arr[0][i] = i;
    for(int i = 1; i <= l1; i++)
        for(int j = 1; j <= l2; j++){
            if(s1[i - 1] == s2[j - 1])
                arr[i][j] = arr[i - 1][j - 1];
            else{
                int min = INT_MAX;
                if(min > arr[i][j - 1])
                    min = arr[i][j - 1];
                if(min > arr[i - 1][j])
                    min = arr[i - 1][j];
                if(min > arr[i - 1][j - 1])
                    min = arr[i - 1][j - 1];
                arr[i][j] = 1 + min;
            }
        }
    cout << arr[l1][l2];
}
