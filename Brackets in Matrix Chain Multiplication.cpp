#include<bits/stdc++.h>
using namespace std;

void matrixChain(int);
void printSolution(int**, int, int, int, char&);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        matrixChain(n);
        cout << endl;
    }
    return 0;
}

void matrixChain(int n){
    int p[n], arr[n][n];
    int **split = new int*[n];
    char name = 'A';

    for(int i = 0; i < n; i++)
        split[i] = new int[n];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 1; i < n; i++)
        arr[i][i] = 0;
    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            int min = INT_MAX, s;
            for(int k = i; k < j; k++){
                int temp = arr[i][k] + arr[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(min > temp){
                    min = temp;
                    s = k;
                }
            }
            arr[i][j] = min;
            split[i][j] = s;
        }
    }
    printSolution(split, 1, n - 1, n, name);
}

void printSolution(int **split, int s, int e, int n, char &name){
    if(s == e){
        cout << name;
        name++;
        return;
    }
    cout << "(";
    int temp = split[s][e];
    printSolution(split, s, temp, n, name);
    printSolution(split, temp + 1, e, n, name);
    cout << ")";
}
