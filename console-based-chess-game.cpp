#include <iostream>

using namespace std;

class PlayerOne{
public:
    string name;
    PlayerOne(string name){
        this->name = name;
    }
};

class PlayerTwo{
public:
    string name;
    PlayerTwo(string name){
        this->name = name;
    }
};

bool isValidPawn(char chessBoard[8][8], int startRow, int endRow, int startCol, int endCol, char currentPlayerColor){
    //base case
     if (endRow < 0 || endRow >= 8 || endCol < 0 || endCol >= 8) {
        return false;
    }

    if(currentPlayerColor == 'W'){
        //single move
        if((startCol == endCol) && (startRow - endRow == 1) && (chessBoard[endRow][endCol] == '.')){
            return true;
        }

        //two steps from starting position
        else if((startRow == 6) && (startCol == endCol) && (startRow - endRow == 2) && (chessBoard[endRow][endCol] == '.') && (chessBoard[endRow - 1][endCol] == '.')){
            return true;
        }

        //diagonally capture
        else if((startRow - endRow == 1) && (abs(startCol - endCol) == 1) && (chessBoard[endRow][endCol] != '.') && (islower(chessBoard[endRow][endCol]))){
            return true;
        }
    }

    else if(currentPlayerColor == 'B'){
        //single move
        if((startCol == endCol) && (endRow - startRow == 1) && (chessBoard[endRow][endCol] == '.')){
            return true;
        }

        //two steps from starting position
        else if((startRow == 1) && (startCol == endCol) && (endRow - startRow == 2) && (chessBoard[endRow][endCol] == '.') && (chessBoard[endRow + 1][endCol] == '.')){
            return true;
        }

        //diagonally capture
        else if((endRow - startRow == 1) && (abs(startCol - endCol) == 1) && (chessBoard[endRow][endCol] != '.') && (isupper(chessBoard[endRow][endCol]))){
            return true;
        }
    }

    //invalid pawn move
    return false;
}

bool isValidRook(char chessBoard[8][8], int startRow, int endRow, int startCol, int endCol, char currentPlayerColor){
    //vertical up
    for(int i = startRow - 1; i>=0; i--){
        if(chessBoard[i][startCol] != '.'){
            if((i == endRow) && (startCol == endCol)){
                if(((currentPlayerColor == 'W') && (islower(chessBoard[endRow][endCol]))) ||  ((currentPlayerColor == 'B') && (isupper(chessBoard[endRow][endCol])))){
                    return true;
                }
            }
            break;
        }

        // empty square no killing of opponent
        if (i == endRow && startCol == endCol) {
            return true;  
        }
    }

    //vertical down
     for(int i = startRow + 1; i < 8; i++){
        if(chessBoard[i][startCol] != '.'){
            if((i == endRow) && (startCol == endCol)){
                if(((currentPlayerColor == 'W') && (islower(chessBoard[endRow][endCol]))) ||  ((currentPlayerColor == 'B') && (isupper(chessBoard[endRow][endCol])))){
                    return true;
                }
            }
            break;
        }

        // empty square no killing of opponent
        if (i == endRow && startCol == endCol) {
            return true;  
        }
    }

    //horizontal right
    for(int j = startCol + 1; j < 8; j++){
        if(chessBoard[startRow][j] != '.'){
            if((j == endCol) && (startRow == endRow)){
                 if(((currentPlayerColor == 'W') && (islower(chessBoard[endRow][endCol]))) ||  ((currentPlayerColor == 'B') && (isupper(chessBoard[endRow][endCol])))){
                    return true;
                }
            }
            break;
        }

        //if square is empty
        if((j == endCol) && (startRow == endRow)){
            return true;
        }
    }

    //horizontal left
    for(int j = startCol - 1; j >= 0; j--){
        if(chessBoard[startRow][j] != '.'){
            if((j == endCol) && (startRow == endRow)){
                 if(((currentPlayerColor == 'W') && (islower(chessBoard[endRow][endCol]))) ||  ((currentPlayerColor == 'B') && (isupper(chessBoard[endRow][endCol])))){
                    return true;
                }
            }
            break;
        }

        //if square is empty
        if((j == endCol) && (startRow == endRow)){
            return true;
        }
    }

    return false;
}

bool isValidBishop(char chessBoard[8][8], int startRow, int endRow, int startCol, int endCol, char currentPlayerColor){
    //Upside Diagonal right
    for(int i = startRow - 1, j = startCol + 1; i >= 0, j < 8; i--, j++){
        if(i == endRow && j == endCol){
              if (chessBoard[endRow][endCol] == '.' || (currentPlayerColor == 'W' && islower(chessBoard[endRow][endCol])) || (currentPlayerColor == 'B' && isupper(chessBoard[endRow][endCol]))) {
                return true;
            }
        }
        if (chessBoard[i][j] != '.'){
                 break;
        }
    }

    //upside diagonal left
     for(int i = startRow - 1, j = startCol - 1; i >= 0, j >= 0; i--, j--){
        if(i == endRow && j == endCol){
              if (chessBoard[endRow][endCol] == '.' || (currentPlayerColor == 'W' && islower(chessBoard[endRow][endCol])) || (currentPlayerColor == 'B' && isupper(chessBoard[endRow][endCol]))) {
                return true;
            }
        }
        if (chessBoard[i][j] != '.'){
                 break;
        }
    }

    //downside diagonal right
     for(int i = startRow + 1, j = startCol + 1; i < 8, j < 8; i++, j++){
        if(i == endRow && j == endCol){
              if (chessBoard[endRow][endCol] == '.' || (currentPlayerColor == 'W' && islower(chessBoard[endRow][endCol])) || (currentPlayerColor == 'B' && isupper(chessBoard[endRow][endCol]))) {
                return true;
            }
        }
        if (chessBoard[i][j] != '.'){
                 break;
        }
    }

    //downside diagonal left
     for(int i = startRow + 1, j = startCol - 1; i < 8, j >= 0; i++, j--){
        if(i == endRow && j == endCol){
              if (chessBoard[endRow][endCol] == '.' || (currentPlayerColor == 'W' && islower(chessBoard[endRow][endCol])) || (currentPlayerColor == 'B' && isupper(chessBoard[endRow][endCol]))) {
                return true;
            }
        }
        if (chessBoard[i][j] != '.'){
                 break;
        }
    }

    return false;
}

