//快速排序
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

int adjustArray(int array[], int beg, int end)
{
    int i = beg;
    int j = end;
    int x = array[beg];

    while (i < j)
    {
        while (i < j && array[j] >= x)
        {
            j --;
        }
        if (i < j)
        {
            array[i] = array[j];
            i ++;
        }

        while (i < j && array[i] < x)
        {
            i ++;
        }
        if (i < j)
        {
            array[j] = array[i];
            j --;
        }
    }
    array[i] = x;
    return i;
}

void quick_sort(int array[], int beg, int end)
{
    if (beg < end)
    {
        int i = adjustArray(array, beg, end);
        quick_sort(array, beg, i-1);
        quick_sort(array, i+1, end);
    }
}

int main()
{
    int array[] = {4, 2, 5, 6, 1, 3};
    int beg = 0;
    int end = 5;
    int length = 6;
    quick_sort(array, beg, end);
    print(array, length);
    return 0;
}
