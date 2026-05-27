#pragma once
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include <stdexcept>
#include <cmath>
Eigen::VectorXd conjugate_gradient(const Eigen::MatrixXd& A, const Eigen::VectorXd& b, Eigen::VectorXd x0, double tol , int max_iter) {
    
	if (A.rows() != A.cols() || A.rows() != b.size()) {
         throw std::invalid_argument("Dimensioni di A e b non compatibili.");
      }

    Eigen::VectorXd x = x0;
    Eigen::VectorXd r = b - A * x;
    Eigen::VectorXd p = r;
    
    int k = 0;
    
    while (r.norm() > tol && k < max_iter) {
        
        Eigen::VectorXd Ap = A * p;
        double p_Ap = p.dot(Ap); 
        
        if (std::abs(p_Ap) < 1e-14) {
            std::cerr << "Divisione per zero, la matrice potrebbe essere singolare\n";
            break;
         }

        double alpha = p.dot(r) / p_Ap;
        x = x + alpha * p;
        
        Eigen::VectorXd r_next = b - A * x;
        
		//se la norma del nuovo residuo è minore della tolleranza esco dal while
        if (r_next.norm() <= tol) {
            r = r_next;
            break;
        }

        double beta = p.dot(A * r_next) / p_Ap;
        p = r_next - beta * p;
        
        r = r_next;
        k++;
    }
    
	//stampo risultati algoritmo
	std::cout.precision(4);
	std::cout<< std::scientific<< "it"<< "/"<< "it_max"<< std::endl;
	std::cout<< std::scientific<< k<< "/"<< max_iter<< std::endl;
	std::cout<< std::scientific<< "res"<< "/"<< "res_tol"<< std::endl;
	std::cout<< std::scientific<< r.norm()<< "/"<< tol<< std::endl;
	
	
    return x;
}