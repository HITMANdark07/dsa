#include<iostream>
#include<map>
#include<string>
using namespace std;
int roman (string );

int romanToInt(string s) {
    map<char,int> rmap;
    rmap['I'] =   1;
    rmap['V'] =   5;
    rmap['X'] =  10;
    rmap['L'] =  50;
    rmap['C'] = 100;
    rmap['D'] = 500;
    rmap['M'] =1000;
    int number=0,i=0;
    
    if(s.length()<=1){
        return rmap[s.at(0)];
    }else{
        while(i<rmap.size()){
            if(rmap[s[i]]<rmap[s[i+1]]){
                number+=rmap[s[i+1]]-rmap[s[i]];
                i+=2;
            }else{
                number+=rmap[s[i]];
                i++;
            }
        }
        return number;
    }
}

int main(){
    int res=romanToInt("III");
    cout<<res;
    return 0;
}