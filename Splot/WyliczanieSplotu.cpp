#include "WyliczanieSplotu.h"

WyliczanieSplotu::WyliczanieSplotu(vector<long double>* vector_a, vector<int>* vector_t, const double v, const int m,
                                   const int len) : vector_a_(vector_a), v_(v), m_(m), vector_t_(vector_t), len_(len)
{
}

void WyliczanieSplotu::WyliczanieRozkladuZajetosci(double* p, const double a, const int t, const double v)
{
  p[0] = 1;

  long double temp;
  for (auto n = 1; n <= v; n++)
  {
    if ((n - t) < 0)
      temp = 0;
    else
      temp = p[n - t];
    const auto suma_wew = (a * long double(t) * temp);
    p[n] = (1 / long double(n)) * suma_wew;
  }
  cout << endl;
}

void WyliczanieSplotu::LiczSplot(double* a, double* b, double* c, const int len)
{
  int i, j, i1;
  double tmp;

  const auto nconv = 2 * len - 1;

  for (i = 0; i < nconv; i++)
  {
    i1 = i;
    tmp = 0.0;
    for (j = 0; j < len; j++)
    {
      if (i1 >= 0 && i1 < len)
        tmp = tmp + (a[i1] * b[j]);

      i1 = i1 - 1;
      c[i] = tmp;
    }
  }

  const auto amount = (len);
  cout << endl;

  for (auto k = 0; k < amount; k++)
  {
    cout << "splot : " << c[k] << endl;
  }
  cout << endl;
}

void WyliczanieSplotu::Normalizacja(double* p, double* pn, const double v, const int klasa)
{
  long double suma_p = 0;
  for (auto n = 0; n <= v; n++)
  {
    suma_p += p[n];
  }
  for (auto n = 0; n <= v; n++)
  {
    pn[n] = p[n] / suma_p;
    cout << endl << klasa << " klasa po normalizacji P[" << n << "] = " << pn[n];
  }
  cout << endl;
}

void WyliczanieSplotu::Blokada(double* splot, double* e, const double m, const double v, vector<int>* vector_t)
{
  for (auto i = 0; i < m; i++)
  {
    e[i] = 0;
    for (auto n = static_cast<int>(v - vector_t->at(i) + 1); n <= v; n++)
    {
      e[i] += splot[n];
    }
    cout << endl << "E[" << i << "] = " << e[i];
  }
}

void WyliczanieSplotu::Rozpocznij()
{
  if (m_ == 1)
  {
    WyliczanieRozkladuZajetosci(p1_, vector_a_->at(0), vector_t_->at(0), v_);
    Normalizacja(p1_, pn1_, v_, 1);
    Blokada(p1_, e_, m_, v_, vector_t_);
  }
  else if (m_ == 2)
  {
    WyliczanieRozkladuZajetosci(p1_, vector_a_->at(0), vector_t_->at(0), v_);
    WyliczanieRozkladuZajetosci(p2_, vector_a_->at(1), vector_t_->at(1), v_);
    Normalizacja(p1_, pn1_, v_, 1);
    Normalizacja(p2_, pn2_, v_, 2);

    LiczSplot(pn1_, pn2_, splot12_, len_);
    Normalizacja(splot12_, splot12_n_, v_, 1);
    Blokada(splot12_n_, e_, m_, v_, vector_t_);
  }
  else if (m_ == 3)
  {
    WyliczanieRozkladuZajetosci(p1_, vector_a_->at(0), vector_t_->at(0), v_);
    WyliczanieRozkladuZajetosci(p2_, vector_a_->at(1), vector_t_->at(1), v_);
    WyliczanieRozkladuZajetosci(p3_, vector_a_->at(2), vector_t_->at(2), v_);
    Normalizacja(p1_, pn1_, v_, 1);
    Normalizacja(p2_, pn2_, v_, 2);
    Normalizacja(p3_, pn3_, v_, 3);

    LiczSplot(pn1_, pn2_, splot12_, len_);
    Normalizacja(splot12_, splot12_n_, v_, 1);
    LiczSplot(splot12_n_, pn3_, splot123_, len_);
    Normalizacja(splot123_, splot123_n_, v_, 1);
    Blokada(splot123_n_, e_, m_, v_, vector_t_);
  }
  else if (m_ == 4)
  {
    WyliczanieRozkladuZajetosci(p1_, vector_a_->at(0), vector_t_->at(0), v_);
    WyliczanieRozkladuZajetosci(p2_, vector_a_->at(1), vector_t_->at(1), v_);
    WyliczanieRozkladuZajetosci(p3_, vector_a_->at(2), vector_t_->at(2), v_);
    WyliczanieRozkladuZajetosci(p4_, vector_a_->at(3), vector_t_->at(3), v_);
    Normalizacja(p1_, pn1_, v_, 1);
    Normalizacja(p2_, pn2_, v_, 2);
    Normalizacja(p3_, pn3_, v_, 3);
    Normalizacja(p4_, pn4_, v_, 4);

    LiczSplot(pn1_, pn2_, splot12_, len_);
    Normalizacja(splot12_, splot12_n_, v_, 1);
    LiczSplot(splot12_n_, pn3_, splot123_, len_);
    Normalizacja(splot123_, splot123_n_, v_, 1);
    LiczSplot(splot123_n_, pn4_, splot1234_, len_);
    Normalizacja(splot1234_, splot1234_n_, v_, 1);
    Blokada(splot1234_n_, e_, m_, v_, vector_t_);
  }
  else if (m_ == 5)
  {
    WyliczanieRozkladuZajetosci(p1_, vector_a_->at(0), vector_t_->at(0), v_);
    WyliczanieRozkladuZajetosci(p2_, vector_a_->at(1), vector_t_->at(1), v_);
    WyliczanieRozkladuZajetosci(p3_, vector_a_->at(2), vector_t_->at(2), v_);
    WyliczanieRozkladuZajetosci(p4_, vector_a_->at(3), vector_t_->at(3), v_);
    WyliczanieRozkladuZajetosci(p5_, vector_a_->at(4), vector_t_->at(4), v_);
    Normalizacja(p1_, pn1_, v_, 1);
    Normalizacja(p2_, pn2_, v_, 2);
    Normalizacja(p3_, pn3_, v_, 3);
    Normalizacja(p4_, pn4_, v_, 4);
    Normalizacja(p5_, pn5_, v_, 5);

    LiczSplot(pn1_, pn2_, splot12_, len_);
    Normalizacja(splot12_, splot12_n_, v_, 1);
    LiczSplot(splot12_n_, pn3_, splot123_, len_);
    Normalizacja(splot123_, splot123_n_, v_, 1);
    LiczSplot(splot123_n_, pn4_, splot1234_, len_);
    Normalizacja(splot1234_, splot1234_n_, v_, 1);
    LiczSplot(splot1234_n_, pn5_, splot12345_, len_);
    Normalizacja(splot12345_, splot12345_n_, v_, 1);
    Blokada(splot12345_n_, e_, m_, v_, vector_t_);
  }
  else
  {
    cerr << "B��D" << endl;
    cin.get();
  }
}
