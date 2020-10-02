// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(size_t mp) : BitField(-1)
{
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(-1)
{
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(-1)
{
}

TSet::operator TBitField()
{
}

size_t TSet::GetMaxPower() const // получить макс. к-во эл-тов
{
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
    return 0;
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
    return *this;
}

bool TSet::operator==(const TSet &s) const // сравнение
{
    return false;
}

bool TSet::operator!=(const TSet &s) const // сравнение
{
    return false;
}

TSet TSet::operator+(const TSet &s) // объединение
{
    return *this;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
    return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
    return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
    return *this;
}

TSet TSet::operator~() // дополнение
{
    return *this;
}

// перегрузка ввода/вывода

std::istream &operator>>(std::istream &istream, TSet &s) // ввод
{
    return istream;
}

std::ostream& operator<<(std::ostream &ostream, const TSet &s) // вывод
{
    return ostream;
}
