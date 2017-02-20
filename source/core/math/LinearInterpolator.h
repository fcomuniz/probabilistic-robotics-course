/*
 * LinearInterpolator.h
 *
 *  Created on: Oct 16, 2015
 *      Author: root
 */

#ifndef SOURCE_MATH_LINEARINTERPOLATOR_H_
#define SOURCE_MATH_LINEARINTERPOLATOR_H_

#include "Interpolator.h"

namespace itandroids_lib{
namespace math {

template <class T = double>
class LinearInterpolator : public Interpolator<T>{
public:

	LinearInterpolator(T initialPosition, T finalPosition): initialPosition(initialPosition), finalPosition(finalPosition) {

	}
	virtual ~LinearInterpolator(){

	}
	T interpolate(double fraction){
	    return initialPosition + (finalPosition - initialPosition)*fraction;
	}
private:
	T initialPosition;
	T finalPosition;
};

} /* namespace keyframe */
} /* namespace control */

#endif /* SOURCE_MATH_LINEARINTERPOLATOR_H_ */
