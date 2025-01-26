#version 430 core

in vec2 texCoord;
out vec4 fragColor;

uniform float time;

void main() {
    fragColor = vec4(abs(texCoord.x), abs(texCoord.y), 0, 1);
}
