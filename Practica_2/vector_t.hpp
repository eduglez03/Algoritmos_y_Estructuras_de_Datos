// AUTOR: Eduardo González Gutiérrez
// FECHA: 27 de febrero de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: esta práctica se ha llevado a cabo bajo las condiciones de la guía de estilo de Google

#pragma once

#include <iostream>
#include <cassert>
#include<vector>

using namespace std;

template<class T> class vector_t {
  // Metodos publicos de la clase vector_t
  public:
    // Constructor y destructor de la clase 
    vector_t(const int = 0);
    ~vector_t();
    
    // Metodo que redimensiona un vector_t
    void resize(const int);
  
    // getters
    T get_val(const int) const;
    int get_size(void) const;
  
    // setters
    void set_val(const int, const T);
  
    // getters-setters
    T& at(const int);
    T& operator[](const int);
  
    // getters constantes
    const T& at(const int) const;
    const T& operator[](const int) const;
    
    // Sobrecarga operadores de lectura de teclado y escritura en pantalla
    void write(ostream& = cout) const;
    void read(istream& = cin);

  // Atributos privados de la clase
  private:
    T *v_;
    int sz_;
    void build(void);
    void destroy(void);
};


/**
 * @brief Construct a new vector t<T>::vector t object
 * 
 * @tparam T 
 * @param n 
 */
template<class T> vector_t<T>::vector_t(const int n) { sz_ = n;
  build();
}

/**
 * @brief Destroy the vector t<T>::vector t object
 * 
 * @tparam T 
 */
template<class T> vector_t<T>::~vector_t() {
  destroy();
}

/**
 * @brief Función que llama al constructor
 * 
 * @tparam T 
 */
template<class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

/**
 * @brief Funcion que llama al destructor
 * 
 * @tparam T 
 */
template<class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

/**
 * @brief Metodo que redimenciona un vector_t
 * 
 * @tparam T 
 * @param n 
 */
template<class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

/**
 * @brief Getter valor concreto del vector
 * 
 * @tparam T 
 * @param i 
 * @return T 
 */
template<class T> inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief Getter tamaño vector
 * 
 * @tparam T 
 * @return int 
 */
template<class T> inline int vector_t<T>::get_size() const {return sz_;}

/**
 * @brief Setter valor concreto del vector
 * 
 * @tparam T 
 * @param i 
 * @param d 
 */
template<class T> void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

/**
 * @brief Getter posicion vector
 * 
 * @tparam T 
 * @param i 
 * @return T& 
 */
template<class T> T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief Sobrecarga operador [] que nos permite acceder a una posicion concreta del vector
 * 
 * @tparam T 
 * @param i 
 * @return T& 
 */
template<class T> T& vector_t<T>::operator[](const int i) {return at(i);}

/**
 * @brief Getter posicion vector para constante
 * 
 * @tparam T 
 * @param i 
 * @return const T& 
 */
template<class T> const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

// Sobrecarga operador [] que nos permite acceder a una posicion concreta del vector para constente
template<class T> const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}

/**
 * @brief Sobrecarga operador escritura por pantalla
 * 
 * @tparam T 
 * @param os 
 */
template<class T> void vector_t<T>::write(ostream& os) const { 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}

/**
 * @brief Sobrecarga operador lectura de teclado
 * 
 * @tparam T 
 * @param is 
 */
template<class T> void vector_t<T>::read(istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar

/**
 * @brief Productor escalar de dos vectores para tipo rational_t
 * 
 * @tparam T 
 * @param v 
 * @param w 
 * @return T 
 */
template<class T> T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {
  T resultado{0};

  for (int i = 0; i < v.get_size() || i < w.get_size();) {
    resultado = resultado + (v[i] * w[i]);
    i++;
  }
  return resultado;
}

/**
 * @brief Productor escalar para dos vectores de tipo double
 * 
 * @param v 
 * @param w 
 * @return double 
 */
double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  double resultado{0};

  for (int i = 0; i < v.get_size() || i < w.get_size();) {
    resultado = resultado + (v[i].value()) * (w[i].value());
    i++;
  }
  return resultado;
}


// MODIFICACION

/**
 * @brief Mostrar los elementos que se encuentran en las posiciones pares del vector
 * 
 * @param v 
 */
void elementos_pares(const vector_t<rational_t>& v) {
  std::vector<double> elementos;

  for (int i= 0; i < v.get_size();) {
    if (i % 2 == 0) {
      elementos.push_back(v[i].value());
    }
    i++;
  }

  for (int i = 0; i < elementos.size();) {
    std::cout << elementos[i] << " ";
    i++;
  }
  std::cout << std::endl << std::endl;
}

/**
 * @brief Sumar elementos de un vector de dos en dos
 * 
 * @param v 
 */
void Suma2a2(const vector_t<double>& v) {
  vector_t<double> solucion;
  double suma{0};

  for (int i = 0; i < (v.get_size() - 1);) {
    suma = (v[i] + v[i + 1]);
    std::cout << suma << " ";
    i++;
  }
  std::cout << std::endl << std::endl;
}

/**
 * @brief Suma elementos en posiciones multiplos de tres de un vector
 * 
 * @param v 
 */
void SumaMultiplos(const vector_t<double>& v) {
  double suma{0};
  
  for (int i = 0; i <= v.get_size();) {
    if (i % 3 == 0) {
      suma = suma + (v.get_val(i));
    }
    i++;
  }
  std::cout << suma << std::endl << std::endl;
}