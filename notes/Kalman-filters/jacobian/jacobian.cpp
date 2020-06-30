#include <iostream>
#include <vector>
#include <Eigen/Dense>

using Eigen::MatrixXd;
using Eigen::VectorXd;
using std::cout;
using std::endl;

MatrixXd CalculateJacobian(const VectorXd& x_state);

int main() {
  /**
   * Compute the Jacobian Matrix
   */

  // predicted state example
  // px = 1, py = 2, vx = 0.2, vy = 0.4
  VectorXd x_predicted(4);
  x_predicted << 1, 2, 0.2, 0.4;

  MatrixXd Hj = CalculateJacobian(x_predicted);

  cout << "Hj:" << endl << Hj << endl;

  return 0;
}

MatrixXd CalculateJacobian(const VectorXd& x_state) {

  MatrixXd Hj(3,4);
  // recover state parameters
  float px = x_state(0);
  float py = x_state(1);
  float vx = x_state(2);
  float vy = x_state(3);

  // TODO: YOUR CODE HERE 
  float px2 = px*px;
  float py2 = py*py;
  float a = sqrt(px2 + py2);
  float b = px2 + py2;
  float c = pow(b, 1.5);

  cout << "DEBUG: " << c << endl;

  // check division by zero
  if (a == 0.0 || b == 0.0 || c == 0.0) {
    cout << "Error: Divde by zero" << endl;
    return Hj;
  }
  
  // compute the Jacobian matrix
  Hj(0,0) = px / a;
  Hj(0,1) = py / a;
  Hj(0,2) = Hj(0,3) = 0.0;

  Hj(1,0) = -py/b;
  Hj(1,1) = px/b;
  Hj(1,2) = Hj(1,3) = 0.0;

  Hj(2,0) = py*(vx*py - vy*px) / c;
  Hj(2,1) = px*(vy*px - vx*py) / c;
  Hj(2,2) = px / a;
  Hj(2,3) = py / a;

  return Hj;
}
