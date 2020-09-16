#-------------------------------------------------
#
# Project created by QtCreator 2016-07-14T07:51:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qttest
TEMPLATE = app

CONFIG += c++14

DEFINES += OPEN_GL_DESKTOP
DEFINES += GLEW_NO_GLU
DEFINES += GLEW_STATIC
INCLUDEPATH += ../../glm/glm \
INCLUDEPATH += ../../glew/include \
INCLUDEPATH += ../../Box2D \
INCLUDEPATH += ../.. \
INCLUDEPATH += "$(KINDLER_ROOT)/Game/GameEngineX/QtTest/qttest" \


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../Source/Core/Graphics/BaseLightComponent.cpp \
    ../../Source/Core/Graphics/DirectionalLightComponent.cpp \
    ../../Source/Core/Graphics/LightHandler.cpp \
    ../../Source/Core/Graphics/Mesh.cpp \
    ../../Source/Core/Graphics/MeshHandler.cpp \
    ../../Source/Core/Graphics/PointLightComponent.cpp \
    ../../Source/Core/Graphics/ShaderProgram.cpp \
    ../../Source/Core/Graphics/ShaderProgramHandler.cpp \
    ../../Source/Core/Graphics/SimpleLightingShaderProgram.cpp \
    ../../Source/Core/Graphics/SimpleShaderProgram.cpp \
    ../../Source/Core/Graphics/SpriteLightRenderComponent.cpp \
    ../../Source/Core/Graphics/SpriteRenderComponent.cpp \
    ../../Source/Core/Graphics/Texture.cpp \
    ../../Source/Core/Graphics/TextureHandler.cpp \
    ../../glew/src/glew.c \
    ../../Source/Core/Subject.cpp \
    ../../Source/Core/Camera.cpp \
    ../../Source/Core/Component.cpp \
    ../../Source/Core/Entity.cpp \
    ../../Source/Core/Game.cpp \
    ../../Source/Core/Resources.cpp \
    ../../Source/Core/Timer.cpp \
    ../../Source/Core/Transformation.cpp \
    ../../Source/Core/TransformationMatrixStack.cpp \
    ../../Source/Core/Input/InputHandler.cpp \
    ../../Source/Core/Physics/Physics2DContactListener.cpp \
    ../../Source/Core/Physics/PhysicsBody2DCircleComponent.cpp \
    ../../Source/Core/Physics/PhysicsBody2DComponent.cpp \
    ../../Source/Core/Physics/PhysicsBody2DEdgeShapeComponent.cpp \
    ../../Source/Core/Physics/PhysicsBody2DPolygonComponent.cpp \
    ../../Source/Core/Physics/PhysicsWorld2DComponent.cpp \
    ../../Source/Core/Physics/PhysicsWorldHandler.cpp \
    ../../Box2D/Collision/b2BroadPhase.cpp \
    ../../Box2D/Collision/b2CollideCircle.cpp \
    ../../Box2D/Collision/b2CollideEdge.cpp \
    ../../Box2D/Collision/b2CollidePolygon.cpp \
    ../../Box2D/Collision/b2Collision.cpp \
    ../../Box2D/Collision/b2Distance.cpp \
    ../../Box2D/Collision/b2DynamicTree.cpp \
    ../../Box2D/Collision/b2TimeOfImpact.cpp \
    ../../Box2D/Common/b2BlockAllocator.cpp \
    ../../Box2D/Common/b2Draw.cpp \
    ../../Box2D/Common/b2Math.cpp \
    ../../Box2D/Common/b2Settings.cpp \
    ../../Box2D/Common/b2StackAllocator.cpp \
    ../../Box2D/Common/b2Timer.cpp \
    ../../Box2D/Dynamics/b2Body.cpp \
    ../../Box2D/Dynamics/b2ContactManager.cpp \
    ../../Box2D/Dynamics/b2Fixture.cpp \
    ../../Box2D/Dynamics/b2Island.cpp \
    ../../Box2D/Dynamics/b2World.cpp \
    ../../Box2D/Dynamics/b2WorldCallbacks.cpp \
    ../../Box2D/Rope/b2Rope.cpp \
    ../../Box2D/Collision/Shapes/b2ChainShape.cpp \
    ../../Box2D/Collision/Shapes/b2CircleShape.cpp \
    ../../Box2D/Collision/Shapes/b2EdgeShape.cpp \
    ../../Box2D/Collision/Shapes/b2PolygonShape.cpp \
    ../../Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    ../../Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    ../../Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    ../../Box2D/Dynamics/Contacts/b2Contact.cpp \
    ../../Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    ../../Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    ../../Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    ../../Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    ../../Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    ../../Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2GearJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2Joint.cpp \
    ../../Box2D/Dynamics/Joints/b2MotorJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    ../../Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    kindlerwidget.cpp \
    ../../Source/Core/Subject.cpp \
    ../../Source/Core/Graphics/AnimationComponent.cpp \
    ../../Source/Core/Graphics/meshdata.cpp \
    ../../Source/Core/Graphics/vertex.cpp \

