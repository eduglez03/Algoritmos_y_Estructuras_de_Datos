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
#include <cmath>

using namespace std;

# define EPSILON 1e-6

class rational_t {
  // Metodos publicos de la clase rational_t
  public:
    // Constructor y destructor de la clase
    rational_t(const int = 0, const int = 1);
    ~rational_t() {}
  
    // getters
    int get_num() const;
    int get_den() const;
  
    // setters
    void set_num(const int);
    void set_den(const int);
    
    // Metodo que obtiene el valor de un numero fraccionario
    double value(void) const;

    // Metodo que obtiene el opuesto de un numero racional
    rational_t opposite(void) const;

    // Metodo que obtiene el reciproco de un numero racional
    rational_t reciprocal(void) const;
 
    // Metodos de comparacion
    bool is_equal(const rational_t&, const double precision = EPSILON) const;
    bool is_greater(const rational_t&, const double precision = EPSILON) const;
    bool is_less(const rational_t&, const double precision = EPSILON) const;
    
    // Metodos de operaciones
    rational_t add(const rational_t&) const;
    rational_t substract(const rational_t&) const;
    rational_t multiply(const rational_t&) const;
    rational_t divide(const rational_t&) const;
    
    // Sobrecarga operadores de lectura por teclado y escritura en pantalla
    void write(ostream& os = cout) const;
    void read(istream& is = cin);
  
  // Atributos privados de la clase rational_t
  private:
    int num_, den_;
};


// sobrecarga de los operadores de E/S
ostream& operator<<(ostream& os, const rational_t&);
istream& operator>>(istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);

