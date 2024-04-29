#include "helpers.h"
#include <math.h>

void cap_values(int *sepiaRed, int *sepiaGreen, int *sepiaBlue);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // TODO
            // Take average of red, green, and blue
            float average =
                ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            // Update pixel values
            image[i][j].rgbtRed = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtBlue = round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // TODO
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            // Compute sepia values
            int sepiaRed =
                round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen =
                round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue =
                round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            // Cap Values at 255
            cap_values(&sepiaRed, &sepiaGreen, &sepiaBlue);

            // Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

void cap_values(int *sepiaRed, int *sepiaGreen, int *sepiaBlue)
{
    if (*sepiaRed > 255)
    {
        *sepiaRed = 255;
    }
    if (*sepiaGreen > 255)
    {
        *sepiaGreen = 255;
    }
    if (*sepiaBlue > 255)
    {
        *sepiaBlue = 255;
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // TODO
            // Swap Pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Apply Box Blur to pixels in copy
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;

            // Loop through each pixel and its surrounding pixels
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    // Check if surrounding pixels are within bounds of image
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {

                        sumRed = sumRed + copy[k][l].rgbtRed;
                        sumGreen = sumGreen + copy[k][l].rgbtGreen;
                        sumBlue = sumBlue + copy[k][l].rgbtBlue;

                        count++;
                    }
                }
            }

            // Average RGB
            int averageRed = round(sumRed / (float) count);
            int averageGreen = round(sumGreen / (float) count);
            int averageBlue = round(sumBlue / (float) count);

            // set original pixel to average value
            image[i][j].rgbtRed = averageRed;
            image[i][j].rgbtGreen = averageGreen;
            image[i][j].rgbtBlue = averageBlue;
        }
    }
    return;
}
