#include<iostream>
using namespace std;

// Low level design of Tic-Tac-toe game

class User{
    string name;
    char symbol;
public:
    User(string name, char symbol){
        this->name = name;
        this->symbol = symbol;
    }

    string get_name(){
        return name;
    }

    char get_symbol(){
        return symbol;
    }
};

class Grid{
    char grid[3][3];
public:
    Grid(){
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                grid[row][col] = '-';
            }
        }
    }

    void display(){
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                cout<<grid[row][col]<<" ";
            }
            cout<<endl;
        }
    }

    void set_symbol(int row, int col, char symbol){
        grid[row][col] = symbol;
    }

    bool is_empty(int row, int col){
        return grid[row][col] == '-';
    }

    bool is_winner(char symbol){
        for(int index = 0; index < 3; index++){
            if(grid[index][0] == symbol && grid[index][1] == symbol && grid[symbol][2] == symbol){
                return true;
            }
            if(grid[0][index] == symbol && grid[1][index] == symbol && grid[2][index] == symbol){
                return true;
            }
        }
        if(grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol){
            return true;
        }
        if(grid[2][0] == symbol && grid[1][1] == symbol && grid[0][2] == symbol){
            return true;
        }
        return false;
    }

    bool is_full(){
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                if(grid[row][col] == '-')
                    return false;
            }
        }
        return true;
    }
};

int main(){

    string name1, name2;
    cout<<"Enter name of player 1:";
    cin>>name1;
    cout<<"Enter name of player 2:";
    cin>>name2;
    int row, col;
    User player1(name1, 'X'), player2(name2, 'O');
    User current_player = player1;
    Grid grid;
    while(true){
        cout<<current_player.get_name()<<"'s turn"<<endl;
        grid.display();
        cout<<"Enter value of row and column (or exit):";
        string input;
        cin>>input;
        if(input=="exit"){
            cout<<"Game exited by user.";
            break;
        }
        try {
            row = stoi(input);
            cin>>col;
        } 
        catch (const invalid_argument& e) {
            cout<<"Invalid input. Please enter numeric values for row and column."<<endl;
            continue;
        }
        if(row - 1 < 0 || row - 1 > 2 || col - 1 < 0 || col - 1 > 2){
            cout<<"Invalid Move"<<endl;
            continue;
        }
        if(!grid.is_empty(row - 1, col - 1)){
            cout<<"Invalid Move"<<endl;
            continue;
        }
        grid.set_symbol(row - 1, col - 1, current_player.get_symbol());
        if(grid.is_winner(current_player.get_symbol())){
            cout<<current_player.get_name()<<" won the game."<<endl;
            grid.display();
            break;
        }
        if(grid.is_full()){
            cout<<"Game Draw"<<endl;
            grid.display();
            break;
        }

        current_player = current_player.get_name() == player1.get_name() ? player2 : player1;
    }

    return 0;
}