#include<iostream>
using namespace std;

class node
{
private:
    int data;
    node* next;
    node* prev;

public:
    node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    void setdata(int val)
    {
        data = val;
    }

    int getdata()
    {
        return data;
    }

    void setnext(node* ptr)
    {
        next = ptr;
    }

    node* getnext()
    {
        return next;
    }

    void setprev(node* ptr)
    {
        prev = ptr;
    }

    node* getprev()
    {
        return prev;
    }
};

class deque
{
private:
    node* front;
    node* rear;

public:
    deque()
    {
        front = rear = nullptr;
    }

    bool isempty()
    {
        return front == nullptr;
    }
    void insertfront(int val)
    {
        node* newnode = new node();
        newnode->setdata(val);

        if (isempty())
        {
            front = rear = newnode;
            front->setnext(front);
            front->setprev(front);
            return;
        }

        newnode->setnext(front);
        newnode->setprev(rear);

        front->setprev(newnode);
        rear->setnext(newnode);

        front = newnode;
    }

    void insertrear(int val)
    {
        node* newnode = new node();
        newnode->setdata(val);

        if (isempty())
        {
            front = rear = newnode;
            front->setnext(front);
            front->setprev(front);
            return;
        }

        newnode->setnext(front);
        newnode->setprev(rear);

        rear->setnext(newnode);
        front->setprev(newnode);

        rear = newnode;
    }

   ssss
    void deletefront()
    {
        if (isempty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        node* temp = front;

        if (front == rear)
        {
            cout << temp->getdata() << " deleted\n";
            delete temp;
            front = rear = nullptr;
            return;
        }

        front = front->getnext();

        front->setprev(rear);
        rear->setnext(front);

        cout << temp->getdata() << " deleted\n";

        delete temp;
    }


    void deleterear()
    {
        if (isempty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        node* temp = rear;

        if (front == rear)
        {
            cout << temp->getdata() << " deleted\n";
            delete temp;
            front = rear = nullptr;
            return;
        }

        rear = rear->getprev();

        rear->setnext(front);
        front->setprev(rear);

        cout << temp->getdata() << " deleted\n";

        delete temp;
    }

    void display()
    {
        if (isempty())
        {
            cout << "Deque is Empty\n";
            return;
        }

        node* temp = front;

        cout << "Deque : ";

        do
        {
            cout << temp->getdata() << " ";
            temp = temp->getnext();
        } while (temp != front);

        cout << endl;
    }
};

int main()
{
    deque q;

    q.insertfront(10);
    q.insertfront(20);
    q.insertfront(30);
    q.display();
    q.insertrear(40);
    q.insertrear(50);
    q.insertrear(60);

    q.display();

    q.deletefront();
    q.display();

    q.deleterear();
    q.display();

    q.deletefront();
    q.deletefront();
    q.deletefront();
    q.deletefront();

    q.display();

    return 0;
}