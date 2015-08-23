//选择排序
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
    int temp = a;
    a = b;
    b = temp;
}

void select(int array[], int length)
{
    for (int i = 0; i < length; i ++)
    {
        int min = i;
        for (int j = i+1; j < length; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swap(array[i], array[min]);
    }
}

int main()
{
    int array[] = {4, 2, 5, 6, 1, 3};
    int length = 6;
    select(array, length);
    print(array, length);
    return 0;
}
