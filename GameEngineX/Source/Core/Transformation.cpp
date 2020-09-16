//
//  Transformation.cpp
//  GameEngineX
//
//  Created by George Hanna on 22/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "Transformation.hpp"

void Transformation::PushTransformation()
{
    TransformationMatrixStack::Push(GetTransformationMatrix());
}

void Transformation::PopTransformation()
{
    TransformationMatrixStack::Pop();
}

void Transformation::SetupMatrices()
{
    TransformationMatrixStack::SetupMatrices(_mmatrix, _mvmatrix, _mvpmatrix);
}

glm::mat4x4 Transformation::GetTransformationMatrix()
{
    glm::mat4x4 model = glm::mat4x4(1.0f);
    glm::mat4x4 translation = glm::translate(model, _position);
    glm::mat4 rotation = glm::mat4_cast(_rotation);
    glm::mat4x4 scale = glm::scale(model, _scale);
    model = translation * rotation * scale;
    return model;
}

