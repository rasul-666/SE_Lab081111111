/*
    @file
    @brief Заголовочный файл класса Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

/*!
   @brief Класса комплексного числа
*/
class Complex
{
    /*!
        @brief Действительная состовляющая
    */
    double Re;

    /*!
        @brief Мнимая состовляющая
    */
    double Im;
    /*!
        @brief  список членов класса
    */
	public:
	    /*!
            @brief  Конструктор мнимой и действительной части
        */
	    Complex(double aRe = 0, double aIm = 0);

	    /*!
            @brief  Конструктор комплексного числа
        */
	    Complex(const Complex &);
        /*!
            @brief  Деструктор
        */
        ~Complex();

        /*!
            @brief  Установка мнимой и действительной состовляющих
        */
        void Set(double aRe, double aIm = 0);
        operator double();

        /*!
            @brief  Модуль комплексного числа
        */
        double abs();

        /*!
            @brief  Дружественный метод операции перезагрузки ввода/вывода
        */
        friend istream & operator >> (istream &, Complex &);
        friend ostream & operator << (ostream &, Complex &);

        /*!
            @brief  Операции для мнимой и действительной части
        */
        Complex operator - (const double &);
        Complex operator + (const Complex &);
        Complex operator - (const Complex &);
        Complex operator + (const double &);
        Complex operator * (const Complex &);
        Complex operator * (const double &);
        Complex operator / (const double &);

        /*!
            @brief  Дружественный метод операции сложения
        */
        friend Complex operator + (const double &, const Complex &);

        /*!
            @brief  Дружественный метод операции вычитания
        */
        friend Complex operator - (const double &, const Complex &);

        /*!
            @brief  Дружественный метод операции умножения
        */
        friend Complex operator * (const double &, const Complex &);

        /*!
            @brief  Перезагрузка операций для действительного и комплексного числа
        */
        Complex & operator += (const Complex &);
        Complex & operator -= (const Complex &);
        Complex & operator *= (const Complex &);
        Complex & operator += (const double &);
        Complex & operator -= (const double &);
        Complex & operator *= (const double &);
        Complex & operator /= (const double &);
        Complex & operator = (const Complex &);
        Complex & operator = (const double &);

};
#endif
