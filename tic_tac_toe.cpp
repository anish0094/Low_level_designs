#include<iostream>
using namespace std;

// Creating a LLD for Tic Tac Toe Game
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
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                grid[i][j] = '-';
            }
        }
    }
    void display(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool is_empty(int x, int y){
        return grid[x][y] == '-';
    }
    void set(int x, int y, char symbol){
        grid[x][y] = symbol;
    }
    char get(int x, int y){
        return grid[x][y];
    }
    bool is_winner(char symbol){
        for(int i=0; i<3; i++){
            if(grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol){
                return true;
            }
            if(grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol){
                return true;
            }
        }
        if(grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol){
            return true;
        }
        if(grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol){
            return true;
        }
        return false;
    }
    bool is_full(){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(grid[i][j] == '-'){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    string name1, name2;
    cout<<"Enter Name of User1: ";
    cin>>name1;
    cout<<"Enter Name of User2: ";
    cin >> name2;
    User user1(name1, 'X');
    User user2(name2, 'O');
    Grid grid;
    int x, y;
    User current_user = user1;
    while (true) {
        cout << current_user.get_name() << "'s Turn" << endl;
        grid.display();
        cout << "Enter x and y (or exit): ";
        string input;
        cin >> input;
        if (input == "exit") {
            cout << "Game exited by user." << endl;
            break;
        }

        x = stoi(input);
        cin >> y;
        if (x - 1 < 0 || x - 1 > 2 || y - 1 < 0 || y - 1 > 2) {
            cout << "Invalid Move" << endl;
            continue;
        }
        if (!grid.is_empty(x - 1, y - 1)) {
            cout << "Invalid Move" << endl;
            continue;
        }
        grid.set(x - 1, y - 1, current_user.get_symbol());
        if (grid.is_winner(current_user.get_symbol())) {
            cout << current_user.get_name() << " won the game" << endl;
            grid.display();
            break;
        }
        if (grid.is_full()) {
            cout << "Game Over" << endl;
            grid.display();
            break;
        }
        current_user = current_user.get_name() == user1.get_name() ? user2 : user1;
    }
    return 0;
}
