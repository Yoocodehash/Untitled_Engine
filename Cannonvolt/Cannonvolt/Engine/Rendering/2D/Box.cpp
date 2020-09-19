#include "Box.h"

Box::Box() {
	GLuint vbo;
	glGenBuffers(1, &vbo);
	
	// Allocate space and upload the data from CPU to GPU
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_position), vertices_position, GL_STATIC_DRAW);
}

Box::~Box()
{
}

void Box::GenBuffers()
{
}
