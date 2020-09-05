#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
#include "WyliczanieSplotu.h"

int main()
{
  double v;
  int m;
  cerr << "Pojemnosc V: ";
  cin >> v;

  while (true)
  {
    cerr << "Liczba klas ruchu (minimum 1 maksimum 5): ";
    cin >> m;
    if (m > 0 && m < 6)break;
  }
  cerr << endl;
  vector<long double> vector_a;
  long double pomocnicza;
  for (auto n = 1; n <= m; n++)
  {
    cerr << "Natezenie ruchu A(" << n << "): ";
    cin >> pomocnicza;
    vector_a.push_back(pomocnicza);
  }
  vector<int> vector_t;

  for (auto n = 1; n <= m; n++)
  {
    cerr << "\nNatezenie liczbe t(" << n << "): ";
    cin >> pomocnicza;
    vector_t.push_back(static_cast<int>(pomocnicza));
  }
  cout << endl;

  const auto len = static_cast<int>(v + 1);
  auto splot = new WyliczanieSplotu(&vector_a, &vector_t, v, m, len);
  splot->Rozpocznij();
}
