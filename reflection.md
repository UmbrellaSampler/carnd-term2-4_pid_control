# CarND-Controls-PID Reflection

### Describe the effect each of the P, I, D components had in your implementation.

The P (proportional) component steers the car always towards the road center line. The stronger we are off-located the stronger the (counter) steering. It leads to oszillations around the center line. This behavior is expected.

The I (integral) component to act contrary to (constant) biases in the steering angle. Since I expected the simulation not have such a bias I set the coefficient to 0.0. It worked as expected.

The D (differential) component is propotional to the difference in the CTE (actually d(cte)/dt). Is has the effect of damping the oszillation introduced by the P component and enables a smoother steering twords the centerline after a heavy breakout from the centerline.

I also introduced a PID for the throttle. When the CTE went to high the PID reduced the speed in order to not get off the road. When the CTE got smaller the speed was gently increased. This was the key element to succeed this project in my case.

### Describe how the final hyperparameters were chosen.

The values were found by manual tuning for both the steering and the throttle PID.

