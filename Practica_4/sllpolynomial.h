// AUTOR: Eduardo González Gutiérrez
// FECHA: 24 de marzo de 2023
// EMAIL: alu0101461588@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 // Metodos publicos de la clase
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);

  // Modificaciones
  void QuitarMonomios();
};

/**
 * @brief Metodo que comprueba si un elemento del polinomio es cero
 * 
 * @param val 
 * @param eps 
 * @return true 
 * @return false 
 */
bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
/**
 * @brief Construct a new Sll Polynomial:: Sll Polynomial object
 * 
 * @param v 
 * @param eps 
 */
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  for ( int i = v.get_size() - 1; i >= 0; i--) {
    pair_double_t par(v.get_val(i), i); // Preparamos un par con su valor y su indice
    SllPolyNode* nuevo_nodo = new SllPolyNode; // Preparamos un nuevo nodo
    nuevo_nodo->set_data(par);  // Rellenamos el nodo 

    if (fabs(par.get_val()) > eps) {
      push_front(nuevo_nodo);
    }
  }
}

// E/S
/**
 * @brief Operador escritura por pantalla
 * 
 * @param os 
 */
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
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
std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios
// FASE III
/**
 * @brief Evaluación de un polinomio representado por lista simple
 * 
 * @param x 
 * @return double 
 */
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  
  SllPolyNode* aux = get_head();

  while (aux != NULL) {
    result += aux->get_data().get_val() * pow(x, aux->get_data().get_inx());
    aux = aux->get_next();
  }

  return result;
}

/**
 * @brief Comparación si son iguales dos polinomios representados por listas simples
 * 
 * @param sllpol 
 * @param eps 
 * @return true 
 * @return false 
 */
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol, const double eps) const {
  bool differents = true;

  SllPolyNode* pol1 = get_head();
  SllPolyNode* pol2 = sllpol.get_head();

  while(pol1 != NULL && pol2 != NULL) {
    if (pol1->get_data().get_val() != pol2->get_data().get_val() && pol1->get_data().get_inx() != pol2->get_data().get_inx()) differents = false;
    pol1 = pol1->get_next();
    pol2 = pol2->get_next();
  }
  return differents;
}

/**  
 * @brief Get the size object without ceros
 * 
 * @param polinomio 
 * @return int 
 */
int get_size(const SllPolynomial& polinomio) {
  int size{0};
  
  SllPolyNode* aux = polinomio.get_head();

  while(aux != NULL) {
    size++;
    aux = aux->get_next();
  }
  return size;
}

/**
 * @brief Metodo que ordena un SllPolynomial
 * 
 * @param polinomio 
 */
void ordenar(SllPolynomial& polinomio) {
  vector_t<pair_double_t> vector;
  vector.resize(get_size(polinomio));
  SllPolyNode* aux = polinomio.get_head();
  SllPolynomial resultado;

  for(int i = get_size(polinomio) - 1; i >= 0 && aux != NULL; --i) {
    vector.at(i) = aux->get_data();
    aux = aux->get_next();
  }
  
  while(!polinomio.empty()) {
    polinomio.pop_front();
  }

  for (int i = vector.get_size() - 1; i >= 0; i--) {
    pair_double_t par = (vector.at(i));
    SllPolyNode* nodo = new SllPolyNode;
    nodo->set_data(par);
    polinomio.push_front(nodo);
  }
}

// FASE IV
/**
 * @brief Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
 * 
 * @param sllpol 
 * @param sllpolsum 
 * @param eps 
 */
