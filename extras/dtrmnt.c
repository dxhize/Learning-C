#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

float get_next_float(string *string_ptr);
void print_matrix(int order, float (*matrix)[order]);

int main(void)
{
    // get matrix order
    int matrix_order = get_int("enter matrix-order: ");
    //create a 2d VLA array dynammically to prevent stack overflow
    float (*matrix)[matrix_order] = malloc(matrix_order*matrix_order*sizeof(float));
    if (matrix == NULL)
    {
        return 1;
    }
    printf("enter Row-values in comma seperated manner: 1,2,3,4...\n");

    for (int i = 0; i<matrix_order; i++)
    {
        char *input = get_string("row[%i]: ",i+1);
        char *current_pos = input;
        for (int j = 0; j<matrix_order; j++)
        {
            matrix[i][j] = get_next_float(&current_pos);
        }
    }
    print_matrix(matrix_order, matrix);
    char proceed = get_char("Press 'y' to see result: ");
    if (proceed != 'y')
    {
        return 1;
    }
    // det sign in case of row replacement
    int val_sign = 1;
    float *row_cpy = malloc(matrix_order*sizeof(float));
    if (row_cpy == NULL)
    {
        return 1;
    }

    for (int i = 0; i<matrix_order-1; i++)
    {
        //matrix[row][column]
        int cr_rvi = i; //column row replacement value index
        // find the first greatest target element in the column and save its row_index
        for (int k = i+1; k<matrix_order; k++)
        {
            if (fabs(matrix[k][i]) > fabs(matrix[i][i]))
            {
                cr_rvi = k;
            }
        }
        // first check if anchor_index got replaced
        if (cr_rvi != i)
        {   // if yes, do the row shift with the target element row index
            memcpy(row_cpy,matrix[cr_rvi],matrix_order*sizeof(float)); 
            memcpy(matrix[cr_rvi],matrix[i],matrix_order*sizeof(float));
            memcpy(matrix[i],row_cpy,matrix_order*sizeof(float));
            val_sign *= -1;
        }

        //float anchor = matrix[i][i];
        float factor;  
        // subtract the values of anchor row from target row to get consistent zero under anchor
        for (int k = i; k<matrix_order-1; k++)
        {   
            factor = (matrix[k+1][i])/(matrix[i][i]);
            for (int j = 0; j<matrix_order; j++)
            {
                matrix[k+1][j] -= matrix[i][j]*factor;
            }
        }
    }
    print_matrix(matrix_order, matrix);
    float val_det = 1;
    for (int i = 0; i<matrix_order; i++)
    {
        val_det *= matrix[i][i];
    } val_det *= val_sign;
    printf("Going back to History to ask Albert Einstein!\n");
    printf("Awakening AryaBhatta!\n");
    printf("Calling Nikola Tesla!\n");
    printf("Asking Elon Musk for funds!\n");
    printf("Creating Time Machine!\n");
    printf("Awakening Adolf Hitler!\n");
    printf("Found Answer, Verify Yourself fool!\n");
    printf("\nDet(Matrix) = %f\n",val_det);
}

float get_next_float(string *string_ptr) {
    char *current = *string_ptr;

    // 1. Skip any leading spaces BEFORE the number
    while (*current != '\0' && isspace((unsigned char)*current)) {
        current++;
    }

    // If we hit the end of the string after skipping spaces, stop
    if (*current == '\0') {
        *string_ptr = current;
        return 0.0f;
    }

    char *next_token;
    // 2. Convert the number
    float value = strtof(current, &next_token);

    // 3. Skip any trailing spaces AFTER the number but BEFORE the comma
    while (*next_token != '\0' && isspace((unsigned char)*next_token)) {
        next_token++;
    }

    // 4. If we are sitting on a comma, skip over it
    if (*next_token == ',') {
        next_token++;
    }

    // Update the original string pointer position
    *string_ptr = next_token;

    return value;
}

void print_matrix(int order, float (*matrix)[order])
{
    printf("\n--- Current Matrix State ---\n");
    for (int r = 0; r < order; r++)
    {
        printf("|");
        for (int c = 0; c < order; c++)
        {
            // %8.2f keeps the numbers aligned neatly in columns
            printf("%8.2f ", matrix[r][c]);
        }
        printf("|\n");
    }
    printf("----------------------------\n");
}
