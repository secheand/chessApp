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

chessPiece::chessPiece(pieceType type, pieceColor color, const std::string& texturePath, sf::Vector2<float> initialPixelPosition, sf::Vector2i initialSquarePosition)
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
	_pixelPosition = initialPixelPosition;
	_squarePosition = initialSquarePosition;
	_sprite.setPosition(_pixelPosition);
}

chessPiece& chessPiece::operator=(const chessPiece& other)
{
	// handle self-assignment
	if (this == &other)
	{
		return *this;
	}

	// Copy private values
	_type = other._type;
	_color = other._color;
	_pixelPosition = other._pixelPosition;
	_squarePosition = other._squarePosition;
	_texturePath = other._texturePath;

	// Reload texture
	if (!_texture.loadFromFile(_texturePath))
	{
		std::cerr << "Error loading texture from file: " << _texturePath << std::endl;
	}
	_sprite.setTexture(_texture);

	// Copy sprite properties
	_sprite.setOrigin(other._sprite.getOrigin());
	_sprite.setPosition(_pixelPosition);

	return *this;
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
	_sprite.setPosition(_pixelPosition);
}

std::vector<sf::Vector2<float>> chessPiece::getPossibleMoves(chessPiece* pieceMap)
{
	// This function will return a vector of possible moves for the piece
	std::vector<sf::Vector2<float>> possibleMoves;

	// Check the type of piece and calculate possible moves accordingly
	switch (_type)
	{
	case Pawn:
		
		break;
	case Knight:
		// Add logic for knight moves
		break;
	case Bishop:
		// Add logic for bishop moves
		break;
	case Rook:
		// Add logic for rook moves
		break;
	case Queen:
		// Add logic for queen moves
		break;
	case King:
		// Add logic for king moves
		break;
	default:
		break;
	}
	return possibleMoves;
}