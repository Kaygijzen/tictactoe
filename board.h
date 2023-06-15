#include <string>
#include <vector>

using namespace std;

class Board {
    private:
        char values[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        bool is_board_full() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (values[i][j] == ' ') {
                        return false;
                    }
                }
            }
            return true;
        }

        int check_winner() {
            // If no conlusion, returns -1
            // If player wins,  returns 0
            // If machine wins, returns 1

            // Checking rows and columns
            for (int i = 0; i < 3; i++) {
                if (
                    (values[i][0] == 'X' && values[i][1] == 'X' && values[i][2] == 'X') || // checking rows
                    (values[0][i] == 'X' && values[1][i] == 'X' && values[2][i] == 'X') // checking columns
                ) {
                    // Player (X) wins.
                    return 0;
                } else if (
                    (values[i][0] == 'O' && values[i][1] == 'O' && values[i][2] == 'O') || // checking rows
                    (values[0][i] == 'O' && values[1][i] == 'O' && values[2][i] == 'O') // checking columns
                ) {
                    // Machine (O) wins.
                    return 1;
                }
            }
            // Checking diagonals
            if (
                (values[0][0] == 'X' && values[1][1] == 'X' && values[2][2] == 'X') ||
                (values[0][2] == 'X' && values[1][1] == 'X' && values[2][0] == 'X')
            ) {
                // Player (X) wins.
                return 0;
            } else if (
                (values[0][0] == 'O' && values[1][1] == 'O' && values[2][2] == 'O') ||
                (values[0][2] == 'O' && values[1][1] == 'O' && values[2][0] == 'O')
            ) {
                // Machine (O) wins.
                return 1;
            }
            // No conclusion inferred
            return -1;
        }

    public:
        Board() {}

        Board(const Board& rhs) { /* copy construction from rhs */ }
        // Board& operator=(const Board& rhs) {};

        bool is_finished() {
            // Checking if we have a winner
            int winner = check_winner();
            if (winner != -1) {
                if (winner == 0) {
                    cout << "Player has won!" << endl;
                } else {
                    cout << "Machine has won!" << endl;
                }
                return true;
            }

            // Checking if any fields are still fillable
            if (is_board_full()) { 
                cout << "Terminating, board is full" << endl;
                return true; 
            }
            return false;
        }


        pair<string,vector<pair<int, int> > > get_available_inputs() {
            Board empty_board;
            vector<pair<int, int> > empty_spots;

            int input_count = 1;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++)
                if (values[i][j] == ' ') {
                    empty_spots.push_back(make_pair(i,j));

                    string t = ::to_string(input_count);
                    char const *n_char = t.c_str();

                    empty_board.insert_value(n_char[0], i, j);
                    input_count += 1;
                } else {
                    empty_board.insert_value(values[i][j], i, j);
                }
            }

            return make_pair(
                empty_board.to_string(),
                empty_spots
            );
        }

        void insert_value(char value, int i, int j) {
            values[i][j] = value;
        }

        string to_string() {
            string s = ""; 
            for(int i = 0; i < 3; i++)
            {
                s += " ";
                for(int j = 0; j < 3; j++)
                {
                    s+= values[i][j];
                    if (j != 2) s+= " | ";
                }
                s += "\n";
                if (i != 2) s += "---+---+---\n";
            } 
            return s; 
        }
};