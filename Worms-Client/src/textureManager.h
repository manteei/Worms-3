#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>

class TextureManager
{
public:
    GLuint LoadTexture(sf::String name);
    void drawSkybox(std::vector<GLuint> skybox, float size);
    void drawBox(GLuint skybox, float size);
    std::vector<GLuint> createSkybox();
    GLuint createBox();
    GLuint createWorm();

};  