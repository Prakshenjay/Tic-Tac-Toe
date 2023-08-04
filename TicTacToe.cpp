#include <iostream>

using namespace std;

char Board[3][3];

int NumberOfPlayers;

string Player1;
string Player2;

int Score1 = 0;
int Score2 = 0;

char CurrentMarker;

void Startup();

void Print_Instructions();

void Play_game();

void Initialise();

void Print_Board();

void Player_Move();

void switch_current_marker();

void Computer_Move();

bool Game_over();

char Check_Rows();

char Check_Columns();

char Check_Diagonals();

bool Check_Tie();

void declare_winner();

int MiniMax(int depth , bool isMaximizing);

void print_score();

int exiting();

int main()
{
    Startup();
}

void Startup()
{
    int ch;

    system("clear");
    cout << "\n";
    cout << "\t\t WELCOME TO TIC-TAC-TOE\n\n";

    cout << "Choose Game Style :\n";
    cout << "1. Player Vs Player\n";
    cout << "2. Player Vs Computer\n";

choice:;
    cout << "\nYour Choice : ";
    cin >> ch;

    switch (ch)
    {
    case 1:
            cout << "\nEnter Player 1 Name : ";
            cin >> Player1;
            cout << "\nEnter Player 2 Name : ";
            cin >> Player2;

            NumberOfPlayers = 2;
            break;

    case 2:
            cout << "\nEnter Player Name : ";
            cin >> Player1;
            Player2 = "Computer";

            NumberOfPlayers = 1;
            break;

    default:
            cout << "\nInvalid Choice, Please Enter Again";
            goto choice;
            break;
    }

    Print_Instructions();
    Play_game();
}

void Print_Instructions()
{
    cout << endl;
    cout << "\t\t Tic-Tac-Toe\n\n";
    cout << "Choose a cell numbered from 1 to 9 as below to place your Marker\n\n";

    cout << "\t\t " << 1 << " | " << 2 << " | " << 3 << " \n";
    cout << "\t\t-----------\n";
    cout << "\t\t " << 4 << " | " << 5 << " | " << 6 << " \n";
    cout << "\t\t-----------\n";
    cout << "\t\t " << 7 << " | " << 8 << " | " << 9 << " \n";

    cout << "\n\nPress Enter to Play" ;
    char ch;
    scanf("%c", &ch);
    getchar();
}

void Play_game()
{
    system("clear");

    Initialise();

    while (1)
    {
        Print_Board();

        Player_Move();

        if ( Game_over() )
        {
            declare_winner();
            break;
        }

        system("clear");
        switch_current_marker();

        if (NumberOfPlayers == 1)
        {
            Computer_Move();

            if (Game_over() )
            {
                declare_winner();
                break;
            }

            system("clear");
            switch_current_marker();
        }
    }
}

void Initialise()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Board[i][j] = ' ';
        }
    }

    CurrentMarker = 'X';
}

void Print_Board()
{
    cout << "\n\n";

    cout << "\t\t " << Board[0][0] << " | " << Board[0][1] << " | " << Board[0][2] << " \n";
    cout << "\t\t-----------\n";
    cout << "\t\t " << Board[1][0] << " | " << Board[1][1] << " | " << Board[1][2] << " \n";
    cout << "\t\t-----------\n";
    cout << "\t\t " << Board[2][0] << " | " << Board[2][1] << " | " << Board[2][2] << " \n";
}

void Player_Move()
{
    int x, y;
    while (1)
    {
        int pos;
        cout << "\nEnter Position(1-9) : " ;
        cin >> pos;

        switch (pos)
        {
        case 1 : x = 0 ;  y = 0 ; break;
        case 2 : x = 0 ;  y = 1 ; break;
        case 3 : x = 0 ;  y = 2 ; break;
        case 4 : x = 1 ;  y = 0 ; break;
        case 5 : x = 1 ;  y = 1 ; break;
        case 6 : x = 1 ;  y = 2 ; break;
        case 7 : x = 2 ;  y = 0 ; break;
        case 8 : x = 2 ;  y = 1 ; break;
        case 9 : x = 2 ;  y = 2 ; break;
        default:
                cout << "Invalid Input\n";
                break;
        }

        if (Board[x][y] == ' ')
        {
            Board[x][y] = CurrentMarker;
            break;
        }
        else
        {
            cout << "\nThat position is occupied";
        }
    }
}

