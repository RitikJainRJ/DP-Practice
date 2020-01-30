#include<bits/stdc++.h>
using namespace std;

int wordBreak(int);
int _wordBreak(unordered_set<string>, string);

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        cout << wordBreak(n) << endl;
    }
    return 0;
}

int wordBreak(int n){
    string str;
    unordered_set<string> us;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        us.insert(temp);
    }
    cin >> str;
    return _wordBreak(us, str);
}

int _wordBreak(unordered_set<string> us, string str){
    if(str.empty())
        return 1;
    for(int i = 1; i <= str.length(); i++){
        if(us.find(str.substr(0, i)) != us.end() && _wordBreak(us, str.substr(i, str.length() - i)))
            return 1;
    }
    return 0;
}
