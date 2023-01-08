#include<iostream>
#include<array>

using namespace std;

int arr2[100];

void merge(int arr[], int lb, int mid, int ub){

int i, j, k;

i=lb;
j=mid+1;
k=lb;

while(i<=mid && j<=ub){
    if(arr[i]<arr[j]){
        arr2[k] = arr[i];
        i++;
    }
    else{
        arr2[k] = arr[j];
        j++;
    }
    k++;
}
if(i>mid){
    while(j<=ub){
        arr2[k] = arr[j];
        j++;
        k++;
    }
}
else{
    while(i<=mid){
        arr2[k] = arr[i];
        i++;
        k++;
    }
}
int x;
// Copy sorted elements from arr2 back into arr
    for (int x = lb; x <= ub; x++) {
        arr[x] = arr2[x];
    }

}

void mergeSort(int arr[], int lb, int ub){
    if(ub>lb){
        int mid = (ub+lb)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr,mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}


int main(){
    int arr[] = {10,9,8,7,6,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }

    return 0;
}