#include <iostream>

using namespace std;


/**
 * \brief Класс RGBColor
 * 
 * @param int red
 * @param int green
 * @param int blue
 */
class RGBColor {
private:
    int red;
    int green;
    int blue;
    /**
     * \brief Счетчик цветов.
     */
    static int colorCount;
    /**
     * \brief Предел для цвета в представлении RGB - [0, 255].
     * 
     * \param value
     * \return Значение в диапазоне [0, 255]
     */
    static int limit(int value) {
        return max(0, min(255, value));
    }

public:


    /**
     * \brief Конструктор по умолчанию черный цвет(0, 0, 0).
     * 
     */
    RGBColor() : red(0), green(0), blue(0) {
        colorCount++;
    }

    /**
     * \brief Конструктор с параметрами.
     * 
     * \param int r
     * \param int g
     * \param int b
     */
    RGBColor(int r, int g, int b) : red(limit(r)), green(limit(g)), blue(limit(b)) {
        colorCount++;
    }

    /**
     * \brief Конструктор копирования.
     *
     */
    RGBColor(const RGBColor& other) : red(other.red), green(other.green), blue(other.blue) {
        colorCount++;
    }

    /**
     * \brief Деструктор.
     *
     */
    ~RGBColor() {
        colorCount--;
        cout << "Removed color RGB(" << red << ", " << green << ", " << blue << ")" << endl;
    }


    /**
     * \brief Функция вывода данных о цвете.
     *
     */
    void print() {
        cout << "A color was created with the following parameters RGB(" << red << ", " << green << ", " << blue << "), Brightnes: " << getBrightness() << endl;
    }

    /**
     * \brief Функция получения яркости цвета.
     *
     */
    double getBrightness() const {
        return (0.299*red + 0.587*green + 0.114*blue);
    }

    int SetR(int valueR) {
        red = limit(valueR);
    }

    int SetG(int valueG) {
        green = limit(valueG);
    }

    int SetB(int valueB) {
        blue = limit(valueB);
    }

    /**
     * \brief Функция по получению количества цветов
     * 
     * \return Количество цветов
     */
    static int getColorCount() {
        return colorCount;
    }

    /**
     * Перегрузка оператора префиксного инкремента
     * 
     * \return Значения цветов после префиксного инкремента
     */
    RGBColor& operator++() {
        red = limit(++red);
        green = limit(++green);
        blue = limit(++blue);
        return *this;
    }

    /**
     * Перегрузка оператора постфиксного инкремента
     *
     * \return Значения цветов после постфиксного инкремента
     */
    RGBColor operator++(int) {
        RGBColor temp(*this);
        red = limit(red + 1);
        green = limit(green + 1);
        blue = limit(blue + 1);
        return temp;
    }

    /**
     * Перегрузка оператора префиксного декримента
     *
     * \return Значения цветов после префиксного декримента
     */
    RGBColor& operator--() {
        red = limit(--red);
        green = limit(--green);
        blue = limit(--blue);
        return *this;
    }

    /**
     * Перегрузка оператора постфиксного декримента
     *
     * \return Значения цветов после постфиксного декримента
     */
    RGBColor operator--(int) {
        RGBColor temp(*this);
        red = limit(red - 1);
        green = limit(green - 1);
        blue = limit(blue - 1);
        return temp;
    }


    /**
     * Перегрузка оператора +=
     *
     * \return Значения цветов после +=
     */
    RGBColor& operator+=(const RGBColor& other) {
        red = limit(red + other.red);
        green = limit(green + other.green);
        blue = limit(blue + other.blue);
        return *this;
    }

    /**
     * Перегрузка оператора -=
     *
     * \return Значения цветов после -=
     */
    RGBColor& operator-=(const RGBColor& other) {
        red = limit(red - other.red);
        green = limit(green - other.green);
        blue = limit(blue - other.blue);
        return *this;
    }

    /**
     * Перегрузка оператора присваивания
     *
     * \return Значения цветов после присваивания
     */
    RGBColor& operator=(const RGBColor& other) {
        if (this != &other) {
            red = other.red;
            green = other.green;
            blue = other.blue;
        }
        return *this;
    }

    /**
     * Перегрузка оператора /=
     *
     * \return Значения цветов после /=
     */
    RGBColor& operator/=(const RGBColor& other) {
        red = (other.red == 0) ? red : limit(red / other.red);
        green = (other.green == 0) ? green : limit(green / other.green);
        blue = (other.blue == 0) ? blue : limit(blue / other.blue);
        return *this;
    }


    /**
     * Перегрузка оператора сложения
     * 
     * \param lhs - параметры левого цвета
     * \param other - параметры правого цвета
     *
     * \return Значения цветов после сложения
     */
    friend RGBColor operator+(RGBColor lhs, const RGBColor& other) {
        lhs += other;
        return lhs;
    }

    /**
     * Перегрузка оператора вычитания
     * 
     * \param lhs - параметры левого цвета
     * \param other - параметры правого цвета
     *
     * \return Значения цветов после вычитания
     */
    friend RGBColor& operator-(RGBColor lhs, const RGBColor& other) {
        lhs -= other;
        return lhs;
    }

