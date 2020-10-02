// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество

#ifndef __SET_H__
#define __SET_H__

#include "tbitfield.h"

class TSet
{
private:
  size_t MaxPower;    // максимальная мощность множества
  TBitField BitField; // битовое поле для хранения характеристического вектора
public:
  TSet(size_t mp);
  TSet(const TSet &s);       // конструктор копирования
  TSet(const TBitField &bf); // конструктор преобразования типа
  explicit operator TBitField(); // преобразование типа к битовому полю

  // доступ к битам
  size_t GetMaxPower() const;     // максимальная мощность множества
  void InsElem(const int Elem);       // включить элемент в множество
  void DelElem(const int Elem);       // удалить элемент из множества
  bool IsMember(const int Elem) const; // проверить наличие элемента в множестве

  // теоретико-множественные операции
  bool operator== (const TSet &s) const; // сравнение
  bool operator!= (const TSet &s) const; // сравнение
  TSet& operator=(const TSet &s);  // присваивание
  TSet& operator+ (const int Elem) const; // объединение с элементом
                                   // элемент должен быть из того же универса
  TSet& operator- (const int Elem) const; // разность с элементом
                                   // элемент должен быть из того же универса
  TSet& operator+ (const TSet &s) const;  // объединение
  TSet& operator- (const TSet &s) const;  // объединение
  TSet& operator* (const TSet &s) const;  // пересечение
  TSet& operator~ () const;           // дополнение

  friend std::istream &operator>>(std::istream &istream, TSet &bf);
  friend std::ostream &operator<<(std::ostream &ostream, const TSet &bf);
};
#endif
