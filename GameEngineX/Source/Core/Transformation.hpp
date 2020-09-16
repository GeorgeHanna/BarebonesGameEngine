//
//  Transformation.hpp
//  GameEngineX
//
//  Created by George Hanna on 22/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef Transformation_hpp
#define Transformation_hpp

#include <stdio.h>
#include "glm.hpp"
#include "gtc/quaternion.hpp"
#include "TransformationMatrixStack.hpp"

class Transformation {
public:
    glm::vec3 _position;
    glm::vec3 _scale;
    glm::quat _rotation;
    
    glm::mat4x4 _mmatrix;
    glm::mat4x4 _mvmatrix;
    glm::mat4x4 _mvpmatrix;
    glm::mat4x4 GetTransformationMatrix();
    void PushTransformation();
    void PopTransformation();
    void SetupMatrices();
};

#endif /* Transformation_hpp */
