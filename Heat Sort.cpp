#include <iostream>

using namespace std;

void Helper_function (int A[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && A[left] > A[largest])
        largest = left;

    if (right < n && A[right] > A[largest])
        largest = right;

    if (largest != i)
    {
        swap(A[i], A[largest]);

        Helper_function(A, n, largest);
    }
}

void Heap_Sort(int A[], int n)
{
    for (int i=n/2 - 1; i>=0; i--)
        Helper_function(A, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(A[0],A[i]);
        Helper_function(A, i, 0);
    }
    cout << "Sorted array is: ";
    for (int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i=0; i<n; i++)
    {
        cin >> A[i];
    }
    Heap_Sort(A, n);
    return 0;
}
