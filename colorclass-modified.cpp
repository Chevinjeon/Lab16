// COMSC-210 | Lab 16 | Chevin Jeon
// IDE used: VSC
// Date: 2025-09-29

#include <iostream>   // std::cout, std::endl
#include <iomanip>    // std::hex, std::setw, std::setfill, std::uppercase
#include <stdexcept>  // std::out_of_range


// --------------------- Color class ---------------------
class Color {
private:
    int r; // red channel (0–255)
    int g; // green channel (0–255)
    int b; // blue channel (0–255)

    // Helper: validate a single 8-bit channel
    int clampByte(int value) const {
        if (value < 0 || value > 255) {
            throw std::out_of_range("Color channel must be in range 0–255");
        }
        return value;
    }

public:
    // Default constructor → black (0,0,0)
    Color() : r(0), g(0), b(0) {}

    // Full parameter constructor → sets all three channels
    Color(int red, int green, int blue)
        : r(clampByte(red)), g(clampByte(green)), b(clampByte(blue)) {}

    // Partial constructor → set only red, green = blue = 0
    Color(int red) : r(clampByte(red)), g(0), b(0) {}

    // Another partial constructor → set red+green, blue = 0
    Color(int red, int green) 
        : r(clampByte(red)), g(clampByte(green)), b(0) {}

    // ---- Getters ----
    int getR() const { return r; }
    int getG() const { return g; }
    int getB() const { return b; }

    // ---- Setters ----
    void setR(int red)   { r = clampByte(red); }
    void setG(int green) { g = clampByte(green); }
    void setB(int blue)  { b = clampByte(blue); }

    // ---- Print: RGB + Hex ----
    void print() const {
        std::cout << "Color(r=" << r
                  << ", g=" << g
                  << ", b=" << b
                  << ", hex=#"
                  << std::uppercase << std::hex << std::setfill('0')
                  << std::setw(2) << r
                  << std::setw(2) << g
                  << std::setw(2) << b
                  << std::dec
                  << ")" << std::endl;
    }
};


// --------------------- Main ---------------------
int main() {
    try {
        std::cout << "== Demonstrating different constructors ==" << std::endl;

        // Default constructor → black
        Color c1;
        c1.print();

        // Partial constructor → red only
        Color c2(200); 
        c2.print();

        // Partial constructor → red + green
        Color c3(100, 150);
        c3.print();

        // Full constructor → full RGB
        Color c4(123, 45, 67);
        c4.print();

        // Predefined “named colors”
        Color red(255, 0, 0);
        Color green(0, 255, 0);
        Color blue(0, 0, 255);
        red.print();
        green.print();
        blue.print();

    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
