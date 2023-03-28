#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>

#define MAX 50

using namespace std;

void display(int data[], int s)
{
	int i = 0;
	cout << "Contents of the Array: ";
	for (i = 0; i < s; i = i + 1)
		cout << data[i] << "\t";
	cout << endl;
	cout << endl;
	return;
}

void bubblesort(int data[], int s)
{
	int i = 0, j = 0, temp = 0;
	for (i = 0; i < s; i = i + 1)
	{
		for (j = 0; j < s - i - 1; j = j + 1)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	display(data, s);
	return;
}

void insertionsort(int data[], int s)
{
	int i = 0, j = 0, key;
	for (i = 1; i < s; i++)
	{
		j = i - 1;
		key = data[i];
		while (j >= 0 && data[j] > key)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = key;
	}
	display(data, s);
	return;
}

void selectionsort(int data[], int s)
{
	int i = 0, j = 0, min_idx = 0;
	for (i = 0; i < s - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < s; j++)
		{
			if (data[j] < data[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			data[min_idx] = data[min_idx] + data[i];
			data[i] = data[min_idx] - data[i];
			data[min_idx] = data[min_idx] - data[i];
		}
	}
	display(data, s);
	return;
}

void merge(int data[], int aux[], int lo, int mid, int hi)
{
	for (int k = lo; k <= hi; k++)
	{
		aux[k] = data[k];
	}
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; k++)
	{
		if (i > mid)
			data[k] = aux[j++];
		else if (j > hi)
			data[k] = aux[i++];
		else if (aux[j] < aux[i])
			data[k] = aux[j++];
		else
			data[k] = aux[i++];
	}
	return;
}
void msort(int data[], int aux[], int lo, int hi)
{
	if (hi <= lo)
		return;
	int mid = lo + (hi - lo) / 2;
	msort(data, aux, lo, mid);
	msort(data, aux, mid + 1, hi);
	merge(data, aux, lo, mid, hi);
	return;
}

void mergesort(int data[], int s)
{
	int aux[s];
	msort(data, aux, 0, s - 1);
	display(data, s);
	return;
}

int partition(int data[], int lo, int hi)
{
	int i = lo - 1;
	int j = hi + 1;
	int v = data[lo];
	while (true)
	{

		while (data[++i] < v)
		{
			if (i == hi)
				break;
		}

		while (v < data[--j])
		{
			if (j == lo)
				break;
		}

		if (i >= j)
			break;
		data[i] = data[i] + data[j];
		data[j] = data[i] - data[j];
		data[i] = data[i] - data[j];
	}

	data[lo] = data[lo] + data[j];
	data[j] = data[lo] - data[j];
	data[lo] = data[lo] - data[j];
	return j;
}

void qsort(int data[], int lo, int hi)
{
	if (lo < hi)
	{
		int j = partition(data, lo, hi);
		qsort(data, lo, j - 1);
		qsort(data, j + 1, hi);
	}
	return;
}

void quicksort(int data[], int s)
{
	qsort(data, 0, s - 1);
	display(data, s);
	return;
}

void linearsearch(int data[], int s, int target)
{
	int i = 0;
	bool flag = false;
	for (i = 0; i < s; i = i + 1)
	{
		if (data[i] == target)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		cout << target << " found at position: " << (i + 1) << endl;
	else
		cout << target << " not found in the array!!!" << endl;
	cout << endl;
	return;
}

void binarysearch(int data[], int s, int target)
{
	int lo = 0, hi = s - 1, mid = 0;
	while (lo <= hi)
	{
		mid = (hi + lo) / 2;
		if (data[mid] == target)
		{
			cout << target << " found at position: " << (mid + 1) << endl;
			cout << endl;
			return;
		}
		if (data[mid] < target)
			lo = mid + 1;
		if (data[mid] > target)
			hi = mid - 1;
	}
	cout << target << " not found in the array!!!" << endl;
	cout << endl;
	return;
}

int main()
{
	int data[MAX], size = 0, i = 0, choice = 0, target = 0;
	bool flag1 = true, flag2;
start:
	i = 0;
	flag2 = true;
	cout << "***************************************" << endl;
	cout << "*********Sorting and Searching*********" << endl;
	cout << "***************************************" << endl;
	cout << endl;
	cout << "***************************************" << endl;
	cout << "Enter the size of the array(MAX 50): ";
	cin >> size;
	cout << "***************************************" << endl;
	cout << endl;
	if (size > MAX)
	{
		cout << "Error: Entered size greater than Maximum permissible size!!!" << endl;
		cout << endl;
		goto restart;
	}
	if (size < 1)
	{
		cout << "Error: Entered size less than 1!!!" << endl;
		cout << endl;
		goto restart;
	}
	cout << "Enter the elements of the array..." << endl;
	while (i < size)
	{
		cin >> data[i];
		i = i + 1;
	}
	cout << endl;
	while (flag1)
	{
		cout << "***************************************" << endl;
		cout << "1. Linear Search" << endl;
		if (!flag2)
			cout << "2. Binary Search" << endl;
		else
			cout << "2. Binary Search (Warning: Array may not be sorted!!!)" << endl;
		if (flag2)
			cout << "3. Bubble sort" << endl;
		else
			cout << "3. Bubble sort (Array already sorted once!!!)" << endl;
		if (flag2)
			cout << "4. Selection sort" << endl;
		else
			cout << "4. Selection sort (Array already sorted once!!!)" << endl;
		if (flag2)
			cout << "5. Insertion sort" << endl;
		else
			cout << "5. Insertion sort (Array already sorted once!!!)" << endl;
		if (flag2)
			cout << "6. Merge sort" << endl;
		else
			cout << "6. Merge sort (Array already sorted once!!!)" << endl;
		if (flag2)
			cout << "7. Quick sort" << endl;
		else
			cout << "7. Quick sort (Array already sorted once!!!)" << endl;
		cout << "8. Restart (Reinitialise array)" << endl;
		cout << "0. Exit" << endl;
		cout << "***************************************" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		cout << "***************************************" << endl;
		cout << endl;
		switch (choice)
		{
		case 1:
			cout << "Enter target value: ";
			cin >> target;
			cout << endl;
			linearsearch(data, size, target);
			break;
		case 2:
			cout << "Enter target value: ";
			cin >> target;
			cout << endl;
			binarysearch(data, size, target);
			break;
		case 3:
			flag2 = false;
			cout << endl;
			bubblesort(data, size);
			break;
		case 4:
			flag2 = false;
			cout << endl;
			selectionsort(data, size);
			break;
		case 5:
			flag2 = false;
			cout << endl;
			insertionsort(data, size);
			break;
		case 6:
			flag2 = false;
			cout << endl;
			mergesort(data, size);
			break;
		case 7:
			flag2 = false;
			cout << endl;
			quicksort(data, size);
			break;
		case 8:
		restart:
			cout << "Restarting";
			for (int i = 0; i < 4; i++)
			{
				Sleep(1000);
				cout << ".";
			}
			cout << "\033[2J\033[1;1H";
			goto start;
			break;
		case 0:
			flag1 = false;
			break;
		default:
			cout << "Invalid Input!! Please try again.\n"
				 << endl;
			break;
		}
	}
	cout << "\033[2J\033[1;1H";
	cout << "********************************************" << endl;
	cout << "\t\tExiting"
		 << endl;
	cout << "********************************************" << endl;
	return 0;
}
