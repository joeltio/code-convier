#include "LineOfSightComponent.h"

namespace Component {

	float LineOfSight::getMinExtent(char axis) {
		if (this->points.first[axis] < this->points.second[axis])
		{
			return this->points.first[axis];
		}
		else
		{
			return this->points.second[axis];
		}
	}

	float LineOfSight::getMaxExtent(char axis) {
		if (this->points.first[axis] > this->points.second[axis])
		{
			return this->points.first[axis];
		}
		else
		{
			return this->points.second[axis];
		}
	}

}
