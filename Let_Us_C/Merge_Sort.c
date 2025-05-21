// merge sort program in C
// CSE-23-46
#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int left = low;
    int right = mid + 1;
    int k = low;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k] = arr[left];
            left++;
            k++;
        }
        else
        {
            temp[k] = arr[right];
            right++;
            k++;
        }
    }
    while (left <= mid)
    {
        temp[k] = arr[left];
        left++;
        k++;
    }
    while (right <= high)
    {
        temp[k] = arr[right];
        right++;
        k++;
    }
    int i;
    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
void print(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[7] = {1, 4, 3, 2, 6, 5, 7};
    int low = 0, high = 6, size = 7;
    print(arr, size);
    mergeSort(arr, 0, size - 1);
    print(arr, size);
}
