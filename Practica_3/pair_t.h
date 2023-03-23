// AUTOR: Eduardo González Gutiérrez
// FECHA: 12 de marzo de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 // Metodos publicos de la clase pair_t
 public:
  // constructores
  pair_t(void); 
  pair_t(T, int);

  // destructor
  ~pair_t(void);

  // getters & setters
  T get_val(void) const;
  int get_inx(void) const;
  void set(T, int);

  // E/S
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;

 // Atributos privados de la clase pair_t
 private:
  T val_;
  int inx_;
};

/**
 * @brief Construct a new pair t<T>::pair t object
 * 
 * @tparam T 
 */
template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}

/**
 * @brief Construct a new pair t<T>::pair t object
 * 
 * @tparam T 
 * @param val 
 * @param inx 
 */
template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

/**
 * @brief Destroy the pair t<T>::pair t object
 * 
 * @tparam T 
 */
template<class T> pair_t<T>::~pair_t() {}

/**
 * @brief Setter
 * 
 * @tparam T 
 * @param val 
 * @param inx 
 */
template<class T> void pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

/**
 * @brief Getter indice
 * 
 * @tparam T 
 * @return int 
 */
template<class T> int pair_t<T>::get_inx() const {
  return inx_;
}

/**
 * @brief Getter valor
 * 
 * @tparam T 
 * @return T 
 */
template<class T> T pair_t<T>::get_val() const {
  return val_;
}

/**
 * @brief Metodo de lectura desde teclado
 * 
 * @tparam T 
 * @param is 
 * @return std::istream& 
 */
template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

/**
 * @brief Metodo para escritura en pantalla
 * 
 * @tparam T 
 * @param os 
 * @return std::ostream& 
 */
template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

/**
 * @brief Sobrecarga operador extraccion
 * 
 * @tparam T 
 * @param os 
 * @param p 
 * @return std::ostream& 
 */
template<class T> std::ostream& operator<<(std::ostream& os, const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
