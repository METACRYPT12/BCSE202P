#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#define Sleep(timeMs) usleep((timeMs)*1000)
#endif
#include <iostream>

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

class LinkedList
{
    Node *head;

public:
    LinkedList();
    ~LinkedList();

    void insert(int, int);
    void deletep(int);
    void search(int);
    void display(void);
};

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList() {}

void LinkedList::insert(int data, int position)
{
    Node *temp = new Node(data);

    if (position == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }

    Node *ptr = head;

    if (position == 0)
    {
        if (ptr == NULL)
        {
            ptr = new Node(data);
            head = ptr;
            return;
        }

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        return;
    }

    int i = 1;
    Node *prevPtr = head;

    while (i <= position - 1 && ptr != NULL)
    {
        i++;
        prevPtr = ptr;
        ptr = ptr->next;
    }

    if (i != position || position < 0 || ptr == NULL)
    {
        cout << "Positiion Out of Bounds!!!" << endl;
        cout << endl;
        return;
    }

    temp->next = ptr;
    prevPtr->next = temp;
    return;
}

void LinkedList::deletep(int position)
{
    Node *ptr = head;

    if (position == 1)
    {
        head = ptr->next;
        free(ptr);
        return;
    }

    Node *iter = ptr;

    if (position == 0)
    {
        while (iter->next != NULL)
        {
            ptr = iter;
            iter = iter->next;
        }
        ptr->next = NULL;
        return;
    }

    int i = 1;
    while (iter->next != NULL && i <= position - 1)
    {
        i++;
        ptr = iter;
        iter = iter->next;
    }
    if (i == position)
    {
        ptr->next = iter->next;
        return;
    }

    cout << "Positiion Out of Bounds!!!" << endl;
    cout << endl;
    return;
}

void LinkedList::search(int data)
{
    Node *iter = head;
    int i = 1;
    while (iter != NULL)
    {
        if (iter->data == data)
        {
            cout << "Data found at position: " << i << endl;
            cout << endl;
            return;
        }
        iter = iter->next;
        i++;
    }

    cout << "Data not found!!!" << endl;
    cout << endl;
    return;
}

void LinkedList::display(void)
{
    Node *iter = head;

    if (iter == NULL)
    {
        cout << "List Empty!!" << endl;
        cout << endl;
        return;
    }

    cout << "List Contents: ";
    while (iter != NULL)
    {
        cout << iter->data << "\t";
        iter = iter->next;
    }
    cout << "\n\n";

    return;
}

int main()
{
    bool flag = true;
    int option = 0, data = 0, position = 0;
start:
    LinkedList list;
    cout << "********************************************" << endl;
    cout << "*****Array Based Implementation of List*****" << endl;
    cout << "********************************************" << endl;
    do
    {
        cout << "*********************************************" << endl;
        cout << "1. Insert at End" << endl;
        cout << "2. Insert at Front" << endl;
        cout << "3. Insert at Position (0 triggers insertion at end)" << endl;
        cout << "4. Delete from End" << endl;
        cout << "5. Delete from Front" << endl;
        cout << "6. Delete from Position (0 triggers deletion at end)" << endl;
        cout << "7. Search" << endl;
        cout << "8. Display" << endl;
        cout << "9. Restart" << endl;
        cout << "0. Exit" << endl;
        cout << "********************************************" << endl;
        cout << "Enter the Option: ";
        cin >> option;
        cout << "********************************************" << endl;
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "Enter the Data to Insert at the End: ";
            cin >> data;
            cout << endl;
            list.insert(data, 0);
            break;
        case 2:
            cout << "Enter the Data to Insert at the Front: ";
            cin >> data;
            cout << endl;
            list.insert(data, 1);
            break;
        case 3:
            cout << "Enter Position: ";
            cin >> position;
            cout << "Enter the Data to Insert: ";
            cin >> data;
            cout << endl;
            list.insert(data, position);
            break;
        case 4:
            list.deletep(0);
            break;
        case 5:
            list.deletep(1);
            break;
        case 6:
            cout << "Enter Position: ";
            cin >> position;
            cout << endl;
            list.deletep(position);
            break;
        case 7:
            cout << "Enter Data to Search: ";
            cin >> data;
            cout << endl;
            list.search(data);
            break;
        case 8:
            list.display();
            break;
        case 9:
            list.~LinkedList();
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
            break;
        default:
            cout << "Invalid Input!!!" << endl;
            cout << endl;
            break;
        }
    } while (flag);
    cout << "\033[2J\033[1;1H";
    cout << "********************************************" << endl;
    cout << "\t\tExiting"
         << endl;
    cout << "********************************************" << endl;
    return 0;
}
