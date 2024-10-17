#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size, count;
    int *queue;

public:
    CircularQueue(int s) {
        front = rear = -1;
        size = s;
        queue = new int[size];
        count = 0;  // Initialize count to 0
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return count == size;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        queue[rear] = value;
        count++;  // Increment count
        cout << "Inserted " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to dequeue." << endl;
            return -1;
        }

        int data = queue[front];
        queue[front] = -1;

        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }

        count--;  // Decrement count
        cout << "Dequeued " << data << endl;
        return data;
    }

    int countElements() {
        return count;
    }

    void clear() {
        front = rear = -1;
        count = 0;
        cout << "Queue cleared!" << endl;
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
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.clear();
    cout << "Elements in queue after clearing: " << q.countElements() << endl;
    q.display();

    return 0;
}

