#version 430 core

in vec2 fragCoord;
out vec4 fragColor;

void main() {
    fragColor = vec4(fragCoord.x, fragCoord.y, 0, 1);
}
