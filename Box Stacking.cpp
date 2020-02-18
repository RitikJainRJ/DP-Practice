struct Box{
    int h, w, l;
};

bool comp(Box a, Box b){
    int temp1 = a.w * a.l;
    int temp2 = b.w * b.l;
    return temp1 < temp2;
}

int maxHeight(int height[], int width[], int length[], int n){
    Box arr[3 * n];
    int k = 0;

    for(int i = 0; i < n; i++){
        arr[k].h = height[i];
        arr[k].w = min(width[i], length[i]);
        arr[k].l = max(width[i], length[i]);
        k++;
        arr[k].h = width[i];
        arr[k].w = min(height[i], length[i]);
        arr[k].l = max(height[i], length[i]);
        k++;
        arr[k].h = length[i];
        arr[k].w = min(width[i], height[i]);
        arr[k].l = max(width[i], height[i]);
        k++;
    }
    sort(arr, arr + 3 * n, comp);
    n = 3 * n;
    int load[n];
    for(int i = 0; i < n; i++)
        load[i] = arr[i].h;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(arr[j].w < arr[i].w && arr[j].l < arr[i].l && load[i] < arr[i].h + load[j])
                load[i] = arr[i].h + load[j];

    return *max_element(load, load + n);
}
