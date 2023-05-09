// AUTOR: Eduardo González Gutiérrez
// FECHA: 24 de abril de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <math.h>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);
  int multiplicar(queue_l_t<char>&);

  
 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
/**
 * @brief Metodo que comprueba operando y operadores
 * 
 * @tparam T 
 * @param q 
 * @return const int 
 */
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }
  return stack_.top();
}

/**
 * @brief Metodo que opera con elementos de la pila
 * 
 * @tparam T 
 * @param c 
 */
template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');
  double elemento1{0};
  double elemento2{0};
  double resultado{0};

  elemento1 = stack_.top();
  stack_.pop();
  std::cout << "   Sacamos de la pila un operando: " << elemento1 << std::endl;
  
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
    elemento2 = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << elemento2 << std::endl;
    
    switch (c) {
      case '+':
        resultado = elemento2 + elemento1;
        break;
    
      case '-':
        resultado = (elemento2 - elemento1);
        break;
    
      case '*':
        resultado = elemento2 * elemento1;
        break;
    
      case '/':
        resultado = elemento2 / elemento1;
        break;

      case '^':
        resultado = pow(elemento2,elemento1);
        break;
    }  
  }
  else if (c == 'r' || c == 'l' || c == 'c') {
    switch (c) {
      case 'r':
        resultado = sqrt(elemento1);
        break;
      
      case 'l':
        resultado = log2(elemento1);
        break;

      case 'c':
        resultado = elemento1 * elemento1;
        break;
    }
  }
  stack_.push(resultado);
  std::cout << "   Metemos en la pila el resultado: " << resultado << std::endl;
}


template<class T> int rpn_t<T>::multiplicar(queue_l_t<char>& k) {
  while (!k.empty()) {
    char c = k.front();
    k.pop();
    
    if (c != '+' || c != '-' || c != '*' || c != '/' || c != '^' || c != 'r' || c != 'l' || c != 'c') {
      stack_.push(c);
    }
  }

  while (!stack_.empty()) {
    int resultado{0};
    int elemento1 = stack_.top();
    stack_.pop();
    int elemento2 = stack_.top();
    stack_.pop();

    resultado = stack_.multiply(elemento1,elemento2);
    stack_.push(resultado);
    std::cout << "Resultado de la multiplicacion: " << resultado << std::endl;
  }

  return stack_.top();
}

#endif  // RPNT_H_