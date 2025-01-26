#version 430 core

in vec2 aPos;
out vec2 fragCoord;

void main() {
    fragCoord = (aPos + vec2(1.0, 1.0)) * 0.5;
    gl_Position = vec4(aPos, 0.0, 1.0);
}
