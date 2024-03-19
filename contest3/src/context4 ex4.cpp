/*Напишите класс Rational (рациональное число). Конструктор класса должен получать на вход два числа
типа int (числитель и знаменатель). Считайте, что по умолчанию числитель равен 0, а знаменатель — 1.
Переопределите бинарные операторы сложения, вычитания, умножения и деления
(работающие в том числе и с аргументами типа int), унарные плюс и минус.
Предусмотрите функции-члены numerator и denominator для получения числителя и знаменателя
несократимого представления этой дроби (знаменатель должен быть положительным).
Переопределите также операторы +=, -=, *= и /=. Не забудьте определить операторы == и !=.
Реализуйте также префиксный и постфиксный операторы ++ и --.

Можете считать, что числитель и знаменатель всех получающихся в процессе не превосходят 10^4 по модулю.

Примечания
В вашей программе не должно быть функции main. Напишите только сам класс, а также необходимые внешние функции
и операторы.*/
#include <iostream>

class Rational
{
private:
    int numerator;
    int denominator;

    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce()
    {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom)
    {
        reduce();
    }

    int getNumerator() const
    {
        return numerator;
    }

    int getDenominator() const
    {
        return denominator;
    }

    Rational operator+(const Rational& other) const
    {
        return Rational(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational operator-(const Rational& other) const
    {
        return Rational(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Rational operator*(const Rational& other) const
    {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    Rational operator/(const Rational& other) const
    {
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    Rational& operator+=(const Rational& other)
    {
        *this = *this + other;
        return *this;
    }

    Rational& operator-=(const Rational& other)
    {
        *this = *this - other;
        return *this;
    }

    Rational& operator*=(const Rational& other)
    {
        *this = *this * other;
        return *this;
    }

    Rational& operator/=(const Rational& other)
    {
        *this = *this / other;
        return *this;
    }

    bool operator==(const Rational& other) const
    {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Rational& other) const
    {
        return !(*this == other);
    }

    Rational& operator++()
    {
        *this += 1;
        return *this;
    }

    Rational operator++(int)
    {
        Rational temp = *this;
        *this += 1;
        return temp;
    }

    Rational& operator--()
    {
        *this -= 1;
        return *this;
    }

    Rational operator--(int)
    {
        Rational temp = *this;
        *this -= 1;
        return temp;
    }

    Rational operator+() const
    {
        return *this;
    }

    Rational operator-() const
    {
        return Rational(-numerator, denominator);
    }
};

std::ostream& operator<<(std::ostream& os, const Rational& rational)
{
    os << rational.getNumerator() << "/" << rational.getDenominator();
    return os;
}
