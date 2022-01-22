// Binary search using recursion 
#include<iostream>
using namespace std;

int binarysearch(int ns[],int start,int end, int element){
    if(start<=end){
        if(ns[(start+end)/2]==element){
        return (start+end)/2;
        }else if(ns[(start+end)/2]>element){
            return binarysearch(ns,start,((start+end)/2)-1,element);
        }else if(ns[(start+end)/2]<element){
            return binarysearch(ns,((start+end)/2)+1,end,element);
        }
    }
    return -1;
    
}

int main(){
    int nums[] = {-1,0,3,5,9,12};
    int size=sizeof(nums)/sizeof(nums[0]);
    int target=12;
    int rs = binarysearch(nums,0,size-1,target);
    if(rs>=0){
        cout<<target<<" Found at index number : "<<rs;
    }else{
        cout<<"Element not found";
    }
    return 0;
}