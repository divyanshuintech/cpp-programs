#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int size, qfront, rear;
    int *arr;

public:
    Queue()
    {
        size = 1000001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        return qfront == rear;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == rear)
        {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    void enqueue(int data)
    {
        if (size == rear)
        {
            cout << "Queue is full\n";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int front()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
            return arr[qfront];
    }

    int back()
    {
        if (qfront == rear)
        {
            return -1;
        }
        else
            return arr[rear-1];
    }

    void print()
    {
        if (qfront == rear)
        {
            cout << arr[qfront] << " ";
        }
        for (int i = qfront; i < rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Printing the elements of the queue
    q.print();
    cout << "Front element is : " << q.front() << endl;
    cout << "Back element is : " << q.back() << endl;

    // Removing an element from the queue
    q.dequeue();
    q.print();
    cout << "Front element is : " << q.front() << endl;
    cout << "Back element is : " << q.back() << endl;

    // Checking if the queue is empty
    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
        cout << "Queue is not empty" << endl;

    return 0;
}