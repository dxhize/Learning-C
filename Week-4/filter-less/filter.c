#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


#pragma pack(1)
typedef struct
{
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits_per_pixels;
    uint8_t unused_rest[24];
} CustomInfoHeaderStruct;

typedef struct
{
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} pix_data;

#pragma pack()

void grayscale(uint32_t height, uint32_t width, pix_data pix_data_arr[height][width]);
void sepia(uint32_t height, uint32_t width, pix_data pix_data_arr[height][width]);
void reflect(uint32_t height, uint32_t width, pix_data pix_data_arr[height][width]);
void blur(uint32_t height, uint32_t width, pix_data pix_data_arr[height][width]);
int max(int i, int j);
int min(int i, int j);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./filter [flag] input.bmp output.bmp\n");
        return 1;
    }

    FILE *src = fopen(argv[2], "rb");
    if (src == NULL)
    {
        printf("Could not open file.\n");
        printf("the alloted memory was %p\n", src);
        return 1;    
    }

    FILE *dst = fopen(argv[3], "wb");
    if (dst == NULL)
    {
        printf("Could not open file. \n");
        return 1;
    }

    char flag = argv[1][1];

    unsigned char file_header[14];
    

    size_t characters_read = fread(file_header, 1, 14, src);
    if (characters_read != 14)
    {
        printf("Could'nt read Header data. \n");
        return 1;
    }
    printf("read header success\n");

    size_t characters_wrote = fwrite(file_header, 1, 14, dst);
    if (characters_wrote != 14)
    {
        printf("Error while writing Header data. \n");
        return 1;
    }
    printf("write header success\n");
    // till here we just read and wrote the headers from og file to new dst

    CustomInfoHeaderStruct info_header;

    size_t characters_read1 = fread(&info_header, sizeof(CustomInfoHeaderStruct), 1, src);
    if (characters_read1 != 1)
    {
        printf("Error reading Info Header data_1. \n");
        return 1;
    }
    printf("read info_header success\n");

    int bit_width = info_header.width;
    int bit_height = info_header.height;
    printf("fetched data from Info-Header.\n");
    //extracting the values from our custom struct
    if (info_header.bits_per_pixels != 24)
    {
        printf("Unsupported file structure. Please use 24-bit BMP file formatting. Terminating execution! \n");
        return 1;
    }// a quick safety check for the bmp formatting
    printf("24-bit format verified!\n");

    pix_data pix_data_arr[bit_height][bit_width];
    int padding = (4 - (bit_width * 3) % 4) % 4;

    uint32_t data_read1 = 0;
    uint32_t p = 0;

    for (int i = 0; i<bit_height; i++)
    {
        for (int j = 0; j<bit_width; j++)
        {
            fread(&pix_data_arr[i][j], sizeof(pix_data), 1, src);
            data_read1++;
        }
        fseek(src, padding, SEEK_CUR);
        p += padding;
    } 
    // till here the pix_data_arr will be filled up with the pixel data, and can be used futher
    if (data_read1 != bit_width*bit_height)
        {
            printf("Unable to read Pixel data. Terminating execution.\n");
            return 1;
        }
    if (p!=bit_height*padding)
        {
            printf("Encountered an Error while skipping padding bytes. Contact the Dumb Developer!\n");
            return 1; 
        }

    printf("image data copied into memory success\n");

    if (flag == 'g')
    {
        grayscale(bit_height, bit_width, pix_data_arr);
    }
    if (flag == 's')
    {
        sepia(bit_height, bit_width, pix_data_arr);
    }
    if (flag == 'r')
    {
        reflect(bit_height, bit_width, pix_data_arr);
    }
    if (flag == 'b')
    {
        blur(bit_height, bit_width, pix_data_arr);
    }

    size_t data_wrote1 = fwrite(&info_header, sizeof(CustomInfoHeaderStruct), 1, dst);
    if (data_wrote1 != 1)
    {
        printf("Error while Writing Info Header.\n");
        return 1;
    }
    printf("write info_header dst success\n");

    uint8_t zero_padder = 0;
    int write_safe = 0;
    printf("starting image_data write\n");

    for (int i = 0; i<bit_height; i++)
    {
        for (int j = 0; j<bit_width; j++)
        {
            fwrite(&pix_data_arr[i][j], sizeof(pix_data), 1, dst);
            write_safe++;
        }
        fwrite(&zero_padder, sizeof(uint8_t), padding, dst);
    }
    if (write_safe != bit_width*bit_height)
    {
        printf("encountered error while writing image_data.\n");
        return 1;
    }
    printf("File created!\n");
    printf("file details: \n");
    printf("    Resolution: %ix%i\n", bit_width, bit_height);
    printf("    Bits per pixel: %i\n", info_header.bits_per_pixels);
    printf("    File format: 24-Bit BMP\n");

    fclose(src);
    fclose(dst);
}

