//Make changes accordingly if using Opengl ES 2.0
// Info in:
//https://developer.apple.com/library/ios/documentation/3DDrawing/Conceptual/OpenGLES_ProgrammingGuide/AdoptingOpenGLES3/AdoptingOpenGLES3.html#//apple_ref/doc/uid/TP40008793-CH504-SW18
#version 300 es

precision highp float;

const int NRPOINTLIGHTS = 1;


uniform sampler2D Texture;

//Directional Light
uniform highp vec3 u_directionallightdir;
uniform lowp vec3 u_directionallightcolor;
uniform lowp float u_directionallightambient;

//Point Lights
uniform highp vec3 u_pointlightspos[NRPOINTLIGHTS];
uniform lowp vec3 u_pointlightscolor[NRPOINTLIGHTS];
uniform lowp float u_pointlightssize[NRPOINTLIGHTS];

in highp vec4 vPosition;
in lowp vec4 vColor;
in highp vec4 vNormal;
in lowp vec2 vTexCoord;

out highp vec4 finalFragColor;


void main(void) { // 2
    
    highp vec4 finalcolor = vec4(0,0,0,0);
    
    //Texture reads
    highp vec4 texturecolor = texture(Texture, vTexCoord);
    //If Running on ios device, texturecolor will be stored as bgr else, comment out next line
    //texturecolor = vec4(texturecolor.z, texturecolor.y, texturecolor.x, texturecolor.w);
    
    //highp vec4 normalmapcolor = texture2D(u_normalmap, v_texCoord);
    
    //Normals
    //vec3 normalfrombump = normalize(normalmapC.rgb * 2.0-1.0);
    //vec3 normal = normalize(v_fragmentNormal.xyz + normalfrombump);
    
    // Alpha is below 0.1 then no light calc
    if(texturecolor.w < 0.1)
        finalcolor =  texturecolor;
    else
    {
        
        // Directional Light
        vec3 L = normalize(u_directionallightdir);
        float intensity = max(0.0, dot(vNormal.xyz, normalize(L)));
        intensity = intensity + u_directionallightambient;
        finalcolor.xyz = (texturecolor  * vec4(u_directionallightcolor,1) * intensity).xyz;
        finalcolor.w = texturecolor.w;
        
        vec3 pointlight1pos = u_pointlightspos[0];
        vec3 pointlight1col = u_pointlightscolor[0];
        
        L = pointlight1pos - vPosition.xyz;
        float L_length = length(L);
        float attenuation = (1.0 / (1.0 * L_length * L_length)) * u_pointlightssize[0];
        intensity = max(dot(vNormal.xyz, normalize(L)), 0.0);
        vec3 I = pointlight1col * intensity * attenuation;
        intensity = clamp(intensity, 0.0, 1.0);
        vec4 diffusecolor = vec4(I,1.0)  * texturecolor /* vColor*/;
        finalcolor += diffusecolor;
        
        
        //vec3 light = vec3(u_directionallightdir.x,u_directionallightdir.y,u_directionallightdir.z);
        //vec3 L = light;
        //L = normalize(L);
        //float intensity = max(0.0, dot(normal, L));
        //vec3 I = vec3(intensity, intensity, intensity) * u_directionallightcolor;
        //vec4 diffusecolor = (vec4(I,1.0)  * textureC * v_fragmentColor);
        //totalC += diffusecolor;
        //totalC += vec4(u_directionallightcolor,1.0) * textureC * v_fragmentColor * u_directionallightambient;
        /*
        // Point Lights
        for (int i = 0; i<NRPOINTLIGHTS; i++) {
            if(u_pointlightstobedrawn[i] == 1)
            {
                //Point Light
                vec3 light = vec3(u_pointlightspos[i].x,u_pointlightspos[i].y,1.0 );
                vec3 L =  light - v_fragmentPosition.xyz;
                L = L / u_pointlightspos[i].z;
                //Count in the zoom of the camera to adjust attenuation.
                float L_length = length(L);
                
                
                // Attenuation
                float attenuation = (1.0 / (0.00005 * L_length * L_length)) * u_pointlightssize[i];
                
                //Final Color and Intensity
                float intensity = max(dot(normal, normalize(L)), 0.0);
                intensity = clamp(intensity, 0.0, 1.0);
                vec3 I = u_pointlightscolor[i] * intensity * attenuation;
                vec4 diffusecolor = vec4(I,1.0)  * textureC * v_fragmentColor;
                
                totalC += diffusecolor;
                
            }
        }
         */
    }
    finalcolor.x = clamp(finalcolor.x, 0.0, 1.0);
    finalcolor.y = clamp(finalcolor.y, 0.0, 1.0);
    finalcolor.z = clamp(finalcolor.z, 0.0, 1.0);
    
    
    //finalcolor = texturecolor;

    
    finalFragColor = finalcolor; // 3
}
