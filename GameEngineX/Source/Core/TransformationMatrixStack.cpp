//
//  TransformationMatrixStack.cpp
//  GameEngineX
//
//  Created by George Hanna on 20/05/16.
//  Copyright © 2016 George Hanna. All rights reserved.
//

#include "TransformationMatrixStack.hpp"

namespace TransformationMatrixStack {
    
    TransformationMatrixStack* _matrixstack;
    
    void Initialize()
    {
        _matrixstack = new TransformationMatrixStack();
    }
    
    void SetupMatrices(glm::mat4x4 &mmatrix, glm::mat4x4 &mvmatrix, glm::mat4x4 &mvpmatrix)
    {
        if(_matrixstack->_size > 2)
        {
            mvpmatrix = _matrixstack->_stack[0];
            mvmatrix = _matrixstack->_stack[1];
            mmatrix = _matrixstack->_stack[2];
        
            for (int i = 3; i<_matrixstack->_size; i++) {
                mmatrix = mmatrix * _matrixstack->_stack[i];
            }
            
            mvmatrix = _matrixstack->_stack[1] * mmatrix;
            mvpmatrix = _matrixstack->_stack[0] * mvmatrix;
        }
    }
    
    glm::mat4x4 GetMVPMatrix()
    {
        glm::mat4x4 mvpmatrix;
        if(_matrixstack->_size > 0)
        {
            mvpmatrix = _matrixstack->_stack[0];
            for (int i = 1; i<_matrixstack->_size; i++) {
                mvpmatrix = mvpmatrix * _matrixstack->_stack[i];
            }
        }
        return mvpmatrix;
    }
    glm::mat4x4 GetMVMatrix()
    {
        glm::mat4x4 mvmatrix;
        if(_matrixstack->_size > 1)
        {
            mvmatrix = _matrixstack->_stack[1];
            for (int i = 2; i<_matrixstack->_size; i++) {
                mvmatrix = mvmatrix * _matrixstack->_stack[i];
            }
        }
        return mvmatrix;
    }
    
    void SetViewMatrix(glm::mat4x4 viewmatrix)
    {
        _matrixstack->_stack[1] = viewmatrix;
    }
    
    void Push(glm::mat4x4 matrix)
    {
        _matrixstack->_stack[_matrixstack->_size] = matrix;
        _matrixstack->_size++;
    }
    void Pop()
    {
        if(_matrixstack->_size > 0)
            _matrixstack->_size--;
    }
}
