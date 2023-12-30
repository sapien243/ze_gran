#include <stdint.h>
#include <math.h>
#include <string.h>

#include "helpers.h"

// Prototypes for functions used
RGBTRIPLE alblur(uint8_t a[], uint8_t b[], uint8_t c[], uint8_t d[], uint8_t e[],
                 uint8_t f[], uint8_t g[], uint8_t h[], uint8_t i[], int div);
RGBTRIPLE aledge(uint8_t a[], uint8_t b[], uint8_t c[], uint8_t d[], uint8_t e[],
                 uint8_t f[], uint8_t g[], uint8_t h[], uint8_t i[]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Scan through each pixel, get the average RGB values and assign the average to each
            float a = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            uint8_t b = round(a / 3);
            image[i][j].rgbtBlue = b;
            image[i][j].rgbtGreen = b;
            image[i][j].rgbtRed = b;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int b = width / 2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < b; j++)
        {
            // Scan through each pixel, and swap them with its reflect
            int k = width - (1 + j);
            RGBTRIPLE copy = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = copy;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create an array and set it to 0
    uint8_t copy[height + 2][width + 2][3];
    memset(copy, 0, ((height + 2) * (width + 2) * 3));
    // Copy the image data to the array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i + 1][j + 1][0] = image[i][j].rgbtBlue;
            copy[i + 1][j + 1][1] = image[i][j].rgbtGreen;
            copy[i + 1][j + 1][2] = image[i][j].rgbtRed;
        }
    }
    // The copy of the image has a single-pixel border with RGB values of 0
    // This allows the alblur function to take 9 values and a divisor for each pixel
    // without accessing non-values
    int div;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Scan through each pixel
            // Assign divisor to the alblur function
            // 9 for middle pixels, 6 for side pixels and 4 for corner pixels
            if ((i == 0 && j == 0) || (i == 0 && j == (width - 1)) ||
                (i == (height - 1) && j == 0) || (i == (height - 1) && j == (width - 1)))
            {
                div = 4;
            }
            else if (i == 0 || i == (height - 1) || j == 0 || j == (width - 1))
            {
                div = 6;
            }
            else
            {
                div = 9;
            }
            // The function takes values of the surrounding pixels from the copy and the divisor
            // and then returns the edited pixel
            image[i][j] = alblur(copy[i][j], copy[i][j + 1], copy[i][j + 2],
                                 copy[i + 1][j], copy[i + 1][j + 1], copy[i + 1][j + 2],
                                 copy[i + 2][j], copy[i + 2][j + 1], copy[i + 2][j + 2], div);
        }
    }
    return;
}
RGBTRIPLE alblur(uint8_t a[], uint8_t b[], uint8_t c[], uint8_t d[], uint8_t e[],
                 uint8_t f[], uint8_t g[], uint8_t h[], uint8_t i[], int div)
{
    RGBTRIPLE img;
    // The function takes the arguments, gets each average for each color value,
    // assigns them to img and returns img
    float sum[3];
    for (int k = 0; k < 3; k++)
    {
        sum[k] = a[k] + b[k] + c[k] + d[k] + e[k] + f[k] + g[k] + h[k] + i[k];
    }
    img.rgbtBlue = round(sum[0] / div);
    img.rgbtGreen = round(sum[1] / div);
    img.rgbtRed = round(sum[2] / div);
    return img;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create an array and set it to 0
    uint8_t copy[height + 2][width + 2][3];
    memset(copy, 0, ((height + 2) * (width + 2) * 3));
    // Copy the image data to the array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i + 1][j + 1][0] = image[i][j].rgbtBlue;
            copy[i + 1][j + 1][1] = image[i][j].rgbtGreen;
            copy[i + 1][j + 1][2] = image[i][j].rgbtRed;
        }
    }
    // The copy of the image has a border with pixel values of 0
    // This allows the alblur function to take 9 values and a divisor for each pixel
    // without accessing non-values
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Scan through each pixel
            // The function takes values of the surrounding pixels from the copy
            // and then returns the edited pixel
            image[i][j] = aledge(copy[i][j], copy[i][j + 1], copy[i][j + 2],
                                 copy[i + 1][j], copy[i + 1][j + 1], copy[i + 1][j + 2],
                                 copy[i + 2][j], copy[i + 2][j + 1], copy[i + 2][j + 2]);
        }
    }
    return;
}
RGBTRIPLE aledge(uint8_t a[], uint8_t b[], uint8_t c[], uint8_t d[], uint8_t e[],
                 uint8_t f[], uint8_t g[], uint8_t h[], uint8_t i[])
{
    RGBTRIPLE img;
    float sumx[3], sumy[3], sum[3];
    // Takes each pixel's RGB values and applies the sobel operator
    for (int k = 0; k < 3; k++)
    {
        sumx[k] = (a[k] * -1) + (b[k] * 0) + (c[k] * 1) +
                  (d[k] * -2) + (e[k] * 0) + (f[k] * 2) +
                  (g[k] * -1) + (h[k] * 0) + (i[k] * 1);
        sumy[k] = (a[k] * -1) + (b[k] * -2) + (c[k] * -1) +
                  (d[k] * 0) + (e[k] * 0) + (f[k] * 0) +
                  (g[k] * 1) + (h[k] * 2) + (i[k] * 1);
    }
    // Limit RGB values to 255
    for (int k = 0; k < 3; k++)
    {
        sum[k] = sqrt((sumx[k] * sumx[k]) + (sumy[k] * sumy[k]));
        if (sum[k] > 255)
        {
            sum[k] = 255;
        }
    }
    // Pass the RGB values to img, and return img
    img.rgbtBlue = round(sum[0]);
    img.rgbtGreen = round(sum[1]);
    img.rgbtRed = round(sum[2]);
    return img;
}
