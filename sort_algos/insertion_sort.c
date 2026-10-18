#include <stdio.h>


// prototype
void insertion_sort(int arr[], int arr_len);

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
    insertion_sort(arr, arr_len);
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

void insertion_sort(int arr[], int arr_len)
{

    int j; 
    // lets say our array is {7,3,5,8}
    for (int i = 1; i<arr_len; i++)
    {
        // when i = 1, j = 0, arr[i=1] = 3, arr[j=0] = 7, temp = 3
        // so 7>3, it gets replaced, and the list becomes {3,7,5,8}
        // when i hits 2, j = 1, temp = 5, arr[i=2] = 5, arr[j=1] = 7
        // so 7>5, and j>=0, it shifts back 7, and loop becomes {3,5,7,8} and j becomes 0 now
        // now arr[j=0] = 3 and temp = 5
        j = i - 1;
        int temp = arr[i];
        while (j>=0 && arr[j] > temp)                            
        {
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        } 
    } 
}