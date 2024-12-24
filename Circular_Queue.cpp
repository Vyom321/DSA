#include<iostream>
using namespace std;
class Circular_Queue
{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Circular_Queue(int size);
    ~Circular_Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

Circular_Queue::Circular_Queue(int size){
    this->size = size;
    front =0;
    rear = 0;
    Q = new int[size];
}

Circular_Queue::~Circular_Queue(){
    delete [] Q;
}
bool Circular_Queue::isEmpty(){
    if(front == rear){
        return true;
    }
    return false;
}
bool Circular_Queue::isFull(){
    if((rear+1)%size == front){
        return true;
    }
    return false;
}
void Circular_Queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue is Overflow"<<endl;
    }else{
        rear= (rear+1)%size;
        x=Q[rear];
    }
}
int Circular_Queue::dequeue(){
    int x=-1;
    if(isEmpty()){
        cout<<"Queue is Underflow"<<endl;
    }
    else{
        front = (front+1)%size;
        x=Q[front];
    }
    return front;
}
void Circular_Queue::display(){
     int i = front + 1;
    do {
        cout << Q[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);

}
int main() {
 
    int A[] = {1, 3, 5, 7, 9};
 
    Circular_Queue cq(sizeof(A)/sizeof(A[0]) + 1);
 
    // Enqueue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.enqueue(A[i]);
    }
 
    // Display
    cq.display();
    cout << endl;
 
    // Overflow
    cq.enqueue(10);
 
    // Dequeue
    for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        cq.dequeue();
    }
 
    // Underflow
    cq.dequeue();
 
    return 0;
}
