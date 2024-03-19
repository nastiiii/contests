/*
Напишите класс Complex (комплексное число).
Конструктор класса должен получать на вход либо одно, либо два числа типа
double(действительную и мнимую часть или только действительную). Переопределите бинарные
операторы сложения, вычитания, умножения и деления (работающие в том числе и с
действительными аргументами), унарные плюс и минус.
Предусмотрите функции-члены Re и Im для получения действительной и мнимой части.
Переопределите внешнюю функцию abs, возвращающую модуль комплексного числа.
Не забудьте определить операторы == и !=.
Примечания
В вашей программе не должно быть функции main. Напишите только сам класс,
а также необходимые внешние функции и операторы.
*/
#include <cmath>

class Complex
{
private:
    double real;
    double imag;

public:
    // Конструкторы
    Complex(double realPart = 0.0, double imagPart = 0.0) : real(realPart), imag(imagPart) {}

    // Функции-члены для доступа к действительной и мнимой части
    double Re() const { return real; }
    double Im() const { return imag; }

    // Перегрузка операторов сложения, вычитания, умножения и деления
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex& other) const
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
                       (imag * other.real - real * other.imag) / denominator);
    }

    // Перегрузка унарных операторов плюс и минус
    Complex operator+() const { return *this; }
    Complex operator-() const { return Complex(-real, -imag); }

    // Перегрузка операторов сравнения
    bool operator==(const Complex& other) const
    {
        return (real == other.real) && (imag == other.imag);
    }

    bool operator!=(const Complex& other) const
    {
        return !(*this == other);
    }
};

// Внешняя функция для вычисления модуля комплексного числа
double abs(const Complex& z)
{
    return std::sqrt(z.Re() * z.Re() + z.Im() * z.Im());
}
