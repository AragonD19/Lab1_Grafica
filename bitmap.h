
#ifndef LAB1_GRAFICA_BITMAP_H
#define LAB1_GRAFICA_BITMAP_H


#include <vector>
#include <string>

// Estructura para representar un píxel RGB
struct Pixel {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
};

// Función para guardar el mapa de bits en un archivo BMP
void saveBitmap(const std::string& filename, const std::vector<Pixel>& bitmap, int width, int height);



#endif //LAB1_GRAFICA_BITMAP_H
