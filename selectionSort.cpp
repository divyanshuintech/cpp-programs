#include <iostream>
using namespace std;

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    int arr[] = {23, 567, 456, 15, 46, 437, 3, 56, 8, 97};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Given Array : \n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]\n";

    selectionSort(arr, n);
    
    cout << "Sorted Array : \n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]\n";

    return 0;
}