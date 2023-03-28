#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>

#define MAX 10

using namespace std;

class Queue
{
private:
    int queue[MAX], front = -1, rear = -1, position = 0;

public:
    void enqueue(int d)
    {
        if (isFull())
        {
            cout << "Queue Full!!!\n"
                 << endl;
            return;
        }
        if (front == -1)
            front++;
        queue[++rear] = d;
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
        cout << "Dequeued: " << queue[front] << endl;
        int i = 0;
        for (i = front; i < rear; i++)
            queue[i] = queue[i + 1];
        rear--;
        if ((rear - front) == -1)
            front = -1;
        return;
    }

    void display()
    {
        int i;
        if (isEmpty())
        {
            cout << "Queue Empty!!!\n"
                 << endl;
            return;
        }
        for (i = front; i <= rear; i++)
            cout << queue[i] << "\t";
        cout << "\n"
             << endl;
        return;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        if ((rear - front) == MAX - 1)
            return true;
        return false;
    }
};

int main()
{
    bool flag = true;
    int option = 0, data = 0;
start:
    Queue queue;
    cout << "*********************************************" << endl;
    cout << "*****Array Based Implementation of Queue*****" << endl;
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
