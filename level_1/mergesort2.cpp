#include<iostream>
using namespace std;
int nextGap (int gap){
    if(gap<=1) return 0;
    return (gap/2)+(gap%2);
}

void merge(int arr[], int start ,int mid, int end){

    //gap method
    int gap = ((end-start+1)/2)%2==0 ? ((end-start+1)/2) : (((end-start+1)/2)+1);
    int pointer1=start;
    int pointer2=start+gap;
    while(gap>=1){
        pointer1=start;
        pointer2=start+gap;
        while(pointer2<=end){
            if(arr[pointer1]>arr[pointer2]){
                int temp = arr[pointer1];
                arr[pointer1] = arr[pointer2];
                arr[pointer2] = temp;
            }
            pointer1++;
            pointer2++;
        }
        gap = nextGap(gap);
    }








    // int len1 = mid-start+1;
    // int len2 = end-mid;
    // int arr1[len1],arr2[len2];
    // for(int i=0;i<len1;i++){
    //     arr1[i]=arr[start+i];
    // }
    // for(int j=0;j<len2;j++){
    //     arr2[j]=arr[mid+1+j];
    // }
    // int i=0,j=0,k=start;
    // while(i<len1 && j<len2){
    //     if(arr1[i]>arr2[j]){
    //         arr[k++]=arr2[j++];
    //     }else{
    //         arr[k++]=arr1[i++];
    //     }
    // }

    // while(i<len1){
    //     arr[k++] = arr1[i++];
    // }
    // while(j<len2){
    //     arr[k++] = arr2[j++];
    // }
}

void mergeSort(int arr[], int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[]= {10,2,3,1,6,4,3,9,11,1};
    int size= sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    cout<<"Array is: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}