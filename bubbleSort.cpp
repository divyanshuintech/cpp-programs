#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
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

    bubbleSort(arr, n);

    cout << "Sorted Array : \n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]\n";

    return 0;
}