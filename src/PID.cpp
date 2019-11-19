#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;

    p_error = 0.0;
    d_error = 0.0;
    i_error = 0.0;

    prev_cte = 0.0;
}

void PID::UpdateError(double cte) {

    // Proportional error: this term is proportional to the cte.
    // Effect: The stronger we are off-located from the center of the road the more we steer towards it.
    // Using this error only leads to oscillations.
    p_error = cte;

    // Differential error: this term is driven by the difference in cte (d(cte)/dt) with respect to previous steps.
    // Effect: It reduces/damps the oscillations induced by p_error.
    d_error = cte - prev_cte;

    // Integral error: this term represents the sum of all ctes of previous steps.
    // Effect: It accounts for constant steering biases.
    i_error += cte;

    prev_cte = cte;
}

double PID::TotalError() {
    return p_error * Kp + d_error * Kd + i_error * Ki;
}