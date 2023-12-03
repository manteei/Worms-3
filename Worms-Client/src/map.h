#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/glu.h>
#include "textureManager.h"

using namespace sf;

class Map
{
public:
    int maxX, maxY, maxZ;
    int minX, minY, minZ;

    Map(int x0, int y0, int z0);
    void createMap(std::vector < std::vector<std::vector<bool>>>& mass);
    void drawMap(TextureManager textureManager, float size);
    bool check(int x, int y, int z, std::vector < std::vector<std::vector<bool>>>& mass);
    void drawMap(TextureManager textureManager, float size, GLuint box, std::vector < std::vector<std::vector<bool>>>& mass);

};

