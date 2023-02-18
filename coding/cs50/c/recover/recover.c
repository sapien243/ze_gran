#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open the file
    FILE *org_file = fopen(argv[1], "r");
    if (org_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int img = -1;
    uint8_t *byts = malloc(512 * sizeof(uint8_t));
    char *name = malloc(8);
    FILE *pic;
    // read through the file in blocks of 512-bytes each
    while (fread(byts, (512 * sizeof(uint8_t)), 1, org_file))
    {
        // if starts a jpg, write to a new file
        if (byts[0] == 0xff && byts[1] == 0xd8 && byts[2] == 0xff && (byts[3] & 0xf0) == 0xe0)
        {
            img++;
            // if not the first image, close the previous file
            if (img > 0)
            {
                fclose(pic);
            }
            sprintf(name, "%03i.jpg", img);
            pic = fopen(name, "w");
            fwrite(byts, (512 * sizeof(uint8_t)), 1, pic);
        }
        // if continuation of jpg, write to the current file
        else if (img >= 0)
        {
            fwrite(byts, (512 * sizeof(uint8_t)), 1, pic);
        }
    }
    // close the last pic file if present and org_file
    if (img >= 0)
    {
        fclose(pic);
    }
    fclose(org_file);

    // free dynamic memory
    free(name);
    free(byts);

    return 0;
}
