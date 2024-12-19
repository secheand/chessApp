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
        pawn = 1,
        rook = 2,
        knight = 3,
        bishop = 4,
        queen = 5,
        king = 6
    };

    class chessPiece
    {
        public:
            chessPiece(std::pair<int, int> position, gui::pieceType pieceType);
            std::pair<int, int> getPosition();
            void updatePosition(std::pair<int, int>);
            gui::pieceType getPieceType();
            std::pair<int, int> getPreviousPosition;
        
			sf::Texture texture;
            sf::Sprite sprite;
            
            
        private:
            std::pair<int, int> _position;
            gui::pieceType _pieceType;
            std::pair<int, int> _previousPosition;
            bool _hasMoved;
            bool _exists;
    };
    
    class chessBoard
    {
		public:
			sf::Texture texture;
            sf::Sprite sprite;
		
		private:
	};

    bool setupBoard(std::vector<gui::chessPiece> & whitePieces,
                    std::vector<gui::chessPiece> & blackPieces,
                    gui::chessBoard & chessBoard);

}

#endif /* guiBoard_hpp */
