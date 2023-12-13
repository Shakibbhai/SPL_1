

#include<bits/stdc++.h>
using namespace std;

#pragma pack(push, 1)
typedef struct
{
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct
{
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitsPerPixel;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

int main()
{
    // Pixel values for the RGB image
    vector<vector<double>>R,G,B;
   /* R=RED1();
    G=GREEN1();
    B=BLUE1();*/
    R={{1,1,1,1},
    {2,2,2,2},
    {3,3,3,3}
    };
    G={
        {4,4,4,4},
        {5,5,5,5},
        {6,6,6,6}
        };
    B={
        {7,7,7,7},
        {8,8,8,8},
        {9,9,9,9}
        };
   /* Red:
71.733  -115.670        -99.493 97.338
116.040 -187.117        -160.947        157.461
18.903  -30.482 -26.219 25.651
Green:
7.646   -10.146 -4.262  6.813
1.519   -2.016  -0.847  1.354
4.937   -6.552  -2.752  4.400
Blue:
125.772 -116.981        142.577 96.919
250.487 -232.979        283.955 193.023
41.000  -38.134 46.478  31.594



     R={{71.733, -115.670, -99.493,97.338},{116.04,-187.11,-160.95,157.44},{18.9,-30.48,-26.22,25.651}};
    G={{125.77,-116.9,142.57,96.91},{250.487 ,-232.979 , 283.955, 193.023},{41.000 , -38.134 ,46.478 , 31.594}};
    B={{7.646 , -10.146, -4.262 , 6.813},{1.519 ,  -2.016 , -0.847 , 1.354},{4.937 ,  -6.552 , -2.752  ,4.400}};*/

    int h= R.size();

    /*float R[3][4] = {{1,1,1,1},{1,2,3,3},{1.1,3.5,6,7}};
    float G[3][4] = {{69,122,122,122},{255,255,255,200},{24,36.3,46.4,56.5}};
    float B[3][4] = {{9,8,7,6},{1,1,2,2},{3,4.4,5.5,6.6}};*/

    // BMP image dimensions for square
    int width =h;
    int height =h;

    // BMP header data
    BMPHeader bmpHeader = {0};
    bmpHeader.type = 0x4D42;
    bmpHeader.size = sizeof(BMPHeader) + sizeof(BMPInfoHeader) + width * height * 3;
    bmpHeader.offset = sizeof(BMPHeader) + sizeof(BMPInfoHeader);

    // BMP info header data
    BMPInfoHeader bmpInfoHeader = {0};
    bmpInfoHeader.size = sizeof(BMPInfoHeader);
    bmpInfoHeader.width = width;
    bmpInfoHeader.height = height;
    bmpInfoHeader.planes = 1;
    bmpInfoHeader.bitsPerPixel = 24;
    bmpInfoHeader.compression = 0;
    bmpInfoHeader.imageSize = width * height * 3;
    bmpInfoHeader.xPixelsPerMeter = 0;
    bmpInfoHeader.yPixelsPerMeter = 0;
    bmpInfoHeader.colorsUsed = 0;
    bmpInfoHeader.colorsImportant = 0;

    // Create the BMP file
    FILE* file = fopen("aaaaaaaaaa.bmp", "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);

    // Write pixel data
    for (int y = height - 1; y >= 0; y--)
    {
        for (int x = 0; x < width; x++)
        {
            uint8_t r = R[y][x] * 255;
            uint8_t g = G[y][x] * 255;
            uint8_t b = B[y][x] * 255;

            fwrite(&b, sizeof(uint16_t), 1, file);
            fwrite(&g, sizeof(uint16_t), 1, file);
            fwrite(&r, sizeof(uint16_t), 1, file);
        }
    }

    fclose(file);

    return 0;
}


