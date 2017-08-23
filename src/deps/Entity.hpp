#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include <cmath>
#include <iostream>
#include <cstdint>
#include <epoxy/gl.h>

enum class LinePosition {top, bottom, left, right};

class Entity
{
public:
	// Constructor, creates entity, pass iin all initial conditions and shader program id
	Entity(float xInit, float yInit, float yawInit, float radiusInit,
		unsigned int shaderProgramIdI);
	// Set the new position
	virtual void setPosition(float inX, float inY);
	// Set the new yaw
	virtual void setYaw(float inTheta);
	// Update the position of subobjects based on new pos
	virtual void update();
	// Renders this object
	virtual void render();
	// return current x coordinate
	virtual float getXPos();
	// return current y coordinate
	virtual float getYPos();
	// return current yaw
	virtual float getYaw();
	// reutrn current radius
	virtual float getRadius();
protected:
	// Do opengl setup
	virtual void setup();
	// Posiition, orientation, color data, as well as the shader program to use
	float x;
	float y;
	float yaw;
	float radius;
	unsigned int shaderProgramId;
	// Constant expressions to
	constexpr static float ARENASIZEX = 20;
	constexpr static float ARENASIZEY = 20;
	constexpr static float PI = 3.14159265358979f;
	static void updateTheta(float &thetaVal, float incrementVal)
	{
		thetaVal += incrementVal;
		if (thetaVal > 2.0f * 3.14159265f - 0.01f)
		{
			thetaVal = 0.0f;
		}
	}
};

#endif