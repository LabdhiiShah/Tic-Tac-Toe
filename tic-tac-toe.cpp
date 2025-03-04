#include<iostream>
#include<cstdlib>
using namespace std;

class game
{
public:
    int won=0,currentPlayer,move,move2,totalmoves=0;
    char input,currentMark;
    char board[3][3]={ {'1', '2', '3'},
                       {'4', '5', '6'},
                       {'7', '8', '9'} };
    void choose_mark();
    void drawBoard();
    void moves();
    bool check_space(int move);
    bool check_win();
    void swapPlayer();

};
void game::drawBoard()
{
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                cout << "\033[91m X \033[0m";  // Red X
            } else if (board[i][j] == 'O') {
                cout << "\033[96m O \033[0m";  // Blue O
            } else {
                cout << " " << board[i][j] << " ";
            }

            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---" << endl;
    }
    cout << "\033[0m";  // Reset color
}

bool game :: check_space(int move)
{
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

return (board[row][col] != 'X' && board[row][col] != 'O');
}

bool game :: check_win()
{
//    checks rows & cols
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return currentPlayer;
        }
       if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return currentPlayer;
        }
    }

//    checks diagonals
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        return currentPlayer;
    }
    return false;
}

void game :: swapPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMark = (currentMark == 'X') ? 'O' : 'X';
}

void game :: moves()
{
    while(totalmoves<9)
    {

            cout<<"Player "<<currentPlayer<<" ("<<currentMark<<")"<<" , Enter your move!!"<<endl;
            cin>>move;
            if(move<1 || move>9 || !check_space(move))
            {
               cout<<"Invalid move!!"<<endl;
               continue;
            }

            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            board[row][col] = currentMark;
            system("cls");
            drawBoard();
            totalmoves++;
                if (check_win()!= 0)
                {
                    won = currentPlayer;
                    break;
                }
            swapPlayer();
   }
    if(won)
    {
       cout << "Player " << won << " wins!\n";
    }
    else
    {
       cout << "It's a draw!\n";
    }
}

void game :: choose_mark()
{
        cout<<endl<<"Choose your mark Player1 (X or O): ";
        cin>>currentMark;
        if(currentMark!='X'&&  currentMark!='O')
        {
            cout<<"currentmark: "<<currentMark<<endl;
            cout<<endl<<"Invalid choice!!"<<endl<<"Your default mark is X"<<endl<<endl;
            currentMark='X';
        }
        else if(currentMark=='X')
        {
            cout<<endl<<"Player2 your mark is: O"<<endl;
        }
        else
        {
            cout<<endl<<"Player2 your mark is: X"<<endl;
        }
        currentPlayer = 1;
}

int main()
{
    game g;
    cout<<"Welcome to Tic-Tac-Toe game!!";
    cout<<"Play with: "<<endl<<"(a) Computer "<<endl<<"(b) Friend"<<endl;
    cin>>g.input;
    g.choose_mark();
    cout<<endl<<"Tic-Tac-Toe"<<endl;
    g.drawBoard();
    g.moves();
}
