#include<bits/stdc++.h>
using namespace std;

int zigzag(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
        cin >> n;
        cout << zigzag(n) << endl;
	}
	return 0;
}

int zigzag(int n){
    int arr[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp = 0;
            for(int k = 0; k < n; k++)
                if(j != k && temp < arr[i - 1][k])
                    temp = arr[i - 1][k];
            arr[i][j] += temp;
        }
    }
    return *max_element(&arr[n - 1][0], &arr[n - 1][n - 1] + 1);
}
