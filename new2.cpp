#include<iostream>
using namespace std;
class Queue{
private:
int size;
int front;
int rear;
int* Q;
public:
Queue(int size);
~Queue();
bool isFull();
bool isEmpty();
void enqueue(int x);
int dequeue();
void display();
};
Queue::Queue(int size){
    this->size = size; //set the queue size
    front == rear == -1;
    Q = new int[size];
}
Queue::~Queue(){
    delete[] Q;
}
bool Queue::isEmpty(){
    if(front==rear){
        return true;
    }
    return false;
}
bool Queue::isFull(){
    if(rear == size-1){
        return true;
    }
    return false;
}
void Queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    }else{
        rear++;
        Q[rear]=x;
    }
}
int Queue::dequeue(){
    int x = -1;
    if(isEmpty()){
        cout<<"Queue Overflow"<<endl;

    }else{
        front++;
        x=Q[front];
    }
    return x;
}



