#pragma once
#include "config.h"

//'atom' of engine, a single triangle
//x,y offsets will be from 0,0 as it is center of triangle
//all incoming values need to be normalized

class Chick {
private:
	std::vector<GLfloat> vertexData{
		//x,  y,  z

		//0 vertex
		-0.5f, -0.5f, 0.0f, //bottom left vertex
		//1 vertex
		0.5f, -0.5f, 0.0f, //bottom right vertex
		//2 vertex
		-0.5f, 0.5f, 0.0f, //top left vertex
		//3 vertex
		0.5f, 0.5f, 0.0f, //top right vertex

	};
	std::vector<GLfloat> colorData{
		//r,  g,  b

		//0 vertex
		0.0, 0.0f, 0.0f, //bottom left vertex
		//1 vertex			
		0.0f, 0.0f, 0.0f, //bottom right vertex
		//2 vertex
		0.0f, 0.0f, 0.0f, //top left vertex
		//3 vertex
		0.0f, 0.0f, 0.0f, //top right vertex
	};

	GLfloat x_offset = 0.0f;
	GLfloat y_offset = 0.0f;
	GLfloat z_offset = 0.0f;

	GLfloat r_offset = 0.0f;
	GLfloat g_offset = 0.0f;
	GLfloat b_offset = 0.0f;

	GLfloat rot_offset = 0.0f;
	GLfloat scale_offset = 0.0f;

	glm::mat4 model;


protected:

public:
	Chick(GLfloat x, GLfloat y, GLfloat z, GLfloat r, GLfloat g, GLfloat b, GLfloat rotation, GLfloat scale) {
		this->x_offset = x;
		this->y_offset = y;
		this->z_offset = z;

		this->r_offset = r;
		this->b_offset = b;
		this->g_offset = g;

		//translate by offset
		model = glm::translate(glm::mat4(1.0f), glm::vec3(x_offset, y_offset, z_offset));
		//rotation
		model = glm::rotate(model,glm::radians(rot_offset),glm::vec3(0.0f,0.0f,1.0f));
		//scale
		model = glm::scale(model, glm::vec3(scale, scale, 0.0f));
	}
	Chick(const Chick& copy) {
		this->x_offset = copy.x_offset;
		this->y_offset = copy.y_offset;
		this->z_offset = copy.z_offset;

		this->r_offset = copy.r_offset;
		this->b_offset = copy.g_offset;
		this->g_offset = copy.b_offset;

		this->model = copy.model;
	}
	~Chick() {
		//all the data types should have own destructors
	}
};