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

class Stack
{
private:
    Node *top = NULL;
    // int counter = -1;

public:
    void push(int d)
    {
        /*
        if (isFull())
        {
            cout << "Stack Overflow!!!\n"
                 << endl;
            return;
        }
        */

        Node *ptr = new Node(d);
        ptr->next = top;
        top = ptr;
        // counter++;
        return;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!!!"
                 << endl;
            return;
        }
        cout << "Popped: " << top->data << endl;
        // --counter;
        top = top->next;
        return;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty!!!" << endl;
            return;
        }
        cout << "Item on Top is: " << top->data << endl;
        return;
    }

    bool isEmpty()
    {
        if (top == NULL)
            return true;
        return false;
    }

    /*
        /// @brief Use only if virtual limit is set!!!
        bool isFull()
        {
            if (counter == MAX - 1)
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
    Stack stack;
    cout << "***********************************************" << endl;
    cout << "*****Pointer Based Implementation of Stack*****" << endl;
    cout << "***********************************************" << endl;
    do
    {
        cout << "***********************************************" << endl;
        cout << "1. Push Data" << endl;
        cout << "2. Pop Data" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Restart" << endl;
        cout << "0. Exit" << endl;
        cout << "***********************************************" << endl;
        cout << "Enter the Option: ";
        cin >> option;
        cout << "***********************************************" << endl;
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "Enter the Data to Push on the Stack: ";
            cin >> data;
            cout << endl;
            stack.push(data);
            break;
        case 2:
            stack.pop();
            cout << endl;
            break;
        case 3:
            stack.peek();
            cout << endl;
            break;
        case 4:
            stack.~Stack();
            cout << "Restarting";
            for (int i = 0; i < 4; i++)
            {
                Sleep(1000);
                cout << ".";
            }
            cout << "\n"
                 << endl;
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
    cout << "***********************************************" << endl;
    cout << "\t\tExiting"
         << endl;
    cout << "***********************************************" << endl;
    return 0;
}
