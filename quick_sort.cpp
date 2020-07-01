#include <iostream>

using namespace std;

#define MaxNumber 1000

int n, a[MaxNumber];

void quick_sort(int left, int right)
{
    if(left > right)
        return;
    int i, j, pivot, temp;
    i = left;
    j = right;
    pivot = a[left];
    while(i != j)
    {
        while(a[j] >= pivot && j > i)   //注意先从右边开始，若从左开始，不能保证与最左边交换的数小于pivot
            j--;
        while(a[i] <= pivot && i < j)
            i++;
        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    a[left] = a[i];
    a[i] = pivot;
    quick_sort(left, i-1);
    quick_sort(i+1, right);
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
    quick_sort(0, n-1);
    for(int j = 0; j < n; j++)
        cout<<a[j]<<' ';
    return 0;
}
