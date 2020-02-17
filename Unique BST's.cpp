#include<bits/stdc++.h>
using namespace std;

int numTrees(int);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << numTrees(n) << endl;
    }
    return 0;
}

vector<int> vec;

int numTrees(int n){
    if(vec.empty()){
        vec.push_back(1);
        vec.push_back(1);
    }
    if(n < vec.size())
        return vec[n];
    int temp = vec.size() + 1 - n;
    while(temp--){
        int i = 0, j = vec.size() - 1, sum = 0;
        while(0 <= j && i < vec.size()){
            sum += vec[i] * vec[j];
            i++;
            j--;
        }
        vec.push_back(sum);
    }
    return vec[n];
}
