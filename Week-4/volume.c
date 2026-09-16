#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "rb");
    if (src == NULL)
    {
        printf("Could not open file.\n");
        printf("the alloted memory was %p\n", src);
        return 1;    
    }

    FILE *dst = fopen(argv[2], "wb");
    if (dst == NULL)
    {
        printf("Could not open file. \n");
    }

    float factor = atof(argv[3]);

    unsigned char header_data[44];

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

    int16_t buffer;
    while (fread(&buffer, 2, 1, src) != 0)
    {
        buffer *= factor;
        fwrite(&buffer, 2, 1, dst);
    }

    fclose(src);
    fclose(dst);
}