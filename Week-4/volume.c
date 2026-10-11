#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    } // these are fail safe mechs

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL)
    {
        printf("Could not open file.\n");
        printf("the alloted memory was %p\n", src);
        return 1;    
    } // basically if fopen allots memory in 0x00 memory address, the execution is terminated.

    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL)
    {
        printf("Could not open file. \n");
    }// similar

    float factor = atof(argv[3]);// it converts the commandline argument factor in string data type to a float

    unsigned char header_data[44]; // its kinda a buffer storage of fixed size,

    size_t characters_read1 = fread(header_data, 1, 44, src);
    if (characters_read1 != 44)
    {
        printf("Error reading the input file. \n");
        return 1;
    }

    size_t characters_wrote1 = fwrite(header_data, 1, 44, dst); 
    if (characters_wrote1 != 44)
    {
        printf("Error writing header data. \n");
        return 1;
    }

    uint32_t buffer; // this is the buffer which quickly reads the data, from src, 
    while (fread(&buffer, 2, 1, src) != 0)
    {
        buffer *= factor; // here it gets multiplied by the factor 
        fwrite(&buffer, 2, 1, dst);// and writes into the dst file (output)
    }

    fclose(src);
    fclose(dst);
}