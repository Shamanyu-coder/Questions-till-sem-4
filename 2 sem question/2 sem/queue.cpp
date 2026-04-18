
/*Program to demonstration the implementation of various operations on a linear queue.

a) Enqueue element in a queue

b) dequeue element from a queue

c) Traversing a queue

d) Display the status of queue
*/

#include <iostream>
using namespace std;

class queue
{
public:
    int MAX = 50;
    int arr[50];
    int front = 0;
    int rear = -1;

    void enqueue(int data)
    {
        if (rear > 49)
        {
            cout << "Queue overflow" << endl;
            return;
        }

        rear++;
        arr[rear] = data;

        cout << data << " added in queue" << endl;
    }

    void dequeue()
    {
        if (rear == -1)
        {
            cout << "Queue underflow";
            cout << endl;
            return;
        }
        else if (front > rear)
        {
            cout << "Empty queue,cannot dequeue" << endl;
            return;
        }
        else
        {
            arr[front] = -1;
            front++;
            cout << "Front element is dequeued" << endl;
        }
    }

    void traverse()
    {
        cout << "Printing the queue" << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void status()
    {
        if (rear == -1)
        {
            cout << "Empty queue" << endl;
        }
        else if (rear == 49)
        {
            cout << "Full queue";
        }
        else
        {
            cout << "Queue has " << rear - front + 1 << " elements" << endl;
        }
    }
};

int main()
{
    queue q;
    int data;
    cout << "1)Enqueue an element" << endl
         << "2)Dequeue an element" << endl
         << "3)Traversing a queue" << endl
         << "4)Status of queue" << endl
         << "5)EXIT" << endl;
    int ch = 0;
    while (ch != 5)
    {
        cout << "Enter the operation from the above list : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter the element : ";
            cin >> data;
            q.enqueue(data);

            break;
        }
        case 2:
        {
            q.dequeue();

            break;
        }
        case 3:
        {
            q.traverse();
            break;
        }
        case 4:
        {
            q.status();
            break;
        }
        case 5:
        {
            cout << "Exited Successfully!" << endl;
            break;
        }
        default:
            cout << "OOPS! Wrong Choice." << endl;
        }
    }

    return 0;
}
