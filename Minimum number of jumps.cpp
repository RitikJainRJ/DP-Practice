#include<bits/stdc++.h>
using namespace std;

int minJump(int);

int main(){
	int t, n;

	cin >> t;
	while(t--){
	    cin >> n;
	    cout << minJump(n) << endl;
	}
	return 0;
}

int minJump(int n){
    int arr[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(arr[0] == 0)
        return -1;
    int maxReach = arr[0], step = arr[0], jump = 1;
    for(int i = 1; i < n; i++){
        if(i == n - 1)
            return jump;
        maxReach = max(maxReach, i + arr[i]);
        step--;
        if(step == 0){
            jump++;
            if(maxReach <= i)
                return -1;
            step = maxReach - i;
        }
    }
}
