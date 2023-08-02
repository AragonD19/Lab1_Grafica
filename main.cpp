#include <iostream>
#include <array>
#include "Color.h"
#include "Vertex2.h"
#include "Framebuffer.h"
#include "bitmap.h"
#include <cstdlib>
#include <vector>

// Dimensiones de la pantalla en píxeles
const int screenWidth = 800;
const int screenHeight = 600;

// Framebuffer para representar la pantalla
Framebuffer framebuffer(screenWidth, screenHeight, Color(0, 0, 128)); // Initialize framebuffer with NAVY_BLUE

// Función para limpiar el framebuffer con el color clearColor
void clear() {
    framebuffer.clear();
}

// Función para renderizar el framebuffer en una imagen BMP
void renderBuffer() {
    framebuffer.renderBuffer();
}

// Función para pintar un punto en la pantalla en las coordenadas especificadas
void point(Vertex2 punto, Color color) {
    framebuffer.setCurrentColor(color);
    if (punto.x >= 0 && punto.x < screenWidth && punto.y >= 0 && punto.y < screenHeight) {
        framebuffer.getPixel(punto.x, punto.y) = framebuffer.getCurrentColor();
    }
}

void render() {
    clear();

    Color polygonColor(255, 255, 255);
    Color fillColor(255, 0, 0);

    std::vector<Vertex2> polygonVertices = {
            {377, 249}, {411, 197}, {436, 249}
    };

    // Dibujar el polígono sin relleno
    framebuffer.setCurrentColor(polygonColor);
    drawPolygon(polygonVertices);

    // Rellenar el polígono con el color de relleno
    framebuffer.setCurrentColor(fillColor);
    fillPolygon(polygonVertices, fillColor, polygonColor, framebuffer.getClearColor());

    renderBuffer();
}

int main() {
    render();
    system("start out.bmp");

    return 0;
}
