// info@stce.rwth-aachen.de

// Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.
// https://eigen.tuxfamily.org/index.php?title=Main_Page

#pragma once

#include "Eigen/Dense"

namespace Eigen {

  template<typename T, int N=Dynamic>
  using vector_t=Matrix<T,N,1>;

  template<typename T, int N=Dynamic>
  using row_vector_t=Matrix<T,1,N>;

  template<typename T, int M=Dynamic, int N=M>
  using matrix_t=Matrix<T,M,N>;

}

 
