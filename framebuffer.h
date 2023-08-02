#ifndef LAB1_GRAFICA_FRAMEBUFFER_H
#define LAB1_GRAFICA_FRAMEBUFFER_H

#include <array>
#include "Color.h"

// Clase Framebuffer para representar la pantalla
class Framebuffer {
public:
    // Constructor que inicializa el framebuffer con el color clearColor
    Framebuffer(int width, int height, Color clearColor);

    // Función para limpiar el framebuffer con el color clearColor
    void clear();

    // Función para obtener la anchura del framebuffer
    int getWidth() const;

    // Función para obtener la altura del framebuffer
    int getHeight() const;

    // Función para obtener el color de fondo del framebuffer
    Color getClearColor() const;

    // Función para establecer el color de fondo del framebuffer
    void setClearColor(Color color);

    // Función para obtener el color de un píxel en la posición (x, y)
    Color& getPixel(int x, int y);

    // Función para renderizar el framebuffer en una imagen BMP
    void renderBuffer() const;

    Color getCurrentColor() const {
        return currentColor;
    }

    // Función para establecer el color actual
    void setCurrentColor(Color color) {
        currentColor = color;
    }

private:
    int width;                       // Ancho del framebuffer
    int height;                      // Alto del framebuffer
    Color clearColor;                // Color de fondo del framebuffer
    std::array<std::array<Color, 800>, 600> buffer; // Framebuffer para representar la pantalla
    Color currentColor; // Color actual del píxel
};

#endif // LAB1_GRAFICA_FRAMEBUFFER_H
