// AUTOR: Eduardo González Gutiérrez
// FECHA: 12 de marzo de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 3
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 // Metodos publicos de la clase vector_t
 public:
  // constructores
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol) : vector_t<double>(pol) {}; // constructor de copia

  // destructor
  ~Polynomial() {};

  // E/S
  void Write(std::ostream& = std::cout, const double eps = EPS) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
  Polynomial operator+(const Polynomial& pol);
  Polynomial operator-(const Polynomial& pol);
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 // Metodos publicos de la clase sparse_vector_t
 public:
  // constructores
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia

  // destructor
  ~SparsePolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = EPS) const;
  bool IsEqual(const Polynomial&, const double = EPS) const;
};

// E/S
/**
 * @brief Metodo para escritura por pantalla
 * 
 * @param os 
 * @param eps 
 */
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}

/**
 * @brief Sobrecarga operador extraccion
 * 
 * @param os 
 * @param p 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios
/**
 * @brief Evaluación de un polinomio representado por vector denso
 * 
 * @param x 
 * @return double 
 */
double Polynomial::Eval(const double x) const {
  double result{0.0};
  
  for (int i = 0; i < get_size(); i++) {
    result = result + (get_val(i) * pow(x,i));
  }
  return result;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por vectores densos
 * 
 * @param pol 
 * @param eps 
 * @return true 
 * @return false 
 */
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = true;

  if (NoZero(*this) != NoZero(pol)) differents = false;

  int min = get_size() < pol.get_size() ? get_size() : pol.get_size();

  for(int i = 0; i < min; i++) {
    if(at(i) != pol.at(i)) {
      differents = false;
      break;
    }
  }

  return differents;
}

// constructor de copia
/**
 * @brief Construct a new Sparse Polynomial:: Sparse Polynomial object
 * 
 * @param spol 
 */
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
/**
 * @brief Metodo para escritura por pantalla
 * 
 * @param os 
 */
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}

/**
 * @brief Sobrecarga operador extraccion
 * 
 * @param os 
 * @param p 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios
/**
 * @brief Evaluación de un polinomio representado por vector disperso
 * 
 * @param x 
 * @return double 
 */
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  
  for (int i = 0; i < get_nz(); i++) {
    result = result + (at(i).get_val() * (pow(x, at(i).get_inx())));
  }
  return result;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por vectores dispersos
 * 
 * @param spol 
 * @param eps 
 * @return true 
 * @return false 
 */
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const {
  bool differents = true;
  
  if (get_nz() != spol.get_nz()) {
    differents = false;
  }
  else {
    for (int i = 0; i < get_nz(); i++) {
      if(at(i).get_val() != spol.at(i).get_val()) differents = false;
    }
  }

  return differents;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por vector disperso y vector denso
 * 
 * @param pol 
 * @param eps 
 * @return true 
 * @return false 
 */
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = true;

  if (NoZero(pol) != get_nz()) {
    differents = false;
  }
  else {
    for (int i = 0; i < get_nz(); i++) {
      if (at(i).get_val() != pol[at(i).get_inx()]) differents = false;
    }
  }

  return differents;
} 


// ---------------------------------------------------------------------- Ejercicios para Practicar --------------------------------------------------------------------------------

/**
 * @brief Mostrar por pantalla los numeros de un vector disperso que su indice sea mayor que un numero dado
 * 
 * @param spol 
 * @param valor 
 */
void coef_mayores(const SparsePolynomial& spol, double valor) {

  std::cout << "Los monomios del vector cyos indices son mayores que el valor dado son: " << std::endl;
  for (int i = 0; i < spol.get_nz(); i++) {
    if (spol.at(i).get_inx() >= valor) {
      std::cout << spol.at(i).get_val() << "x^" << spol.at(i).get_inx() << std::endl;
    }
  }
}

/**
 * @brief Sumar los coeficientes de un sparce polynomial
 * 
 */
void SumaCoeficientes(const SparsePolynomial& spol) {
  double suma{0};

  for (int i = 0; i < spol.get_nz(); i++) {
    suma = suma + spol.at(i).get_val();
  }

  std::cout << "La suma de los coeficientes del sparce polynomial es: " << suma << std::endl;
}

/**
 * @brief Imprimir el monomio de mayor y menor grado de un sparse polynomial
 * 
 */
void MayorMonomio(const SparsePolynomial& spol) {
  std::cout << "El monomio de menor grado es: " << spol.at(0).get_val() << "x^" << spol.at(0).get_inx() << std::endl;
  std::cout << "El monomio de mayor grado es: " << spol.at(spol.get_nz() - 1).get_val() << "x^" << spol.at(spol.get_nz() - 1).get_inx() << std::endl;
}

/**
 * @brief Calcula la suma de los grados de un polinomio
 * @param[in] spol: Polinomio disperso
 * @return Suma de grados
 */
void sum_grados(const SparsePolynomial& spol) {
  int suma_grados{0};

  for ( int i = 0; i < spol.get_nz(); i++) {
    suma_grados = suma_grados + spol.at(i).get_inx();
  }
  
  std::cout << "La suma de los grados del polinomio disperso es de: " << suma_grados << std::endl;
}

/**
 * @brief Mostrar los valores de las posiciones con grados pares del vector 
 * 
 * @param spol 
 */
