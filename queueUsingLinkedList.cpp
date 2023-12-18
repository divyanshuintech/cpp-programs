#include <bits/stdc++.h>
using namespace std;

class QNode
{
public:
    int data;
    QNode *next;

    QNode(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class Queue
{
    QNode *qfront, *rear;

public:
    Queue()
    {
        qfront = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return qfront == rear;
    }

    void enqueue(int data)
    {
        QNode *temp = new QNode(data);
        if (rear == NULL)
        {
            qfront = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    void dequeue()
    {
        if (qfront == NULL)
        {
            rear = NULL;
            return;
        }

        QNode *temp = qfront;
        qfront = qfront->next;
        delete (temp);
    }

    int front()
    {
        return qfront->data;
    }

    int back()
    {
        return rear->data;
    }

    void print()
    {
        QNode *temp = qfront;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
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