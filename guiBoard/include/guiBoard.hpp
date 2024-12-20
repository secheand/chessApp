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
            void _setOriginToMiddle(sf::Sprite & sprite);
        
            sf::RenderWindow window;
            sf::Event event;
        
            sf::Texture boardTexture;
            sf::Sprite boardSprite;
        
            sf::Texture whitePawnsTexture;
            sf::Texture whiteKnightsTexture;
            sf::Texture whiteBishopsTexture;
            sf::Texture whiteRooksTexture;
            sf::Texture whiteQueenTexture;
            sf::Texture whiteKingTexture;
        
            sf::Texture blackPawnsTexture;
            sf::Texture blackKnightsTexture;
            sf::Texture blackBishopsTexture;
            sf::Texture blackRooksTexture;
            sf::Texture blackQueenTexture;
            sf::Texture blackKingTexture;
        
            sf::Sprite whitePawnsSprite[8];
            sf::Sprite whiteKnightsSprite[2];
            sf::Sprite whiteBishopsSprite[2];
            sf::Sprite whiteRooksSprite[2];
            sf::Sprite whiteQueenSprite;
            sf::Sprite whiteKingSprite;
        
            sf::Sprite blackPawnsSprite[8];
            sf::Sprite blackKnightsSprite[2];
            sf::Sprite blackBishopsSprite[2];
            sf::Sprite blackRooksSprite[2];
            sf::Sprite blackQueenSprite;
            sf::Sprite blackKingSprite;
        
            std::vector<sf::Sprite *> spriteBoard[8][8];
        
    };

}

#endif /* guiBoard_hpp */
