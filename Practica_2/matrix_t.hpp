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
#include <vector>

#include "vector_t.hpp"

template<class T> class matrix_t {
  public:
    // Constructor y destructor de la clase matrix_t
    matrix_t(const int = 0, const int = 0);
    ~matrix_t();
    
    // Metodo para redimencionar una matriz
    void resize(const int, const int);
  
    // getters
    int get_m(void) const;
    int get_n(void) const;
  
    // getters-setters
    T& at(const int, const int);
    T& operator()(const int, const int);
  
    // getters constantes
    const T& at(const int, const int) const;
    const T& operator()(const int, const int) const;
  
    // operaciones y operadores
    void multiply(const matrix_t<T>&, const matrix_t<T>&);
    
    // Sobrecarga operadores de lectura de teclado y escritura por pantalla
    void write(ostream& = cout) const;
    void read(istream& = cin);


    // MODIFICACIONES
    double sum_diag(const matrix_t<T>& A);
    double sum_sec(const matrix_t<T>& A);
    void traspuesta(const matrix_t<T>& A);
    void filas_pares();
    void SumarFilas();

  private:
    int m_, n_; // m_ filas y n_ columnas
    vector_t<T> v_;
  
    int pos(const int, const int) const;
};


/**
 * @brief Construct a new matrix t<T>::matrix t object
 * 
 * @tparam T 
 * @param m 
 * @param n 
 */
template<class T> matrix_t<T>::matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

/**
 * @brief Destroy the matrix t<T>::matrix t object
 * 
 * @tparam T 
 */
template<class T> matrix_t<T>::~matrix_t() {}

/**
 * @brief Metodo que redimensiona una matrix_t
 * 
 * @tparam T 
 * @param m 
 * @param n 
 */
template<class T> void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}

/**
 * @brief Getter filas
 * 
 * @tparam T 
 * @return int 
 */
template<class T> inline int matrix_t<T>::get_m() const {
  return m_;
}

/**
 * @brief Getter columnas
 * 
 * @tparam T 
 * @return int 
 */
template<class T> inline int matrix_t<T>::get_n() const {
  return n_;
}

/**
 * @brief Getter posicion [m,n] matrix_t
 * 
 * @tparam T 
 * @param i 
 * @param j 
 * @return T& 
 */
template<class T> T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

/**
 * @brief Sobrecarga operador ()
 * 
 * @tparam T 
 * @param i 
 * @param j 
 * @return T& 
 */
template<class T> T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}

/**
 * @brief Getter posicion [m,n] matrix_t
 * 
 * @tparam T 
 * @param i 
 * @param j 
 * @return const T& 
 */
template<class T> const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}

/**
 * @brief Sobrecarga operador ()
 * 
 * @tparam T 
 * @param i 
 * @param j 
 * @return const T& 
 */
template<class T> const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}

/**
 * @brief Sobrecarga operador escritura por pantalla
 * 
 * @tparam T 
 * @param os 
 */
template<class T> void matrix_t<T>::write(ostream& os) const { 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}

/**
 * @brief Sobrecarga operador lectura desde teclado
 * 
 * @tparam T 
 * @param is 
 */
template<class T> void matrix_t<T>::read(istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

/**
 * @brief Getter posicion matrix_t
 * 
 * @tparam T 
 * @param i 
 * @param j 
 * @return int 
 */
template<class T> inline int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}


// FASE III: producto matricial

/**
 * @brief Producto matricial
 * 
 * @tparam T 
 * @param A 
 * @param B 
 */
template<class T> void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B){
  T C;

  assert(A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());

  for (int i = 1; i <= get_m(); i++) {
    for (int j = 1; j <= get_n(); j++) {
      C = 0;
      for (int k = 1; k <= A.get_n(); k++) {
        C = C + (A(i,k) * B(k,j));
      } 
      at(i,j) = C;
    }
  }
}


// MODIFICACION 

/**
 * @brief Calcular la suma de la diagonal principal de una matriz
 * 
 * @tparam T 
 * @param A 
 * @return double 
 */
template<class T> double matrix_t<T>::sum_diag(const matrix_t<T>& A) {
  double suma{0};

  for (int i = 1; i <= A.get_m() && i <= A.get_n();) {
    suma = suma + A(i, i);
    i++;
  }
  return suma;
}

/**
 * @brief Calcular la suma de la diagonal secundaria de una matriz
 * 
 * @tparam T 
 * @param A 
 * @return double 
 */
template<class T> double matrix_t<T>::sum_sec(const matrix_t<T>& A) {
  double resultado{0};
  int j = A.get_n(); 
  for (int i = 1; i <= A.get_m(); i++) {
    if (j > 0 && j <= A.get_n()) {
      resultado = resultado + A(i, j);
      j--;
    }
  }
  return resultado;
}

/**
 * @brief Traspuesta de una matriz
 * 
 * @tparam T 
 * @param A 
 */
template<class T> void matrix_t<T>::traspuesta(const matrix_t<T>& A) {
  resize(A.get_n(), A.get_m());
  for (int i = 1; i <= A.get_m();) {
    for (int j = 1; j <= A.get_n();) {
      at(j, i) = A(i, j);
      j++;
    }
    i++;
  }
}
 
/**
 * @brief Sumar los valores de las filas pares de una matriz y meterlos en un vector
 * 
 * @tparam T 
 * @param A 
 */
template<class T> void matrix_t<T>::filas_pares() {
  std::vector<double> resultado;
  double suma_valores{0};
  for (int i = 2; i <= get_m();) {
    suma_valores = 0;
    for (int j = 1; j <= get_n();) {
      suma_valores = suma_valores + at(i,j);
      j++;
    } 
    resultado.push_back(suma_valores);
    i = i + 2;
  }

  for(int i = 0; i < resultado.size();) {
    std::cout << resultado[i] << " ";
    i++;
  }
  std::cout << std::endl << std::endl;
}

/**
 * @brief Suma de los elementos de cada fila y almacenarlos en un vector
 * 
 * @tparam T 
 */
template<class T> void matrix_t<T>::SumarFilas() {
  vector<double>sumas;
  double suma{0};

  for (int i = 1; i <= get_m();) {
    suma = 0;
    for ( int j = 1; j <= get_n();) {
      suma = suma + at(i,j);
      j++;
    }
    sumas.push_back(suma);
    i++;
  }

  for (int i = 0; i < sumas.size();) {
    std::cout << sumas[i] << " ";
    i++;
  }
  std::cout << std::endl;
}




template<class T> void matrix_t<T>::Serpiente() {
  vector<double> filas;

  for (int i = 1; i <= get_m();) {
    if (i % 2 != 0) {
      for (int j = 1; j <= get_n();) {
        filas.push_back(at(i,j));
        j++;
      }
    }
    else {
      for (int j = get_n(); j >= 1;) {
        filas.push_back(at(i,j));
        j++;
      }
    } 
    i++;
  }

  for (int i = 0; i < filas.size();) {
    std::cout << filas[i] << " ";
    i++;
  }
  std::cout << std::endl << std::endl;
}
