#version 330 core

uniform vec3 uLightDirection;
uniform vec3 uLightColor;
uniform float uLightIntensity;
uniform vec3 uMaterialDiffuse;

in vec3 vertexColor;
in vec3 vNormal;

out vec4 FragColor;

void main()
{
	vec3 lightDirection =
		normalize(-uLightDirection);

	float brightness =
		max(dot(normalize(vNormal), lightDirection),
			0.0);

	vec3 litColor =
		//vertexColor * 
		uMaterialDiffuse *
		brightness * 
		uLightColor * 
		uLightIntensity;

	FragColor =
		vec4(litColor, 1.0);
}