void switch_current_marker()
{
    if (CurrentMarker == 'X')
    {
        CurrentMarker = 'O';
    }
    else
    {
        CurrentMarker = 'X';
    }
}

void Computer_Move()
{
    int BestScore = -99999;
    int X,Y;

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(Board[i][j] == ' ')
            {
                Board[i][j] = CurrentMarker;
                int score = MiniMax(0 , false);
                Board[i][j] = ' ';
                if(score > BestScore)
                {
                    BestScore = score;
                    X = i;
                    Y = j;
                }
            }
        }
    }

    Board[X][Y] = CurrentMarker;
}

int MiniMax(int depth , bool isMaximizing)
{
    if( Game_over() )
    {
        if( Check_Rows() == 'X' || Check_Columns() == 'X' || Check_Diagonals() == 'X' )
        {
            return depth - 10;
        }
        else if( Check_Rows() == 'O' || Check_Columns() == 'O' || Check_Diagonals() == 'O' )
        {
            return 10 - depth;
        }
        else
        {
            return 0;
        }
    }
    else if( isMaximizing )
    {
        int BestScore = -99999;

        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(Board[i][j] == ' ')
                {
                    Board[i][j] = 'O';
                    int score = MiniMax(depth + 1 , false);
                    Board[i][j] = ' ';
                    BestScore = max( BestScore , score );
                }
            }
        }
        return BestScore;
    }
    else
    {
        int BestScore = 99999;

        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                if(Board[i][j] == ' ')
                {
                    Board[i][j] = 'X';
                    int score = MiniMax(depth + 1 , false);
                    Board[i][j] = ' ';
                    BestScore = min( BestScore , score );
                }
            }
        }
        return BestScore;
    }
}

bool Game_over()
{
    if ( Check_Rows() != 0 || Check_Columns() != 0 || Check_Diagonals() != 0 || Check_Tie() )
    {
        return true;
    }
    return false;
}

char Check_Rows()
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == Board[i][1] &&
            Board[i][1] == Board[i][2] &&
            Board[i][0] != ' ')
        {
            return (Board[i][0]);
        }
    }
    return 0;
}

char Check_Columns()
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[0][i] == Board[1][i] &&
            Board[1][i] == Board[2][i] &&
            Board[0][i] != ' ')
        {
            return (Board[0][i]);
        }
    }
    return (0);
}

char Check_Diagonals()
{
    if (Board[0][0] == Board[1][1] &&
        Board[1][1] == Board[2][2] &&
        Board[0][0] != ' ')
    {
        return (Board[1][1]);
    }
    if (Board[0][2] == Board[1][1] &&
        Board[1][1] == Board[2][0] &&
        Board[2][0] != ' ')
    {
        return (Board[1][1]);
    }
    return (0);
}

bool Check_Tie()
{
    bool flag = true;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] == ' ')
            {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

void declare_winner()
{
    system("clear");

    cout << endl << "\t\t GAME - OVER \n";
    Print_Board();

    if( Check_Tie() )
    {
        cout << "\n\n The Game was a Tie" << endl;
    }
    else
    {
        string name;
        if(CurrentMarker == 'X')
        {
            name = Player1;
            Score1++;
        }
        else
        {
            name = Player2;
            Score2++;
        }

        cout << "\n\n Winner is " << name << endl;
    }
    print_score();

    if( exiting() )
    {
        Play_game();
    }
    else
    {
        cout << "\nPress ENTER key to exit.\n" ;
        char ch;
        scanf("%c",&ch);
        getchar();
        exit(1);
    }
}

void print_score()
{
    cout << "\n" << endl;

    cout << "\t-------------- SCORE BOARD --------------" << endl;

    cout << endl;

    cout << "\t-----------------------------------------" << endl;
    cout << "\t|\t" << Player1 << "\t|\t" << Score1 << "\t|" << endl;
    cout << "\t-----------------------------------------" << endl;
    cout << "\t|\t" << Player2 << "\t|\t" << Score2 << "\t|" << endl;
    cout << "\t-----------------------------------------" << endl;
}

int exiting()
{
start:

    cout << "\n\n Thank you for Playing the Game \n" ;

    char answer;

    cout << "\nDo you want to Play Again (Y/N) : " ;
    cin >> answer ;

    switch (answer)
    {
    case 'y':
    case 'Y':
            return 1;
            break;

    case 'n':
    case 'N':
            return 0;
            break;

    default:
            cout << "\nYou did not respond correctly...\n" ;
            goto start;
            break;
    }
}
