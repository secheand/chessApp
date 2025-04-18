//
//  guiBoard.cpp
//  chessApp
//
//  Created by Sebastian Fabian Echeandia Reynes on 19/12/24.
//

// Standard libraries
#include <iostream>

// Internal libraries
#include <guiBoard.hpp>

using namespace gui;

ChessBoard::ChessBoard(const std::string& playerColor)
{
    initChessBoard(playerColor);
}

void ChessBoard::initChessBoard(std::string playerColor)
{
    // Sprite board controls which sprites are still on the board and where. At init, all
    // spaces are set to nullptr (no piece is yet placed). board coordinates are set according to player color.
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pieceMap[i][j] = nullptr;
            
            // Pixel coordinates of each square change if looking at the board as white or black.
            // This if statement sets the correct pixel coordinates to the player always looks at the board according to their piece color.
            if (playerColor == "white")
            {
                boardCoordinates[i][j] = sf::Vector2<float>(36+72*j, 540-72*i);
            }
            else if(playerColor == "black")
            {
                boardCoordinates[i][j] = sf::Vector2<float>(540-72*j, 36+72*i);
            }
        }
    }
    
    
    // Load texture for board and set it to sprite
    boardTexture.loadFromFile("Board.png");
    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(0, 0);

    // If playing as black, need to rotate board by 180°
    // position is reset since the rotation happens around bottom left corner
    if(playerColor == "black")
    {
        boardSprite.rotate(180);
        boardSprite.setPosition(576, 576);
    }
    
    // Render window
    window.create(sf::VideoMode(576, 576), "ChessApp");
}

void ChessBoard::setupBoard()
{
    // All pieces in this function are added to the sprite board after their locations are set.
    // The sprite board is the data structure that keeps track of which sprite is on the board and where it is.
    
    int j = 0;
    // Set positions of pawns on the board.
    for (int i = 0; i < 8; i++)
    {
        chessPiece whitePawn(Pawn, White, "whitePawn.png", boardCoordinates[1][i]);
		pieces[j] = whitePawn;
		pieceMap[1][i] = &pieces[j];
        j++;

        chessPiece blackPawn(Pawn, White, "blackPawn.png", boardCoordinates[6][i]);
        pieces[j] = blackPawn;
        pieceMap[6][i] = &pieces[j];
        j++;
    }
    
    // Set positions of minor pieces on the board
    for (int i = 0; i < 2; i++)
    {
        // Rooks
		chessPiece whiteRook(Rook, White, "whiteRook.png", boardCoordinates[0][0 + 7 * i]);
		pieces[j] = std::move(whiteRook);
		pieceMap[0][0 + 7 * i] = &pieces[j];
		j++;
		chessPiece blackRook(Rook, Black, "blackRook.png", boardCoordinates[7][0 + 7 * i]);
		pieces[j] = std::move(blackRook);
		pieceMap[7][0 + 7 * i] = &pieces[j];
		j++;
        
        // Knights
		chessPiece whiteKnight(Knight, White, "whiteKnight.png", boardCoordinates[0][1 + 5 * i]);
		pieces[j] = std::move(whiteKnight);
		pieceMap[0][1 + 5 * i] = &pieces[j];
		j++;
		chessPiece blackKnight(Knight, Black, "blackKnight.png", boardCoordinates[7][1 + 5 * i]);
		pieces[j] = std::move(blackKnight);
		pieceMap[7][1 + 5 * i] = &pieces[j];
		j++;
        
        // Bishops
		chessPiece whiteBishop(Bishop, White, "whiteBishop.png", boardCoordinates[0][2 + 3 * i]);
		pieces[j] = std::move(whiteBishop);
		pieceMap[0][2 + 3 * i] = &pieces[j];
		j++;
		chessPiece blackBishop(Bishop, Black, "blackBishop.png", boardCoordinates[7][2 + 3 * i]);
		pieces[j] = std::move(blackBishop);
		pieceMap[7][2 + 3 * i] = &pieces[j];
		j++;
    }
    
    // Set positions for queens and kings on the board
	chessPiece whiteQueen(Queen, White, "whiteQueen.png", boardCoordinates[0][3]);
	pieces[j] = std::move(whiteQueen);
	pieceMap[0][3] = &pieces[j];
	j++;
	chessPiece blackQueen(Queen, Black, "blackQueen.png", boardCoordinates[7][3]);
	pieces[j] = std::move(blackQueen);
	pieceMap[7][3] = &pieces[j];
	j++;
	chessPiece whiteKing(King, White, "whiteKing.png", boardCoordinates[0][4]);
	pieces[j] = std::move(whiteKing);
	pieceMap[0][4] = &pieces[j];
	j++;
	chessPiece blackKing(King, Black, "blackKing.png", boardCoordinates[7][4]);
	pieces[j] = std::move(blackKing);
	pieceMap[7][4] = &pieces[j];
}

void ChessBoard::checkForUserInput()
{
   while (window.pollEvent(event))
   {
       // Check if user closed window
       if (event.type == sf::Event::Closed)
       {
           window.close();
       }

       // Check if the user pressed scape to close window
       if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
       {
           window.close();
       }

       // Check if the user left-clicked the mouse
       if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
       {
           // Get position of mouse
           sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
           sf::Vector2<float> mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
           sf::Vector2i coordinates = _getSquareCoordinates(mousePosition);

		// If the user clicked on a square that has a piece, set the piece to be held and update its position
           if (pieceMap[coordinates.x][coordinates.y] != nullptr)
           {
               movingPieceOriginalCoordinates = coordinates;
               (pieceMap[movingPieceOriginalCoordinates.x][movingPieceOriginalCoordinates.y])->setPosition(mousePositionFloat);
               isHoldingPiece = true;
           }
           else
           {
			isHoldingPiece = false;
           }
       }
       // If the user released the left mouse button, also release the held piece
       else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
       {
           (pieceMap[movingPieceOriginalCoordinates.x][movingPieceOriginalCoordinates.y])->setPosition(boardCoordinates[movingPieceOriginalCoordinates.x][movingPieceOriginalCoordinates.y]);
           
           isHoldingPiece = false;
       }
   }

    // If the user is holding a piece, update its position to follow the mouse
    if (isHoldingPiece)
    {
	    // Get position of mouse
	    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	    sf::Vector2<float> mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	    (pieceMap[movingPieceOriginalCoordinates.x][movingPieceOriginalCoordinates.y])->setPosition(mousePositionFloat);
    }
}

void ChessBoard::renderBoard()
{
    // Remove all previous drawings on window.
    window.clear();
    
    // Draw board first
    window.draw(boardSprite);
    
    // Loop through the sprite board to draw all remaining pieces on the board
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(pieceMap[i][j] != nullptr)
            {
                //window.draw(*(pieceMap[i][j]->getSpriteAddress()));
            }
        }
    }
    window.draw(*(pieceMap[0][0]->getSpriteAddress()));
    // Update the window
    window.display();
}

bool ChessBoard::isWindowOpen()
{
    return window.isOpen();
}

sf::Vector2i ChessBoard::_getSquareCoordinates(sf::Vector2i mousePosition)
{
	// Get the coordinates of the square that was clicked. The 7 - row is because the rows are counted bottom up.
	int row = 7 - (int)(mousePosition.y / 72);
	int column = (int)(mousePosition.x / 72);

	return sf::Vector2i(row, column);
}