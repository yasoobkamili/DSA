def quickPartition(arr, low, high):
    pivot = arr[low]
    i, j = low, high
    while i < j:
        while arr[i] <= pivot and i < high:
            i += 1
        while arr[j] >= pivot and j > low:
            j -= 1
        if i < j:
            arr[i], arr[j] = arr[j], arr[i]
    arr[low], arr[j] = arr[j], arr[low]
    return j


def quickSort(arr, low, high):
    if low < high:
        partitionIndex = quickPartition(arr, low, high)
        quickSort(arr, low, partitionIndex - 1)
        quickSort(arr, partitionIndex + 1, high)


arr = [4, 6, 2, 5, 7, 9, 1, 3]
low, high = 0, len(arr) - 1
print("Original array:", arr)
quickSort(arr, low, high)
print("Sorted array:", arr, "\nTime complexity: O(nlog(n))\nSpace Complexity: O(1)")
