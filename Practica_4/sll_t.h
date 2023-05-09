// AUTOR: Eduardo González Gutiérrez
// FECHA: 24 de marzo de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLLT_H_
#define SLLT_H_

#include <iostream>
#include <cassert>

#include "sll_node_t.h"

// Clase para almacenar una lista simplemente enlazada
template <class T> class sll_t {
 // Metodos publicos de la clase sll_t
 public:
  // constructor
  sll_t(void) : head_(NULL) {}

  // destructor
  ~sll_t(void);

  // getters
  sll_node_t<T>* get_head(void) const { return head_; };
  
  bool empty(void) const;

  // operaciones
  void push_front(sll_node_t<T>*);
  sll_node_t<T>* pop_front(void);
 
  void insert_after(sll_node_t<T>*, sll_node_t<T>*);
  sll_node_t<T>* erase_after(sll_node_t<T>*);

  sll_node_t<T>* search(const T&) const;

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 // Atributos privados de la clase
 private:
  sll_node_t<T>* head_;
};


/**
 * @brief Destroy the sll t<T>::sll t object
 * 
 * @tparam T 
 */
template <class T> sll_t<T>::~sll_t(void) {
  while (!empty()) {
    sll_node_t<T>* aux = head_;
    head_ = head_->get_next();
    delete aux;
  }
}

/**
 * @brief Metodo que comprueba si una lista esta vacia
 * 
 * @tparam T 
 * @return true 
 * @return false 
 */
template <class T> bool sll_t<T>::empty(void) const {
  return head_ == NULL;
}

// operaciones
/**
 * @brief Metodo que inserta un elemento al comienzo de la lista
 * 
 * @tparam T 
 * @param n 
 */
template <class T> void sll_t<T>::push_front(sll_node_t<T>* n) {
  assert(n != NULL);

  n->set_next(head_);
  head_ = n;
}

/**
 * @brief Metodo que extrae el primer elemento de la lista
 * 
 * @tparam T 
 * @return sll_node_t<T>* 
 */
template <class T> sll_node_t<T>* sll_t<T>::pop_front(void) { 
  assert(!empty());
  sll_node_t<T>* aux = head_;
  head_ = head_->get_next();
  aux->set_next(NULL);

  return aux;
}

/**
 * @brief Metodo que inserta un elemento detras de otro 
 * 
 * @tparam T 
 * @param prev 
 * @param n 
 */
template <class T> void sll_t<T>::insert_after(sll_node_t<T>* prev, sll_node_t<T>* n) {
  assert(prev != NULL && n != NULL);

  n->set_next(prev->get_next());
  prev->set_next(n);
}

/**
 * @brief Elimina el elemento que se encuentra detras de otro en la lista
 * 
 * @tparam T 
 * @param prev 
 * @return sll_node_t<T>* 
 */
template <class T> sll_node_t<T>* sll_t<T>::erase_after(sll_node_t<T>* prev) { 
  assert(!empty());
  assert(prev != NULL);
  sll_node_t<T>* aux = prev->get_next();
  
  assert(aux != NULL);
  prev->set_next(aux->get_next());
  aux->set_next(NULL);

  return aux;
}

/**
 * @brief Metodo que busca un elemento en la lista
 * 
 * @tparam T 
 * @param d 
 * @return sll_node_t<T>* 
 */
template <class T> sll_node_t<T>* sll_t<T>::search(const T& d) const {
  sll_node_t<T>* aux = head_;
  while ((aux != NULL) && (aux->get_data() != d))
    aux = aux->get_next();
    
  return aux;
}

// E/S
/**
 * @brief Sobrecarga metodo escritura en pantalla
 * 
 * @tparam T 
 * @param os 
 * @return std::ostream& 
 */
template <class T> std::ostream& sll_t<T>::write(std::ostream& os) const {
  sll_node_t<T>* aux = head_;

  while (aux != NULL) {
    aux->write(os);
    aux = aux->get_next();
  }
  return os;
}

#endif  // SLLT_H_
