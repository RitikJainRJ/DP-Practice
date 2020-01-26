bool myComp(val v1, val v2){
    return v1.first < v2.first;
}

int maxChainLen(val p[],int n){
    int arr[n];

    sort(p, p + n, myComp);
    for(int i = 0; i < n; i++)
        arr[i] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(p[i].first > p[j].second && arr[j] + 1 > arr[i])
                arr[i] = arr[j] + 1;
        }
    }
    return *max_element(arr, arr + n);
}
