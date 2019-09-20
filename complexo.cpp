// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
  this->real_ = 0;
  this->imag_ = 0;
}

Complexo::Complexo(double a) {
  this->real_ = a;
}

Complexo::Complexo(double a, double b) {
  this->real_ = a;
  this->imag_ = b;
}

double Complexo::real() {
  return this->real_;
}

double Complexo::imag() {
  return this->imag_;
}

bool Complexo::operator==(Complexo x) {
  if((x.real_ == this->real_) && (x.imag_ == this->imag_))
    return true;
  else
    return false;
}

void Complexo::operator=(Complexo x) {
  this->real_ = x.real_;
  this->imag_ = x.imag_;
}

double Complexo::modulo() {
  return (sqrt(pow(this->real_, 2) + pow(this->imag_, 2)));
}

Complexo Complexo::conjugado() {
  this->imag_ = (-1) * (this->imag_);
}

Complexo Complexo::operator-() {
  this->real_ = (-1) * (this->real_);
  this->imag_ = (-1) * (this->imag_);
}

Complexo Complexo::inverso() {
  
  Complexo i;
  double denominador = (1 + pow(this->imag_, 2));
 
  this->conjugado();
  i.real_ = (this->real_ / denominador);
  i.imag_ = (this->imag_ / denominador);

  return i;
}

Complexo Complexo::operator+(Complexo y) {

  Complexo s;

  s.real_ = this->real_ + y.real_;
  s.imag_ = this->imag_ + y.imag_;

  return s;
}

Complexo Complexo::operator-(Complexo y) {
 
  Complexo c;

  c.real_ = this->real_ - y.real_;
  c.imag_ = this->imag_ - y.imag_;
  
  return c;
}

Complexo Complexo::operator*(Complexo y) {
  
  Complexo p;

  p.real_ = this->real_ * y.real_;
  p.imag_ = this->imag_ * y.imag_;

  return p;
}

Complexo Complexo::operator/(Complexo y) {
 
  Complexo c;

  c.real_ = this->real_ / y.real_;
  c.imag_ = this->imag_ / y.imag_;

  return c;
}

