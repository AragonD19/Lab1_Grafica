#include "bitmap.h"
#include <fstream>
#include <iostream>

#pragma pack(push, 1) // Asegura que la estructura sea empacada en 1 byte para evitar rellenos
struct BMPHeader {
    uint16_t signature;
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t dataOffset;
    uint32_t headerSize;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitDepth;
    uint32_t compression;
    uint32_t imageSize;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t importantColors;
};
#pragma pack(pop)

void saveBitmap(const std::string& filename, const std::vector<Pixel>& bitmap, int width, int height) {
    BMPHeader bmpHeader;
    bmpHeader.signature = 0x4D42; // "BM"
    bmpHeader.fileSize = sizeof(BMPHeader) + static_cast<uint32_t>(bitmap.size() * sizeof(Pixel));
    bmpHeader.reserved = 0;
    bmpHeader.dataOffset = sizeof(BMPHeader);
    bmpHeader.headerSize = sizeof(BMPHeader) - 14; // El tamaño de la estructura BMPHeader sin los campos "signature" y "fileSize"
    bmpHeader.width = width;
    bmpHeader.height = height;
    bmpHeader.planes = 1;
    bmpHeader.bitDepth = 24;
    bmpHeader.compression = 0;
    bmpHeader.imageSize = 0;
    bmpHeader.xPixelsPerMeter = 0;
    bmpHeader.yPixelsPerMeter = 0;
    bmpHeader.colorsUsed = 0;
    bmpHeader.importantColors = 0;

    std::ofstream file(filename, std::ios::binary | std::ios::trunc);
    if (!file) {
        std::cerr << "Error al abrir el archivo: " << filename << std::endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&bmpHeader), sizeof(BMPHeader));
    file.write(reinterpret_cast<const char*>(bitmap.data()), static_cast<std::streamsize>(bitmap.size() * sizeof(Pixel)));

    file.close();
}
