#ifndef SCENEBASIC_H
#define SCENEBASIC_H

#include "scene.h"
#include "/usr/include/GL/glew.h"
#include "glslprogram.h"
#include "../glm/glm.hpp"
using glm::mat4;

class SceneBasic : public Scene
{
private:
    int width, height;
    GLuint vboHandles[2];
    GLuint vaoHandle;
    float angle;
    vec3 eye;
    vec3 direction;
    mat4 rotationMatrix;
    GLSLProgram prog;

    mat4 model;
    mat4 view;
    mat4 projection;

    void readData(const char* fname);
    void CreateVBO();

    float positionData[108];
    float colorData[108];
public:
    SceneBasic();
    void setMatrices();

    void initScene();
    void render();
    void resize(int, int);
    void update( float t );

    void printActiveUniforms(GLuint programHandle);
    void printActiveAttribs(GLuint programHandle);

    void setEye(double eyeVs[]);
    void setDirection(double directionVs[]);
};

#endif // SCENEBASIC_H
