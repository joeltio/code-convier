#include "vectorUtil.h"

// Determines which quadrannt the subject is relative to the
// reference position vector
char getQuadrant(D3DXVECTOR2& subject, D3DXVECTOR2& reference) {
		// 2 | 1
		// 3 | 4
		if (subject.x > reference.x)
		{
			if (subject.y > reference.y)
			{
				return 1;
			}
			else
			{
				return 4;
			}
		}
		else
		{
			if (subject.y > reference.y)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
}

// Determines which quadrannt the subject is relative to the
// reference position vector and based on the xAxisNormal axis
char getQuadrant(D3DXVECTOR2& subject, D3DXVECTOR2& reference, D3DXVECTOR2& xAxisNormal) {
	D3DXVECTOR2 yAxisNormal {xAxisNormal.y, -xAxisNormal.x};

	D3DXVECTOR2 relativeVec = subject - reference;
	float subjectX = D3DXVec2Dot(&relativeVec, &xAxisNormal);
	float subjectY = D3DXVec2Dot(&relativeVec, &yAxisNormal);

	if (subjectX > 0)
	{
		if (subjectY > 0)
		{
			return 1;
		}
		else
		{
			return 4;
		}
	}
	else
	{
		if (subjectY > 0)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
}

// Calculates the squared distance between two position vectors
float distance2(D3DXVECTOR2& a, D3DXVECTOR2& b) {
	D3DXVECTOR2 diffVector = a - b;
	return diffVector.x * diffVector.x + diffVector.y * diffVector.y;
}

bool doExtentsIntersect(std::pair<float, float>& a, std::pair<float, float>& b) {
	return !(
		// a less than b
		a.second < b.first ||
		// a more than b
		b.second < a.first
	);
}

std::pair<float, float> findVectorExtents(std::vector<D3DXVECTOR2> corners, D3DXVECTOR2 normal) {
	float min = INFINITY;
	float max = -INFINITY;

	for (D3DXVECTOR2 corner : corners)
	{
		float projection = D3DXVec2Dot(&corner, &normal);

		if (projection > max)
		{
			max = projection;
		}
		else if (projection < min)
		{
			min = projection;
		}
	}

	return std::pair<float, float>(min, max);
}
