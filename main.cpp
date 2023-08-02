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

    Color polygonColor1(255, 255, 255);
    Color fillColor1(0, 255, 0);

    // Nuevo primer polígono
    std::vector<Vertex2> polygonVertices1 = {
            {413, 177}, {448, 159}, {502, 88}, {553, 53}, {535, 36}, {676, 37},
            {660, 52}, {750, 145}, {761, 179}, {672, 192}, {659, 214}, {615, 214},
            {632, 230}, {580, 230}, {597, 215}, {552, 214}, {517, 144}, {466, 180}
    };

    // Dibujar el nuevo primer polígono sin relleno
    framebuffer.setCurrentColor(polygonColor1);
    drawPolygon(polygonVertices1);

    // Rellenar el nuevo primer polígono con el color de relleno
    framebuffer.setCurrentColor(fillColor1);
    fillPolygon(polygonVertices1, fillColor1, polygonColor1, framebuffer.getClearColor());

    Color polygonColor2(255, 255, 255);
    Color fillColor2(0, 255, 0);

    // Nuevo segundo polígono
    std::vector<Vertex2> polygonVertices2 = {
            {682, 175}, {708, 120}, {735, 148}, {739, 170}
    };

    // Dibujar el nuevo segundo polígono sin relleno
    framebuffer.setCurrentColor(polygonColor2);
    drawPolygon(polygonVertices2);

    // Rellenar el nuevo segundo polígono con el color de relleno
    framebuffer.setCurrentColor(fillColor2);
    fillPolygon(polygonVertices2, fillColor2, polygonColor2, framebuffer.getClearColor());

    renderBuffer();
}

int main() {
    render();
    system("start out.bmp");

    return 0;
}
