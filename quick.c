//Khushi Desai
//21BCP264
//quick sort

#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *a, int l, int r)
{
    if (l < r)
    {
        int i = l;
        int j = r;
        int pivot = a[l];
        while (i < j)
        {
            while (a[i] <= pivot && i < r)
                i++;
            while (a[j] > pivot)
                j--;
            if (i < j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[l];
        a[l] = a[j];
        a[j] = temp;
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, r);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quick_sort(a, 0, n - 1);

    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