    /**
     * Перегрузка оператора деления
     *
     * \param lhs - параметры левого цвета
     * \param other - параметры правого цвета
     * 
     * \return Значения цветов после деления
     */
    friend RGBColor operator/(RGBColor lhs, const RGBColor& other) {
        lhs /= other;
        return lhs;
    }
    
    /**
     * Перегрузка оператора ==
     * 
     * \param other - значения с чем сравнивают
     * \return True or False
     */
    bool operator==(const RGBColor& other) {
        return (red == other.red) && (green == other.green) && (blue == other.blue);
    };

    /**
     * Перегрузка оператора !=
     *
     * \param other - значения с чем сравнивают
     * \return True or False
     */
    bool operator!=(const RGBColor& other) {
        return !(*this == other);
    };

    /**
     * Перегрузка оператора >
     *
     * \param other - значения с чем сравнивают
     * \return True or False
     */
    bool operator>(const RGBColor& other) {
        return getBrightness() > other.getBrightness();
	};

    /**
     * Перегрузка оператора <
     *
     * \param other - значения с чем сравнивают
     * \return True or False
     */
    bool operator<(const RGBColor& other) {
        return getBrightness() < other.getBrightness();
    }

    /**
     * Перегрузка оператора >=
     *
     * \param other - значения с чем сравнивают
     * \return True or False
     */
    bool operator>=(const RGBColor& other) {
        return getBrightness() >= other.getBrightness();
	};

    /**
     * Перегрузка оператора <=
     *
     * \param other - значения с чем сравнивают
     * \return True or False
     */
    bool operator<=(const RGBColor& other) {
        return getBrightness() <= other.getBrightness();
    }
		
};


int RGBColor::colorCount = 0;

int main()
{
    cout << "Constructors of class RGBColor:\n" << endl;

    RGBColor color1;
    color1.print();
    cout << " - Constructor by default\n" << endl;

    RGBColor color2(255, 255, 255);
    color2.print();
    cout << " - Constructor by parametors\n" << endl;

    RGBColor color3(color2);
    color3.print();
    cout << " - Constructor by copy other object with him proparties" << endl;
    
    cout << "-----------------" << endl;

    cout << "Overloading unary operators:\n" << endl;
    ++color1;
    color1.print();
    cout << " - Overloading ++i\n" << endl;

    RGBColor temp = color1++;
    color1.print();
    cout << " - Overloading i++\n" << endl;

    --color1;
    color1.print();
    cout << " - Overloading --i\n" << endl;

    RGBColor temp1 = color1--;
    color1.print();
    cout << " - Overloading i--\n" << endl;

    cout << "-----------------" << endl;

    cout << "Overloading arithmetic assignment:\n" << endl;
    RGBColor red(255, 0, 0);
    RGBColor green(1, 255, 0);
    RGBColor blue(0, 0, 255);

    RGBColor mixed(red);
    mixed += green;
    mixed.print();
    cout << " - Overloading +=\n" << endl;

    mixed -= green;
    mixed.print();
    cout << " - Overloading -=\n" << endl;

    mixed /= red;
    mixed.print();
    cout << " - Overloading /=\n" << endl;

    mixed = red;
    mixed.print();
    cout << " - Overloading =\n" << endl;

    cout << "-----------------" << endl;

    cout << "Overloading binary operators:\n" << endl;
    RGBColor orange(255, 165, 0);
    RGBColor purple(128, 0, 128);

    RGBColor result1 = orange + purple;
    result1.print();
    cout << " - Overloading +\n" << endl;

    RGBColor result2 = orange - purple;
    result2.print();
    cout << " - Overloading -\n" << endl;

    RGBColor result3 = orange / purple;
    result3.print();
    cout << " - Overloading /\n" << endl;

    RGBColor light(200, 200, 200);
    RGBColor medium(100, 100, 100);
    RGBColor dark(50, 50, 50);

    cout << "\nlight > medium: " << (light > medium ? "true" : "false") << endl;
    cout << " - Overloading >\n" << endl;
    cout << "medium < light: " << (medium < light ? "true" : "false") << endl;
    cout << " - Overloading <\n" << endl;
    cout << "dark <= medium: " << (dark <= medium ? "true" : "false") << endl;
    cout << " - Overloading <=\n" << endl;
    cout << "light >= medium: " << (light >= medium ? "true" : "false") << endl;
    cout << " - Overloading >=\n" << endl;

    RGBColor color4(100, 100, 100);
    RGBColor color5(100, 100, 100);
    RGBColor color6(150, 150, 150);

    cout << "\nColor with RGB param(100,100,100) == Color with RGB param(100,100,100): " << (color4 == color5 ? "true" : "false") << endl;
    cout << " - Overloading ==\n" << endl;
    cout << "Color with RGB param(100,100,100) != Color with RGB param(150,150,150): " << (color4 != color6 ? "true" : "false") << endl;
    cout << " - Overloading !=\n" << endl;

    cout << "Total number of colors created in the palette: " << RGBColor::getColorCount() << endl;
    return 0;
}