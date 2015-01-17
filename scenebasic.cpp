#include "scenebasic.h"

#include <cstdio>
#include <cstdlib>

#include <iostream>

#include <fstream>
using std::ifstream;

#include <sstream>
using std::ostringstream;

#include "glutils.h"
#include "../glm/gtc/matrix_transform.hpp"
//#include "C:/glm/glm/gtc/matrix_projection.hpp"
#include "../glm/gtx/transform2.hpp"

SceneBasic::SceneBasic() : angle(0.0)
{
    eye = vec3(0.0f,0.0f,2.0f);
    direction = vec3(0.0f,0.0f,-1.0f);

    readData("shader/scenebasic2.dat");
}

void SceneBasic::readData(const char* fname)
{
    ifstream ifs(fname);

    if (!ifs) {
        std::cout << "data file not found\n";
        exit(1);
    } else {
        for (int i=0; i<108; i++) ifs >> positionData[i];
        for (int i=0; i<108; i++) ifs >> colorData[i];
    }
}


void SceneBasic::CreateVBO()
{
    // Create and populate the buffer objects
    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);

    GLuint positionBufferHandle = vboHandles[0];
    GLuint colorBufferHandle = vboHandles[1];

    // bind positionBufferHandle to GL_ARRAY_BUFFER buffer object target
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    // creates and initializes GL_ARRAY_BUFFER buffer object's data store
    glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), positionData, GL_STATIC_DRAW);

     // bind colorBufferHandle to GL_ARRAY_BUFFER target
    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, 108 * sizeof(float), colorData, GL_STATIC_DRAW);

    // Create and set-up the vertex array object
    glGenVertexArrays( 1, &vaoHandle );
    // bind the vertex array object
    glBindVertexArray(vaoHandle);

    /* enables the generic vertex attribute array
       the values in the generic vertex attribute array will be accessed
       and used for rendering when calls are made to vertex array commands
       such as glDrawArrays */
    glEnableVertexAttribArray(0);  // Vertex position
    glEnableVertexAttribArray(1);  // Vertex color

    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);

    /* define an array of generic vertex attribute data
       specifies the location and data format of the array of generic
       vertex attributes at index 0 to use when rendering */
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colorBufferHandle);
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, 0);
}


void SceneBasic::initScene()
{
    //////////////////////////////////////////////////////
    /////////// Vertex shader //////////////////////////
    //////////////////////////////////////////////////////

    /* The OpenGL Extension Wrangler Library (GLEW) is a cross-platform
     open-source C/C++ extension loading library. GLEW provides efficient
     run-time mechanisms for determining which OpenGL extensions are supported
     on the target platform.

     if you link with some function - it must exist on target platform,
     or your program wouldn't launch. GLEW handles that - you're not linking
     with GL functions directly, but instead getting function pointers after
     initialization phase. It allows you to check at runtime which extensions
     are present and which functions may be used.

     GLEW obtains information on the supported extensions from the graphics driver.
     Experimental or pre-release drivers, however, might not report every available
     extension through the standard mechanism, in which case GLEW will report
     it unsupported. To circumvent this situation, the glewExperimental global switch
     can be turned on by setting it to GL_TRUE before calling glewInit(), which ensures
     that all extensions with valid entry points will be exposed. */

    glewExperimental = GL_TRUE;
    glewInit();

	// Create the vertex shader object
    GLuint vertShader = prog.createShader(GL_VERTEX_SHADER);

    // Check status
    if( 0 == vertShader)
    {
		fprintf(stderr, "Error creating vertex shader.\n");
		exit(1);
    }

	// load the shader from the file
    prog.load_shader(vertShader,"shader/basic.vert");

	// compile the shader
    prog.compileShader(vertShader);

    // Check compilation status
    prog.checkCompileStatus(vertShader);

  
    //////////////////////////////////////////////////////
    /////////// Fragment shader //////////////////////////
    //////////////////////////////////////////////////////


   // Create the fragment shader object
    GLuint fragShader = prog.createShader(GL_FRAGMENT_SHADER);

    // Check status
    if( 0 == fragShader)
    {
		fprintf(stderr, "Error creating fragment shader.\n");
		exit(1);
    }

	// load the shader from the file
    prog.load_shader(fragShader,"shader/basic.frag");

	// compile the shader
    prog.compileShader(fragShader);

    // Check compilation status
    prog.checkCompileStatus(fragShader);

    // Create the program object
    if (!prog.createObject()) printf("error\n");

    // attach shaders to program object
    prog.attachShader(vertShader);
    prog.attachShader(fragShader);

    // Bind index 0 to the shader input variable "VertexPosition"
    prog.bindAttribLocation(0, "VertexPosition");
    // Bind index 1 to the shader input variable "VertexColor"
    prog.bindAttribLocation(1, "VertexColor");

    // link the program
    prog.link();

    // create and populate the vertex buffer opbject
    CreateVBO();

    prog.printActiveUniforms();

    model = mat4(1.0f);
    //float ang = 0; //-35.0;
    //model *= glm::rotate(mat4(1.0f),ang, vec3(1.0f,0.0f,0.0f));
    //model *= glm::rotate(mat4(1.0f),-ang, vec3(0.0f,1.0f,0.0f));
    view = glm::lookAt(eye, direction, vec3(0.0f,1.0f,0.0f));
    projection = mat4(1.0f);

    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glEnable(GL_DEPTH_TEST);
}


