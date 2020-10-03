// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(size_t len)
{
    this->BitLen = len;
    this->MemLen = len >> (sizeof(TELEM) + 1);

    // TODO: Fix magic 31
    if (len & 31) this->MemLen++;

    pMem = new TELEM[this->MemLen];
    if (pMem != nullptr)
        for (int i = 0; i < this->MemLen; ++i)
            pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
    *this = bf;
}

TBitField::~TBitField()
{
    delete this->pMem;
    this->pMem = nullptr;
}

size_t TBitField::GetMemIndex(const size_t n) const // индекс Мем для бита n
{
    return n >> (sizeof(TELEM) + 1);
}

TELEM TBitField::GetMemMask(const size_t n) const // битовая маска для бита n
{
    // TODO: Fix magic 31
    return 1 << (n & 31);
}

// доступ к битам битового поля

size_t TBitField::GetLength() const // получить длину (к-во битов)
{
  return this->BitLen;
}

void TBitField::SetBit(const size_t n) // установить бит
{
    if (n >= this->BitLen)
        throw "Index out of bound exception. 🛠";

    this->pMem[this->GetMemIndex(n)] |= this->GetMemMask(n);
}

void TBitField::ClrBit(const size_t n) // очистить бит
{
    if (n >= this->BitLen)
        throw "Index out of bound exception. 🛠";

    this->pMem[this->GetMemIndex(n)] &= ~this->GetMemMask(n);
}

size_t TBitField::GetBit(const size_t n) const // получить значение бита
{
    if (n >= this->BitLen)
        throw "Index out of bound exception. 🛠";

    return this->pMem[this->GetMemIndex(n)] & this->GetMemMask(n);
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    if (this->BitLen == bf.BitLen && this->pMem == bf.pMem)
        return *this;

    if (this->MemLen != bf.MemLen) {
        this->MemLen = bf.MemLen;

        delete pMem;
        this->pMem = new TELEM[this->MemLen];
    }

    this->BitLen = bf.BitLen;

    if (this->pMem != nullptr && bf.pMem != nullptr) {
        for (int i = 0; i < this->MemLen; ++i)
            this->pMem[i] = bf.pMem[i];
    } else {
        throw "Cannot allocate memory. 🛠";
    }

    return *this;
}

bool TBitField::compare(const TBitField &a, const TBitField &b, bool(*compare)(TELEM, TELEM))
{
    if (compare(a.BitLen, b.BitLen) || compare(a.MemLen, b.MemLen))
        return true;

    if (a.pMem != nullptr && b.pMem != nullptr)
        for (int i = 0; i < a.MemLen; ++i)
            if (compare(a.pMem[i], b.pMem[i]))
                return true;

    return false;
}

bool TBitField::operator==(const TBitField &bf) const // сравнение
{
    return compare(*this, bf, [](TELEM a, TELEM b) {
        return a == b;
    });
}

bool TBitField::operator!=(const TBitField &bf) const // сравнение
{
    return compare(*this, bf, [](TELEM a, TELEM b) {
        return a != b;
    });
}


TBitField& TBitField::operator|(const TBitField &bf) const // операция "или"
{
    if (this->MemLen < bf.MemLen)
        return bf | *this;

    auto result = new TBitField(*this);
    for (int i = 0; i < bf.MemLen; ++i) {
        result->pMem[i] |= bf.pMem[i];
    }

    return *result;
}

TBitField& TBitField::operator&(const TBitField &bf) const // операция "и"
{
    if (this->BitLen < bf.BitLen)
        return bf & *this;

    auto result = new TBitField(*this);
    for (int i = 0; i < bf.MemLen; ++i) {
        result->pMem[i] &= bf.pMem[i];
    }

    return *result;
}

TBitField& TBitField::operator~() const // отрицание
{
    auto result = new TBitField(*this);
    for (int i = 0; i < this->MemLen; ++i) {
        result->pMem[i] = ~result->pMem[i];
    }

    return *result;
}

// ввод/вывод

std::istream &operator>>(std::istream &istream, TBitField &bf) // ввод
{
    int i = 0;
    char ch;
    do {
        istream >> ch;
    } while (ch != ' ');

    while (true) {
        istream >> ch;
        if (ch == '0') {
            bf.ClrBit(++i);
            continue;
        } else if (ch == '1') {
            bf.SetBit(++i);
            continue;
        } else {
            break;
        }
    }

    return istream;
}

std::ostream &operator<<(std::ostream &ostream, const TBitField &bf) // вывод
{
    for (size_t i = 0; i < bf.BitLen; ++i) {
        ostream << (bf.GetBit(i) ? "1" : "0");
    }
    return ostream;
}
