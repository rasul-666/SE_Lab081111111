/*
    @file
    @brief ������������ ���� ������ Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

/*!
   @brief ������ ������������ �����
*/
class Complex
{
    /*!
        @brief �������������� ������������
    */
    double Re;

    /*!
        @brief ������ ������������
    */
    double Im;
    /*!
        @brief  ������ ������ ������
    */
	public:
	    /*!
            @brief  ����������� ������ � �������������� �����
        */
	    Complex(double aRe = 0, double aIm = 0);

	    /*!
            @brief  ����������� ������������ �����
        */
	    Complex(const Complex &);
        /*!
            @brief  ����������
        */
        ~Complex();

        /*!
            @brief  ��������� ������ � �������������� ������������
        */
        void Set(double aRe, double aIm = 0);
        operator double();

        /*!
            @brief  ������ ������������ �����
        */
        double abs();

        /*!
            @brief  ������������� ����� �������� ������������ �����/������
        */
        friend istream & operator >> (istream &, Complex &);
        friend ostream & operator << (ostream &, Complex &);

        /*!
            @brief  �������� ��� ������ � �������������� �����
        */
        Complex operator - (const double &);
        Complex operator + (const Complex &);
        Complex operator - (const Complex &);
        Complex operator + (const double &);
        Complex operator * (const Complex &);
        Complex operator * (const double &);
        Complex operator / (const double &);

        /*!
            @brief  ������������� ����� �������� ��������
        */
        friend Complex operator + (const double &, const Complex &);

        /*!
            @brief  ������������� ����� �������� ���������
        */
        friend Complex operator - (const double &, const Complex &);

        /*!
            @brief  ������������� ����� �������� ���������
        */
        friend Complex operator * (const double &, const Complex &);

        /*!
            @brief  ������������ �������� ��� ��������������� � ������������ �����
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
