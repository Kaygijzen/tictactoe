#include <iostream>
#include <vector>
#include <string>

#include "tictactoe.h"

using namespace std;

int main()
{
    TicTacToe g;

    cout << g.board.to_string() << endl;

    bool running = true;
    // while (running) {
    // }

    g.play();


    // cout << g.board.get_board() << endl;
    return 0;
}
