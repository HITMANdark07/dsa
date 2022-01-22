#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a  = *b;
    *b = temp;
}

int partition(int arr[], int start, int end){
    int index = arr[end];
    int i = start-1;

    for(int j=start;j<end;j++){
        if(arr[j]<=index){
            i++;

            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return i+1;
}
void printArray(int arr[], int size){
    cout<<"Array : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void quicksort(int arr[], int start, int end){
    if(start<end){
        int index = partition(arr, start, end);
        quicksort(arr,start,index-1);
        quicksort(arr,index+1,end);
    }
}

int main(){
    int arr[] = { 10, 14, 28, 11, 7, 16, 30, 50, 25, 18};;
    int size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,size);
    quicksort(arr,0,size-1);
    printArray(arr,size);
    return 0;
}