void SllPolynomial::Sum(const SllPolynomial& sllpol, SllPolynomial& sllpolsum, const double eps) {

  SllPolyNode* pol1 = get_head();
  SllPolyNode* pol2 = sllpol.get_head();

  while (pol1 != NULL && pol2 != NULL) {
    if (pol1->get_data().get_inx() == pol2->get_data().get_inx()) {
      pair_double_t nodo (pol1->get_data().get_val() + pol2->get_data().get_val(), pol1->get_data().get_inx());
      SllPolyNode* pol = new SllPolyNode;
      pol->set_data(nodo);
    
      if (fabs(nodo.get_val()) > eps) {
        sllpolsum.push_front(pol);
      }
      pol1 = pol1->get_next();
      pol2 = pol2->get_next();
    } 
    else if (pol1->get_data().get_inx() != pol2->get_data().get_inx()) {
      if (pol1->get_data().get_inx() < pol2->get_data().get_inx()) {
        pair_double_t nodo1 (pol1->get_data().get_val(), pol1->get_data().get_inx());
        SllPolyNode* poly = new SllPolyNode;
        poly->set_data(nodo1);
        
        if (fabs(nodo1.get_val()) > eps) {
          sllpolsum.push_front(poly);
        }
        pol1 = pol1->get_next();
      }
      else if (pol2->get_data().get_inx() < pol1->get_data().get_inx()) {
        pair_double_t nodo2 (pol2->get_data().get_val(), pol2->get_data().get_inx());
        SllPolyNode* poly1 = new SllPolyNode;
        poly1->set_data(nodo2);
      
        if (fabs(nodo2.get_val()) > eps) {
          sllpolsum.push_front(poly1);
        }
        pol2 = pol2->get_next();
      }
    }
  }

  if (pol1 != NULL || pol2 != NULL) {
    SllPolyNode* mayor = get_size(*this) > get_size(sllpol) ? pol1 : pol2;

    while (mayor != NULL) {
      pair_double_t nodo_ultimo (mayor->get_data().get_val(), mayor->get_data().get_inx());
      SllPolyNode* nodo = new SllPolyNode;
      nodo->set_data(nodo_ultimo);
        
      if (fabs(nodo_ultimo.get_val()) > eps) {
        sllpolsum.push_front(nodo);
      }

      mayor = mayor->get_next();
    }
  }
  ordenar(sllpolsum);
}


// ------------------------------------------------------------------------ Ejercicios para practicar --------------------------------------------------------------------------
/**
 * @brief Metodo que muestra por pantalla el grado maximo de un polinomio
 * 
 * @param sllpol 
 */
int grado_max(const SllPolynomial& sllpol) {
  SllPolyNode* aux = sllpol.get_head();
  int grado_max{0};

  while (aux != NULL) {
    grado_max = aux->get_data().get_inx();
    aux = aux->get_next();
  }
  //std::cout << "El grado máximo del polinomio es de: x^" << grado_max << std::endl;

  return grado_max;
}

/**
 * @brief Metodo que suma todos los grados de un polinomio
 * 
 * @param sllpol 
 */
void sum_grados(const SllPolynomial& sllpol) {
  int suma{0};
  SllPolyNode* aux = sllpol.get_head();

  while(aux != NULL) {
    suma += aux->get_data().get_inx();
    aux = aux->get_next();
  }
  std::cout << "La suma de los grados del polinomio es de: " << suma << std::endl;
}

/**
 * @brief Metodo que muestra por pantalla la suma de los valores cuyos indices son consecutivos
 * 
 * @param sllpol 
 */
void suma_consecutivos(const SllPolynomial& sllpol) { 
  SllPolyNode* aux = sllpol.get_head();
  double suma{0};

  while (aux->get_next() != NULL) {
    if(aux->get_next()->get_data().get_inx() - aux->get_data().get_inx() == 1) {
      suma = suma + (aux->get_next()->get_data().get_val() + aux->get_data().get_val());
    }
    aux = aux->get_next();
  }
  std::cout << "La suma es: " << suma;
}

/**
 * @brief Metodo que devuelve el polinomio llamador sin el primer y ultimo monomio
 * 
 */
void SllPolynomial::QuitarMonomios() {
  this->pop_front();
  SllPolyNode* aux = get_head();
  SllPolyNode* anterior;

  while (aux != NULL) {
    if (aux->get_data().get_inx() == grado_max(*this)) {
      erase_after(anterior);
    }
    anterior = aux;
    aux = aux->get_next();
  }
}

/**
 * @brief Metodo que elimina los coeficientes iguales a los que se le pasa como parametro
 * 
 * @param coef 
 * @param sllpol 
 */
void eliminar(const double coef, const SllPolynomial& pol) {
  SllPolynomial sllpol = pol;
  SllPolyNode* aux{sllpol.get_head()};

  while (aux->get_next() != NULL) {
    if (aux->get_next()->get_data().get_val() == coef) {
      sllpol.erase_after(aux);
    } else {
      aux = aux->get_next();
    }
  }

  std::cout << "El polinomio con los monomios eliminados es: " << sllpol << std::endl;
}

// --------------------- MODIFICACION------------------------------
void MonomiosImpares(const SllPolynomial& pol, SllPolynomial& resultado) {
  SllPolyNode* aux = pol.get_head();
  SllPolynomial nuevo;

  while (aux != NULL) {
    if(aux->get_data().get_inx() % 2 != 0) {
      pair_double_t par (aux->get_data().get_val(), aux->get_data().get_inx());
      SllPolyNode* nodo = new SllPolyNode;
      nodo->set_data(par);
      nuevo.push_front(nodo);
    }
    aux = aux->get_next();
  }
  resultado = nuevo;
  ordenar(resultado);
}



#endif  // SLLPOLYNOMIAL_H_