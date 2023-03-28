#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>

#define MAX 10

using namespace std;

class List
{

private:
	int list[MAX];
	int last;

public:
	List()
	{
		last = -1;
	}

	void insert(int d, int p)
	{
		int i = 0;
		if (isFull())
		{
			cout << "List Full!!!\n"
				 << endl;
			return;
		}
		if (p > last + 1 || p < 0)
		{
			cout << "Entered Position Out of Bounds!!!\n"
				 << endl;
			return;
		}
		for (i = last; i >= p; i--)
		{
			list[i + 1] = list[i];
		}
		list[p] = d;
		last++;
		return;
	}

	void deletep(int p)
	{
		if (isEmpty())
		{
			cout << "List Empty!!!\n"
				 << endl;
			return;
		}
		if (p > last || p < 0)
		{
			cout << "Entered Position Out of Bounds!!!\n"
				 << endl;
			return;
		}
		int i = 0;
		cout << "Deleted: " << list[p] << "\n"
			 << endl;
		for (i = p; i < last; i++)
		{
			list[i] = list[i + 1];
		}
		last--;
		return;
	}

	void search(int d)
	{
		int i = 0;
		for (i = 0; i <= last; i++)
		{
			if (list[i] == d)
			{
				cout << "Data found at position: " << i << "\n"
					 << endl;
				return;
			}
		}
		cout << "Data not found!!!\n"
			 << endl;
		return;
	}

	void display()
	{
		int i;
		if (isEmpty())
		{
			cout << "List Empty!!!\n"
				 << endl;
			return;
		}
		for (i = 0; i <= last; i++)
			cout << list[i] << "\t";
		cout << "\n"
			 << endl;
		return;
	}

	int retlast()
	{
		return last;
	}

	bool isEmpty()
	{
		if (last == -1)
			return true;
		return false;
	}

	bool isFull()
	{
		if (last == MAX - 1)
			return true;
		return false;
	}
};

int main()
{
	bool flag = true;
	int option = 0, data = 0, position = 0;
start:
	List list;
	cout << "********************************************" << endl;
	cout << "*****Array Based Implementation of List*****" << endl;
	cout << "********************************************" << endl;
	do
	{
		cout << "*********************************************" << endl;
		cout << "1. Insert at End" << endl;
		cout << "2. Insert at Front" << endl;
		cout << "3. Insert at Position" << endl;
		cout << "4. Delete from End" << endl;
		cout << "5. Delete from Front" << endl;
		cout << "6. Delete from Position" << endl;
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
			list.insert(data, list.retlast() + 1);
			break;
		case 2:
			cout << "Enter the Data to Insert at the Front: ";
			cin >> data;
			cout << endl;
			list.insert(data, 0);
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
			list.deletep(list.retlast());
			break;
		case 5:
			list.deletep(0);
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
			list.~List();
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
			cout << "Invalid Input!!!\n"
				 << endl;
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
