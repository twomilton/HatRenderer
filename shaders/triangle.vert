#version 330 core

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec3 aNormal;

uniform mat4 uTransform;

out vec3 vertexColor;
out vec3 vNormal;

void main()
{
	gl_Position = 
		uTransform * 
		vec4(aPosition, 1.0);

	vertexColor = aColor;
	vNormal = aNormal;
}