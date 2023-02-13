// AUTOR: Eduardo González Gutiérrez
// FECHA: 13 de febrero de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: Se lleva a cabo la practica bajo las condiciones de la guía de estilo de google

#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

# define EPSILON 1e-6

class rational_t {
  //Metodos publicos de la clase
  public:
    rational_t(const int = 0, const int = 1); // Constructor de la clase
    ~rational_t() {} // Destructor de la clase
  
    // Getters
    int get_num() const;
    int get_den() const;
  
    // Setters
    void set_num(const int);
    void set_den(const int);

    double value(void) const;

    // FASE II
    bool is_equal(const rational_t&, const double precision = EPSILON) const;
    bool is_greater(const rational_t&, const double precision = EPSILON) const;
    bool is_less(const rational_t&, const double precision = EPSILON) const;
    bool is_cero(const double precision = EPSILON);
  
    // FASE III
    rational_t add(const rational_t&);
    rational_t substract(const rational_t&);
    rational_t multiply(const rational_t&);
    rational_t divide(const rational_t&);
  
    void write(std::ostream& = std::cout) const; // Escritura a pantalla
    void read(std::istream& = std::cin); // Lectura desde teclado
  
  //Atributos privados de la clase
  private:
    int num_, den_;
};
