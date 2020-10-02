// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(size_t mp) : MaxPower(mp), BitField(mp) {}
TSet::TSet(const TSet &s) : MaxPower(s.MaxPower), BitField(s.BitField) {}
TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower(bf.GetLength()) {}

TSet::operator TBitField()
{
    TBitField result(this->BitField);
    return result;
}

size_t TSet::GetMaxPower() const // получить макс. к-во эл-тов
{
    return this->MaxPower;
}

bool TSet::IsMember(const int Elem) const // элемент множества?
{
    if (Elem > this->MaxPower)
        return false;

    return this->BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
    if (Elem > MaxPower)
        throw "Too big for this set. 🛠: " + Elem;

    this->BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
    if (Elem > MaxPower)
        throw "Too big for this set. 🛠: " + Elem;

    this->BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) = default;

bool TSet::operator==(const TSet &s) const // сравнение
{
    return
        this->MaxPower == s.MaxPower &&
        this->BitField == s.BitField;
}

bool TSet::operator!=(const TSet &s) const // сравнение
{
    return
        this->MaxPower != s.MaxPower ||
        this->BitField != s.BitField;
}

TSet& TSet::operator+(const TSet &s) const // объединение
{
    if (this->MaxPower < s.MaxPower)
        return s + *this;

    auto result = new TSet(this->MaxPower);
    result->BitField = this->BitField | s.BitField;

    return *result;
}

TSet &TSet::operator-(const TSet &s) const {
    return *this * ~s;
}


TSet& TSet::operator*(const TSet &s) const // пересечение
{
    if (this->MaxPower < s.MaxPower)
        return s + *this;

    auto result = new TSet(this->MaxPower);
    result->BitField = this->BitField & s.BitField;

    return *result;
}

TSet& TSet::operator+(const int Elem) const // объединение с элементом
{
    auto result = new TSet(*this);
    result->InsElem(Elem);

    return *result;
}

TSet& TSet::operator-(const int Elem) const // разность с элементом
{
    auto result = new TSet(*this);
    result->DelElem(Elem);

    return *result;
}


TSet& TSet::operator~() const // дополнение
{
    auto result = new TSet(*this);
    result->BitField = ~result->BitField;
    return *result;
}

// перегрузка ввода/вывода

std::istream &operator>>(std::istream &istream, TSet &s) // ввод
{
    int temp;
    char ch;

    do {
        istream >> ch;
    } while (ch != '{');

    do {
        istream >> temp;
        s.InsElem(temp);

        do {
            istream >> ch;
        } while (ch != '}' && ch != ',');
    } while (ch != '}');

    return istream;
}

std::ostream& operator<<(std::ostream &ostream, const TSet &s) // вывод
{
    ostream << "{ ";
    bool first = true;
    for (int i = 0; i < s.GetMaxPower(); ++i) {
        if (s.IsMember(i)) {
            ostream << (first? "": ", ") << i;
            first = false;
        }
    }
    ostream << " }";
    return ostream;
}
