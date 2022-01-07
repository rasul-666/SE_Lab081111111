/*!
    @file
    @brief Файл  с описанием методов класса Complex
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
     @brief Конструктор класса
     @param a_Re Действительная состовляющая
     @param a_im Мнимая состовляющая
*/
Complex :: Complex(double aRe, double aIm){
    Re = aRe;
    Im = aIm;
}

/*!
     @brief Конструктор класса
     @param a_Rval Комплексное число
*/
Complex :: Complex(const Complex & aRval){
    Re = aRval.Re;
    Im = aRval.Im;
}

/*!
     @brief Деструктор класса
*/
Complex :: ~Complex(){
    Re = 0.0;
    Im = 0.0;
}

/*!
     @brief Установление мнимой и действительной состовляющих
*/
void Complex :: Set(double aRe, double aIm){
    Re = aRe;
    Im = aIm;
}

/*!
     @brief Возвращает модуль комплексного числа
     @return Модуль комплексное числа
*/
Complex :: operator double(){
    return abs();
}

/*!
     @brief Возвращает модуль выражения комплексного числа
     @return Модуль выражения комплексного числа
*/
double Complex :: abs(){
    return sqrt(Re * Re + Im * Im);
}

/*!
     @brief Возвращает результат сложения комплексного числа
     @return Результат сложения комплексного числа
*/
Complex Complex ::  operator + (const Complex & aRval){
  Complex Result;
  Result.Re = Re + aRval.Re;
  Result.Im = Im + aRval.Im;
  return Result;
}

/*!
     @brief Возвращает результат вычитания комплексного числа
     @return Результат сложения комплексного числа
*/
Complex Complex  ::   operator - (const Complex & aRval){
    Complex Result;

    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/*!
     @brief Возвращает результат сложения действительного числа
     @return Результат сложения комплексного числа
*/
Complex Complex :: operator + (const double & aval){
    Complex result;
    result.Re = Re + aval;
    result.Im = Im;
    return result;
}

/*!
     @brief Возвращает результат вычитания действительного  числа
     @return Результат
*/
Complex Complex :: operator - (const double & aRval){
    Complex Result( * this);
    Result.Re = Re - aRval;
    return Result;
}

/*!
     @brief Возвращает результат умножения комплексного  числа
     @return Результат
*/
Complex Complex :: operator * (const Complex & aRval){
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}

/*!
     @brief Возвращает результат умножения действительного  числа
     @return Результат
*/
Complex Complex :: operator * (const double & aRval){
   Complex Result;
   Result.Re = Re * aRval;
   Result.Im = Im * aRval;
   return Result;
}

/*!
     @brief Возвращает результат деления действительного  числа
     @return Результат
*/
Complex Complex :: operator / (const double & aRval){
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}

/*!
     @brief Ссылается на результат сложения комплексного  числа
     @return возврат по значанию
*/
Complex & Complex :: operator += ( const Complex & arval){
  Re += arval.Re;
  Im += arval.Im;
  return * this;
}

/*!
     @brief Ссылается на результат вычитания комплексного  числа
     @return возврат по значанию
*/
Complex & Complex :: operator -= (const Complex & aRval){
    Re -= aRval.Re;
    Im -= aRval.Im;
    return * this;
}

/*!
     @brief Ссылается на результат умножения комплексного  числа
     @return возврат по значанию
*/
Complex & Complex :: operator *= (const Complex & aRval){
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return * this;
}

/*!
     @brief Ссылается на результат сложения дейситвительного  числа
     @return возврат по значанию
*/
Complex & Complex :: operator += (const double & aRval){
    Re += aRval;
    return * this;
}

/*!
     @brief Ссылается на результат вычитания дейситвительного  числа
     @return возврат по значанию
*/
Complex & Complex :: operator -= (const double & aRval){
    Re -= aRval;
    return * this;
}

/*!
     @brief Ссылается на результат умножения действительного числа
     @return возврат по значанию
*/
Complex & Complex :: operator *= (const  double  &  aRval){
    Re *= aRval;
    Im *= aRval;

    return * this;
}

/*!
     @brief Ссылается на результат деления действительного числа
     @return возврат по значанию
*/
Complex & Complex :: operator /= (const double & aRval){
    Re /= aRval;
    Im /= aRval;
    return * this;
}

/*!
     @brief Ссылается на результат равенства комплексного числа
     @return возврат по значанию
*/
Complex & Complex :: operator = (const Complex & aRval){
    Re = aRval.Re;
    Im = aRval.Im;
    return * this;
}

/*!
     @brief Ссылается на результат равенства действительного числа
     @return возврат по значанию
*/
Complex & Complex :: operator = (const double & aRval){
    Re = aRval;
    Im = 0.0;
    return * this;
}

/*!
     @brief Извлекаем мнимую и действительную часть
     @return Извлечение
*/
istream & operator >>(istream & stream, Complex & a){
  char tmp[256];  stream >> a.Re >>
  a.Im >> tmp;
  return stream;
}

/*!
     @brief Вставляем мнимую и действительную часть
     @return Вставка
*/
ostream & operator << (ostream & stream,Complex & a){
    stream << a.Re;

    if( !(a.Im < 0) )
     stream << '+';
     stream << a.Im << 'i';
     return stream;
}

/*!
     @brief Возвращает результат сложения действительного и комплексного числа
     @param aLval Действительное число
     @return Результат сложения
*/
Complex operator + (const double & aLval, const Complex & aRval){
   Complex Result;
   Result.Re = aLval + aRval.Re;
   Result.Im = aRval.Im;
   return Result;
}

/*!
     @brief Возвращает результат вычитания действительного и комплексного числа
     @return Результат вычитания
*/
Complex operator - (const double & aLval, const Complex & aRval){

    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = -aRval.Im;
    return Result;
}

/*!
     @brief Возвращает результат умножения действительного и комплексного числа
     @return Результат умножения
*/
Complex operator * (const double & aLval, const Complex & a){
    Complex r;
    r.Re = aLval * a.Re;
    r.Im = aLval * a.Im;
    return r;
}
