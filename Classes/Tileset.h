#ifndef OOP_TILESET_H
#define OOP_TILESET_H

#include <SFML/Graphics.hpp>

class Tileset : public sf::Drawable, public sf::Transformable {
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        // apply the entity's transform -- combine it with the one that was passed by the caller
        states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

        // apply the texture
        states.texture = &m_tileset;

        // you may also override states.shader or states.blendMode if you want

        // draw the vertex array
        target.draw(m_vertices, states);
    }


public:
    bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);
};


#endif //OOP_TILESET_H
