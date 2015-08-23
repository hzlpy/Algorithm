//冒泡排序
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

void swap(int &a, int &b)
{
    //a = a + b;
    //b = a - b;
    //a = a - b;
    //或者
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void bubble(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int flag = length;
        if (flag != 0)
        {
            int k = flag;
            flag = 0;
            for (int j = 0; j < k-i; j++)
            {
                if (array[j] > array[j+1])
                {
                    swap(array[j], array[j+1]);
                    flag = j;
                }
            }
        }
    }
}

int main()
{
    int array[] = {4, 2, 5, 6, 1, 3};
    int length = 6;
    bubble(array, length);
    print(array, length);
    return 0;
}
