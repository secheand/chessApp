//
//  guiBoard.hpp
//  chessApp
//
//  Created by Sebastian Fabian Echeandia Reynes on 19/12/24.
//


/*! @file guiBoard.h
 *  @brief header file for the guiboard library. Includes definitions for ChessBoard class.
 *
 *  The namespace gui is used to make it clear that all these objects interact with the GUI and not the chess engine.
 *  The ChessBoard class stores and handles all the sprites so the rendered product adequately represents the state of the game.
 */
#ifndef guiBoard_hpp
#define guiBoard_hpp

#include <pieceManager.hpp>

namespace gui
{
    class ChessBoard
    {
        public:
            // Constructor explícito que inicializa la clase
            ChessBoard(const std::string& playerColor);
            // Destructor
            //~ChessBoard();

            /**
             * @brief Initializes internal parameters for the ChessBoard class
             *
             * The function fills the sprite board with nullptrs. Loads textures for all pieces and board.
             * Creates game window.
             *
             */
            void initChessBoard(std::string playerColor);
        
            /**
             @brief Sets the correct initial placement for all sprites on the board
             *
             * For each sprite, the function sets the correct initial location. It also asigns each sprite's memory address
             * to the corresponding square within the sprite board.
             */
            void setupBoard();
        
            /**
             * @brief Checks if the user has interacted with the app and responds accordingly
             *
             * When the user clicks escape key or closes the window, terminate the window object.
             */
            void checkForUserInput();
        
            /**
             * @brief Render board and all pieces in it.
             *
             * Clears the window, draws the board and all remaining pieces, and then updates the window.
             */
            void renderBoard();
        
            /**
             * @brief returns the state of the rendered window (closed or opened)
             *
             * @return true if window is open, false if it isn't
             */
            bool isWindowOpen();
            
        private:
            /**
             * @brief returns the coordinates of the square that was clicked
             *
             * @param mousePosition the position of the mouse when clicked
             * @return a pair of integers representing the row and column of the square clicked
             */
            sf::Vector2i _getSquareCoordinates(sf::Vector2i mousePosition);

            // Parameters for handling pieces based on user input
			bool isHoldingPiece = false; // Boolean to check if the user is holding a piece
			sf::Vector2i movingPieceOriginalCoordinates; // Coordinates of the square where the piece was before being moved
			std::vector<sf::Vector2i> movingPiecePossibleMoves; // Vector of possible moves for the piece being moved
        
            // SFML objects to handle the game window and any interactions with it
            sf::RenderWindow window;
            sf::Event event;

			// Objects to store pieces' sprites and their coordinates
			chessPiece pieces[32]; // Holds all pieces in the game
			chessPiece* pieceMap[8][8]; // Holds the pieces on the board according to their square coordinates
			sf::Vector2<float> boardCoordinates[8][8]; // Holds the pixel coordinates of each square on the board
        
			////////// Textures and Sprites //////////
            // Board
            sf::Texture boardTexture;
            sf::Sprite boardSprite;
    };

}

#endif /* guiBoard_hpp */
