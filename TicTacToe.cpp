#include <iostream>

using namespace std;

char Board[3][3];

int NumberOfPlayers;

string Player1;
string Player2;

int Score1 = 0;
int Score2 = 0;

char CurrentMarker = 'X';

void print_instructions()
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

void print_board()
{
    cout << "\n\n";

    cout << "\t\t " << Board[0][0] << " | " << Board[0][1] << " | " << Board[0][2] << " \n";
    cout << "\t\t-----------\n";
    cout << "\t\t " << Board[1][0] << " | " << Board[1][1] << " | " << Board[1][2] << " \n";
    cout << "\t\t-----------\n";
    cout << "\t\t " << Board[2][0] << " | " << Board[2][1] << " | " << Board[2][2] << " \n";
}

void initialise()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Board[i][j] = ' ';
        }
    }
}

void switch_current_marker()
{
    if (CurrentMarker == 'X')
        CurrentMarker = 'O';
    else
        CurrentMarker = 'X';
}

void player_move()
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

int MiniMax()
{
    

    return 1;
}

void computer_move()
{
    int BestScore = -1;
    int BestMove[2];

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            if(Board[i][j] == ' ')
            {
                Board[i][j] = CurrentMarker;
                int score  = MiniMax();
                Board[i][j] = ' ';
                if(score > BestScore)
                {
                    BestScore = score;
                    BestMove[0] = i ; BestMove[1] = j ;
                }
            }
        }
    }

    Board[ BestMove[0] ][ BestMove[1] ] = CurrentMarker;
}

bool check_rows()
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == Board[i][1] &&
            Board[i][1] == Board[i][2] &&
            Board[i][0] != ' ')
        {
            return (true);
        }
    }
    return (false);
}

bool check_columns()
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[0][i] == Board[1][i] &&
            Board[1][i] == Board[2][i] &&
            Board[0][i] != ' ')
        {
            return (true);
        }
    }
    return (false);
}

bool check_diagonals()
{
    if (Board[0][0] == Board[1][1] &&
        Board[1][1] == Board[2][2] &&
        Board[0][0] != ' ')
    {
        return (true);
    }
    if (Board[0][2] == Board[1][1] &&
        Board[1][1] == Board[2][0] &&
        Board[2][0] != ' ')
    {
        return (true);
    }
    return (false);
}

bool check_tie()
{
    int flag = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] == ' ')
            {
                flag = 0;
                break;
            }
        }
    }

    return flag;
}

int game_over()
{
    if ( check_rows() || check_columns() || check_diagonals() || check_tie() )
    {
        return 1;
    }
    return 0;
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
            cout << "\nPress ENTER key to exit.\n" ;
            return 0;
            break;

    default:
            cout << "\nYou did not respond correctly...\n" ;
            goto start;
            break;
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

void declare_winner();

void play_game()
{
    system("clear");

    initialise();

    while (1)
    {
        print_board();

        player_move();

        if ( game_over() )
        {
            declare_winner();
            break;
        }

        system("clear");
        switch_current_marker();

        if (NumberOfPlayers == 1)
        {
            print_board();

            computer_move();

            if (game_over() )
            {
                declare_winner();
                break;
            }

            system("clear");
            switch_current_marker();
        }
    }
}

void declare_winner()
{
    system("clear");

    cout << endl << "\t\t GAME - OVER \n";
    print_board();

    if( check_tie() )
    {
        cout << "\n\n The Game was a TIE" << endl;
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
        play_game();
    }
    else
    {
        char ch;
        scanf("%c",&ch);
        getchar();
        exit(1);
    }
}

void startup()
{
    int ch;

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

    print_instructions();
    play_game();
}

int main()
{
    startup();
}