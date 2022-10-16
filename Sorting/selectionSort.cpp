#include <stdio.h>

void show(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", arr[i]);
    }

    printf("\n");
}
int main()
{

    int arr[9] = {22, 4, 4646, 45, 45, 35, 54, 67, 9};
    int key, temp;
    for (int i = 0; i < 9; i++)
    {
        key = arr[i];

        for (int j = 1 + i; j < 10; j++)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    show(arr);
}