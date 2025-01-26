#version 430 core

in vec2 texCoord;
out vec4 fragColor;

void main() {
    fragColor = vec4(abs(texCoord.x), abs(texCoord.y), 0, 1);
}
