#include <stdio.h>

void selection_sort(int arr[], int arr_len);

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
    selection_sort(arr, arr_len);
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

void selection_sort(int arr[], int arr_len)
{
    // for view, our array is {7,5,3,8,1,9,4,6,2}
    for (int i = 0; i<arr_len;i++)
    {   
        int min_index = i;
        int temp = arr[i];
        int j;
        for (j = i+1; j<arr_len;j++)
        {
            if (arr[j] < arr[min_index]) //
            {
                min_index = j;
            }
        }
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }    
}