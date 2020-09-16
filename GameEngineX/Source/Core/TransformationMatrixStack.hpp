//
//  TransformationMatrixStack.hpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#ifndef TransformationMatrixStack_hpp
#define TransformationMatrixStack_hpp

#include <stdio.h>
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

namespace TransformationMatrixStack {
    class TransformationMatrixStack
    {
        
    public:
        glm::mat4x4 _stack[10];
        int _size;
    };
    
    void Push(glm::mat4x4 matrix);
    glm::mat4x4 GetMVPMatrix();
    glm::mat4x4 GetMVMatrix();
    void SetupMatrices(glm::mat4x4 &mmatrix, glm::mat4x4 &mvmatrix, glm::mat4x4 &mvpmatrix);
    void SetViewMatrix(glm::mat4x4 viewmatrix);
    
    void Pop();
    void Initialize();
}



#endif /* TransformationMatrixStack_hpp */
