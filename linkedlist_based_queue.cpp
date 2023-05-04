#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#define Sleep(timeMs) usleep((timeMs)*1000)
#endif
#include <iostream>

//  #define MAX 10 // Virtual top limit of Stack; if set, enable isFull() and counter

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
private:
    Node *front = NULL;
    Node *rear = NULL;

public:
    void enqueue(int d)
    {
        /*
        if (isFull())
        {
            cout << "Queue Full!!!\n"
                 << endl;
            return;
        }
        */

        Node *ptr = new Node(d);

        if (front == NULL)
        {
            front = ptr;
            rear = front;
            return;
        }

        rear->next = ptr;
        rear = ptr;
        return;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!!!"
                 << endl;
            return;
        }

        cout << "Dequeued: " << front->data << endl;

        if (front == rear)
        {
            front = rear = NULL;
            return;
        }

        front = front->next;
        return;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!!!\n"
                 << endl;
            return;
        }

        Node *ptr = front;

        while (ptr != NULL)
        {
            cout << ptr->data << "\t";
            ptr = ptr->next;
        }
        cout << "\n"
             << endl;
        return;
    }
    bool isEmpty()
    {
        if (front == NULL && rear == NULL)
            return true;
        return false;
    }

    /*
        /// @brief Use only if virtual limit is set!!!
        bool isFull()
        {
            if ((rear - front) == MAX - 1)
                return true;
            return false;
        }
    */
};

int main()
{
    bool flag = true;
    int option = 0, data = 0;
start:
    Queue queue;
    cout << "*********************************************" << endl;
    cout << "*****Pointer Based Implementation of Queue*****" << endl;
    cout << "  Sliding Queue Implementation. i.e. front\n\tslides to the left on deletion" << endl;
    cout << "*********************************************" << endl;
    do
    {
        cout << "*********************************************" << endl;
        cout << "1. EnQueue" << endl;
        cout << "2. DeQueue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Restart" << endl;
        cout << "0. Exit" << endl;
        cout << "*********************************************" << endl;
        cout << "Enter the Option: ";
        cin >> option;
        cout << "*********************************************" << endl;
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "Enter the Data to Enqueue: ";
            cin >> data;
            cout << endl;
            queue.enqueue(data);
            break;
        case 2:
            queue.dequeue();
            cout << endl;
            break;
        case 3:
            queue.display();
            cout << endl;
            break;
        case 4:
            queue.~Queue();
            cout << "Restarting";
            for (int i = 0; i < 4; i++)
            {
                Sleep(1000);
                cout << ".";
            }
            cout << "\033[2J\033[1;1H";
            goto start;
        case 0:
            flag = false;
            cout << "\033[2J\033[1;1H";
            break;
        default:
            cout << "Invalid Input!!!\n"
                 << endl;
            break;
        }
    } while (flag);
    cout << "*********************************************" << endl;
    cout << "\t\tExiting"
         << endl;
    cout << "*********************************************" << endl;
    return 0;
}
