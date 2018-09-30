#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
// main function to do heap sort
void heapSort(int arr[], int n)
{
    // rearrange array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // extract an element
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout <<endl;
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;
    heapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}
