#include <stdio.h>

void merge_sort(int *arr, int low, int high);
void merge(int *arr, int left, int mid, int right);

void print_arr(int *arr,int size)
{
    for (int i = 0, j = size; i<j; i++)
    {
        printf("%i,",arr[i]);
    } printf("%i", arr[size]);
}

int main(void)
{
    int arr[] = {9,6,1,4,3,7,2};
    int arr_size = 7;   
    int left = 0;
    int right = arr_size-1; 

    printf("initial array: [");
    print_arr(arr, arr_size-1);
    printf("]");
    merge_sort(arr,left,right);
    printf("\n");
    printf("final array: [");
    print_arr(arr, arr_size-1);
    printf("]\n");
}

void merge_sort(int *arr, int left, int right)
{
    if (!(left<right))
    {
        return;
    }
    else
    {
        int mid = left + (right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int *arr, int left, int mid, int right)
{
    int i = left;
    int j = mid+1;
    int tmp[right-left+1];
    int k = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k] = arr[i];
            i++;
        }
        else
        {
            tmp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i<=mid)
    {
        tmp[k] = arr[i];
        i++;
        k++;
    }
    while (j<=right)
    {
        tmp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = 0; p<(right-left+1); p++)
    {
        arr[left + p] = tmp[p];
    }
} 