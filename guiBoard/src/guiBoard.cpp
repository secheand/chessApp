//
//  guiBoard.cpp
//  chessEngine
//
//  Created by Sebastian Fabian Echeandia Reynes on 23/03/23.
//

#include <guiBoard.hpp>

#include <iostream>

void gui::ChessBoard::initChessBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            spriteBoard[i][j] = nullptr;
        }
    }
    
    boardTexture.loadFromFile("Board.png");
    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(0, 0);
    
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
    
    for (int i = 0; i < 8; i++)
    {
        whitePawnsSprite[i].setTexture(whitePawnsTexture);
        _setOriginToMiddle(whitePawnsSprite[i]);
        
        blackPawnsSprite[i].setTexture(blackPawnsTexture);
        _setOriginToMiddle(blackPawnsSprite[i]);
    }
    
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
    
    window.create(sf::VideoMode(576, 576), "ChessApp");
    
}

void gui::ChessBoard::setupBoardForWhite()
{
    for (int i = 0; i < 8; i++)
    {
        whitePawnsSprite[i].setPosition(36*(i*2+1), 468);
        spriteBoard[1][i] = &(whitePawnsSprite[i]);
    }
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
    window.draw(boardSprite);
    
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

/*gui::chessPiece::chessPiece(std::pair<int, int> position, gui::pieceType pieceType)
{
    _position = position;
    _pieceType = pieceType;
    _previousPosition = position;
    _hasMoved = false;
    _exists = true;
}

std::pair<int, int> gui::chessPiece::getPosition()
{
	return _position;
}

bool gui::setupBoard(std::vector<gui::chessPiece> & whitePieces,
                std::vector<gui::chessPiece> & blackPieces,
                gui::chessBoard & chessBoard)
{
        std::vector<std::string> whitePiecesFileNames {"assets/whitePawn.png",
        "assets/whiteRook.png",
        "assets/whiteKnight.png",
        "assets/whiteBishop.png",
        "assets/whiteQueen.png",
        "assets/whiteKing.png"};
    std::vector<std::string> blackPiecesFileNames {"assets/blackPawn.png",
        "assets/blackRook.png",
        "assets/blackKnight.png",
        "assets/blackBishop.png",
        "assets/blackQueen.png",
        "assets/blackKing.png"};
    sf::Texture whitePiecesTextures[6];
    sf::Texture blackPiecesTextures[6];
    
    sf::FloatRect pieceRect;
    for(int i = 1; i < 9; i++)
    {
        gui::chessPiece whitePawn(std::make_pair(2,i), gui::pieceType::pawn);
        whitePawn.texture.loadFromFile(whitePiecesFileNames[0]);
		whitePawn.sprite.setTexture(whitePawn.texture);
		pieceRect = whitePawn.sprite.getLocalBounds();
		whitePawn.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		whitePawn.sprite.setPosition(whitePawn.getPosition().first*100-50, whitePawn.getPosition().second*100-50);
		whitePieces.push_back(whitePawn);
		
        gui::chessPiece blackPawn(std::make_pair(2,i), gui::pieceType::pawn);
        blackPawn.texture.loadFromFile(blackPiecesFileNames[0]);
		blackPawn.sprite.setTexture(blackPawn.texture);
		pieceRect = blackPawn.sprite.getLocalBounds();
		blackPawn.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		blackPawn.sprite.setPosition(blackPawn.getPosition().first*100-50, blackPawn.getPosition().second*100-50);
		blackPieces.push_back(blackPawn);
    }
    
	for(int i = 0; i < 1; i++)
    {
        gui::chessPiece whiteRook(std::make_pair(1,1+i*8), gui::pieceType::rook);
		whiteRook.texture.loadFromFile(whitePiecesFileNames[1]);
		whiteRook.sprite.setTexture(whiteRook.texture);
		pieceRect = whiteRook.sprite.getLocalBounds();
		whiteRook.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		whiteRook.sprite.setPosition(whiteRook.getPosition().first*100-50, whiteRook.getPosition().second*100-50);
		whitePieces.push_back(whiteRook);
		
		gui::chessPiece blackRook(std::make_pair(8,1+i*8), gui::pieceType::rook);
		blackRook.texture.loadFromFile(blackPiecesFileNames[1]);
		blackRook.sprite.setTexture(blackRook.texture);
		pieceRect = blackRook.sprite.getLocalBounds();
		blackRook.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		blackRook.sprite.setPosition(blackRook.getPosition().first*100-50, blackRook.getPosition().second*100-50);
		blackPieces.push_back(blackRook);
		
		gui::chessPiece whiteKnight(std::make_pair(1,2+i*7), gui::pieceType::knight);
		whiteKnight.texture.loadFromFile(whitePiecesFileNames[2]);
		whiteKnight.sprite.setTexture(whiteKnight.texture);
		pieceRect = whiteKnight.sprite.getLocalBounds();
		whiteKnight.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		whiteKnight.sprite.setPosition(whiteKnight.getPosition().first*100-50, whiteKnight.getPosition().second*100-50);
		whitePieces.push_back(whiteKnight);
		
		gui::chessPiece blackKnight(std::make_pair(8,2+i*7), gui::pieceType::rook);
		blackKnight.texture.loadFromFile(blackPiecesFileNames[2]);
		blackKnight.sprite.setTexture(blackKnight.texture);
		pieceRect = blackKnight.sprite.getLocalBounds();
		blackKnight.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		blackKnight.sprite.setPosition(blackKnight.getPosition().first*100-50, blackKnight.getPosition().second*100-50);
		blackPieces.push_back(blackKnight);
		
		gui::chessPiece whiteBishop(std::make_pair(1,3+i*6), gui::pieceType::bishop);
		whiteBishop.texture.loadFromFile(whitePiecesFileNames[3]);
		whiteBishop.sprite.setTexture(whiteBishop.texture);
		pieceRect = whiteBishop.sprite.getLocalBounds();
		whiteBishop.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		whiteBishop.sprite.setPosition(whiteBishop.getPosition().first*100-50, whiteBishop.getPosition().second*100-50);
		whitePieces.push_back(whiteBishop);
		
		gui::chessPiece blackBishop(std::make_pair(8,3+i*6), gui::pieceType::bishop);
		blackBishop.texture.loadFromFile(blackPiecesFileNames[3]);
		blackBishop.sprite.setTexture(blackBishop.texture);
		pieceRect = blackBishop.sprite.getLocalBounds();
		blackBishop.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
		blackBishop.sprite.setPosition(blackBishop.getPosition().first*100-50, blackBishop.getPosition().second*100-50);
		blackPieces.push_back(blackBishop);
    }
    
    gui::chessPiece whiteQueen(std::make_pair(1,4), gui::pieceType::queen);
    whiteQueen.texture.loadFromFile(whitePiecesFileNames[4]);
	whiteQueen.sprite.setTexture(whiteQueen.texture);
	pieceRect = whiteQueen.sprite.getLocalBounds();
	whiteQueen.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
	whiteQueen.sprite.setPosition(whiteQueen.getPosition().first*100-50, whiteQueen.getPosition().second*100-50);
	whitePieces.push_back(whiteQueen);
	
	gui::chessPiece whiteKing(std::make_pair(1,5), gui::pieceType::king);
	whiteKing.texture.loadFromFile(whitePiecesFileNames[5]);
	whiteKing.sprite.setTexture(whiteKing.texture);
	pieceRect = whiteKing.sprite.getLocalBounds();
	whiteKing.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
	whiteKing.sprite.setPosition(whiteKing.getPosition().first*100-50, whiteKing.getPosition().second*100-50);
	whitePieces.push_back(whiteKing);
	
	gui::chessPiece blackQueen(std::make_pair(1,4), gui::pieceType::queen);
	blackQueen.texture.loadFromFile(blackPiecesFileNames[4]);
	blackQueen.sprite.setTexture(blackQueen.texture);
	pieceRect = blackQueen.sprite.getLocalBounds();
	blackQueen.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
	blackQueen.sprite.setPosition(blackQueen.getPosition().first*100-50, blackQueen.getPosition().second*100-50);
	whitePieces.push_back(blackQueen);
	
	gui::chessPiece blackKing(std::make_pair(1,5), gui::pieceType::king);
	blackKing.texture.loadFromFile(blackPiecesFileNames[5]);
	blackKing.sprite.setTexture(blackKing.texture);
	pieceRect = blackKing.sprite.getLocalBounds();
	blackKing.sprite.setOrigin(pieceRect.left + pieceRect.width / 2, pieceRect.top + pieceRect.height / 2);
	blackKing.sprite.setPosition(blackKing.getPosition().first*100-50, blackKing.getPosition().second*100-50);
	whitePieces.push_back(blackKing);
	
	chessBoard.texture.loadFromFile("assets/board.jpeg");
	chessBoard.sprite.setTexture(chessBoard.texture);
	chessBoard.sprite.setPosition(0, 0);
	chessBoard.sprite.setScale(1.69, 1.69);
	
	return true;
    
}*/
