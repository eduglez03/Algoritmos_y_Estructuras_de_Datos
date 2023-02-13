// AUTOR: Eduardo González Gutiérrez
// FECHA: 13 de febrero de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: Se lleva a cabo la practica bajo las condiciones de la guía de estilo de google

#include "rational_t.hpp"

//Metodo Constructor de la clase rational_t
rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

//Getter numerador
int rational_t::get_num() const {
  return num_;
}

//Getter denominador
int rational_t::get_den() const {
  return den_;
}

//Setter numerador
void rational_t::set_num(const int n) {
  num_ = n;
}

//Setter denominador
void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

//Metodo que obtiene el valor decimal de una fraccion
double rational_t::value() const { 
  return double(get_num()) / get_den();
}


// Fase 2: Comparaciones

// Metodo que comprueba si dos numeros reales son iguales
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  if (abs(value() - r.value()) < precision) {
    return true;
  } 
  return false;
}

// Metodo que comprueba si un numero real a es mayor que otro numero reaal b
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  if ((value() - r.value()) > precision) {
    return true;
  }
  return false;
}

// Metodo que comprueba si un numero real a es menor que un numero real b
bool rational_t::is_less(const rational_t& r, const double precision) const {
  if ((r.value() - value()) > precision) {
    return true;
  }
  return false;
}

// Metodo que comprueba si un numero real a es igual a 0
bool rational_t::is_cero(const double precision) {
  if (abs(value()) < precision) {
    return true;
  }
  return false;
}


// Fase 3: Operaciones

// Metodo que suma dos numeros racionales
rational_t rational_t::add(const rational_t& r) {
  double numerador = (get_num() * r.get_den()) + (get_den() * r.get_num());
  double denominador = get_den() * r.get_den();
  
  return rational_t (numerador, denominador);
}


// Metodo que resta dos numeros racionales
rational_t rational_t::substract(const rational_t& r) {
  double numerador = ((r.get_num() * get_den()) + (r.get_den() * (-1 * get_num())));
  double denominador = (r.get_den() * get_den());

  return rational_t (numerador, denominador);
}


// Metodo que multiplica dos numeros racionales
rational_t rational_t::multiply(const rational_t& r) {
  double numerador = (get_num() * r.get_num());
  double denominador = (get_den() * r.get_den());

  return rational_t (numerador, denominador);
}


// Metodo que divide dos numeros racionales
rational_t rational_t::divide(const rational_t& r) {
  double numerador = (get_num() * r.get_den());
  double denominador = (get_den() * r.get_num());

  return rational_t (numerador, denominador);
}


// E/S
void rational_t::write(std::ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << std::endl;
}

void rational_t::read(std::istream& is) {
  std::cout << "Numerador? ";
  is >> num_;
  std::cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
