#include <iostream>
#include <tuple>
int answer1, answer2;

class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction(int inputNumerator, int inputDenominator)
    {
        numerator = inputNumerator;
        denominator = inputDenominator;
    }
    Fraction operator+(const Fraction &fr)
    {
        return Fraction(numerator * fr.denominator + denominator * fr.numerator, denominator * fr.denominator);
    }
    Fraction operator-(const Fraction &fr)
    {
        return Fraction(numerator * fr.denominator - denominator * fr.numerator, denominator * fr.denominator);
    }
    Fraction operator*(const Fraction &fr)
    {
        return Fraction(numerator * fr.numerator, denominator * fr.denominator);
    }
    Fraction operator/(const Fraction &fr)
    {
        return Fraction(numerator * fr.denominator, denominator * fr.numerator);
    }
    std::tuple<int, int> getData()
    {
        return std::tuple<int, int>{numerator, denominator};
    }
    friend std::ostream &operator<<(std::ostream &os, const Fraction &fr)
    {
        os << fr.numerator << '/' << fr.denominator;
        return os;
    }
};

int main()
{
    Fraction a(1, 2), b(2, 3);
    Fraction c = a / b;
    std::cout << "C = " << c << std::endl;
    answer1 = std::get<0>(c.getData());
    answer2 = std::get<1>(c.getData());
    return 0;
}