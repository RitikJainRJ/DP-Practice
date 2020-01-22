#include<bits/stdc++.h>
#define INF 10000000
using namespace std;

void floydWarshall(int);

int main(){
    int t, v;

    cin >> t;
    while(t--){
        cin >> v;
        floydWarshall(v);
    }
    return 0;
}

void floydWarshall(int v){
    int arr[v][v], dist[v][v];

    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++){
            cin >> arr[i][j];
            dist[i][j] = arr[i][j];
        }
    for(int k = 0; k < v; k++)
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                if(dist[i][k] != INF  && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++)
            if(dist[i][j] == INF)
                cout << "INF" << " ";
            else
                cout << dist[i][j] << " ";
        cout << endl;
    }
}
