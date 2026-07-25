
#include <iostream>
using namespace std;

class Queue {
public:
    const int size = 10;
    int front, rear;
    int queue[10];

    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (isfull())
        {
            cout << "queue is full " << endl;
        }
        else {
            rear = (rear + 1) % size;
           
            if (front == -1)
            {
                front = 0;
            }
            queue[rear] = value;
        }
    }
    int deque() {
        if (isempty())
        {
            cout << " queue is empty" << endl;
         }
        else {
            int v = queue[front];
            front++;
            return v;
        }
    }
    bool isempty()
    {
        return (front == -1 && rear == -1);
    }
    bool isfull()
    {
        return rear == size - 1;
    }
    void display()
    {
        if (isempty())
        {
            cout << "queue is empty" << endl;
        }
        else {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
	}
};

int main()
{
    Queue q;
    q.enqueue(10);
	q.enqueue(20); 
	q.enqueue(30);
	q.enqueue(40);
    q.enqueue(55);
    q.enqueue(77);
	q.enqueue(50);
	cout << "Elements in the queue: " << endl;
    q.display();
    q.deque();
    q.deque();
    q.deque();
	cout << "After dequeuing an element: " << endl;
	q.display();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
