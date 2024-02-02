#include <string>
#include <vector>

using namespace std;

class Board {
    private:
        char values[9] = {
            '1', '2', '3', 
            '4', '5', '6',
            '7', '8', '9'
        };

        bool is_board_full() {
            for (int i = 0; i < 9; i++) {
                if (values[i] == ' ') {
                    return false;
                }
            }
            return true;
        }

    public:
        Board() {}

        Board(const Board& rhs) { /* copy construction from rhs */ }
        // Board& operator=(const Board& rhs) {};

        int check_winner() {
            // If no conclusion, returns -1
            // If win, returns 1
            // If draw, return 0
            if (values[1] == values[2] && values[2] == values[3])
                return 1;
            else if (values[4] == values[5] && values[5] == values[6])
                return 1;
            else if (values[7] == values[8] && values[8] == values[9])
                return 1;
            else if (values[1] == values[4] && values[4] == values[7])
                return 1;
            else if (values[2] == values[5] && values[5] == values[8])
                return 1;
            else if (values[3] == values[6] && values[6] == values[9])
                return 1;
            else if (values[1] == values[5] && values[5] == values[9])
                return 1;
            else if (values[3] == values[5] && values[5] == values[7])
                return 1;
            else if (values[0] != '1' && values[1] != '2' && values[2] != '3' 
                    && values[3] != '4' && values[4] != '5' && values[5] != '6' 
                  && values[6] != '7' && values[7] != '8' && values[8] != '9')
                return 0;
            else
                return -1;
        }

        vector<int> get_available_inputs() {
            vector<int> empty_spots;

            int input_count = 1;
            for (int i = 0; i < 9; i++) {
                if (values[i] != 'X' || values[i] != 'O') 
                    empty_spots.push_back(i);
            }

            return empty_spots;
        }

        void insert_value(char value, int i) {
            values[i] = value;
        }

        string to_string() {
            string s = ""; 
            for(int i = 0; i < 3; i++)
            {
                s += " ";
                for(int j = 0; j < 3; j++)
                {
                    s+= values[3*i + j];
                    if (j != 2) s+= " | ";
                }
                s += "\n";
                if (i != 2) s += "---+---+---\n";
            } 
            return s; 
        }
};