#ifndef LAB1_GRAFICA_COLOR_H
#define LAB1_GRAFICA_COLOR_H

#include <cstdint>
#include <iostream>

class Color {
public:
    Color();

    // Constructor que acepta valores r, g y b y los almacena en la clase Color
    Color(int r, int g, int b);

    // Constructor que acepta valores r, g, b y alpha y los almacena en la clase Color
    Color(int r, int g, int b, float a);

    // Métodos para obtener los valores de r, g, b y alpha
    uint8_t getRed() const;
    uint8_t getGreen() const;
    uint8_t getBlue() const;
    float getAlpha() const;

    // Métodos para establecer los valores de r, g, b y alpha con clamping
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    void setAlpha(float a);

    // Operadores sobrecargados para comparación, suma y multiplicación
    bool operator==(const Color& other) const;
    bool operator!=(const Color& other) const;
    Color operator+(const Color& other) const;
    Color operator*(float factor) const;

    // Función amiga para mostrar el color en formato de cadena
    friend std::ostream& operator<<(std::ostream& os, const Color& color);

private:
    // Función para realizar el clamping y asegurar que el valor esté en el rango [0, 255]
    static uint8_t clamp(int value);

    // Función para asegurar que el valor alpha esté en el rango [0, 1]
    static float clampAlpha(float value);

    uint8_t red;   // Canal rojo
    uint8_t green; // Canal verde
    uint8_t blue;  // Canal azul
    float alpha;   // Canal de transparencia
};

// Definición de los colores predefinidos
extern Color WHITE;
extern Color NAVY_BLUE;
extern Color BLACK;
extern Color GRAY;
extern Color YELLOW;

#endif // LAB1_GRAFICA_COLOR_H
