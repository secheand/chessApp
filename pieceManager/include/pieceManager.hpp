//
//  pieceManager.hpp
//  chessApp
//
//  Created by Sebastian Fabian Echeandia Reynes on 18/04/25.
//

/*! @file pieceManager.hpp
*  @brief header file for the pieceManager library. Includes definitions for ChessPiece class.
*
*  The namespace gui is used to make it clear that all these objects interact with the GUI and not the chess engine.
*  The ChessPiece class stores and handles all the relevant information for the GUI pieces.
*/
#ifndef pieceManager_hpp
#define pieceManager_hpp

#include <SFML/Graphics.hpp>

namespace gui
{
   enum pieceType
   {
       Pawn = 1,
       Knight = 2,
       Bishop = 3,
       Rook = 4,
       Queen = 5,
       King = 6
   };

enum pieceColor
{
	White = 1,
	Black = 2
};

   class chessPiece
   {
       public:
		   chessPiece(); // Default constructor
           chessPiece(pieceType type, pieceColor color, const std::string& texturePath, sf::Vector2<float> initialPosition);
           chessPiece& operator=(const chessPiece& other); // assignment operator
		   ~chessPiece();

           sf::Sprite* getSpriteAddress();

           void setPosition(sf::Vector2<float>);
		   void resetPosition();

       private:
		   pieceType _type;
		   pieceColor _color;

		   bool _hasMoved = false; // Boolean to check if the piece has moved at least once
		   bool _hasCastled = false; // Boolean to check if the piece has castled at least once

		   sf::Vector2<float> _position; // Pixel Position of the piece on the board

           std::string _texturePath;
           sf::Texture _texture;
           sf::Sprite _sprite;
   };
}
#endif /* pieceManager_hpp */