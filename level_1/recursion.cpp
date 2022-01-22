#include <iostream>
using namespace std;

int lastIndexOf(int arr[],int size,int x){
    if(size==0){
        return -1;
    }
    int small =  lastIndexOf(arr+1,size-1,x) ;
    if(arr[0]==x){
        return small+1;
    }
    if(small>=0){
        return small+1;
    }else{
        return small;
    }
    
}
int firstIndexof(int arr[], int size, int x){
    if(size==0){
        return -1;
    }
    if(arr[0] == x){
        return 0;
    }
    int small = firstIndexof(arr+1,size-1,x);
    if(small>=0){
        return small+1;
    }else{
        return small;
    }
}
int allIndexof(int arr[], int size,int x,int arr2[]){
    if(size==0)return 0;
    
    int small = allIndexof(arr+1,size-1,x,arr2);
    if(arr[0]==x){
        for(int i=small-1;i>=0;i--){
            arr2[i+1]=arr2[i]+1;
        }
        arr2[0]=0;
        small++;
    }else{
        for(int i=small-1;i>=0;i--){
            arr2[i]=arr2[i]+1;
        }
    }
    return small;
}
int allIndexof2(int arr[], int size, int x, int arr2[]){
    if(size==0){
        return 0;
    }
    int small =  allIndexof2(arr, size-1, x, arr2);
    if(arr[size-1]==x){
        arr2[small++]=size-1;
        return small;
    }else{
        return small;
    }
}


int main()
{
    int arr[] = {5,5,6,5,6,10};
    int num = 5;
    int size = sizeof(arr)/sizeof(arr[0]);
    int output[size]; 
    int x =lastIndexOf(arr,size,num);
    cout<<"Last Index: "<<x<<endl;
    int y = firstIndexof(arr,size,num);
    cout<<"First Index: "<<y<<endl;
    int z=allIndexof(arr,size,num,output);
    cout<<"All Index of: "<<z<<endl;
    cout<<"array is: [";
    for(int i=0;i<z-1;i++){
        cout<<output[i]<<",";
    }
    cout<<output[z-1];
    cout<<"]"<<endl;

    int p=allIndexof(arr,size,num,output);
    cout<<"All Index of 2 : "<<z<<endl;
    cout<<"array is: [";
    for(int i=0;i<p-1;i++){
        cout<<output[i]<<",";
    }
    cout<<output[p-1];
    cout<<"]"<<endl;
    
    return 0;
}
