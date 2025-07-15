#include <iostream>
#include <vector>
using namespace std;

// Function to display the 3x3 game board
void displayBoard(const vector<string>& board) {
    cout << "\n";
    cout << "  " << board[1] << "  |  " << board[2] << "  |  " << board[3] << "  \n";
    cout << "---------------------\n";
    cout << "  " << board[4] << "  |  " << board[5] << "  |  " << board[6] << "  \n";
    cout << "---------------------\n";
    cout << "  " << board[7] << "  |  " << board[8] << "  |  " << board[9] << "  \n";
    cout << "\n";
}

// Checks if a move is valid (1–9 and cell not already taken)
bool isValidMove(int move, const vector<string>& board) {
    return move >= 1 && move <= 9 && board[move] != "X" && board[move] != "O";
}

// Makes a move on the board
void makeMove(int position, string symbol, vector<string>& board) {
    board[position] = symbol;
}

// Checks for a win condition
bool hasPlayerWon(const string& symbol, const vector<string>& board) {
    return (
        (board[1] == symbol && board[2] == symbol && board[3] == symbol) ||
        (board[4] == symbol && board[5] == symbol && board[6] == symbol) ||
        (board[7] == symbol && board[8] == symbol && board[9] == symbol) ||
        (board[1] == symbol && board[4] == symbol && board[7] == symbol) ||
        (board[2] == symbol && board[5] == symbol && board[8] == symbol) ||
        (board[3] == symbol && board[6] == symbol && board[9] == symbol) ||
        (board[1] == symbol && board[5] == symbol && board[9] == symbol) ||
        (board[3] == symbol && board[5] == symbol && board[7] == symbol)
    );
}

// Starts a single game session
void playGame() {
    vector<string> board(10); // index 1–9 used
    for (int i = 1; i <= 9; i++) {
        board[i] = to_string(i);
    }

    string currentPlayer = "X";
    int totalMoves = 0;
    bool gameWon = false;

    displayBoard(board);

    while (totalMoves < 9 && !gameWon) {
        int move;

        cout << "Player " << (currentPlayer == "X" ? "1" : "2") << " (" << currentPlayer << "), enter your move (1 to 9): ";
        cin >> move;

        while (!isValidMove(move, board)) {
            cout << "Invalid move! Try again (1 to 9): ";
            cin >> move;
        }

        makeMove(move, currentPlayer, board);
        displayBoard(board);
        totalMoves++;

        if (hasPlayerWon(currentPlayer, board)) {
            cout << " Player " << (currentPlayer == "X" ? "1" : "2") << " wins the game!\n";
            gameWon = true;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == "X") ? "O" : "X";
    }

    if (!gameWon && totalMoves == 9) {
        cout << "It's a draw! \n";
    }
}

int main() {
    char choice;
    cout << "=== Welcome to the Console Tic-Tac-Toe Game! ===\n";
    cout << "Press any key to start, or 'q' to quit: ";
    cin >> choice;

    while (choice != 'q' && choice != 'Q') {
        playGame();
        cout << "\nWould you like to play again? (Press any key to continue or 'q' to quit): ";
        cin >> choice;
    }

    cout << "\nThanks for playing! Goodbye \n";
    return 0;
}
