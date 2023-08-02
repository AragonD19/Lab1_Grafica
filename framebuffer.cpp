#include "framebuffer.h"
#include "bitmap.h"

// Constructor que inicializa el framebuffer con el color clearColor
Framebuffer::Framebuffer(int width, int height, Color clearColor) : width(width), height(height), clearColor(clearColor) {
    clear();
}

// Función para limpiar el framebuffer con el color clearColor
void Framebuffer::clear() {
    for (auto& row : buffer) {
        for (auto& pixel : row) {
            pixel = clearColor;
        }
    }
}

// Función para obtener la anchura del framebuffer
int Framebuffer::getWidth() const {
    return width;
}

// Función para obtener la altura del framebuffer
int Framebuffer::getHeight() const {
    return height;
}

// Función para obtener el color de fondo del framebuffer
Color Framebuffer::getClearColor() const {
    return clearColor;
}

// Función para establecer el color de fondo del framebuffer
void Framebuffer::setClearColor(Color color) {
    clearColor = color;
}

// Función para obtener el color de un píxel en la posición (x, y)
Color& Framebuffer::getPixel(int x, int y) {
    return buffer[y][x];
}

// Función para renderizar el framebuffer en una imagen BMP
void Framebuffer::renderBuffer() const {
    std::vector<Pixel> bitmap(width * height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const Color& color = buffer[y][x]; // Cambio a const Color&
            bitmap[y * width + x] = {color.getBlue(), color.getGreen(), color.getRed()};
        }
    }

    // Guardar el mapa de bits en un archivo BMP para visualizarlo
    saveBitmap("out.bmp", bitmap, width, height);
}

