#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAX 10

struct stack{
    int items[MAX];
    int top;
};

void createEmptStack(stack *s) {
    s->top=-1;
}

int isFull(stack *s){
    if(s->top==MAX-1){
        return 1;
    }
    return 0;
}

int isEmpty(stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

void push(stack *s, int newItem){
    if(isFull(s)){
        cout<<"\nSTACK OVERFLOW\n";
    }else{
        s->top++;
        s->items[s->top]=newItem;
    }
    // size++;
}

void pop(stack *s){
    if(isEmpty(s)){
        cout<<"\nSTACK EMPTY\n";
    }else{
        cout<<"Item Popped :"<<s->items[s->top];
        s->top--;
    }
    // size--;
    cout<<endl;
}

void printStack(stack *s){
    cout<<"\nStack: \n";
    for(int i=0;i<=s->top;i++){
        cout<<s->items[i]<<" ";
    }
    cout<<endl;
}

int main(){
    stack *s = (stack *)malloc(sizeof(stack));
    createEmptStack(s);
    pop(s);
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    pop(s);
    printStack(s);
    return 0;
}
