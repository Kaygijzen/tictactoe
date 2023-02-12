#include <string>

class Board {
    private:
        std::string values[3][3] = {{"X", " ", "X"},
                    {" ", "O", " "},
                    {" ", " ", "O"}};

    public:
        Board() {}
        std::string get_board() {
            std::string s = ""; 
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