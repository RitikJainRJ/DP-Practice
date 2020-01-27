struct Box{
    int h, w, l, base;
};

bool myComp(Box a, Box b){
    return a.base < b.base;
}

int maxHeight(int height[],int width[],int length[],int n){
    Box arr[3 * n];
    int k = 0, load[3 * n];

    for(int i = 0; i < n; i++){
        arr[k].h = height[i];
        arr[k].w = width[i];
        arr[k].l = length[i];
        arr[k].base = width[i] * length[i];
        k++;

        arr[k].h = width[i];
        arr[k].w = length[i];
        arr[k].l = height[i];
        arr[k].base = height[i] * length[i];
        k++;

        arr[k].h = length[i];
        arr[k].w = height[i];
        arr[k].l = width[i];
        arr[k].base = width[i] * height[i];
        k++;
    }
    sort(arr, arr + 3 * n, myComp);
    for(int i = 0; i < 3 * n; i++)
        load[i] = arr[i].h;
    for(int i = 1; i < 3 * n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j].w < arr[i].w && arr[j].l < arr[i].l){
                if(load[j] + arr[i].h > load[i])
                    load[i] = load[j] + arr[i].h;
            }
        }
    }
    return *max_element(load, load + 3 * n);
}
