#version 330 core
in vec3 fragColor;
in vec3 fragNormal;
in vec3 fragPosition;

out vec4 outColor;

uniform vec3 lightPos = vec3(5.0, 5.0, 5.0);
uniform vec3 viewPos = vec3(0.0, 0.0, 10.0);

void main() {
	// Освещение: ламбертовское + ambient
	vec3 norm = normalize(fragNormal);
	vec3 lightDir = normalize(lightPos - fragPosition);
	float diff = max(dot(norm, lightDir), 0.0);

	vec3 ambient = 0.2 * fragColor;
	vec3 diffuse = diff * fragColor;

	outColor = vec4(ambient + diffuse, 1.0);
}