#include <iostream>
#include "Eigen.hpp"
// Eigen is a C++ template library for linear algebra: matrices, vectors, numerical solvers, and related algorithms.
// https://eigen.tuxfamily.org/index.php?title=Main_Page

using namespace std;

int main(){
    
    
    // initialization: operand vector x, x belongs R^{n}
    int n;
    cout << "input the length of operand vector" << endl;
    cin >> n;
    
    cout << "input the values of operand vector" << endl;
    Eigen::vector_t<double> x(n);
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    
    
    cout << "input the positions p and q of transformed elements, where 1 =< p < q < n = " << n << endl;
    int p,q;
    cin >> p >> q;
    
    // matrix index begin at 0
    p--;
    q--;
    
    // Generating the Givens Rotation Matrix G, G belongs R^{nxn}
    
    // - Calculating the cos and sin of theta based on tan
    
//     double tan, sin, cos, ctan;
//     if(abs(x[p]) > abs(x[q])){
//         tan = x[q]/x[p];
        
//         cos = 1/sqrt(1 + tan*tan);
//         sin = cos*tan;
//     }
//     else{
//         ctan = x[p]/x[q];
        
//         sin = 1/sqrt(1 + ctan*ctan);
//         cos = sin*ctan;
//     }
    
    double x_pq_norm = sqrt(x[p]*x[p] + x[q]*x[q]);
    double cos = x[p]/x_pq_norm;
    double sin = x[q]/x_pq_norm;
    
    // - Generating the Identity Matrix
    Eigen::matrix_t<double> G(n, n);
    G.setIdentity();
    
    
    // - replace the value of elements in position (p,p), (p,q), (q,p), (q,q)
    
    G(p,p) = cos;
    G(p,q) = sin;
    G(q,p) = -sin;
    G(q,q) = cos;
    
    cout << endl << "The Givens Rotation Matrix is:" << endl;
    std::cout << G << endl << endl;
    
    // Result = G*x
    cout << G*x << endl;
    
    cout << x_pq_norm << endl;
}
