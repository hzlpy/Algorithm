#include <iostream>
using namespace std;

void print(int array[], int length)
{
    for (int i = 0; i < length; ++ i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void mergeArray(int array[], int beg, int mid, int end, int temp[])
{
    int i = beg;
    int j = mid + 1;
    int m = mid;
    int n = end;
    int k = 0;
    while (i <= m && j <= n)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = array[j];
            k++;
            j++;
        }
        while (i <= m)
        {
            temp[k] = array[i];
            k++;
            i++;
        }
        while (j <= n)
        {
            temp[k] = array[j];
            k++;
            j++;
        }
        for (int i=0; i<k; i++)
        {
            array[beg + i] = temp[i];
        }
    }
}

void mergeSort(int array[], int beg, int end, int temp[])
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(array, beg, mid, temp);
        mergeSort(array, mid+1, end, temp);
        mergeArray(array, beg, mid, end, temp);
    }
}

void merge(int array[], int length)
{
    int beg = 0;
    int end = length - 1;
    int mid = (beg + end) / 2;
    int temp[length];
    mergeSort(array, beg, end, temp);
}

int main()
{
    int array[] = {4, 2, 5, 6, 1, 3};
    int length = 6;
    merge(array, length);
    print(array, length);
    return 0;
}
