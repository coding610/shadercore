#version 430 core

in vec2 position;
out vec2 texCoord;

void main() {
    gl_Position = vec4(position, 0, 1);
    texCoord = position;
}
