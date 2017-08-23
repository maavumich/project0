#ifndef _VEHICLE_HPP_
#define _VEHICLE_HPP_

#include "Entity.hpp"
#include "AnimatedEntity.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include <cstdint>
#include <vector>

class Vehicle : public AnimatedEntity
{
public:
	Vehicle(float xInit, float yInit, float angleInit, float radiusInit,
		Program *program, float *color);
	virtual void update();
	virtual void render();
private:
	virtual void setup();
	Rectangle body;
	std::vector<Rectangle> rectangles;
	std::vector<Circle> circles;
};

#endif