void grayscale(uint32_t height, uint32_t width, pix_data pix_data_arr[height][width])
{
    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j<width; j++)
        {
            uint8_t avg_clr = (pix_data_arr[i][j].blue + pix_data_arr[i][j].green + pix_data_arr[i][j].red)/3;
            pix_data_arr[i][j].blue = avg_clr;
            pix_data_arr[i][j].green = avg_clr;
            pix_data_arr[i][j].red = avg_clr;
        }
    }
}

void sepia(uint32_t height, uint32_t width, pix_data pix_data_arr[height][width])
{
    uint32_t sepiaRed;
    uint32_t sepiaGreen;
    uint32_t sepiaBlue;
    
    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j<width; j++)
        {
            sepiaRed = .393 * pix_data_arr[i][j].red + .769 * pix_data_arr[i][j].green + .189 * pix_data_arr[i][j].blue;
            sepiaGreen = .349 * pix_data_arr[i][j].red + .686 * pix_data_arr[i][j].green + .168 * pix_data_arr[i][j].blue;
            sepiaBlue = .272 * pix_data_arr[i][j].red + .534 * pix_data_arr[i][j].green + .131 * pix_data_arr[i][j].blue;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            pix_data_arr[i][j].red = sepiaRed;
            pix_data_arr[i][j].green = sepiaGreen;
            pix_data_arr[i][j].blue = sepiaBlue;
        }
    }
}

void reflect(uint32_t height, uint32_t width, pix_data pix_data_arr[height][width])
{
    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j<width/2; j++)
        {
            pix_data tmp;
            tmp = pix_data_arr[i][j];
            pix_data_arr[i][j] = pix_data_arr[i][width-1-j];
            pix_data_arr[i][width-1-j] = tmp;
        }
    }
}

int max(int i, int j)
{
    if (i>j)
    {
        return i;
    }
    else if (i == j)
    {
        return j;
    }
    else
    {
        return j;
    }
}
int min(int i, int j)
{
    if (i<j)
    {
        return i;
    }
    else if (i == j)
    {
        return j;
    }
    else
    {
        return j;
    }
}

void blur(uint32_t height, uint32_t width, pix_data pix_data_arr[height][width])
{
    pix_data img_cpy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img_cpy[i][j] = pix_data_arr[i][j];
        }
    }   // till here we made a copy of the og array

    for (int i = 0; i<height; i++)
    {
        for (int j = 0; j<width; j++)
        {
            int row_start = max(0, i-1);
            int row_end = min(width -1, i+1);

            int col_start = max(0, j-1);
            int col_end = min(height-1, j+1);
            int row_arr[row_end - row_start + 1];
            int col_arr[col_end - col_start + 1];
            if (row_end - row_start + 1 == 2)
            {
                row_arr[0] = row_start;
                row_arr[1] = row_end;
            }
            if (row_end - row_start + 1 == 3)
            {
                row_arr[0] = row_start;
                row_arr[1] = row_end -1;
                row_arr[2] = row_end;
            }
            if (col_end - col_start + 1 == 2)
            {
                col_arr[0] = col_start;
                col_arr[1] = col_end;
            }
            if (col_end - col_start + 1 == 3)
            {
                col_arr[0] = col_start;
                col_arr[1] = col_end -1;
                col_arr[2] = col_end;
            }
            uint32_t ttl_red = 0;
            uint32_t ttl_blue = 0;
            uint32_t ttl_green = 0;

            for (int j = 0; j<col_end - col_start + 1; j++)     
            {
                for (int k = 0; k<row_end - row_start + 1; k++)
                {
                    ttl_red += img_cpy[col_arr[j]][row_arr[k]].red;
                    ttl_green += img_cpy[col_arr[j]][row_arr[k]].green;
                    ttl_blue += img_cpy[col_arr[j]][row_arr[k]].blue; 
                } 
            }
            uint8_t avg_red = ttl_red/((row_end - row_start + 1) * (col_end - col_start +1));
            uint8_t avg_blue = ttl_blue/((row_end - row_start + 1) * (col_end - col_start +1));
            uint8_t avg_green = ttl_green/((row_end - row_start + 1) * (col_end - col_start +1));

            pix_data_arr[i][j].red = avg_red;
            pix_data_arr[i][j].green = avg_green;
            pix_data_arr[i][j].blue = avg_blue;
        }
    }


}

