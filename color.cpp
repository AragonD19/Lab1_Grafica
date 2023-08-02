#include "Color.h"

Color::Color() : red(0), green(0), blue(0), alpha(0) {}

Color::Color(int r, int g, int b) : red(clamp(r)), green(clamp(g)), blue(clamp(b)), alpha(1.0f) {}

Color::Color(int r, int g, int b, float a) : red(clamp(r)), green(clamp(g)), blue(clamp(b)), alpha(clampAlpha(a)) {}

uint8_t Color::getRed() const {
    return red;
}

uint8_t Color::getGreen() const {
    return green;
}

uint8_t Color::getBlue() const {
    return blue;
}

float Color::getAlpha() const {
    return alpha;
}

void Color::setRed(int r) {
    red = clamp(r);
}

void Color::setGreen(int g) {
    green = clamp(g);
}

void Color::setBlue(int b) {
    blue = clamp(b);
}

void Color::setAlpha(float a) {
    alpha = clampAlpha(a);
}

bool Color::operator==(const Color& other) const {
    return (red == other.red) && (green == other.green) && (blue == other.blue) && (alpha == other.alpha);
}

bool Color::operator!=(const Color& other) const {
    return !(*this == other);
}

Color Color::operator+(const Color& other) const {
    return {red + other.red, green + other.green, blue + other.blue, alpha};
}

Color Color::operator*(float factor) const {
    return {static_cast<int>(red * factor), static_cast<int>(green * factor), static_cast<int>(blue * factor), alpha};
}

uint8_t Color::clamp(int value) {
    if (value < 0) {
        return 0;
    } else if (value > 255) {
        return 255;
    } else {
        return static_cast<uint8_t>(value);
    }
}

float Color::clampAlpha(float value) {
    if (value < 0) {
        return 0.0f;
    } else if (value > 1) {
        return 1.0f;
    } else {
        return value;
    }
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
    os << "(" << static_cast<int>(color.red) << ", " << static_cast<int>(color.green) << ", " << static_cast<int>(color.blue) << ", " << color.alpha << ")";
    return os;
}

// Definición de los colores predefinidos
Color WHITE(255, 255, 255);
Color NAVY_BLUE(0, 0, 128);
Color BLACK(0, 0, 0);
Color GRAY(128, 128, 128);
Color YELLOW(255, 255, 0);
