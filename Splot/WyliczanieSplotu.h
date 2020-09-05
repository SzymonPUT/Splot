#pragma once
#include <iostream>
#include <vector>
using namespace std;

class WyliczanieSplotu
{
public:
  WyliczanieSplotu(vector<long double>* vector_a, vector<int>* vector_t, double v, int m, int len);
  static void WyliczanieRozkladuZajetosci(double* p, double a, int t, double v);
  static void LiczSplot(double* a, double* b, double* c, int len);
  static void Normalizacja(double* p, double* pn, double v, int klasa);
  static void Blokada(double* splot, double* e, double m, double v, vector<int>* vector_t);
  void Rozpocznij();

private:
  double p1_[10000] = {};
  double p2_[10000] = {};
  double p3_[10000] = {};
  double p4_[10000] = {};
  double p5_[10000] = {};

  double pn1_[10000] = {};
  double pn2_[10000] = {};
  double pn3_[10000] = {};
  double pn4_[10000] = {};
  double pn5_[10000] = {};

  double splot12_[10000] = {};
  double splot123_[10000] = {};
  double splot1234_[10000] = {};
  double splot12345_[10000] = {};

  double splot12_n_[10000] = {};
  double splot123_n_[10000] = {};
  double splot1234_n_[10000] = {};
  double splot12345_n_[10000] = {};

  double e_[10000] = {};

  vector<long double>* vector_a_;
  double v_;
  int m_;
  vector<int>* vector_t_;
  int len_;
};
