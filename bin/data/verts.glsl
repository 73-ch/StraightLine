#version 150
in float seed;
uniform vec3 dVec;
uniform vec3 bPos;
uniform mat4 modelViewProjectionMatrix;
uniform int count;
uniform vec3 randomSeed;
in vec4 position;

vec3 rnd(float n, vec3 s){
    return vec3((fract(sin(dot(vec2(n, s.x), vec2(12.9898, 4.1414))) * 43758.5453) - 0.5) * 20.,
    						(fract(sin(dot(vec2(n, s.y), vec2(12.9898, 4.1414))) * 43758.5453) - 0.5) * 20.,
    						(fract(sin(dot(vec2(n, s.z), vec2(12.9898, 4.1414))) * 43758.5453) - 0.5) * 20.);
}

float rnd(vec2 n){
    return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

void main() {
	vec3 ore = rnd(gl_VertexID, randomSeed);
	gl_Position = modelViewProjectionMatrix * vec4(bPos + dVec * seed + ore * (1.0 - step(count, gl_VertexID)), 1.0);
}