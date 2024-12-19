//
//  guiBoard.hpp
//  chessEngine
//
//  Created by Sebastian Fabian Echeandia Reynes on 23/03/23.
//

#ifndef guiBoard_hpp
#define guiBoard_hpp

#include <utility>
#include <string>

#include <SFML/Graphics.hpp>

namespace gui
{
    enum pieceType
    {
        whitePawn = 1,
        whiteKnight = 2,
        whiteBishop = 3,
        whiteRook = 4,
        whiteQueen = 5,
        whiteKing = 6,
        blackPawn = -1,
        blackKnight = -2,
        blackBishop = -3,
        blackRook = -4,
        blackQueen = -5,
        blackKing = -6
    };

    class ChessBoard
    {
        public:
            void initChessBoard();
            void setupBoardForWhite();
            void checkForEvent();
            void renderBoard();
        
            bool isWindowOpen();
            
        private:
            sf::RenderWindow window;
            sf::Event event;
        
            sf::Texture boardTexture;
            sf::Sprite boardSprite;
    };

}

#endif /* guiBoard_hpp */