void GradosPares(const SparsePolynomial& spol) {

  std::cout << "Los valores de las posiciones con grados pares del vector son: " << std::endl;

  for (int i = 0; i < spol.get_nz(); i++) {
    if (spol.at(i).get_inx() % 2 == 0) {
      std::cout << spol.at(i).get_val() << "  ";
    }
  }
  std::cout << std::endl;
}

/**
 * @brief Mostrar los coeficientes de un polinomio disperso
 * @param[in] spol: Polinomio disperso
 */
void CoefSpol(const SparsePolynomial& spol) {
  vector_t<double> coeficientes;
  int contador{0};
  coeficientes.resize(spol.get_nz()); // MUY IMPORTANTE HACER EL RESIZE

  for (int i = 0; i < spol.get_nz(); i++) {
    coeficientes.at(contador) = spol.at(i).get_val();
    contador++;
  }

  std::cout << "Los coeficientes distintos de 0 del vector disperso son: ";
  for (int i = 0; i < coeficientes.get_size(); i++) {
    std::cout << coeficientes.at(i) << "  ";
  }
  std::cout << std::endl;
}

/**
 * @brief Mostrar los coeficientes de un polinomio denso
 * @param[in] spol: Polinomio denso
 */
void CoefPol(const Polynomial& pol) {
  vector_t<double> coeficientes;
  coeficientes.resize(NoZero(pol));
  int contador{0};

  for (int i = 0; i < pol.get_size(); i++) {
    if (IsNotZero(pol.at(i))) {
      coeficientes.at(contador) = pol.at(i);
      contador++;
    }
  }

  std::cout << "Los coeficientes distintos de 0 del vector denso son: ";
  for (int i = 0; i < coeficientes.get_size(); i++) {
    std::cout << coeficientes.at(i) << "  ";
  }
  std::cout << std::endl;
}

/**
 * @brief Obtener el mayor grado de un polinomio normal
 * @param[in] pol: Polinomio normal
 * @return Grado del polinomio
 */
void MayorGradoPol(const Polynomial& pol) {
  int max_grado{0};

  for (int i = 0; i < pol.get_size(); i++) {
    if (IsNotZero(pol.at(i))) max_grado = i;
  }

  std::cout << "El mayor grado del polinomio denso con coeficiente no cero es: x^" << max_grado << std::endl;
}

/**
 * @brief Obtener el mayor grado de un polinomio disperso
 * @param[in] spol: Polinomio disperso
 * @return Grado del polinomio
 */
void MayorGradoSpol(const SparsePolynomial& spol) {
  int max_grado{spol.at(spol.get_nz() - 1).get_inx()};
  std::cout << "El mayor grado del polinomio disperso con coeficiente no cero es: x^" << max_grado << std::endl;
}

/**
 * @brief Sobrecarga operador +
 * 
 * @param pol 
 * @return Polynomial 
 */
Polynomial Polynomial::operator+(const Polynomial& pol) {
  int grado_max = get_size() > pol.get_size() ? get_size() : pol.get_size();
  Polynomial pol2 = get_size() > pol.get_size() ? *this : pol;
  int grado_min = get_size() < pol.get_size() ? get_size() : pol.get_size();
  Polynomial pol1 = get_size() < pol.get_size() ? *this : pol;
  Polynomial nuevo_pol(grado_max);
  for (int i = 0; i < pol1.get_size(); i++) {
    nuevo_pol.at(i) = pol1.at(i) + pol2.at(i);
  }
  for (int i = grado_max; i < pol2.get_size(); i++) {
    nuevo_pol.at(i) = pol2.at(i);
  }
  return nuevo_pol;
}

/**
 * @brief Sobrecarga operador -
 * 
 * @param pol 
 * @return Polynomial 
 */
Polynomial Polynomial::operator-(const Polynomial& pol) {
  int grado_max = get_size() > pol.get_size() ? get_size() : pol.get_size();
  Polynomial pol2 = get_size() > pol.get_size() ? *this : pol;
  int grado_min = get_size() < pol.get_size() ? get_size() : pol.get_size();
  Polynomial pol1 = get_size() < pol.get_size() ? *this : pol;
  Polynomial nuevo_pol(grado_max);
  for (int i = 0; i < pol1.get_size(); i++) {
    nuevo_pol.at(i) = pol1.at(i) - pol2.at(i);
  }
  for (int i = grado_max; i < pol2.get_size(); i++) {
    nuevo_pol.at(i) = -pol2.at(i);
  }
  return nuevo_pol;
}

/**
 * @brief Muestra las posiciones que tienen un cero
 * @param[in] spol: Polinomio disperso
 * @return Void
 */
void print_zeros(const SparsePolynomial& spol) {
  vector_t<int> inx_non_zeros;
  inx_non_zeros.resize(spol.get_n());
  
  // MArcamos con un 1 las posiciones no cero
  for (int i = 0; i < spol.get_nz(); i++) {
    inx_non_zeros[spol.at(i).get_inx()] = 1;
  }

  // Rellenamos las posiciones restantes con ceros
  for (int i = 0; i < inx_non_zeros.get_size(); i++) {
    if (inx_non_zeros.at(i) != 1) {
      inx_non_zeros.at(i) = 0;
    }
  }

  // Imprimimos
  std::cout << "Los ceros están en: ";
  for (int i = 0; i < inx_non_zeros.get_size(); i++) {
    if (inx_non_zeros.at(i) == 0) {
      std::cout << "x^" << i << "  ";
    }
  }
  std::cout << std::endl;

}

#endif  // POLYNOMIAL_H_