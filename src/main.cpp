//
//  main.cpp
//  chessApp
//
//  Created by Sebastian Fabian Echeandia Reynes on 19/12/24.
//

// Standard libraries

// Internal libraries
#include <guiBoard.hpp>

/**
 * @brief Main function of the chessApp. It handles high level logic of the program.
 *
 * The function initializes instances of all necessary classes.
 * It handles high level logic such as initializations, setting up, and main while loop.
 * Main while loop checks for user interaction with window, and render graphics.
 *
 */
int main(int argc, char const** argv)
{
    gui::ChessBoard chessBoardInstance;
    
    chessBoardInstance.initChessBoard();
    chessBoardInstance.setupBoard();
    
    while (chessBoardInstance.isWindowOpen())
    {
        chessBoardInstance.checkForEvent();
        
        chessBoardInstance.renderBoard();
    }

    return EXIT_SUCCESS;
}
