//Make changes accordingly if using Opengl ES 2.0
// Info in:
//https://developer.apple.com/library/ios/documentation/3DDrawing/Conceptual/OpenGLES_ProgrammingGuide/AdoptingOpenGLES3/AdoptingOpenGLES3.html#//apple_ref/doc/uid/TP40008793-CH504-SW18
#version 300 es

in lowp vec4 DestinationColor; // 1
in lowp vec2 vTexCoord;

out highp vec4 finalFragColor;

uniform sampler2D Texture;

void main(void) { // 2
    
    highp vec4 texturecolor = texture(Texture, vTexCoord)  ;
    
    //If Running on ios device, texturecolor will be stored as bgr else, comment out next line
    texturecolor = vec4(texturecolor.z, texturecolor.y, texturecolor.x, texturecolor.w);
    
    finalFragColor = texturecolor * DestinationColor; // 3
}