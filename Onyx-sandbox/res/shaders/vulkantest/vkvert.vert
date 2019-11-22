#version 450

vec2 positions[6] = vec2[](
	vec2(-0.5, -0.5), //TL
	vec2(0.5, -0.5), //TR
	vec2(0.5, 0.5), //BR
	
	vec2(-0.5, -0.5), //TL
	vec2(0.5, 0.5), //BR
	vec2(-0.5, 0.5)  //BL
);

vec3 colors[6] = vec3[](
    vec3(1.0, 0.0, 1.0),
    vec3(0.0, 1.0, 1.0),
	vec3(0.5, 0.2, 1.0),
	
	vec3(1.0, 0.0, 1.0),
	vec3(0.5, 0.2, 1.0),
    vec3(0.0, 1.0, 1.0)
	
);

layout(location = 0) out vec3 fragColor;

void main() {
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
    fragColor = colors[gl_VertexIndex];
}