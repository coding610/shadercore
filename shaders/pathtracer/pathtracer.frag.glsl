#version 430 core

in vec2 texCoord;
out vec4 fragColor;


layout(std140, binding = 0) uniform Camera {
    vec3 position;
    vec3 direction;
    vec2 fov;
    float focalPoint;
};

void main() {
    fragColor = vec4(focalPoint, 0, 0, 1);
}
