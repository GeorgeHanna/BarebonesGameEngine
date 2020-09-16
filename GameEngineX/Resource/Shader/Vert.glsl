#version 300 es

uniform mat4 MVPMatrix;
uniform mat4 VPMatrix;
uniform mat4 MVMatrix;
uniform vec4 SourceColor;

in vec4 Position; // 1
in vec2 TextureCoord; // 1

out vec4 DestinationColor; // 3
out vec2 vTexCoord;

void main(void) { // 4
    vTexCoord = TextureCoord;
    DestinationColor = SourceColor; // 5
    gl_Position = MVPMatrix * Position;
}