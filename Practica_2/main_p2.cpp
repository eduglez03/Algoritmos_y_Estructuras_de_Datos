// AUTOR: Eduardo González Gutiérrez
// FECHA: 27 de febrero de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: esta práctica se ha llevado a cabo bajo las condiciones de la guía de estilo de Google
// COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2

#include <iostream>
#include <cmath>

#include "rational_t.hpp"
#include "vector_t.hpp"
#include "matrix_t.hpp"

int main() {
  rational_t a(1, 2), b(3);

  // FASE I
  // Sobrecarga operador suma
  std::cout << "a + b: ";
  (a+b).write();

  // Sobrecarga operador resta
  std::cout << "b - a: ";
  (b-a).write();

  // Sobrecarga operador multiplicacion
  std::cout << "a * b: ";
  (a*b).write();

  // Sobrecarga operador division
  std::cout << "a / b: ";
  (a/b).write();
  std::cout << endl;
  
  // FASE II
  // Producto escalar de vectores tipo double
  vector_t<double> v, w;
  v.read(), v.write();
  w.read(), w.write();
  std::cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) << std::endl << std::endl;
  
  //Producto escalar de vectores tipo rational_t
  vector_t<rational_t> x, y;
  x.read(), x.write();
  y.read(), y.write();
  std::cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << std::endl << std::endl;

  // FASE III
  matrix_t<double> A, B, C;
  A.read(), A.write();
  B.read(), B.write();
  
  // Producto de dos matrices
  C.multiply(A, B);
  std::cout << "Multiplicación de matrices A y B: " << std::endl;
  C.write();

  std::cout << "---------------------------------------- MODIFICACIONES --------------------------------------------" << std::endl;

  // POSIBLE MODIFICACION: Suma de la diagonal principal de una matriz
  double sum_diag{0};
  std::cout << "La suma de la diagonal principal de la matriz es: " << std::endl;
  sum_diag = A.sum_diag(A);
  std::cout << sum_diag << std::endl << std::endl;

  // POSIBLE MODIFICACION: Suma de la diagonal secundaria de una matriz
  double sum_sec{0};
  std::cout << "La suma de la diagonal secundaria de la matriz es: " << std::endl;
  sum_sec = A.sum_sec(A);
  std::cout << sum_sec << std::endl << std::endl;

  // POSIBLE MODIFICACION: Traspuesta de una matriz
  std::cout << "Traspuesta de A: " << std::endl;
  C.traspuesta(A);
  C.write();

  // POSIBLE MODIFICACION: Suma de los valores de las filas pares de una matriz
  std::cout << "La suma de los valores de las filas pares de la matriz es: " << std::endl;
  A.filas_pares();

  // POSIBLE MODIFICACION: Mostrar los valores que se encuentran en las posiciones pares de un vector
  std::cout << "Los valores de las posiciones pares del vector son: " << std::endl;
  elementos_pares(x);

  // POSIBLE MODIFICACION: Sumar elementos de un vector de dos en dos
  std::cout << "La suma acumulada de los valores de dos en dos del vector es: " << std::endl;
  Suma2a2(v);

  // POSIBLE MODIFICACION: Suma elementos en posiciones multiplos de tres de un vector
  std::cout << "La suma de los elementos en posiciones multiplo de tres del vector es: " << std::endl;
  SumaMultiplos(v);

  // POSIBLE MODIFICACION: Suma de los elementos de cada fila y almacenarlos en un vector
  std::cout << "La suma de los valores de cada fila son: " << std::endl;
  A.SumarFilas();

  // MODIFICACION QUE ME TOCO EN CLASE
  std::cout << "La serpiente es: " << std::endl;
  A.Serpiente();
  
  return 0;
}