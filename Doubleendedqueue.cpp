// Doubleendedqueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

         
    void insert_front(int value)
    {
        if (isfull()) 
        {
            cout << "queue is full" << endl;
            return;

        }
            if (isempty())
            {
                front = rear = 0;
                queue[front] = value;
            }
            else if (front == 0)
            {
                front = size - 1;
                queue[front] = value;
            }

        else {
            front--;
            queue[front] = value;
        }
    }
        void insert_rear(int value){
            if (isfull())
            {
                cout << "queue is full" << endl;
                return;
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
        void delete_rear()
        {
            if (isempty())
            {
                cout << "Queue is empty" << endl;
                return;
            }
            if (front == rear)
            {
                front = rear = -1;
            }
            else if (rear == 0)
            {
                rear = size - 1;
            }                   
            else
            {
                rear--;
            }
        }                 
        void delete_front()
        {
            if (isempty())
            {
                cout << "Queue is empty" << endl;
                return;
            }

            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % size;
            }
        }
    bool isempty()
    {
        return (front == -1 && rear == -1);
    }
    bool isfull()
    {
		return (front == (rear + 1) % size);
    }
    
    void display() {

        int i = front;
        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }
    }
};
int main()
    {
        Queue q;
        int choice, value;

        do
        {
            cout << "\n Double Ended Queue Menu " << endl;          
            cout << "1. Insert Front" << endl;
            cout << "2. Insert Rear" << endl;
            cout << "3. Delete Front" << endl;
            cout << "4. Delete Rear" << endl;
            cout << "5. Display Queue" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.insert_front(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                q.insert_rear(value);
                break;

            case 3:
                q.delete_front();
                cout << "Front element deleted." << endl;
                break;

            case 4:
                q.delete_rear();
                cout << "Rear element deleted." << endl;
                break;

            case 5:
                cout << "Queue Elements: ";
                q.display();
                cout << endl;
                break;

            case 6:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
            }

        } while (choice != 6);

        return 0;
    }