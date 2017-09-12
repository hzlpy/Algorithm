#include <iostream>
using namespace std;

// 交换
void swap(char &a, char &b)
{
    char tmp = a;
    a = b; 
    b = tmp;
}

// 全排列
void calcAllPermutation(char* perm, int from, int to)
{
    if (to<=1) {
        return;
    }
    if (from == to) {
        for (int i=0; i<=to; i++) {
            cout << perm[i];
        }
        cout << endl;
    } else {
        for (int j=from; j<=to; j++) {
            swap(perm[j], perm[from]);
            calcAllPermutation(perm, from+1, to);
            swap(perm[j], perm[from]);
        }
    }
}

int main()
{
    char str[] = {'a', 'b', 'c'};
    calcAllPermutation(str, 0, 2);
    return 0;
}