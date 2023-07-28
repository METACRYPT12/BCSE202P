/* C++ implementation of QuickSort by taking first element
 * as pivot */
#include <bits/stdc++.h>
using namespace std;

/*This function takes first element as pivot, the function
places the pivot element(first element) on its sorted
position and all the element lesser than pivot will placed
left to it, and all the element greater than pivot placed
right to it.*/

int partition(int arr[], int low, int high)
{

    // First element as pivot
    int pivot = arr[low];
    int st = low;   // st points to the starting of array
    int end = high; // end points to the ending of the array
    int k = high;
    for (int i = high; i > low; i--)
    {
        if (arr[i] > pivot)
            swap(arr[i], arr[k--]);
    }
    swap(arr[low], arr[k]);
    // As we got pivot element index is end
    // now pivot element is at its sorted position
    // return pivot element index (end)
    return k;
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    // If low is lesser than high
    if (low < high)
    {
        // idx is index of pivot element which is at its
        // sorted position
        int idx = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, idx - 1);
        quickSort(arr, idx + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}

// This Code is contributed by Harsh Raghav
