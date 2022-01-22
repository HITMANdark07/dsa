#include<iostream>
#define SIZE 5
using namespace std;

class CircularQueue{
    int front,rear, items[SIZE];
    public:
    CircularQueue(){
        front=-1;
        rear=-1;
    }
    bool isFull(){
        if(front==0 && rear==SIZE-1){
            return true;
        }
        if(front==rear+1){
            return true;
        }
        return false;
    }
    bool isEmpty(){
        if(front==-1) return true;
        return false;
    }
    void enqueue(int element){
        if(isFull()){
            cout<<"Queue Full"<<endl;
        }else{
            if (front ==-1) front=0;
            rear= (rear+1)%5;
            items[rear] = element;
            cout<<"Inserted item: "<<element<<endl;
        }
    }
    int dequeue(){
        int element;
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }else{
            element = items[front];
            if(front==rear){
                front=-1;
                rear=-1;
            }else{
                front = (front+1)%SIZE;
            }
            return element;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }else{
            for(int i=front;i!=rear;i= (i+1)%SIZE)
                cout<<items[i]<<" ";
            cout<<items[rear];
            cout<<endl;
        }
    }
};
int main(){
    CircularQueue q;
    q.display();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}
