#pragma once

#include <glew.h> 

class Box{
	GLfloat vertices_position[24] = {
  		0.0, 0.0,
  		0.5, 0.0,
  		0.5, 0.5,
 
  		0.0, 0.0,
  		0.0, 0.5,
		-0.5, 0.5,
 
 		0.0, 0.0,
		-0.5, 0.0,
		-0.5, -0.5,

 		0.0, 0.0,
 		0.0, -0.5,
 		0.5, -0.5,
		};

public:
	Box();
	~Box();

	void GenBuffers();
};