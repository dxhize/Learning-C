#include <stdio.h>

void bubble_sort(int arr[], int arr_len);

int main(void)
{
    int arr[] = {7,5,3,8,1,9,4,6,2};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    
    // printing the initial array 
    printf("initial array: ");
    printf("{");
    for (int i = 0; i < arr_len - 1; i++)
    {
        printf("%i,",arr[i]);
    }
    printf("%i",arr[arr_len-1]);
    printf("}");
    printf("\n");
    bubble_sort(arr, arr_len);
    // printing the final array
    printf("final array: ");
    printf("{");
    for (int i = 0; i < arr_len - 1; i++)
    {
        printf("%i,",arr[i]);
    }
    printf("%i",arr[arr_len-1]);
    printf("}");
    printf("\n");
}

void bubble_sort(int arr[], int arr_len)
{
    int swapped = 1;
    while (swapped == 1)
    {
        swapped = 0;
        // first we need to compare the arr[i] with arr[i+1] and if passes condition we make a swap and repeat
        // total number of comparisons per n elements are n/2;
        for (int i = 0; i < arr_len-1; i++)
        {
            if (arr[i]>arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped = 1;
            }
        }
    }
}