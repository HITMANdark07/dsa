#include<iostream>
using namespace std;

int subsequence(string input, string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallString = input.substr(1);
    int smallSequenceSize = subsequence(smallString, output);
    for(int i=0;i<smallSequenceSize;i++){
        output[i+smallSequenceSize]=input[0]+output[i];
    }
    return 2*smallSequenceSize;
}

int main(){
    string input;
    cin >> input;
    string *output = new string[1000];
    int size = subsequence(input, output);
    for(int i=0;i<size;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}