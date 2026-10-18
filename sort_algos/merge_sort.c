#include <stdio.h>

void merge(int arr[], int i, int mid, int j);
void merge_sort(int arr[], int i, int j);


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
    merge_sort(arr, 0, arr_len-1);
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

void merge_sort(int arr[], int i, int j)
{
    // arr, start, end
    int mid = (i+j)/2;
    if (i<j)
    {
        merge_sort(arr, i, mid);
        merge_sort(arr, mid+1, j);

        merge(arr, i , mid, j);
    }
} 

void merge(int arr[], int i, int mid, int j)
{
    int n1 = mid - i + 1;
    int n2 = j - mid;

    int a1[n1];
    int a2[n2];
    
    for (int x = 0; x<n1; x++)
    {
        a1[x] = arr[i+x];
    }
    for (int y = 0; y<n2; y++)
    {
        a2[y] = arr[mid+1+y];
    }
    
}


