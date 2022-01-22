#include<iostream>
using namespace std;

int sz=0;
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[], int size, int i){
    int largest =i,l,r;
    l= 2*i+1;
    r= 2*i+2;
    if(l<size && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<size && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,size,largest);
    }
}
void insert(int arr[], int num){
    if(sz==0){
        arr[0] = num;
        sz++;
    }else{
        arr[sz]=num;
        sz++;
        for(int i= (sz-2)/2;i>=0;i--){
            heapify(arr,sz,i);
        }
    }
}
void deleteRoot(int arr[], int num){
    int i;
    for(i=0;i<sz;i++){
        if(num==arr[i]) break;
    }
    swap(&arr[i],&arr[sz-1]);
    sz--;
    for(int i=(sz-2)/2;i>=0;i--){
        heapify(arr,sz,i);
    }
}
void printArray(int arr[]){
    cout<<"Array: ";
    for(int i=0;i<sz;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[10];
    insert(arr,3);
    insert(arr,4);
    insert(arr,9);
    insert(arr,5);
    insert(arr,2);
    insert(arr,10);
    cout<<"Max-heap array: "<<endl;
    printArray(arr);
    deleteRoot(arr,10);
    cout<<"After deleting an element :"<<endl;
    printArray(arr);

    
    return 0;
}