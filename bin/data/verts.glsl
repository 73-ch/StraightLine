attribute float seed;
attribute vec4 position;
uniform vec3 dVec;
uniform vec3 bPos;

varying float sOpac;

float rnd(vec2 n){
    return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

void main() {
	gl_Position = modelViewProjectionMatrix * vec4(vec3(bPos + seed * dVec), 1.0);
	// gl_Position = position;
	sOpac = rnd(vec2(seed, sin(seed))) * 255.;
	gl_PointSize = 5.0;
}