#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int *queue;

public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        queue = new int[size];
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        
        if (isEmpty()) {  // First element insertion
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;  // Wrap around
        } else {
            rear++;
        }
        
        queue[rear] = value;
        cout << "Inserted " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to dequeue." << endl;
            return -1;
        }
        
        int data = queue[front];
        queue[front] = -1;  // Optional: Clear the slot (not necessary)
        
        if (front == rear) {  // Queue has only one element
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;  // Wrap around
        } else {
            front++;
        }
        
        cout << "Dequeued " << data << endl;
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        
        cout << "Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
        } else {
            for (int i = front; i < size; i++)
                cout << queue[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);  // Queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);  // Queue is full here
    
    q.display();

    q.dequeue();
    q.dequeue();
    
    q.enqueue(60);  // Will go to the beginning (wrap around)
    q.enqueue(70);  // Queue is full again
    
    q.display();
    
    return 0;
}

