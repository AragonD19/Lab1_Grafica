#ifndef LAB1_GRAFICA_VERTEX2_H
#define LAB1_GRAFICA_VERTEX2_H

#include <vector>
#include "color.h"

// Estructura Vertex2 para almacenar coordenadas X e Y
struct Vertex2 {
    int x;
    int y;
    Vertex2() : x(0), y(0) {}
    Vertex2(int x, int y) : x(x), y(y) {}
};

void point(Vertex2 punto, Color color);

extern Vertex2 centerScreen;

void linea(Vertex2 punto1, Vertex2 punto2);

void linea(Vertex2 punto1, Vertex2 punto2, int thickness);

void square(int height, int width, Vertex2 vertexE);

void square(int height, int width);

// Corrección de la declaración de la función drawPolygon
void drawPolygon(const std::vector<Vertex2>& vec);

void fillPolygon(const std::vector<Vertex2>& vertices, Color fillColor, Color strokeColor, Color backgroundColor);

#endif // LAB1_GRAFICA_VERTEX2_H
