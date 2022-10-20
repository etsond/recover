#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
//user input

    if (argc != 2)
    {
        printf("usage: ./recover IMAGE\n");
        return 1;
    }
    //glance at the file
    FILE *file_in = fopen(argv[1], "r");
//check if file is good
    if (file_in == NULL)
    {
        printf("Could not open file");
        return 2;
    }
//get the variable and all of the files
    unsigned char buffer[512];
//get the number of images
    int image_count = 0;
//recover image pointer
    FILE *file_out = NULL;
//access the pointer
    char *nameofFile = malloc(8 * sizeof(char));
//go through the 512 bytes
    while (fread(buffer, sizeof(char), 512, file_in))
    {
        //check it
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //writing the file names
            sprintf(nameofFile, "%03i.jpg", image_count);
            //see the file made
            file_out = fopen(nameofFile, "w");
            //how many images
            image_count++;
        }
        if (file_out != NULL)
        {
            fwrite(buffer, sizeof(char), 512, file_out);
        }
    }
    free(nameofFile);
    fclose(file_out);
    fclose(file_in);
    return 0;
}