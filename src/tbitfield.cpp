// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(size_t len)
{
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
}

TBitField::~TBitField()
{
}

size_t TBitField::GetMemIndex(const size_t n) const // индекс Мем для бита n
{
    return size_t();
}

TELEM TBitField::GetMemMask(const size_t n) const // битовая маска для бита n
{
    return TELEM();
}

// доступ к битам битового поля

size_t TBitField::GetLength() const // получить длину (к-во битов)
{
  return 0;
}

void TBitField::SetBit(const size_t n) // установить бит
{
}

void TBitField::ClrBit(const size_t n) // очистить бит
{
}

size_t TBitField::GetBit(const size_t n) const // получить значение бита
{
  return 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    return *this;
}

bool TBitField::operator==(const TBitField &bf) const // сравнение
{
  return false;
}

bool TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return false;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    return *this;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    return *this;
}

TBitField TBitField::operator~() // отрицание
{
    return *this;
}

// ввод/вывод

std::istream &operator>>(std::istream &istream, TBitField &bf) // ввод
{
    return istream;
}

std::ostream &operator<<(std::ostream &ostream, const TBitField &bf) // вывод
{
    return ostream;
}
