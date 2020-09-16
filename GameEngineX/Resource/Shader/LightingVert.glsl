#version 300 es

uniform mat4 MVPMatrix;
uniform mat4 VPMatrix;
uniform mat4 MVMatrix;
uniform mat4 MMatrix;

in vec4 Position;
in vec4 Normal;
in vec2 TextureCoord;
in vec4 SourceColor;

out vec4 vPosition;
out vec4 vColor;
out vec4 vNormal;
out vec2 vTexCoord;

void main(void) { 
    vTexCoord = TextureCoord;
    vPosition = MMatrix * Position;
    vNormal = Normal;
    vColor = SourceColor;
    gl_Position = MVPMatrix * Position;
}