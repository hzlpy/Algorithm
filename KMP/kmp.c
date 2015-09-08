#include <stdio.h>
#include <malloc.h>

void print(int array[], int length)
{
    int i = 0;
    for (i = 0; i < length; ++ i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* getNext(char s[], int length)
{
    int pos;
    int cn;
    int *next = (int*)malloc(sizeof(int)*length);
    next[0] = -1;
    next[1] = 0;
    pos = 2;
    cn = 0;
    while (pos < length)
    {
        if (s[pos-1] == s[cn])
        {
            cn ++;
            next[pos] = cn;
            pos ++;
        }
        else if (cn > 0)
        {
            cn = next[cn];
        }
        else
        {
            next[pos] = 0;
            pos ++;
        }
    }
    return next;
}

int getIndexof(char *str, int len1, char *match, int len2)
{
    int i,j;
    int *next = getNext(match, len2);
    if (str == NULL || match == NULL || len2 < 1 || len1 < len2)
    {
        return -1;
    }
    i = j = 0;
    while (i < len1 && j < len2)
    {
        if (str[i] == match[j])
        {
            i++;
            j++;
        }
        else if (next[j] == -1)
        {
            i++;
        }
        else
        {
            j = next[j];
        }
    }
    return j == len2 ? (i-j) : -1;
}

int main()
{
    char str[] = {'a','1','2','3','1','2','4','b','e'};
    char match[] = {'1','2','3','1','2','4','b'};
    int *next = getNext(match, 7);
    //print(next, 7);
    int index = getIndexof(str, 9, match, 7);
    printf("%d \n", index);
    return 0;
}
