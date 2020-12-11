#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE pixel = image[i][j];
            BYTE b = pixel.rgbtBlue;
            BYTE g = pixel.rgbtGreen;
            BYTE r = pixel.rgbtRed;
            if (b == g && g == r) {
                continue;
            }
            BYTE average = round((r + g + b)/3.0);
            pixel.rgbtBlue = average;
            pixel.rgbtGreen = average;
            pixel.rgbtRed = average;
            image[i][j] = pixel;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE pixel = image[i][j];
            BYTE b = pixel.rgbtBlue;
            BYTE g = pixel.rgbtGreen;
            BYTE r = pixel.rgbtRed;
            int sepiaRed = round(.393 * r + .769 * g + .189 * b);
            int sepiaGreen = round(.349 * r + .686 * g + .168 * b);
            int sepiaBlue = round(.272 * r + .534 * g + .131 * b);
            if (sepiaRed > 255) {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255) {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255) {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
            // image[i][j] = pixel;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGBTRIPLE pixel1 = image[i][j];
            RGBTRIPLE pixel2 = image[i][width -1 - j];
            image[i][j] = pixel2;
            image[i][width - 1 - j] = pixel1;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cp[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            float count = 0;
            int sumr = 0;
            int sumg = 0;
            int sumb = 0;
            for (int ii = i - 1;ii <= i + 1; ii++) {
                if (ii < 0) {
                    continue;
                }
                if (ii >= height) {
                    break;
                }
                for (int jj = j - 1;jj <= j + 1; jj++) {
                    if (jj < 0) {
                        continue;
                    }
                    if (jj >= width) {
                        break;
                    }
                    sumr += image[ii][jj].rgbtRed;
                    sumg += image[ii][jj].rgbtGreen;
                    sumb += image[ii][jj].rgbtBlue;
                    count++;
                }
            }
            int avr = round(sumr / count);
            // printf("simr = %d, count = %f, avt = %d\n", sumr, count, avr);
            int avg = round(sumg / count);
            int avb = round(sumb / count);
            cp[i][j].rgbtRed = avr;
            cp[i][j].rgbtGreen = avg;
            cp[i][j].rgbtBlue = avb;
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = cp[i][j];
        }
    }
    return;
}
