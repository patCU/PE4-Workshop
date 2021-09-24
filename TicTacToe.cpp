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
int* userChoice(char player){
    int rowInput;
    cout << "Player: " << player << " please select row: ";
    cin >> rowInput;
    
    int colInput;
    cout << "please select col: ";
    cin >> colInput;
    cout << " " << endl;
    
    int* temp = new int[2];
    temp[0] = rowInput;
    temp[1] = colInput;
    return temp;
}


int main(){
    char player_one = 'X';
    int* choices;
    
    int** b = CreateBoard();
    
    choices = userChoice(player_one);
    
    b = PlaceMarker(b, choices[0], choices[1], 1);

}
