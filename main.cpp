#include <iostream>

using namespace std;

void Array_merging(int n, int m, int *pointer_A, int *pointer_B)
{
    int i=0, j=0;
    int *C;
    C = new int [m+n];
    int g=0;
    while (g<m+n)
    {
        if (*pointer_A >= *pointer_B)
        {
            C[g] = *pointer_A;
            pointer_A++;
            g++;
        }
        else
        {
            C[g]=*pointer_B;
            pointer_B++;
            g++;
        }
    }
    cout << "New array: ";
    for (int g=0; g<m+n; g++)
    {
        cout << C[g] << " ";
    }
}

void Merge_Sort (int *X, int f)
{
    int *S;
    S = new int [f];
    int middle = f/2;
    if (f%2==1)
    {
        middle++;
    }
    int h=1, t;
    while (h<f)
    {
        t=h;
        int i=0, j=middle, k=0;
        while (t<=middle)
        {
            while ((i<t) && (j<f) && (j<(middle+t)))
            {
                if (X[i] < X[j])
                {
                    S[k] = X[i];
                    i++;
                    k++;
                }
                else
                {
                    S[k] = X[j];
                    j++;
                    k++;
                }
            }
            while (i<t)
            {
                S[k] = X[i];
                i++;
                k++;
            }
            while (j<(middle+t) && j<f)
            {
                S[k] = X[j];
                j++;
                k++;
            }
            t=t+h;
        }
        h=h*2;
        for (i=0; i<f; i++)
        {
            X[i]=S[i];
        }
    }
    cout << "New array after Merge Sort: ";
    for (int l=0; l<f; l++)
    {
        cout << X[l] << " ";
    }
}

int main()
{
    int n, m, i;
    cin >> n >> m;
    int *A, *B, *pointer_A, *pointer_B;
    A = new int [n];
    B = new int [m];
    for (i=0; i<n; i++)
    {
        cin >> A[i];
    }
    for (i=0; i<m; i++)
    {
        cin >> B[i];
    }
    pointer_A = &(A[0]);
    pointer_B = &(B[0]);
    Array_merging(n, m, pointer_A, pointer_B);
    int f;
    cin >> f;
    int *X;
    X = new int [f];
    for (i=0; i<f; i++)
    {
        cin >> X[i];
    }
    Merge_Sort(X, f);
    return 0;
}
