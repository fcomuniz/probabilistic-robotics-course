/**
 * @file Pose3D.h
 * Contains class Pose3D
 * @author <a href="mailto:martin.kallnik@gmx.de">Martin Kallnik</a>
 * @author Max Risler
 */

#ifndef Pose3D_H
#define Pose3D_H

#include "math/RotationMatrix.h"
#include "math/Pose2D.h"

namespace itandroids_lib {
namespace math {

/** representation for 3D Transformation (Location + Orientation)*/
class Pose3D {
public:

	/** rotation as a RotationMatrix*/
	RotationMatrix rotation;

	/** translation as a Vector3*/
	Vector3<double> translation;

	/** constructor*/
	Pose3D() {
	}

	/** constructor from rotation and translation
	 * \param rot Rotation
	 * \param trans Translation
	 */
	Pose3D(const RotationMatrix& rot, const Vector3<double>& trans) :
			rotation(rot), translation(trans) {
	}

	/** constructor from rotation
	 * \param rot Rotation
	 */
	Pose3D(const RotationMatrix& rot) :
			rotation(rot) {
	}

	/** constructor from translation
	 * \param trans Translation
	 */
	Pose3D(const Vector3<double>& trans) :
			translation(trans) {
	}

	/** constructor from three translation values
	 * \param x translation x component
	 * \param y translation y component
	 * \param z translation z component
	 */
	Pose3D(const double x, const double y, const double z) :
			translation(x, y, z) {
	}

	/** constructor from Pose2D */
	Pose3D(const Pose2D p) {
		translation.x = p.translation.x;
		translation.y = p.translation.y;
		translation.z = 0;
		rotation.rotateZ(-p.rotation);
	}

	/** Assignment operator
	 *\param other The other Pose3D that is assigned to this one
	 *\return A reference to this object after the assignment.
	 */
	Pose3D& operator=(const Pose3D& other) {
		rotation = other.rotation;
		translation = other.translation;

		return *this;
	}

	/** Copy constructor
	 *\param other The other vector that is copied to this one
	 */
	Pose3D(const Pose3D& other) {
		*this = other;
	}

	/** Multiplication with Point
	 *\param point (Vector3&lt;double&gt;)
	 */
	Vector3<double> operator*(const Vector3<double>& point) const {
		return rotation * point + translation;
	}

	/** Multiplication with Pose3D
	 *\param other Pose3D
	 */
	Pose3D operator*(const Pose3D& other) const {
		Pose3D result;
		result.translation = this->rotation * other.translation + this->translation;
		result.rotation = this->rotation * other.rotation;
		return result;
	}

	/** Comparison of another vector with this one.
	 *\param other The other vector that will be compared to this one
	 *\return Whether the two vectors are equal.
	 */
	bool operator==(const Pose3D& other) const {
		return ((translation == other.translation)
				&& (rotation == other.rotation));
	}

	/** Comparison of another vector with this one.
	 *\param other The other vector that will be compared to this one
	 *\return Whether the two vectors are unequal.
	 */
	bool operator!=(const Pose3D& other) const {
		return !(*this == other);
	}

	/**Concatenation of this pose with another pose
	 *\param other The other pose that will be concatenated to this one.
	 *\return A reference to this pose after concatenation
	 */
	Pose3D& conc(const Pose3D& other) {
		translation = *this * other.translation;
		rotation *= other.rotation;
		return *this;
	}

	/** Calculates the inverse transformation from the current pose
	 * @return The inverse transformation pose.
	 */
	Pose3D invert() const {
		Pose3D result;
		result.rotation = this->rotation.invert();
		result.translation = result.rotation
				* (Vector3<double>(0, 0, 0) - this->translation);
		return result;
	}

	/**Translate this pose by a translation vector
	 *\param trans Vector to translate with
	 *\return A reference to this pose after translation
	 */
	Pose3D& translate(const Vector3<double>& trans) {
		translation = *this * trans;
		return *this;
	}

	/**Translate this pose by a translation vector
	 *\param x x component of vector to translate with
	 *\param y y component of vector to translate with
	 *\param z z component of vector to translate with
	 *\return A reference to this pose after translation
	 */
	Pose3D& translate(const double x, const double y, const double z) {
		translation = *this * Vector3<double>(x, y, z);
		return *this;
	}

	/**Rotate this pose by a rotation
	 *\param rot Rotationmatrix to rotate with
	 *\return A reference to this pose after rotation
	 */
	Pose3D& rotate(const RotationMatrix& rot) {
		rotation *= rot;
		return *this;
	}

	/**Rotate this pose around its x-axis
	 *\param angle angle to rotate with
	 *\return A reference to this pose after rotation
	 */
	Pose3D& rotateX(const double angle) {
		rotation.rotateX(angle);
		return *this;
	}

	/**Rotate this pose around its y-axis
	 *\param angle angle to rotate with
	 *\return A reference to this pose after rotation
	 */
	Pose3D& rotateY(const double angle) {
		rotation.rotateY(angle);
		return *this;
	}

	/**Rotate this pose around its z-axis
	 *\param angle angle to rotate with
	 *\return A reference to this pose after rotation
	 */
	Pose3D& rotateZ(const double angle) {
		rotation.rotateZ(angle);
		return *this;
	}

	Pose3D relativeToGlobal(const Pose2D &origin) {
		Pose3D retval(*this);
		RotationMatrix rot;
		rot.rotateZ(origin.rotation);
		retval.translation = rot * retval.translation;
		retval.translation.x += origin.translation.x;
		retval.translation.y += origin.translation.y;
		retval.rotation.rotateZ(origin.rotation);
		return retval;
	}

	Pose3D relativeToGlobal(const Pose3D &origin) {
		Pose3D retval(*this);
		retval.translation = origin.rotation * retval.translation;
		retval.translation += origin.translation;
		retval.rotation = origin.rotation * retval.rotation;
		return retval;
	}

	Pose3D globalToRelative(const Pose2D &origin) {
		Pose3D retval(*this);
		retval.translation.x -= origin.translation.x;
		retval.translation.y -= origin.translation.y;
		RotationMatrix rot;
		rot.rotateZ(-origin.rotation);
		retval.translation = rot * retval.translation;
		retval.rotation.rotateZ(-origin.rotation);
		return retval;
	}

	Pose3D globalToRelative(const Pose3D &origin) {
		Pose2D origin_2d(0, 0, 0);
		origin_2d.translation.x = origin.translation.x;
		origin_2d.translation.y = origin.translation.y;
		origin_2d.rotation = origin.rotation.getZAngle();
		return this->globalToRelative(origin_2d);
	}
};

} /* namespace math */
} /* namespace itandroids_lib */

#endif // Pose3D_H
