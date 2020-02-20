#include<bits/stdc++.h>
using namespace std;

void uniquePartitions(int);
void printResult(int, int, int**, int, vector<int>);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        uniquePartitions(n);
        cout << endl;
    }
    return 0;
}

void uniquePartitions(int n){
    vector<int> vec;
    int **arr = new int*[n + 1];
    for(int i = 0; i <= n; i++)
        arr[i] = new int[n + 1];

    for(int i = 0; i <= n; i++)
        arr[i][0] = 1;
    for(int i = 1; i <= n; i++)
        arr[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(j >= i)
                arr[i][j] = arr[i - 1][j] + arr[i][j - i];
            else
                arr[i][j] = arr[i - 1][j];
        }
    }
    printResult(n, n, arr, n, vec);
}

void printResult(int i, int j, int **arr, int n, vector<int> vec){
    if(i == 0 || j == 0){
        for(int k = 0; k < vec.size(); k++)
            cout << vec[k] << " ";
        return;
    }
    while(i - 1 >= 0 && arr[i - 1][j] == arr[i][j])
        i--;
    vector<int> vec1 = vec;
    vec1.push_back(i);
    printResult(i, j - i, arr, n, vec1);
    if(i - 1 > 0)
        printResult(i - 1, j, arr, n, vec);
}
