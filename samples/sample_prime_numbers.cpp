// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_prime_numbers.cpp - Copyright (c) Гергель В.П. 20.08.2000
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Тестирование битового поля и множества

#include <iomanip>

using namespace std;

//#define USE_SET // Использовать класс TSet,
// закоментировать, чтобы использовать битовое поле

#ifndef USE_SET // Использовать класс TBitField

#include "tbitfield.h"


int main() {
    int n, m, k, count;

    cout << "Testing program support of bit set" << endl;
    cout << "       Sieve of Eratosthenes      " << endl;
    cout << "Please, input upper limit:  ";
    cin >> n;
    TBitField s(n + 1);

    for (m = 2; m <= n; m++)
        s.SetBit(m);
    for (m = 2; m * m <= n; m++)
        if (s.GetBit(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.GetBit(k))
                    s.ClrBit(k);

    cout << endl << "Set of undivided number: " << s << endl;
    cout << endl << "Prime numbers: ";
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.GetBit(m)) {
            count++;
            cout << setw(3) << m << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }
    cout << endl << "In first " << n << " elements count " << count << " prime number" << endl;
}

#else

#include "tset.h"

int main()
{
  int n, m, k, count;

  cout << "Testing program support of bit set" << endl;
  cout << "       Sieve of Eratosthenes      " << endl;
  cout << "Please, input upper limit:  ";
  cin  >> n;
  TSet s(n + 1);

  for (m = 2; m <= n; m++)
    s.InsElem(m);
  for (m = 2; m * m <= n; m++)
    if (s.IsMember(m))
      for (k = 2 * m; k <= n; k += m)
       if (s.IsMember(k))
         s.DelElem(k);

  cout << endl << "Set of undivided number: " << endl << s << endl;
  cout << endl << "Prime numbers: " << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= n; m++)
    if (s.IsMember(m))
    {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  cout << endl;
  cout << "In first " << n << " elements count " << count << " prime number" << endl;
}

#endif