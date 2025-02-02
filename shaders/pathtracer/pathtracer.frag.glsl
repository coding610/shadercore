#version 430 core

in vec2 texCoord;
out vec4 fragColor;

struct Camera {
    vec3 position;
    vec3 direction;
    float fov;
    float focalPoint;
};

layout(std140, binding = 0) uniform camera {
    vec3 position;
    vec3 direction;
    float fov;
    float focalPoint;
};

void main() {
    Camera camera = {position, direction, fov, focalPoint};
    fragColor = vec4(camera.position, 1);
}
