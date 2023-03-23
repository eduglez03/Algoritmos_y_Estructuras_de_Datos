// AUTOR: Eduardo González Gutiérrez
// FECHA: 12 de marzo de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

class sparse_vector_t {
 // Metodos publicos de la clase
 public:
  // constructores
  sparse_vector_t(const int = 0);
  sparse_vector_t(const vector_t<double>&, const double = EPS); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia

  // operador de asignación
  sparse_vector_t& operator=(const sparse_vector_t&);

  // destructor
  ~sparse_vector_t();
  
  // getters
  int get_nz(void) const;
  int get_n(void) const;

  // getters-setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);
  
  // getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;

  // E/S
  void write(std::ostream& = std::cout) const;

 // Atributos privados de la clase
 private:
  pair_vector_t pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  //bool IsNotZero(const double, const double = EPS) const;
};

/**
 * @brief Metodo que comprueba si un elemento del vector es 0
 * 
 * @param val 
 * @param eps 
 * @return true 
 * @return false 
 */
bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

/**
 * @brief Metodo que calcula el numero de elementos no cero de un polinomio
 * 
 * @tparam T 
 * @param pol 
 * @return int 
 */
template<class T> int NoZero(const vector_t<T>& pol) {
  int nozero{0};

  for (int i = 0; i < pol.get_size(); i++) {
    if (IsNotZero(pol[i])) ++nozero;
  }
  return nozero;
}

/**
 * @brief Construct a new sparse vector t::sparse vector t object
 * 
 * @param n 
 */
sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

// FASE II
/**
 * @brief Construct a new sparse vector t::sparse vector t object
 * 
 * @param v 
 * @param eps 
 */
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps) : pv_(), nz_(0), n_(0) {
  int size{0};
  int contador{0};

  for (int i = 0; i < v.get_size(); i++) {
    if (IsNotZero(v[i])) {
      size++;
    }
  }

  pv_.resize(size);
  for (int i = 0; i < v.get_size(); i++) {
    if (IsNotZero(v[i])) {
      pv_[contador] = pair_double_t(v[i], i);
      ++contador;
    }
  }

  nz_ = size;
  n_ = v.get_size();
}

/**
 * @brief Construct a new sparse vector t::sparse vector t object
 * 
 * @param w 
 */
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // se invoca directamente al operator=
}

/**
 * @brief operador de asignación
 * 
 * @param w 
 * @return sparse_vector_t& 
 */
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}

/**
 * @brief Destroy the sparse vector t::sparse vector t object
 * 
 */
sparse_vector_t::~sparse_vector_t() {}

/**
 * @brief Metodo que obtiene el tamaño de un vector contando solo con los elementos no cero
 * 
 * @return int 
 */
inline int sparse_vector_t::get_nz() const {
  return nz_;
}

/**
 * @brief Metodo que obtiene el tamaño de un vector con los ceros y los no cero
 * 
 * @return int 
 */
inline int sparse_vector_t::get_n() const {
  return n_;
}

/**
 * @brief Metodo que accede a una posicion concreta del vector disperso
 * 
 * @param i 
 * @return pair_double_t& 
 */
pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief Sobrecarga operador [] para vectores dispersos
 * 
 * @param i 
 * @return pair_double_t& 
 */
pair_double_t& sparse_vector_t::operator[](const int i) {
  return at(i);
}

/**
 * @brief Metodo que accede a una posicion concreta de un vector disperso para constante
 * 
 * @param i 
 * @return const pair_double_t& 
 */
const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief Sobrecarga oeprador [] para constante
 * 
 * @param i 
 * @return const pair_double_t& 
 */
const pair_double_t& sparse_vector_t::operator[](const int i) const {
  return at(i);
}

// E/S
/**
 * @brief Operador para la escritura sde un vector disperso
 * 
 * @param os 
 */
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

/**
 * @brief Sobrecarga operador extraccion
 * 
 * @param os 
 * @param sv 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_
