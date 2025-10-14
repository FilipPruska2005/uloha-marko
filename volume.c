// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE8;
typedef uint16_t BYTE16;
// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE8 b;
    BYTE16 a;
    for(int i=0; i<44 ; i++)
    {
        fread(&b, sizeof(b), 1, input);
        fwrite(&b, sizeof(b), 1, output);

    }
    // TODO: Read samples from input file and write updated data to output file
    while(fread(&a, sizeof(a), 2, input) != 0)
    {
        fwrite(&a, sizeof(a), 2, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
