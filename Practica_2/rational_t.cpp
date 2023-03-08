// AUTOR: Eduardo González Gutiérrez
// FECHA: 27 de febrero de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: esta práctica se ha llevado a cabo bajo las condiciones de la guía de estilo de Google

#include "rational_t.hpp"

/**
 * @brief Construct a new rational t::rational t object
 * 
 * @param n 
 * @param d 
 */
rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

/**
 * @brief Getter numerador
 * 
 * @return int 
 */
inline int rational_t::get_num() const {return num_;}

/**
 * @brief Getter denominador
 * 
 * @return int 
 */
inline int rational_t::get_den() const {return den_;}

/**
 * @brief Setter numerador
 * 
 * @param n 
 */
void rational_t::set_num(const int n) {
  num_ = n;
}

/**
 * @brief Setter denominador
 * 
 * @param d 
 */
void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

/**
 * @brief Metodo que obtiene el valor decimal de un numero fraccionario
 * 
 * @return double 
 */
inline double rational_t::value() const {return double(get_num()) / get_den();}

/**
 * @brief Metodo que obtiene el opuesto de un numero racional
 * 
 * @return rational_t 
 */
rational_t  rational_t::opposite() const { 
  return rational_t((-1)*get_num(), get_den());
}

/**
 * @brief Metodo que obtiene el reciproco de un numero racional
 * 
 * @return rational_t 
 */
rational_t rational_t::reciprocal() const { 
  return rational_t(get_den(), get_num());
}

// Comparaciones

/**
 * @brief Metodo que comprueba si dos racionales son iguales
 * 
 * @param r 
 * @param precision 
 * @return true 
 * @return false 
 */
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}

/**
 * @brief Metodo que comprueba si un racional es mayor que otro
 * 
 * @param r 
 * @param precision 
 * @return true 
 * @return false 
 */
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return (value() - r.value()) > precision;
}

/**
 * @brief Metodo que comprueba si un racional es menor que otro 
 * 
 * @param r 
 * @param precision 
 * @return true 
 * @return false 
 */
bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);
}

// Operaciones

/**
 * @brief Metodo que suma dos racionales
 * 
 * @param r 
 * @return rational_t 
 */
rational_t rational_t::add(const rational_t& r) const {
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), get_den() * r.get_den());
}

/**
 * @brief Metodo que resta dos racionales
 * 
 * @param r 
 * @return rational_t 
 */
rational_t rational_t::substract(const rational_t& r) const {
  return add(r.opposite());
}

/**
 * @brief Metodo que multiplica dos racionales
 * 
 * @param r 
 * @return rational_t 
 */
rational_t rational_t::multiply(const rational_t& r) const {
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}

/**
 * @brief Metodo que divide dos racionales
 * 
 * @param r 
 * @return rational_t 
 */
rational_t rational_t::divide(const rational_t& r) const {
  return multiply(r.reciprocal());
}


// FASE I: operadores

/**
 * @brief Sobrecarga operador suma
 * 
 * @param a 
 * @param b 
 * @return rational_t 
 */
rational_t operator+(const rational_t& a, const rational_t& b) {
  return rational_t(a.get_num() * b.get_den() + a.get_den() * b.get_num(), a.get_den() * b.get_den());
}

/**
 * @brief Sobrecarga operador resta
 * 
 * @param a 
 * @param b 
 * @return rational_t 
 */
rational_t operator-(const rational_t& a, const rational_t& b) {
  return rational_t (((b.get_num() * a.get_den()) + (b.get_den() * (-1 * a.get_num()))), (b.get_den() * a.get_den()));
}

/**
 * @brief Sobrecarga operador multiplicacion
 * 
 * @param a 
 * @param b 
 * @return rational_t 
 */
rational_t operator*(const rational_t& a, const rational_t& b) {
  return rational_t(a.get_num() * b.get_num(), a.get_den() * b.get_den());
}

/**
 * @brief Sobrecarga operador division
 * 
 * @param a 
 * @param b 
 * @return rational_t 
 */
rational_t operator/(const rational_t& a, const rational_t& b) {
  return rational_t(a.get_num() * b.get_den(), a.get_den() * b.get_num());
}


// E/S

/**
 * @brief Sobrecarga operador para escritura por pantalla
 * 
 * @param os 
 */
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

/**
 * @brief Sobrecarga operador para lectura de teclado
 * 
 * @param is 
 */
void rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}

/**
 * @brief Sobrecarga operador extraccion
 * 
 * @param os 
 * @param r 
 * @return ostream& 
 */
ostream& operator<<(ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}

/**
 * @brief Sobrecarga operador insercion
 * 
 * @param is 
 * @param r 
 * @return istream& 
 */
istream& operator>>(istream& is, rational_t& r) {
  r.read(is);
  return is;
}