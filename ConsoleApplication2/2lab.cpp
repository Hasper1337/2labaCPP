#include <iostream>

using namespace std;

class RGBColor {
private:
    int red;
    int green;
    int blue;

    static int colorCount;
public:

    RGBColor() : red(0), green(0), blue(0) { // Конструктор по умолчанию черный цвет(0, 0, 0)
        colorCount++;
    }

    RGBColor(int r, int g, int b) : red(r), green(g), blue(b) { // Конструктор с параметрами
        colorCount++;
    }

    RGBColor(int r, int g) : red(r), green(g), blue(255) { // Конструктор с параметрами(r, g, 250)
        colorCount++;
    }

    void Print(){
        cout << "Создан цвет со следующими параметрами r = " << red << "\t g = " << green << "\t b = " << blue << endl;
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

    // перегрузки //


};



int main()
{
    RGBColor a;
    a.Print();
}