HEADERS  += mainwindow.h \
    ../../Source/Core/Subject.hpp \
    ../../Source/Core/Graphics/BaseLightComponent.hpp \
    ../../Source/Core/Graphics/DirectionalLightComponent.hpp \
    ../../Source/Core/Graphics/LightHandler.hpp \
    ../../Source/Core/Graphics/Mesh.hpp \
    ../../Source/Core/Graphics/MeshHandler.hpp \
    ../../Source/Core/Graphics/PointLightComponent.hpp \
    ../../Source/Core/Graphics/ShaderProgram.hpp \
    ../../Source/Core/Graphics/ShaderProgramHandler.hpp \
    ../../Source/Core/Graphics/SimpleLightingShaderProgram.hpp \
    ../../Source/Core/Graphics/SimpleShaderProgram.hpp \
    ../../Source/Core/Graphics/SpriteLightRenderComponent.hpp \
    ../../Source/Core/Graphics/SpriteRenderComponent.hpp \
    ../../Source/Core/Graphics/Texture.hpp \
    ../../Source/Core/Graphics/TextureHandler.hpp \
    ../../Source/Core/Graphics/openglinclude.h \
    ../../Source/Core/Camera.hpp \
    ../../Source/Core/Component.hpp \
    ../../Source/Core/Entity.hpp \
    ../../Source/Core/Game.hpp \
    ../../Source/Core/Resources.hpp \
    ../../Source/Core/Timer.hpp \
    ../../Source/Core/Transformation.hpp \
    ../../Source/Core/TransformationMatrixStack.hpp \
    ../../Source/Core/Input/InputHandler.hpp \
    ../../Source/Core/Physics/Physics2DContactListener.hpp \
    ../../Source/Core/Physics/PhysicsBody2DCircleComponent.hpp \
    ../../Source/Core/Physics/PhysicsBody2DComponent.hpp \
    ../../Source/Core/Physics/PhysicsBody2DEdgeShapeComponent.hpp \
    ../../Source/Core/Physics/PhysicsBody2DPolygonComponent.hpp \
    ../../Source/Core/Physics/PhysicsWorld2DComponent.hpp \
    ../../Source/Core/Physics/PhysicsWorldHandler.hpp \
    ../../Box2D/Collision/b2BroadPhase.h \
    ../../Box2D/Collision/b2Collision.h \
    ../../Box2D/Collision/b2Distance.h \
    ../../Box2D/Collision/b2DynamicTree.h \
    ../../Box2D/Collision/b2TimeOfImpact.h \
    ../../Box2D/Common/b2BlockAllocator.h \
    ../../Box2D/Common/b2Draw.h \
    ../../Box2D/Common/b2GrowableStack.h \
    ../../Box2D/Common/b2Math.h \
    ../../Box2D/Common/b2Settings.h \
    ../../Box2D/Common/b2StackAllocator.h \
    ../../Box2D/Common/b2Timer.h \
    ../../Box2D/Dynamics/b2Body.h \
    ../../Box2D/Dynamics/b2ContactManager.h \
    ../../Box2D/Dynamics/b2Fixture.h \
    ../../Box2D/Dynamics/b2Island.h \
    ../../Box2D/Dynamics/b2TimeStep.h \
    ../../Box2D/Dynamics/b2World.h \
    ../../Box2D/Dynamics/b2WorldCallbacks.h \
    ../../Box2D/Rope/b2Rope.h \
    ../../Box2D/Collision/Shapes/b2ChainShape.h \
    ../../Box2D/Collision/Shapes/b2CircleShape.h \
    ../../Box2D/Collision/Shapes/b2EdgeShape.h \
    ../../Box2D/Collision/Shapes/b2PolygonShape.h \
    ../../Box2D/Collision/Shapes/b2Shape.h \
    ../../Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    ../../Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    ../../Box2D/Dynamics/Contacts/b2CircleContact.h \
    ../../Box2D/Dynamics/Contacts/b2Contact.h \
    ../../Box2D/Dynamics/Contacts/b2ContactSolver.h \
    ../../Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    ../../Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    ../../Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    ../../Box2D/Dynamics/Contacts/b2PolygonContact.h \
    ../../Box2D/Dynamics/Joints/b2DistanceJoint.h \
    ../../Box2D/Dynamics/Joints/b2FrictionJoint.h \
    ../../Box2D/Dynamics/Joints/b2GearJoint.h \
    ../../Box2D/Dynamics/Joints/b2Joint.h \
    ../../Box2D/Dynamics/Joints/b2MotorJoint.h \
    ../../Box2D/Dynamics/Joints/b2MouseJoint.h \
    ../../Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    ../../Box2D/Dynamics/Joints/b2PulleyJoint.h \
    ../../Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    ../../Box2D/Dynamics/Joints/b2RopeJoint.h \
    ../../Box2D/Dynamics/Joints/b2WeldJoint.h \
    ../../Box2D/Dynamics/Joints/b2WheelJoint.h \
    kindlerwidget.h \
    ../../Source/Core/Subject.hpp \
    ../../Source/Core/Graphics/AnimationComponent.hpp \
    ../../Source/Core/Graphics/meshdata.hpp \
    ../../Source/Core/Graphics/vertex.hpp \
    ../../Source/Core/Common/stringhelpers.h \
    ../../Source/Core/Game.cpp.orig

FORMS    += mainwindow.ui

DISTFILES += \
    ../../Resource/Shader/LightingFrag.glsl \
    ../../Resource/Shader/LightingVert.glsl
