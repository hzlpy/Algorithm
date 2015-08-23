//直接插入排序
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

void insertSort(int array[], int length)
{
    int i, j, k;
    for (i = 1; i < length; ++ i)
    {
        for (j = i-1; j >= 0; j --)
        {
            if (array[j] < array[i])
            {
                break;
            }
        }
        if (j != i-1)
        {
            int temp = array[i];
            for (k = i-1; k > j; k--)
            {
                array[k+1] = array[k];
            }
            array[k+1] = temp;
        }
    }
}



int main()
{
    int array[] = {4, 2, 5, 6, 1, 3};
    int length = 6;
    insertSort(array, length);
    print(array, length);
    return 0;
}
