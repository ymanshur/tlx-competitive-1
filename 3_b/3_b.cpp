#include <iostream>
#include <iomanip>

using namespace std;

/* This function takes last element as pivot,
places the pivot element at its correct
position in sorted array, and places
all smaller (smaller than pivot) to left
of pivot and all greater elements to
right of pivot */
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index */
void quickSort(int A[], int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    quickSort(arr, 0, N - 1);

    double res;
    if (N % 2 == 0)
        res = (arr[N / 2] + arr[N / 2 - 1]) / 2.0;
    else
        res = arr[N / 2];

    cout << fixed << setprecision(1) << res << endl;

    return 0;
}
