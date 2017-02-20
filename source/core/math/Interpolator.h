/*
 * Interpolator.h
 *
 *  Created on: Oct 16, 2015
 *      Author: root
 */

#ifndef SOURCE_MATH_INTERPOLATOR_H_
#define SOURCE_MATH_INTERPOLATOR_H_

namespace itandroids_lib {
namespace math {

template<class T=double>
class Interpolator {
public:
	Interpolator(){

	}
	virtual ~Interpolator(){

	}
	virtual T interpolate(double t) = 0;
private:
};
}
}

#endif /* SOURCE_MATH_INTERPOLATOR_H_ */
