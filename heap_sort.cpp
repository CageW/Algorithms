#include <iostream>

using namespace std;

#define MaxNumber 1000

int n, a[MaxNumber];

void adjust(int i, int size)
{
    int maxMem = i;
    int lchild = 2 * i + 1;
    int rchild = lchild + 1;
    if(lchild <= size - 1 && a[maxMem] < a[lchild])
        maxMem = lchild;
    if(rchild <= size - 1 && a[maxMem] < a[rchild])
        maxMem = rchild;
    if(maxMem != i)
    {
        int temp = a[i];
        a[i] = a[maxMem];
        a[maxMem] = temp;
        adjust(maxMem, size);
    }
}

void heap_build()
{
    int i = n / 2 - 1;
    while(i >= 0)
    {
        adjust(i, n);
        i--;
    }
}

void heap_sort()
{
    heap_build();
    for(int i = n - 1; i >= 1; i--)
    {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        adjust(0, i);   //注意需要修改size
    }
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    heap_sort();
    for(int j = 0; j < n; j++)
        cout<<a[j]<<' ';
    return 0;
}
