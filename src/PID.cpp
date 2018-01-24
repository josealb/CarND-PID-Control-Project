#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
    p_error = -cte * Kp;
    double delta_error = cte - previous_cte;
    previous_cte=cte;
    d_error = -delta_error * Kd;
    cte_sum += cte;
    i_error = -cte_sum * Ki;
}

double PID::TotalError() {
    std::cout << "p_error: " << p_error << "d_error: " << d_error << " i_error: " << i_error << std::endl;
    return p_error + d_error + i_error;
}

