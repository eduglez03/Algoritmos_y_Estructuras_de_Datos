// AUTOR: Eduardo González Gutiérrez
// FECHA: 24 de abril de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Programa principal para probar la calculadora de expresiones 
//              en notaión polaca inversa (RPN, Reverse Polish Notation)
// COMPILACIÓN: g++ main_rpn_t.cc -o main_rpn_t
// EJECUCIÓN:
//   ./main_rpn_t < data_rpn_t_1.txt
//   ./main_rpn_t < data_rpn_t_2.txt
//   ./main_rpn_t < data_rpn_t_3.txt

// Compilar con:
// 

#include <iostream>

#include "stack_l_t.h"
#include "queue_l_t.h"
#include "rpn_t.h"

using namespace std;

int main(void) {
  rpn_t<stack_l_t<int>> calculadora;
  rpn_t<stack_l_t<int>> calculadora2;
  queue_l_t<char> cola;
  queue_l_t<char> cola2;
	
  while (!cin.eof()) 	{
    cin >> ws; // lee los espacios en blanco, que dan problemas
    if (!cin.eof()) {
      char c;
      cin >> c;
      cola.push(c);
    }
  }
  cola2 = cola;

  cout << "Expresión a evaluar: ";	
  cola.write();

  int r = calculadora.evaluate(cola);
  cout << "Resultado: " << r << endl;

  std::cout << "---------------------------- MODIFICACION -------------------------------" << std::endl;
  

  int resultado = calculadora2.multiplicar(cola2);
  std::cout << "La multiplicacion es: " << resultado << std::endl;

}

