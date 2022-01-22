#include<iostream>
#define SIZE 5

using namespace std;

class Queue{
    private:
    int items[SIZE],front, rear;

    public:
    Queue(){
        front=-1;
        rear=-1;
    }

    bool isEmpty(){
        if(front==-1) return true;
        return false;
    }

    bool isFull(){
        if(front==0 && rear==SIZE-1) return true;
        return false;
    }

    void enqueue(int element){
        if(isFull()){
            cout<<"Queue is Full"<<endl;
        } else{
            if(front==-1) front=0;
            rear++;
            items[rear]=element;
            cout<<"Insert Element: "<<element<<endl;
        }
    }

    int dequeue(){
        int element;
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        element = items[front];
        if(front>=rear){
            front=-1;
            rear=-1;
        }else{
            front++;
        }
        cout<<"Deleted Element: "<<element<<endl;
        return element;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue Empty"<<endl;
        }else{
            cout<<"Queue: ";
            for(int i=front ;i<=rear;i++){
                cout<<items[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Queue q;

    q.dequeue();

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.enqueue(6);

    q.display();

    q.dequeue();

    q.display();
    return 0;
}