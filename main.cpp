// Copyright 2010 Universidade Federal de Minas Gerais (UFMG)
//
// Lista de exercícios sobre Tipos Abstratos de Dados.
// Aplicação: Números Complexos - Coordenadas Euclidianas.
//
// QUESTÃO 1:
// Implemente em complexo.cpp as funções descritas em complexo.h.
//
// QUESTÃO 2:
// Escreva um programa que simula uma calculadora de números complexos.
// Ele deve apresentar um menu com as operações de soma, subtração,
// multiplicação, divisão, módulo e conjugado. Após o usuário escolher uma das
// funções, o programa deve ler o valor dos parâmetros e em seguida exibir o
// resultado da função.
//
// QUESTÃO 3:
// Escreva uma função "void CalcularRaizes(float a, float b, float c,
// Complexo* r1, Complexo* r2)" que recebe os coeficientes
// de uma equação de segundo grau "a.x^2 + b.x + c = 0" e retorna por r1 e r2
// as raízes (possivelmente complexas) desta equação.
//
// QUESTÃO 4:
// Escreva um programa que lê do teclado os coeficientes reais de uma equação de
// segundo grau e imprime na tela as raízes (possivelmente complexas) desta
// equação.

#include <cmath>
#include <iostream>
#include <sstream>

#include "complexo.h"

using namespace std;

Complexo criaComplexo(){

  double real, imag;

  cout << "Parte Real: ";
  cin >> real;
  cout << "Parte Imaginaria: ";
  cin >> imag;

  Complexo comp(real, imag);
  
  return comp;
}

void CalcularRaizes(float a, float b, float c, Complexo* r1, Complexo* r2){

  float delta = (pow(b, 2) - (4*a*c));

  if(delta >= 0){

    Complexo aux1((((b*(-1)) + sqrt(delta)) / (2*a)));
    Complexo aux2((((b*(-1)) - sqrt(delta)) / (2*a)));

    *r1 = aux1;
    *r2 = aux2;
  }
  else if(delta < 0){
    Complexo aux1(((b*(-1)) / (2*a)), ((sqrt(delta*(-1)) / (2*a))));
    Complexo aux2(((b*(-1)) / (2*a)), (-(sqrt(delta*(-1)) / (2*a))));

    *r1 = aux1;
    *r2 = aux2;
  }
}

int main() {

  Complexo cp1, cp2;
  int opMenu, opComplexo;
  double real1_, imag1_, real2_, imag2_;


  do{
    cout << "\n\nQue operacao deseja realizar?\n";
    cout << "\n1. Soma\n2. Subtracao\n3. Multiplicacao\n4. Divisao\n5. Modulo\n6. Conjugado\n7. Raizes de equacao de 2 grau\n0. Sair\n\n=>";

    cin >> opMenu;
    cout << "\n";

    switch (opMenu){
      case 1:
        cout << "Soma:\n\n";
        cp1 = criaComplexo();
        cp2 = criaComplexo();
        cout << (cp1 + cp2).real() << " + (" << (cp1 + cp2).imag() << "i)";
      break;

      case 2:
        cout << "Subtracao:\n\n";
        cp1 = criaComplexo();
        cp2 = criaComplexo();
        cout << (cp1-cp2).real() << " + (" << (cp1-cp2).imag() << "i)";
      break;

      case 3:
        cout << "Multiplicacao:\n\n";
        cp1 = criaComplexo();
        cp2 = criaComplexo();
        cout << (cp1 * cp2).real() << " + (" << (cp1 * cp2).imag() << "i)";
      break;

      case 4:
        cout << "Divisao:\n\n";
        cp1 = criaComplexo();
        cp2 = criaComplexo();
        cout << (cp1 / cp2).real() << " + (" << (cp1 / cp2).imag() << "i)";
      break;

      case 5:
        cout << "Modulo:\n\n";
        cp1 = criaComplexo();
        cout << (cp1.modulo());
      break;

      case 6:
        cout << "Conjugado:\n\n";
        cp1 = criaComplexo();
        cp1.conjugado();
        cout << (cp1.real()) << " + (" << (cp1.imag()) << "i)";
      break;

      case 7:
        float a, b, c;
        Complexo r1, r2;
        cout << "Coeficientes da equacao:\n\n";
        cout << "A: ";
        cin >> a;
        cout << "B: ";
        cin >> b;
        cout << "C: ";
        cin >> c;

        CalcularRaizes(a, b, c, &r1, &r2);
        cout << "Raiz 1: " << (r1.real()) << " + (" << (r1.imag()) << "i)\n";
        cout << "Raiz 2: " << (r2.real()) << " + (" << (r2.imag()) << "i)";
      break;

    }
  }while((opMenu > 0) && (opMenu < 7));
  
  return 0;
}
