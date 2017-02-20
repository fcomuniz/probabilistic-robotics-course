/*
 * SplineInterpolator.h
 *
 *  Created on: Oct 16, 2015
 *      Author: root
 */

#ifndef SOURCE_MATH_SPLINEINTERPOLATOR_H_
#define SOURCE_MATH_SPLINEINTERPOLATOR_H_

#include "Interpolator.h"
#include "Vector2.h"
#include "MathUtils.h"
#include <iostream>
#include <vector>
#include <cmath>

namespace itandroids_lib {
namespace math {
using namespace itandroids_lib::math;
class SplineInterpolator: public Interpolator<double> {
public:
	SplineInterpolator(std::vector<Vector2<double> > points);
	virtual ~SplineInterpolator();
	double interpolate(double position);
private:
	std::vector<double> diff;
	std::vector<Vector2<double> > points;
	std::vector<double> phi;

};

} /* namespace math */
} /* namespace itandroids_lib */

#endif /* SOURCE_MATH_SPLINEINTERPOLATOR_H_ */
