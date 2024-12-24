#include <iostream>
using namespace std;

struct Queue {
    int size;
    int front;
    int rear;
    int* Q;

    // Constructor to initialize the queue
    Queue(int sz) {
        size = sz;
        front = rear = -1;
        Q = new int[size];
    }

    // Destructor to free memory
    ~Queue() {
        delete[] Q;
    }

    // Function to enqueue an element
    void enqueue(int x) {
        if (rear == size - 1) {
            cout << "Queue is Full" << endl;
        } else {
            rear++;
            Q[rear] = x;
        }
    }

    // Function to dequeue an element
    int dequeue() {
        int x = -1;
        if (front == rear) {
            cout << "Queue is Empty" << endl;
        } else {
            front++;
            x = Q[front];
        }
        return x;
    }

    // Function to display the queue elements
    void display() {
        for (int i = front + 1; i <= rear; i++) {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Create a queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    return 0;
}
