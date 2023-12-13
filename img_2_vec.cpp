#include <iostream>
#include <fstream>
#include <vector>

#pragma pack(push, 1)
struct BMPHeader
{
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
};

struct BMPInfoHeader
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
};
#pragma pack(pop)

std::vector<std::vector<std::vector<uint8_t>>> readBMP(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    BMPHeader header;
    file.read(reinterpret_cast<char*>(&header), sizeof(BMPHeader));

    if (header.type != 0x4D42)
    {
        std::cerr << "Invalid BMP file format." << std::endl;
        return {};
    }

    BMPInfoHeader infoHeader;
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(BMPInfoHeader));

    if (infoHeader.bitsPerPixel != 24)
    {
        std::cerr << "This example only supports 24-bit BMP images." << std::endl;
        return {};
    }

    //file.seekg(header.offset, std::ios::beg);

    int width = infoHeader.width;
    int height = infoHeader.height;
    std::cout<<width<<",,,,"<<height<<std::endl;

    std::vector<std::vector<std::vector<uint8_t>>> imagePixels(height, std::vector<std::vector<uint8_t>>(width, std::vector<uint8_t>(3)));

    for (int i = height - 1; i >= 0; --i)
    {
        for (int j = 0; j < width; ++j)
        {
            file.read(reinterpret_cast<char*>(imagePixels[i][j].data()), 3);
            /*std::cout << "RGB values at position (" << j << ", " << i << "): "
                      << "R=" << static_cast<int>(imagePixels[i][j][0]) << " "
                      << "G=" << static_cast<int>(imagePixels[i][j][1]) << " "
                      << "B=" << static_cast<int>(imagePixels[i][j][2]) << std::endl;*/
        }
    }

    return imagePixels;
}

int main()
{
    // Replace "your_image.bmp" with the path to your BMP file
    std::string filename = "yoo.bmp";

    std::vector<std::vector<std::vector<uint8_t>>> image = readBMP(filename);

    if (!image.empty())
    {
        // Save the vectors
        std::vector<std::vector<uint8_t>> redVector;
        std::vector<std::vector<uint8_t>> greenVector;
        std::vector<std::vector<uint8_t>> blueVector;

        for (const auto& row : image)
        {
            std::vector<uint8_t> redRow;
            std::vector<uint8_t> greenRow;
            std::vector<uint8_t> blueRow;

            for (const auto& pixel : row)
            {
                redRow.push_back(pixel[0]);
                greenRow.push_back(pixel[1]);
                blueRow.push_back(pixel[2]);
            }

            redVector.push_back(redRow);
            greenVector.push_back(greenRow);
            blueVector.push_back(blueRow);
        }

        // Print the entire vectors (optional)
        std::cout << "R[][]:" << std::endl;
        for (const auto& row : redVector)
        {
            for (const auto& value : row)
            {
                std::cout << static_cast<int>(value) << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "G[][]:" << std::endl;
        for (const auto& row : greenVector)
        {
            for (const auto& value : row)
            {
                 std::cout << static_cast<int>(value) << " ";
            }
            std::cout << std::endl;
        }

        std::cout << "B[][]:" << std::endl;
        for (const auto& row : blueVector)
        {
            for (const auto& value : row)
            {
                std::cout << static_cast<int>(value) << " ";
            }
            std::cout << std::endl;
        }

        // Now, you have redVector, greenVector, and blueVector containing the R, G, B values respectively.
    }

    return 0;
}



