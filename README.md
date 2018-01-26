# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Project Goal

The goal of this project is to make a controller than can keep the car centered in the lane without producing oscillations. The car does not see the road but receives a cross track error signal, which it will try to minimize.

## Implementation

The implementation consists of 2 PID controllers, one for the steering and one for the speed. The speed isn't necessary, as it can just be kept low, but it the result is more interesting with a speed PID.

The final values for [Kp,Ki,Kd] are [0.1,0.001,0.5] for the steering controller and [0.4,0,0] for the speed controller
The method was the following:
*Find a Kp value that kept the car cented as stable as possible, even with the oscillations
*Increase Kd until the oscillations were reduced
*Increased Ki to keep the car centered in the lane even in longer curves

For the speed PID, oscillations were not so problematic so I just used the Kp parameter. The value is such pre-calculated such that the car will start breaking before leaving the track width

## Effect of different components

The proportional P component raises or lowers the frequency of the oscillations. This is as expected
The integral I component, seems to me, made the car more cented in the lane. This is not what I expected because I did not think the simulated car had a bias, so maybe it was just my perception.
It also seems to me that when I introduced the i component, the car was more centered in the lane during the curves, where the other two parameters were not able to center the car
The derivative D component stopped the vehicle from oscillating.

## Results

The results can be found on this video: https://www.youtube.com/watch?v=B3K3s_2b3T4

The car can run a lap pretty quickly while remaining inside the lane.
It has some oscillations when driving at high speeds. I reduced this by adding a correction factor for the steering at high speeds, but it did not completely elliminate the oscillations.
The larger problem is that the car starts to break when it's already inside the curve and leaving the desired track. From the vehicle dynamics point of view this is a danerous behaviour. However, the car in this simulation has no vision of the road, so it is impossible for it to know that it should start breaking before the curve arrives and the cross track error starts to increase.
