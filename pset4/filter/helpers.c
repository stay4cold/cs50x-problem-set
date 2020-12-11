#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            RGBTRIPLE p = image[i][j];
            int r = p.rgbtRed;
            int g = p.rgbtGreen;
            int b = p.rgbtBlue;
            if (r == g && g == b) {
                continue;
            }
            int aver = round((r + g + b) / 3.0);
            image[i][j].rgbtRed = aver;
            image[i][j].rgbtGreen = aver;
            image[i][j].rgbtBlue = aver;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            RGBTRIPLE rgb = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = rgb;
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
            int r = 0;
            int g = 0;
            int b = 0;
            for (int ii = i - 1; ii <= i + 1; ii++) {
                if (ii < 0) {
                    continue;
                }
                if (ii > height - 1) {
                    break;
                }
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    if (jj < 0) {
                        continue;
                    }
                    if (jj > width - 1) {
                        break;
                    }
                    r += image[ii][jj].rgbtRed;
                    g += image[ii][jj].rgbtGreen;
                    b += image[ii][jj].rgbtBlue;
                    count++;
                }
            }
            cp[i][j].rgbtRed = round(r / count);
            cp[i][j].rgbtGreen = round(g / count);
            cp[i][j].rgbtBlue = round(b / count);
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = cp[i][j];
        }
    }
    return;
}

int min(int a, int b) {
    return a > b ? b : a;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cp[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int rx = 0;
            int gx = 0;
            int bx = 0;
            int ry = 0;
            int gy = 0;
            int by = 0;
            RGBTRIPLE tmp[3][3];
            for (int ii = i - 1; ii <= i + 1; ii++) {
                for (int jj = j - 1; jj <= j + 1; jj++) {
                    RGBTRIPLE rgb;
                    if (ii == -1 || ii == height || jj == -1 || jj == width) {
                        rgb.rgbtRed = 0;
                        rgb.rgbtGreen = 0;
                        rgb.rgbtBlue = 0;
                    } else {
                        rgb = image[ii][jj];
                    }
                    tmp[ii + 1 - i][jj + 1 - j] = rgb;
                }
            }
            rx = -1 * tmp[0][0].rgbtRed + tmp[0][2].rgbtRed + 
                 -2 * tmp[1][0].rgbtRed + 2 * tmp[1][2].rgbtRed +
                 -1 * tmp[2][0].rgbtRed + tmp[2][2].rgbtRed;
            ry = -1 * tmp[0][0].rgbtRed + -2 * tmp[0][1].rgbtRed + -1 * tmp[0][2].rgbtRed +
                 tmp[2][0].rgbtRed + 2 * tmp[2][1].rgbtRed + tmp[2][2].rgbtRed;
            gx = -1 * tmp[0][0].rgbtGreen + tmp[0][2].rgbtGreen + 
                 -2 * tmp[1][0].rgbtGreen + 2 * tmp[1][2].rgbtGreen +
                 -1 * tmp[2][0].rgbtGreen + tmp[2][2].rgbtGreen;
            gy = -1 * tmp[0][0].rgbtGreen + -2 * tmp[0][1].rgbtGreen + -1 * tmp[0][2].rgbtGreen +
                 tmp[2][0].rgbtGreen + 2 * tmp[2][1].rgbtGreen + tmp[2][2].rgbtGreen;
            bx = -1 * tmp[0][0].rgbtBlue + tmp[0][2].rgbtBlue + 
                 -2 * tmp[1][0].rgbtBlue + 2 * tmp[1][2].rgbtBlue +
                 -1 * tmp[2][0].rgbtBlue + tmp[2][2].rgbtBlue;
            by = -1 * tmp[0][0].rgbtBlue + -2 * tmp[0][1].rgbtBlue + -1 * tmp[0][2].rgbtBlue +
                 tmp[2][0].rgbtBlue + 2 * tmp[2][1].rgbtBlue + tmp[2][2].rgbtBlue;
            cp[i][j].rgbtRed = min(round(sqrt(rx*rx + ry*ry)), 255);
            cp[i][j].rgbtGreen = min(round(sqrt(gx*gx + gy*gy)), 255);
            cp[i][j].rgbtBlue = min(round(sqrt(bx*bx + by*by)), 255);
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = cp[i][j];
        }
    }
    return;
}
