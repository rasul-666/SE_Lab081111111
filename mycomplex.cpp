/*!
    @file
    @brief ����  � ��������� ������� ������ Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
     @brief ����������� ������
     @param a_Re �������������� ������������
     @param a_im ������ ������������
*/
Complex :: Complex(double aRe, double aIm){
    Re = aRe;
    Im = aIm;
}

/*!
     @brief ����������� ������
     @param a_Rval ����������� �����
*/
Complex :: Complex(const Complex & aRval){
    Re = aRval.Re;
    Im = aRval.Im;
}

/*!
     @brief ���������� ������
*/
Complex :: ~Complex(){
    Re = 0.0;
    Im = 0.0;
}

/*!
     @brief ������������ ������ � �������������� ������������
*/
void Complex :: Set(double aRe, double aIm){
    Re = aRe;
    Im = aIm;
}

/*!
     @brief ���������� ������ ������������ �����
     @return ������ ����������� �����
*/
Complex :: operator double(){
    return abs();
}

/*!
     @brief ���������� ������ ��������� ������������ �����
     @return ������ ��������� ������������ �����
*/
double Complex :: abs(){
    return sqrt(Re * Re + Im * Im);
}

/*!
     @brief ���������� ��������� �������� ������������ �����
     @return ��������� �������� ������������ �����
*/
Complex Complex ::  operator + (const Complex & aRval){
  Complex Result;
  Result.Re = Re + aRval.Re;
  Result.Im = Im + aRval.Im;
  return Result;
}

/*!
     @brief ���������� ��������� ��������� ������������ �����
     @return ��������� �������� ������������ �����
*/
Complex Complex  ::   operator - (const Complex & aRval){
    Complex Result;

    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/*!
     @brief ���������� ��������� �������� ��������������� �����
     @return ��������� �������� ������������ �����
*/
Complex Complex :: operator + (const double & aval){
    Complex result;
    result.Re = Re + aval;
    result.Im = Im;
    return result;
}

/*!
     @brief ���������� ��������� ��������� ���������������  �����
     @return ���������
*/
Complex Complex :: operator - (const double & aRval){
    Complex Result( * this);
    Result.Re = Re - aRval;
    return Result;
}

/*!
     @brief ���������� ��������� ��������� ������������  �����
     @return ���������
*/
Complex Complex :: operator * (const Complex & aRval){
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/*!
     @brief ���������� ��������� ��������� ���������������  �����
     @return ���������
*/
Complex Complex :: operator * (const double & aRval){
   Complex Result;
   Result.Re = Re * aRval;
   Result.Im = Im * aRval;
   return Result;
}

/*!
     @brief ���������� ��������� ������� ���������������  �����
     @return ���������
*/
Complex Complex :: operator / (const double & aRval){
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/*!
     @brief ��������� �� ��������� �������� ������������  �����
     @return ������� �� ��������
*/
Complex & Complex :: operator += ( const Complex & arval){
  Re += arval.Re;
  Im += arval.Im;
  return * this;
}

/*!
     @brief ��������� �� ��������� ��������� ������������  �����
     @return ������� �� ��������
*/
Complex & Complex :: operator -= (const Complex & aRval){
    Re -= aRval.Re;
    Im -= aRval.Im;
    return * this;
}

/*!
     @brief ��������� �� ��������� ��������� ������������  �����
     @return ������� �� ��������
*/
Complex & Complex :: operator *= (const Complex & aRval){
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return * this;
}

/*!
     @brief ��������� �� ��������� �������� ����������������  �����
     @return ������� �� ��������
*/
Complex & Complex :: operator += (const double & aRval){
    Re += aRval;
    return * this;
}

/*!
     @brief ��������� �� ��������� ��������� ����������������  �����
     @return ������� �� ��������
*/
Complex & Complex :: operator -= (const double & aRval){
    Re -= aRval;
    return * this;
}

/*!
     @brief ��������� �� ��������� ��������� ��������������� �����
     @return ������� �� ��������
*/
Complex & Complex :: operator *= (const  double  &  aRval){
    Re *= aRval;
    Im *= aRval;

    return * this;
}

/*!
     @brief ��������� �� ��������� ������� ��������������� �����
     @return ������� �� ��������
*/
Complex & Complex :: operator /= (const double & aRval){
    Re /= aRval;
    Im /= aRval;
    return * this;
}

/*!
     @brief ��������� �� ��������� ��������� ������������ �����
     @return ������� �� ��������
*/
Complex & Complex :: operator = (const Complex & aRval){
    Re = aRval.Re;
    Im = aRval.Im;
    return * this;
}

/*!
     @brief ��������� �� ��������� ��������� ��������������� �����
     @return ������� �� ��������
*/
Complex & Complex :: operator = (const double & aRval){
    Re = aRval;
    Im = 0.0;
    return * this;
}

/*!
     @brief ��������� ������ � �������������� �����
     @return ����������
*/
istream & operator >>(istream & stream, Complex & a){
  char tmp[256];  stream >> a.Re >>
  a.Im >> tmp;
  return stream;
}

/*!
     @brief ��������� ������ � �������������� �����
     @return �������
*/
ostream & operator << (ostream & stream,Complex & a){
    stream << a.Re;

    if( !(a.Im < 0) )
     stream << '+';
     stream << a.Im << 'i';
     return stream;
}

/*!
     @brief ���������� ��������� �������� ��������������� � ������������ �����
     @param aLval �������������� �����
     @return ��������� ��������
*/
Complex operator + (const double & aLval, const Complex & aRval){
   Complex Result;
   Result.Re = aLval + aRval.Re;
   Result.Im = aRval.Im;
   return Result;
}

/*!
     @brief ���������� ��������� ��������� ��������������� � ������������ �����
     @return ��������� ���������
*/
Complex operator - (const double & aLval, const Complex & aRval){

    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

/*!
     @brief ���������� ��������� ��������� ��������������� � ������������ �����
     @return ��������� ���������
*/
Complex operator * (const double & aLval, const Complex & a){
    Complex r;
    r.Re = aLval * a.Re;
    r.Im = aLval * a.Im;
    return r;
}
