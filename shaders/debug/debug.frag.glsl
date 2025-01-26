#version 430 core

in vec2 texCoord;
out vec4 fragColor;

uniform float time;

void main() {
    // float r = sin(fragCoord.x * 10.0 + time * 2.0) * 0.5 + 0.5;
    // float g = sin(fragCoord.y * 10.0 + time * 2.0) * 0.5 + 0.5;
    // float b = sin((fragCoord.x + fragCoord.y) * 5.0 + time * 2.0) * 0.5 + 0.5;
    // fragColor = vec4(r, g, b, 1); 
    fragColor = vec4(abs(texCoord.x), abs(texCoord.y), 0, 1);
}
