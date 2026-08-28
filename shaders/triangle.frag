#version 330 core

in vec3 vertexColor;
in vec3 vNormal;

out vec4 FragColor;

void main()
{
	vec3 lightDirection =
		normalize(vec3(1.0, 1.0, 1.0));

	float brightness =
		max(dot(normalize(vNormal), lightDirection), 0.0);

	vec3 litColor =
		vertexColor * brightness;

	FragColor =
		vec4(litColor, 1.0);
}