void SceneBasic::update( float t )
{
    while(angle < t)
    {
        angle += 1.0f;
        if( angle >= 360.0f)
            angle -= 360.0f;
    }
}


void SceneBasic::setMatrices()
{
    rotationMatrix = glm::rotate(mat4(1.0f),glm::radians(angle),vec3(1.0f,1.0f,0.0f));
    mat4 mv = view * model;
    prog.setUniform("ModelViewMatrix", mv);
    prog.setUniform("MVP", projection * mv);
}


void SceneBasic::render()
{

    /* sets the bitplane area of the window to values previously
       selected by glClear. GL_COLOR_BUFFER_BIT indicates the buffers
       currently enabled for color writing. */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* render primitives from array data
       GL_TRIANGLES Specifies what kind of primitives to render.
       Possibilities are symbolic constants GL_POINTS, GL_LINE_STRIP,
       GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN and GL_TRIANGLES.
       0 specifies the starting index in the enabled arrays.
       36 specifies the number of indices to be rendered. */

    setMatrices();
    glDrawArrays(GL_TRIANGLES, 0, 36 );
}

void SceneBasic::resize(int w, int h)
{
    glViewport(0,0,w,h);
    width = w;
    height = h;
    projection = glm::perspective(70.0f, (float)w/h, 0.3f, 100.0f);
}


void SceneBasic::printActiveUniforms(GLuint programHandle) {

    GLint nUniforms, size, location, maxLen;
    GLchar * name;
    GLsizei written;
    GLenum type;

    glGetProgramiv( programHandle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxLen);
    glGetProgramiv( programHandle, GL_ACTIVE_UNIFORMS, &nUniforms);

    name = (GLchar *) malloc( maxLen );

    printf(" Location | Name\n");
    printf("------------------------------------------------\n");
    for( int i = 0; i < nUniforms; ++i ) {
        glGetActiveUniform( programHandle, i, maxLen, &written, &size, &type, name );
        location = glGetUniformLocation(programHandle, name);
        printf(" %-8d | %s\n",location, name);
    }

    free(name);
}

void SceneBasic::printActiveAttribs(GLuint programHandle) {

    GLint written, size, location, maxLength, nAttribs;
    GLenum type;
    GLchar * name;

    glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
    glGetProgramiv(programHandle, GL_ACTIVE_ATTRIBUTES, &nAttribs);

    name = (GLchar *) malloc( maxLength );

    printf(" Index | Name\n");
    printf("------------------------------------------------\n");
    for( int i = 0; i < nAttribs; i++ ) {
        glGetActiveAttrib( programHandle, i, maxLength, &written, &size, &type, name );
        location = glGetAttribLocation(programHandle, name);
        printf(" %-5d | %s\n",location, name);
    }

    free(name);
}

void SceneBasic::setEye(double eyeVs[])
{
    eye = vec3(eyeVs[0], eyeVs[1], eyeVs[2]);
}

void SceneBasic::setDirection(double directionVs[])
{
    direction = vec3(directionVs[0], directionVs[1], directionVs[2]);
}
