//
// Created by Yang Shuangzhen on 2020/8/24.
//


#include <iostream>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    int j = low;

    while (j < high){
        if (arr[j] < pivot){
            int tmp = arr[++i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
        j++;
    }

    int tmp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = tmp;

    return i+1;
}

int selection(int arr[], int low, int high, int k){
    int pi = partition(arr, low, high);
    int result;

    if (k == pi-low+1){
        result =  arr[pi];
    }
    else if (k < pi-low+1){
        result= selection(arr, low, pi-1, k);
    }
    else{
        result = selection(arr, pi+1, high, k-(pi-low+1));
    }

    return result;
}

int main(){
    int arr[] = {2, 6, 1, 3, 9, 5, 4, 7, 2};

    int res = selection(arr, 0, 8, 4);
    assert(res == 3);

    return 0;
}