bool isValidQueen(char chessBoard[8][8], int startRow, int endRow, int startCol, int endCol, char currentPlayerColor){
    return  isValidBishop(chessBoard, startRow, endRow, startCol, endCol, currentPlayerColor) ||  isValidRook(chessBoard, startRow, endRow, startCol, endCol, currentPlayerColor);
}

bool isValidKing(char chessBoard[8][8], int startRow, int endRow, int startCol, int endCol, char currentPlayerColor){
    if (abs(startRow - endRow) > 1 || abs(startCol - endCol) > 1) {
         return false;  
    }

    if (chessBoard[endRow][endCol] == '.' ||  (currentPlayerColor == 'W' && islower(chessBoard[endRow][endCol])) || (currentPlayerColor == 'B' && isupper(chessBoard[endRow][endCol]))) {
        return true;  
    }

    return false;
}

bool isValidKnight(char chessBoard[8][8], int startRow, int endRow, int startCol, int endCol, char currentPlayerColor){
    int diffRow = abs(startRow - endRow);
    int diffCol = abs(startCol - endCol);

    if((diffRow == 2) && (diffCol == 1) || (diffRow == 1) && (diffCol == 2)){
        if((chessBoard[endRow][endCol] == '.') || ((currentPlayerColor == 'W') && (islower(chessBoard[endRow][endCol]))) || ((currentPlayerColor == 'B') && (isupper(chessBoard[endRow][endCol])))){
            return true;
        }
    }

    return false;
}

void nota(string position, int &row, int &col) {
    col = position[0] - 'a';        
    row = 8 - (position[1] - '0');    
} 

void printBoard(char chessBoard[8][8]){
    cout << "    " << "a    b   c   d   e   f   g   h" << endl;
    cout <<  "  " << "+---+---+---+---+---+---+---+---+" << endl;

    for(int i = 0; i < 8; i++){
        cout << 8 - i;
        for(int j = 0; j < 8; j++){
            cout << " |" << chessBoard[i][j] << " ";
        }
        cout << " |" << 8 - i;
        cout << endl;
        cout << "  " << "+---+---+---+---+---+---+---+---+" << endl;
    }

    cout << "    " << "a    b   c   d   e   f   g   h" << endl; 
}

void playTurn(char chessBoard[8][8], PlayerOne &p1, PlayerTwo &p2, char &currentPlayerColor) {
    string startPos, endPos;
    int startRow, startCol, endRow, endCol;

    string currentPlayerName = (currentPlayerColor == 'W' ? p1.name : p2.name);
    cout << currentPlayerName << " turn." << endl;

    cout << "Enter the start position: ";
    cin >> startPos;
    cout << "Enter the end position: ";
    cin >> endPos;

    nota(startPos, startRow, startCol);
    nota(endPos, endRow, endCol);

    char piece = chessBoard[startRow][startCol];

    bool validMove = false;
    if ((piece == 'P' || piece == 'p') && isValidPawn(chessBoard, startRow, endRow, startCol, endCol, currentPlayerColor)) {
        validMove = true;
    } 
    else if ((piece == 'R' || piece == 'r') && isValidRook(chessBoard, startRow, endRow, startCol, endCol, currentPlayerColor)) {
        validMove = true;
    }
    else if ((piece == 'N' || piece == 'n') && isValidKnight(chessBoard, startRow, endRow, startCol, endCol, currentPlayerColor)) {
        validMove = true;
    } 
    else if ((piece == 'B' || piece == 'b') && isValidBishop(chessBoard, startRow, endRow, startCol, endCol, currentPlayerColor)) {
        validMove = true;
    } 
    else if ((piece == 'Q' || piece == 'q') && isValidQueen(chessBoard, startRow, endRow, startCol, endCol, currentPlayerColor)) {
        validMove = true;
    } 
    else if ((piece == 'K' || piece == 'k') && isValidKing(chessBoard, startRow, endRow, startCol, endCol, currentPlayerColor)) {
        validMove = true;
    }

    if (validMove) {
        chessBoard[endRow][endCol] = chessBoard[startRow][startCol];
        chessBoard[startRow][startCol] = '.';

        printBoard(chessBoard);

        currentPlayerColor = (currentPlayerColor == 'W' ? 'B' : 'W');
    } 
    else {
        cout << "Invalid move. Please try again." << endl;
    }
}

     
int main(){
    PlayerOne p1("white");
    cout << p1.name << endl;
    PlayerTwo p2("black");
    cout << p2.name << endl;

    char chessBoard[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                             {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                             {'.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.'},
                             {'.', '.', '.', '.', '.', '.', '.', '.'},
                             {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                             {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

    printBoard(chessBoard);

     char currentPlayerColor = 'W';  
    

    while (true) {
        playTurn(chessBoard, p1, p2, currentPlayerColor);
    }

    return 0;
}