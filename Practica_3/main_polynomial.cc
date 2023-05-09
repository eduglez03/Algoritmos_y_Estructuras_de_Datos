// AUTOR: Eduardo González Gutiérrez
// FECHA: 12 de marzo de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 
// COMPILACIÓN: g++ -g main_polynomial.cc -o main_polynomial
// EJECUCIÓN: ./main_polynomial < data_polynomial.txt

#include <iostream>

#include "polynomial.h"

using namespace std;

int main() {
  Polynomial p1, p2, p3;
  
  cin >> p1 >> p2 >> p3;
  cout << "p1= " << p1;
  cout << "p2= " << p2;
  cout << "p3= " << p3;
  cout << endl;

  // Fase II
  SparsePolynomial sp1(p1), sp2(p2), sp3(p3);
  cout << "sp1= " << sp1;
  cout << "sp2= " << sp2;
  cout << "sp3= " << sp3;
  cout << endl;

  // Fase III
  double x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  cout << "p1(" << x1 << ")= " << p1.Eval(x1) << endl;
  cout << "p1(" << x2 << ")= " << p1.Eval(x2) << endl;
  cout << "p1(" << x3 << ")= " << p1.Eval(x3) << endl;
  cout << "p2(" << x1 << ")= " << p2.Eval(x1) << endl;
  cout << "p2(" << x2 << ")= " << p2.Eval(x2) << endl;
  cout << "p2(" << x3 << ")= " << p2.Eval(x3) << endl;
  cout << "p3(" << x1 << ")= " << p3.Eval(x1) << endl;
  cout << "p3(" << x2 << ")= " << p3.Eval(x2) << endl;
  cout << "p3(" << x3 << ")= " << p3.Eval(x3) << endl;
  cout << endl;

  cout << "sp1(" << x1 << ")= " << sp1.Eval(x1) << endl;
  cout << "sp1(" << x2 << ")= " << sp1.Eval(x2) << endl;
  cout << "sp1(" << x3 << ")= " << sp1.Eval(x3) << endl;
  cout << "sp2(" << x1 << ")= " << sp2.Eval(x1) << endl;
  cout << "sp2(" << x2 << ")= " << sp2.Eval(x2) << endl;
  cout << "sp2(" << x3 << ")= " << sp2.Eval(x3) << endl;
  cout << "sp3(" << x1 << ")= " << sp3.Eval(x1) << endl;
  cout << "sp3(" << x2 << ")= " << sp3.Eval(x2) << endl;
  cout << "sp3(" << x3 << ")= " << sp3.Eval(x3) << endl;
  cout << endl;

  // Fase IV
  cout << "p1 == p1? " << (p1.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p2 == p2? " << (p2.IsEqual(p2) ? "true" : "false") << endl;
  cout << "p3 == p3? " << (p3.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p1 == p2? " << (p1.IsEqual(p2) ? "true" : "false") << endl;
  cout << "p2 == p1? " << (p2.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p1 == p3? " << (p1.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p3 == p1? " << (p3.IsEqual(p1) ? "true" : "false") << endl;
  cout << "p2 == p3? " << (p2.IsEqual(p3) ? "true" : "false") << endl;
  cout << "p3 == p2? " << (p3.IsEqual(p2) ? "true" : "false") << endl;
  cout << endl;

  cout << "sp1 == sp1? " << (sp1.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp2 == sp2? " << (sp2.IsEqual(sp2) ? "true" : "false") << endl;
  cout << "sp3 == sp3? " << (sp3.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp1 == sp2? " << (sp1.IsEqual(sp2) ? "true" : "false") << endl;
  cout << "sp2 == sp1? " << (sp2.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp1 == sp3? " << (sp1.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp3 == sp1? " << (sp3.IsEqual(sp1) ? "true" : "false") << endl;
  cout << "sp2 == sp3? " << (sp2.IsEqual(sp3) ? "true" : "false") << endl;
  cout << "sp3 == sp2? " << (sp3.IsEqual(sp2) ? "true" : "false") << endl;
  cout << endl;

  cout << "sp1 == p1? " << (sp1.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp2 == p2? " << (sp2.IsEqual(p2) ? "true" : "false") << endl;
  cout << "sp3 == p3? " << (sp3.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp1 == p2? " << (sp1.IsEqual(p2) ? "true" : "false") << endl;
  cout << "sp2 == p1? " << (sp2.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp1 == p3? " << (sp1.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp3 == p1? " << (sp3.IsEqual(p1) ? "true" : "false") << endl;
  cout << "sp2 == p3? " << (sp2.IsEqual(p3) ? "true" : "false") << endl;
  cout << "sp3 == p2? " << (sp3.IsEqual(p2) ? "true" : "false") << endl;
  cout << endl;

  // MODIFICACIONES PARA PRACTICAR

  std::cout << "------------------------------------------------------ MODIFICACIONES PARA PRACTICAR --------------------------------------------------" << std::endl;

  // Mostrar por pantalla los numeros de un vector disperso que su indice sea mayor que un numero dado
  coef_mayores(sp1,5);
  std::cout << std::endl;

  // Sumar los coeficientes de un sparce polynomial
  SumaCoeficientes(sp1);
  std::cout << std::endl;
  
  // Imprimir el monomio de mayor y menor grado de un sparse polynomial
  MayorMonomio(sp1);
  std::cout << std::endl;

  // Calcula la suma de los grados de un polinomio
  sum_grados(sp1);
  std::cout << std::endl;

  // Mostrar los valores de las posiciones con grados pares del vector 
  GradosPares(sp1);
  std::cout << std::endl;

  // Calcula los coeficientes de un polinomio disperso
  CoefSpol(sp1);
  std::cout << std::endl;
  
  // Calcula los coeficientes de un polinomio denso
  CoefPol(p1);
  std::cout << std::endl;

  // Obtener el mayor grado de un polinomio denso
  MayorGradoPol(p1);
  std::cout << std::endl;

  // Obtener el mayor grado de un polinomio disperso
  MayorGradoSpol(sp1);
  std::cout << std::endl;

  // Muestra las posiciones que tienen un cero
  print_zeros(sp1);
  std::cout << std::endl;

  // MODIFICACION CLASE
  std::cout << "Monomios Consecutivos en sp1: " << std::endl;
  MonomiosConsecutivos(sp1);
  std::cout << "Monomios Consecutivos en sp2: " << std::endl;
  MonomiosConsecutivos(sp2);
  std::cout << "Monomios Consecutivos en sp3: " << std::endl;
  MonomiosConsecutivos(sp3);

  std::cout << std::endl;
  
  return 0;
}
