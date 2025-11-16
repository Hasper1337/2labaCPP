#include <iostream>

using namespace std;

class RGBColor {
private:
    int red;
    int green;
    int blue;

    static int colorCount;

    static int limit(int value) {
        return max(0, min(255, value));
    }

public:

    RGBColor() : red(0), green(0), blue(0) { // Конструктор по умолчанию черный цвет(0, 0, 0)
        colorCount++;
    }

    RGBColor(int r, int g, int b) : red(limit(r)), green(limit(g)), blue(limit(b)) { // Конструктор с параметрами
        colorCount++;
    }

    RGBColor(const RGBColor& other) : red(other.red), green(other.green), blue(other.blue) { // Конструктор копирования
        colorCount++;
    }

    ~RGBColor() { // Деструктор
        colorCount--;
        cout << "Removed color RGB(" << red << ", " << green << ", " << blue << ")" << endl;
    }


    void print(){
        cout << "A color was created with the following parameters RGB(" << red << ", " << green << ", " << blue << ")" << endl;
    }

    int SetR(int valueR) {
        red = valueR;
    }

    int SetG(int valueG) {
        green = valueG;
    }

    int SetB(int valueB) {
        blue = valueB;
    }

    static int getColorCount() {
        return colorCount;
    }

    // перегрузки //

    // унарные операции
    RGBColor& operator++() { // префикс инкремент
        red = limit(++red);
        green = limit(++green);
        blue = limit(++blue);
        return *this;
    }

    RGBColor operator++(int) { // постфикс инкремент
        RGBColor temp(*this);
        red = limit(red + 1);
        green = limit(green + 1);
        blue = limit(blue + 1);
        return temp;
    }

    RGBColor& operator--() { // префикс декримент
        red = limit(--red);
        green = limit(--green);
        blue = limit(--blue);
        return *this;
    }

    RGBColor operator--(int) { // постфикс декримент
        RGBColor temp(*this);
        red = limit(red - 1);
        green = limit(green - 1);
        blue = limit(blue - 1);
        return temp;
    }

    // арифметическое присваивание

    RGBColor& operator+=(const RGBColor& other) {
        red += limit((red + other.red) / 2);
        green += limit((green + other.green) / 2);
        blue += limit((blue + other.blue) / 2);
    }

    RGBColor& operator-=(const RGBColor& other) {
        red -= limit((red - other.red) / 2);
        green -= limit((green - other.green) / 2);
        blue -= limit((blue - other.blue) / 2);
    }

    RGBColor& operator=(const RGBColor& other) {
        if (this != &other) {
            red = other.red;
            green = other.green;
            blue = other.blue;
       }
        return *this;
    }

    RGBColor& operator/=(const RGBColor& other) {
        red /= limit(red / other.red);
        green /= limit(green / other.green);
        blue /= limit(blue / other.blue);
    }

    // бинарные

    friend RGBColor operator+(RGBColor lhs, const RGBColor& rhs) {
        lhs += rhs;
        return lhs;
    }

};

int RGBColor::colorCount = 0;

int main()
{
    //RGBColor a(20, 20, 20);
    //++a;
    //a.print();

    //RGBColor temp(a++);
    //temp.print();
    //a.print();

    RGBColor red(255, 0, 0);
    RGBColor green(0, 255, 0);
    RGBColor blue(0, 0, 255);

    cout << "Total number of colors created in the palette: " << RGBColor::getColorCount() << endl;
    return 0;
}