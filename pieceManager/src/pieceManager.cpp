//
//  pieceManager.cpp
//  chessApp
//
//  Created by Sebastian Fabian Echeandia Reynes on 18/4/25.
//

// Standard libraries
#include <iostream>

// Internal libraries
#include <pieceManager.hpp>

using namespace gui;

chessPiece::chessPiece()
{
	// Default constructor
}

chessPiece::chessPiece(pieceType type, pieceColor color, const std::string& texturePath, sf::Vector2<float> initialPosition)
{
	_type = type;
	_color = color;
	_texturePath = texturePath;

	// Load texture for piece
	if (!_texture.loadFromFile(_texturePath))
	{
		std::cerr << "Error loading texture from file: " << texturePath << std::endl;
	}
	_sprite.setTexture(_texture);

	// Set the origin of the sprite to the middle of the piece
	sf::FloatRect pieceRect = _sprite.getLocalBounds();
	_sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);

	// Set the initial position of the piece
	_position = initialPosition;
	_sprite.setPosition(_position);
}

chessPiece::chessPiece(const chessPiece& other)
{
	// Copiar los valores primitivos
	_type = other._type;
	_color = other._color;
	_position = other._position;

	// Recargar la textura desde el archivo original
	if (!_texture.loadFromFile(other._texturePath))
	{
		std::cerr << "Error loading texture from file: " << other._texturePath << std::endl;
	}
	_sprite.setTexture(_texture);

	// Copiar las propiedades del sprite
	_sprite.setOrigin(other._sprite.getOrigin());
	_sprite.setPosition(_position);
}

chessPiece::~chessPiece()
{
	// Destructor
}

sf::Sprite* chessPiece::getSpriteAddress()
{
	return &_sprite;
}

void chessPiece::setPosition(sf::Vector2<float> newPosition)
{
	_sprite.setPosition(newPosition);
}

void chessPiece::resetPosition()
{
	_sprite.setPosition(_position);
}

