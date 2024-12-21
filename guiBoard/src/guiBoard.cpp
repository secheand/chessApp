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

void gui::ChessBoard::initChessBoard(std::string playerColor)
{
    // Sprite board controls which sprites are still on the board and where. At init, all
    // spaces are set to nullptr (no piece is yet placed). board coordinates are set according to player color.
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            spriteBoard[i][j] = nullptr;
            
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
    
    // Load textures for all pieces
    whitePawnsTexture.loadFromFile("whitePawn.png");
    blackPawnsTexture.loadFromFile("blackPawn.png");
    whiteKnightsTexture.loadFromFile("whiteKnight.png");
    blackKnightsTexture.loadFromFile("blackKnight.png");
    whiteBishopsTexture.loadFromFile("whiteBishop.png");
    blackBishopsTexture.loadFromFile("blackBishop.png");
    whiteRooksTexture.loadFromFile("whiteRook.png");
    blackRooksTexture.loadFromFile("blackRook.png");
    whiteQueenTexture.loadFromFile("whiteQueen.png");
    blackQueenTexture.loadFromFile("blackQueen.png");
    whiteKingTexture.loadFromFile("whiteKing.png");
    blackKingTexture.loadFromFile("blackKing.png");
    
    // Set texture to pawn sprites. Set the sprite origin to the middle of the figure.
    for (int i = 0; i < 8; i++)
    {
        whitePawnsSprite[i].setTexture(whitePawnsTexture);
        _setOriginToMiddle(whitePawnsSprite[i]);
        blackPawnsSprite[i].setTexture(blackPawnsTexture);
        _setOriginToMiddle(blackPawnsSprite[i]);
    }
    
    // Set textures for minor pieces sprites and set their origin to the middle of the figure.
    for (int i = 0; i < 2; i++)
    {
        whiteKnightsSprite[i].setTexture(whiteKnightsTexture);
        _setOriginToMiddle(whiteKnightsSprite[i]);
        blackKnightsSprite[i].setTexture(blackKnightsTexture);
        _setOriginToMiddle(blackKnightsSprite[i]);
        
        whiteBishopsSprite[i].setTexture(whiteBishopsTexture);
        _setOriginToMiddle(whiteBishopsSprite[i]);
        blackBishopsSprite[i].setTexture(blackBishopsTexture);
        _setOriginToMiddle(blackBishopsSprite[i]);
        
        whiteRooksSprite[i].setTexture(whiteRooksTexture);
        _setOriginToMiddle(whiteRooksSprite[i]);
        blackRooksSprite[i].setTexture(blackRooksTexture);
        _setOriginToMiddle(blackRooksSprite[i]);
    }
    
    // Set textures for queen and king sprites and set their origin to the middle of the figure.
    whiteQueenSprite.setTexture(whiteQueenTexture);
    _setOriginToMiddle(whiteQueenSprite);
    blackQueenSprite.setTexture(blackQueenTexture);
    _setOriginToMiddle(blackQueenSprite);
    
    whiteKingSprite.setTexture(whiteKingTexture);
    _setOriginToMiddle(whiteKingSprite);
    blackKingSprite.setTexture(blackKingTexture);
    _setOriginToMiddle(blackKingSprite);
    
    // Render window
    window.create(sf::VideoMode(576, 576), "ChessApp");
}

void gui::ChessBoard::setupBoard()
{
    // All pieces in this function are added to the sprite board after their locations are set.
    // The sprite board is the data structure that keeps track of which sprite is on the board and where it is.
    
    // Set positions of pawns on the board.
    for (int i = 0; i < 8; i++)
    {
        //std::cout << boardCoordinates[1][i].x << ", " << boardCoordinates[1][i].y << std::endl;
        whitePawnsSprite[i].setPosition(boardCoordinates[1][i]);
        spriteBoard[1][i] = &(whitePawnsSprite[i]);
        blackPawnsSprite[i].setPosition(boardCoordinates[6][i]);
        spriteBoard[6][i] = &(blackPawnsSprite[i]);
    }
    
    // Set positions of minor pieces on the board
    for (int i = 0; i < 2; i++)
    {
        // Rooks
        whiteRooksSprite[i].setPosition(boardCoordinates[0][0+7*i]);
        spriteBoard[0][0+7*i] = &(whiteRooksSprite[i]);
        blackRooksSprite[i].setPosition(boardCoordinates[7][0+7*i]);
        spriteBoard[7][0+7*i] = &(blackRooksSprite[i]);
        
        // Knights
        whiteKnightsSprite[i].setPosition(boardCoordinates[0][1+5*i]);
        spriteBoard[0][1+5*i] = &(whiteKnightsSprite[i]);
        blackKnightsSprite[i].setPosition(boardCoordinates[7][1+5*i]);
        spriteBoard[7][1+5*i] = &(blackKnightsSprite[i]);
        
        // Bishops
        whiteBishopsSprite[i].setPosition(boardCoordinates[0][2+3*i]);
        spriteBoard[0][2+3*i] = &(whiteBishopsSprite[i]);
        blackBishopsSprite[i].setPosition(boardCoordinates[7][2+3*i]);
        spriteBoard[7][2+3*i] = &(blackBishopsSprite[i]);
    }
    
    // Set positions for queens and kings on the board
    whiteQueenSprite.setPosition(boardCoordinates[0][3]);
    spriteBoard[0][3] = &whiteQueenSprite;
    blackQueenSprite.setPosition(boardCoordinates[7][3]);
    spriteBoard[7][3] = &blackQueenSprite;
    
    whiteKingSprite.setPosition(boardCoordinates[0][4]);
    spriteBoard[0][4] = &whiteKingSprite;
    blackKingSprite.setPosition(boardCoordinates[7][4]);
    spriteBoard[7][4] = &blackKingSprite;
    
}

void gui::ChessBoard::checkForEvent()
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
    }
}

void gui::ChessBoard::renderBoard()
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
            if(spriteBoard[i][j] != nullptr)
            {
                window.draw(*(spriteBoard[i][j]));
            }
        }
    }
    
    // Update the window
    window.display();
}

bool gui::ChessBoard::isWindowOpen()
{
    return window.isOpen();
}

void gui::ChessBoard::_setOriginToMiddle(sf::Sprite & sprite)
{
    sf::FloatRect pieceRect = sprite.getLocalBounds();
    sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top +  pieceRect.height / 2);
}
