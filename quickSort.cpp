#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = s + count;

    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        if (arr[i] <= pivot)
        {
            i++;
        }
        else if (arr[j] > pivot)
        {
            j--;
        }
        else
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[10] = {1, 25, 124, 34, 132, 54, 23, 7, 46, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given Array : \n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]\n";

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array : \n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]\n";
    return 0;
}