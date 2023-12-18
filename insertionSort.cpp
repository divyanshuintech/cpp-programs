#include <iostream>
using namespace std;

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            {
                // stop
                break;
            }
        }
        arr[j + 1] = temp;
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

    insertionSort(arr, n);

    cout << "Sorted Array : \n[ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << " ]\n";

    return 0;
}