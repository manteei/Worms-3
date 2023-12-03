#include "player.h"

    Player::Player(float x0, float y0, float z0, float size0)
    {
        x = x0; y = y0; z = z0;
        dx = 0; dy = 0; dz = 0;
        w = 5; h = 20; d = 5; speed = 5;
        onGround = false;
        size = size0;
        needJump = false;
    }

    void Player::update(float time, std::vector < std::vector<std::vector<bool>>>& mass, Map map)
    {
        needJump = false;
        if (!onGround) dy -= 1.5 * time;
        onGround = 0;

        x += dx * time;  
        collision(dx, 0, 0, mass, map);
        y += dy * time;
        collision(0, dy, 0, mass, map);
        z += dz * time;
        collision(0, 0, dz, mass, map);

        dx = dz = 0;
    }
    void Player::setPosition(float x1, float y1, float z1)
    {
        x = x1;
        y = y1;
        z = z1;

    }
    
    void Player::collision(float Dx, float Dy, float Dz, std::vector < std::vector<std::vector<bool>>>& mass, Map map)
    {
        float minX = map.minX; 
        float minY = map.minY; 
        float minZ = map.minZ; 
        float maxX = map.maxX * size; 
        float maxY = map.maxY * size; 
        float maxZ = map.maxZ * size; 

        if (x - w + Dx < minX) {
            x = minX + w;
        }
        if (x + w + Dx > maxX) {
            x = maxX - w;

        }
        if (y + h + Dy < minY) {
            y = minY +h;
        }

        if (y + h + Dy > maxY) {
            y = maxY - h;
        }
        if (z - d + Dz < minZ) {
            z = minZ + d;
        }
        if (z + d + Dz > maxZ) {
            z = maxZ - d;
        }

        for (int X = (x - w) / size; X < (x + w) / size; X++)
            for (int Y = (y - h) / size; Y < (y + h) / size; Y++)
                for (int Z = (z - d) / size; Z < (z + d) / size; Z++)
                    if (check(X, Y, Z, mass)) {
                        if (Dx > 0) {
                            x = X * size - w; needJump = true;
                        }
                        if (Dx < 0) {
                            x = X * size + size + w; needJump = true;
                        }
                        if (Dy > 0)  y = Y * size - h;
                        if (Dy < 0) { y = Y * size + size + h; onGround = true; dy = 0; }
                        if (Dz > 0) { z = Z * size - d; needJump = true; }
                        if (Dz < 0) { z = Z * size + size + d; needJump = true; }
                    }
    }

    bool Player::check(int x, int y, int z, std::vector < std::vector<std::vector<bool>>>& mass)
    {
        if ((x < 0) || (x >= 500) ||
            (y < 0) || (y >= 500) ||
            (z < 0) || (z >= 500)) return false;

        return mass[x][y][z];
    }

    

    void Player::keyboard(float angleX)
    {
            if (Keyboard::isKeyPressed(Keyboard::Space)) if (onGround) { onGround = false; dy = 12; };

            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                dx = -sin(angleX / 180 * PI) * speed;
                dz = -cos(angleX / 180 * PI) * speed;
                if (needJump) {
                    onGround = false; dy = 12;
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                dx = sin(angleX / 180 * PI) * speed;
                dz = cos(angleX / 180 * PI) * speed;
                if (needJump) {
                    onGround = false; dy = 12;
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                dx = sin((angleX + 90) / 180 * PI) * speed;
                dz = cos((angleX + 90) / 180 * PI) * speed;
                if (needJump) {
                    onGround = false; dy = 12;
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                dx = sin((angleX - 90) / 180 * PI) * speed;
                dz = cos((angleX - 90) / 180 * PI) * speed;
                if (needJump) {
                    onGround = false; dy = 12;
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::E))
            {
                onGround = false; dy = 40;
            }

    };


