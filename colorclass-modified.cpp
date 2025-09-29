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