#include <iostream>
#include <Eigen/Dense>
#include "cg.hpp"
#include <Eigen/SVD>

//funzione che trova condizionamento
double condA(const Eigen::MatrixXd& A)
{
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
  Eigen::VectorXd singularValuesA = svd.singularValues();
  return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

int main(void) 
{
  const double tol = 1.0e-9;
  unsigned int n = 4;

  //genero una matrice random
  Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);

  //se è singolare non applico l'algoritmo
  if (abs(B.determinant()) < tol)
    return -1;
  
  
  //genero matrice definita positiva B'*B
  Eigen::MatrixXd A = B.transpose() * B;
  Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n); //sol esatta

  Eigen::VectorXd b = A * x_ex; //costruisco vettore b

  Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n); //vettore iniziale arbitrario
  
  std::cout.precision(2);
  std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;
  
  const unsigned int it_max = 10000;
  const double res_tol = 1.0e-12;
  Eigen::VectorXd x_calc = conjugate_gradient(A, b, x0, res_tol, it_max);
    


  const auto err_rel = (x_calc - x_ex).norm() / x_ex.norm();

  std::cout.precision(4);
  
  std::cout<< std::scientific<< "err_rel"<< std::endl;
  std::cout<< std::scientific<< err_rel<< std::endl;
  std::cout<< std::scientific<< "soluzione"<< std::endl;
  std::cout<< std::scientific<< x_calc << std::endl;

  return 0;
}
