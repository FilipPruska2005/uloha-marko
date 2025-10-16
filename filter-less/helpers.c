#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen +  image[i][j].rgbtGreen)/3.0;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            grayscale([i], [j],image[i][j]);
            image[i][j].rgbtRed += 100;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
            {
            int temp = image[i][j];
            image[i][j] = image[i][width-j];
            image[i][width-j] = temp;
            }
        }


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width]
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            {
            copy[i][j] = image[i][j];
            }
    }
    for (int i = 0; i < height/2; i++)
    {
        for (int j = 0; j < widht/2; j++)
            {
                for(int k = 0; k<2;k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        copy[i+k][j+l];
                    }
                }

            }
    }
    return;
}
