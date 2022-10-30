# Global Variables

Board = [' ',' ',' ',
         ' ',' ',' ',
         ' ',' ',' ']

CurrentPlayer = 'X'
Winner = None
GameRunning = True

# Game Functions

def print_board() :
    print(" %s | %s | %s " %(Board[0],Board[1],Board[2]))
    print("-"*11)
    print(" %s | %s | %s " %(Board[3],Board[4],Board[5]))
    print("-"*11)
    print(" %s | %s | %s " %(Board[6],Board[7],Board[8]))
    
    
def player_input() :
    while True :
        inp = int(input("Enter a position(1-9) to place your marker : "))
        if Board[inp-1] == " " :
            Board[inp-1] = CurrentPlayer
            break
        else :
            print("That position is occupied")
        
        
def check_rows() :
    
    if Board[0] == Board[1] == Board[2] and Board[0] != ' ' :
        Winner = CurrentPlayer
        GameRunning = False
        return True
    
    elif Board[3] == Board[4] == Board[5] and Board[3] != ' ' :
        Winner = CurrentPlayer
        GameRunning = False
        return True
    
    elif Board[6] == Board[7] == Board[8] and Board[6] != ' ' :
        Winner = CurrentPlayer
        GameRunning = False
        return True
        
        
def check_columns() :
    
    if Board[0] == Board[3] == Board[6] and Board[0] != ' ' :
        Winner = CurrentPlayer
        GameRunning = False
        return True
    
    elif Board[1] == Board[4] == Board[7] and Board[1] != ' ' :
        Winner = CurrentPlayer
        GameRunning = False
        return True
    
    elif Board[2] == Board[5] == Board[8] and Board[2] != ' ' :
        Winner = CurrentPlayer
        GameRunning = False
        return True
    
    
def check_diagonals() :
    
    if Board[0] == Board[4] == Board[8] and Board[0] != ' ' :
        Winner = CurrentPlayer
        GameRunning = False
        return True
    
    elif Board[2] == Board[4] == Board[6] and Board[2] != ' ' :
        Winner = CurrentPlayer
        GameRunning = False
        return True
 
 
def check_tie() :
    flag = 0
    for i in range(9) :
        if Board[i] == ' ' :
            flag = 1
    if flag == 0 :
        return True
       
          
def check_win() :
    
    if check_columns() or check_rows() or check_diagonals() :
        return 1
    elif check_tie() :
        return 2    
    else :
        return 0
    
    
def switch_player() :
    if CurrentPlayer == 'X' :
        CurrentPlayer = 'O'
    else :
        CurrentPlayer = 'X'
        

def computer_random() :
    print(1)
    
    
def algorithm() :
    print(1)
    
def main() :
    
    # print("\nWelcome to TIC TAC TOE\n")
    # print("Choose your game option")
    # print("1. Player Vs Player")
    # print("2. Player Vs Computer(Random)")
    # print("3. Player Vs Computer(Algorithm)\n")
    
    # ch = int(input("Enter Your Choice : "))
    
    # if ch == 1 :
    #     Player1 = input("Enter Player 1 Name : ")
    #     Player2 = input("Enter Player 2 Name : ")
    # else :
    #     Player1 = "User"
    #     player2 = "Computer"
        
    while True :
        print_board()
        player_input()
        if check_win() == 1 :
            print("Winner is %s" %CurrentPlayer)
        elif check_win() == 2 :
            print("Game is a Tie")
        switch_player()
        
            
main()