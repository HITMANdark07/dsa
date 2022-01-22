#include<iostream>
using namespace std;

void removex(char s[]){
    if(s[0]=='\0'){
        return;
    }
    if(s[0]!='x'){
        removex(s+1);
    }else{
        int i;
        for(i=1;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removex(s);
    }
}

int len(char s[]){
    if(s[0]=='\0'){
        return 0;
    }
    int smallstring = len(s+1);
    return smallstring+1;
}
void removeduplicate(char s[]){
    if(s[0]=='\0'){
        return;
    }
    removeduplicate(s+1);
    if(s[0]==s[1]){
        int i;
        for(i=1;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
    }else{
        return;
    }
}

int main(){
    char s[100];
    cout<<"Enter a String : ";
    cin>>s;
    int l = len(s);
    cout<<"string length: "<<l<<endl;
    removex(s);
    cout<<s<<endl;
    l = len(s);
    cout<<"string length: "<<l<<endl;
    removeduplicate(s);
    cout<<"removing duplicates : "<<s<<endl;
    return 0;
}