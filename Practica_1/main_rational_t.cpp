// AUTOR: Eduardo González Gutiérrez
// FECHA: 13 de febrero de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t
// COMENTARIOS: Se lleva a cabo la practica bajo las condiciones de la guía de estilo de google

#include <iostream>
#include <cmath>

#include "rational_t.hpp"

int main() {
  rational_t a(1, 2), b(3), c;

  std::cout << "a.value()= " << a.value() << std::endl;
  std::cout << "b.value()= " << b.value() << std::endl;
  std::cout << "c.value()= " << c.value() << std::endl;

  std::cout << "a: ";
  a.write();
  std::cout << "b: ";
  b.write();

  c.read();
  std::cout << "c: ";
  c.write();

  // FASE II
  rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();

  std::cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << std::endl;
  std::cout << "x > y? " << (x.is_greater(y) ? "true" : "false") << std::endl;
  std::cout << "x < y? " << (x.is_less(y) ? "true" : "false") << std::endl;
  std::cout << "x = 0? " << (x.is_cero() ? "true" : "false") << std::endl;

  // FASE III
  std::cout << "a + b: ";
  a.add(b).write();
  
  std::cout << "b - a: ";
  b.substract(a).write();

  std::cout << "a * b: ";
  a.multiply(b).write();
  
  std::cout << "a / b: ";
  a.divide(b).write();

  // MODIFICACIÓN
  c.write();
  std::cout << c.get_num() << " / " << c.get_den() << " = " << (c.is_integer() ? "Es entero" : "No es entero") << std::endl;
  
  return 0;
}