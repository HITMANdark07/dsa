#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int ll = m-l+1;
    int rl = r-m;
    int l1[ll],l2[rl];

    for(int i=0;i<ll;i++){
        l1[i]=arr[l+i];
    }
    for(int j=0;j<rl;j++){
        l2[j]=arr[m+1+j];
    }
    int i=0,j=0,k=l;

    while(i<ll && j<rl){
        if(l1[i]<=l2[j]){
            arr[k]=l1[i];
            i++;
        }else{
            arr[k]=l2[j];
            j++;
        }
        k++;
    }

    while(i<ll){
        arr[k]=l1[i];
        i++;
        k++;
    }
    while(j<rl){
        arr[k]=l2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r){
    if(r>l){
        int m = l+ (r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

void printArray(int arr[], int size){
    cout<<"Array : ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = { 10, 14, 28, 11, 7, 16, 30, 50, 25, 18};;
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    printArray(arr,size);
    return 0;
}
