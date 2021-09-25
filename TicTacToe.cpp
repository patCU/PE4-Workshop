#include <iostream>

using namespace std;


int** CreateBoard(){
    int** a = new int*[3];
    for(int i = 0; i < 3; i++) {
        a[i] = new int[3];
    }
    return a;
}


int** PlaceMarker(int** a, int r, int c, int val){
    a[r][c] = val;
    return a;
}


int* GetPlayerChoice(char player){ //for the players to make choices, input based on which player is going
    int rowInput; //make a variable for the player's row input
    cout << "Player: " << player << " please select row: "; //output message prompting for a row input
    cin >> rowInput; //take players input
    
    int colInput; //variable for player's column input
    cout << "please select col: "; //output message prompting for a column input
    cin >> colInput; //take players input
    cout << " " << endl; //add a space and end line here
    
    int* temp = new int[2]; //make an array to store the inputs (compatible with the placemarker and display board function to update)
    temp[0] = rowInput; //store row input at 0 index
    temp[1] = colInput; //store column input at 1 index
    return temp; //return array (to be used with the other functions)
}


void displayBoard(int** a){ //display board takes in a 2 dimension int array and returns nothing
    for(int i=0;i<3;i++){ //first for loop for rows
        for(int j=0;j<3;j++){ //second for loop for columns
            cout << a[i][j] << " "; //output the individual spaces for each row combined with a space to make it distinct and easy to understand 
            if(j == 2){cout << " " << endl;} //add a space before ending line (at the end of each row, we move to the next)
        }
    }
}


int main(){
    char player_one = 'X'; //player with X will be player 1
    char player_two = 'O'; //player with O will be player 2
    int* choices; //make an array for the choices

    int** b = CreateBoard(); //create a board and store in array
    //loop through 9 times for total squares
    for(int i=0;i<9;i++){
      choices = GetPlayerChoice(player_one); //add X's choice
      b = PlaceMarker(b, choices[0], choices[1], 1); //mark X's choice
      displayBoard(b); //display board for player 2
      choices = GetPlayerChoice(player_two); //add O's choice
      b = PlaceMarker(b, choices[0], choices[1], 2); //mark O's choice
      displayBoard(b); //display the board for player 1
    }

}
