// AUTOR: Eduardo González Gutiérrez
// FECHA: 24 de abril de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  void push(const T&);
  void pop(void);
  const T& top(void) const;
  bool empty(void) const;
  int multiply(const int a, const int b);

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  dll_t<T> l_;
};


template<class T> int stack_l_t<T>::multiply(const int a, const int b) {
  int resultado{0};
  resultado = a * b;
  return resultado;
}





// operaciones
/**
 * @brief Metodo que inserta un elemento al comienzo de la pila
 * 
 * @tparam T 
 * @param dato 
 */
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  l_.push_front(nodo);
}

/**
 * @brief Metodo que extrae el primer elemento de la pila
 * 
 * @tparam T 
 */
template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

/**
 * @brief Metodo que obtiene el primer elemento de la pila
 * 
 * @tparam T 
 * @return const T& 
 */
template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

/**
 * @brief Metodo que comprueba si la pila esta vacia
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

// E/S
/**
 * @brief Metodo para la escritura por pantalla
 * 
 * @tparam T 
 * @param os 
 * @return std::ostream& 
 */
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}


#endif  // STACKL_H_
