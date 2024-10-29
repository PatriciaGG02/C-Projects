/** 
 * @file TER.cpp
 * @brief Implementación de un juego Tres en Raya sin interfaz gráfica de uno o dos jugadores.
 * 
 * Este programa permite al jugador jugar al Tres en Raya de manera indicidual o con otro jugador.
 * 
 * @author Patricia García González.
 * 
 * @date 27/10/2024
*/

#include <iostream>
#include <ctime>
using namespace std;

void print_Board(char *board);
void player_Turn(char player1, char *board);
void computer_Turn(char computer, char *board);
bool check_Play(char player, char *board);
bool check_Tied_Play(char *board);



char board[9]={' ',' ',' ', ' ',' ',' ',' ',' ',' '};
char player1 = 'X';
char player2 ='O';
char computer ='P';
bool running = true;



/**
 * @brief Funcionamiento del juego Tres en Raya
 * 
 * Consiste en el funcionamiento del juego Tres en Raya a partir de un if,
 * donde se puede elegir un solo jugador o dos
 * 
 */
int main(){

cout<<"Bienvenido al Tres en raya!\n";
cout<<"Ingrese la cantidad de jugadores (1 o 2)\n";

int players;
cin>>players;

if (players == 1){
    while(running){
    player_Turn(player1, board);
    print_Board(board);

    if (check_Play(player1, board) || check_Tied_Play(board)){
        running = false;
        break;
    }
    
    computer_Turn(computer, board);
    print_Board(board);

    if (check_Play(computer, board) || check_Tied_Play(board)){
        running = false;
        break;
    }}
     
} else if(players == 2){

    while(running){
    player_Turn(player1, board);
    print_Board(board);

    if (check_Play(player1, board) || check_Tied_Play(board)) {
        cout << "Ha ganado el jugador 1\n";
        running = false;
        break;
    }

    player_Turn(player2, board);
    print_Board(board);

    if (check_Play(player2, board) || check_Tied_Play(board)) {
        cout << "Ha ganado el jugador 2\n";
        running = false;
        break;
    }} 
   
}else{
    cout<<"Ingrese un número permitido (1 o 2)\n";
}

cout<<"Gracias por jugar! :D";

}


/**
 * @brief Imprime el tablero de juego en la consola.
 * 
 * @param board Para rellenar el tablero propiamente creado
 * Esta función muestra el tablero de 3x3 en la consola
 * 
 */
void print_Board(char *board){
    std::cout<< '\n';
    std::cout<<"     |     |     \n";
    std::cout<<"  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<board[2]<<"  \n";
    std::cout<<"_____|_____|_____\n";
    std::cout<<"     |     |     \n";
    std::cout<<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<board[5]<<"  \n";
    std::cout<<"_____|_____|_____\n";
    std::cout<<"     |     |     \n";
    std::cout<<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<board[8]<<"  \n";
    std::cout<<"     |     |     \n";
    std::cout<<'\n';
}

/**
 * @brief Se ejecuta el turno del jugador correspondiente
 * 
 * @param player La simbolización del primer jugador
 * @param board Para rellenar el tablero propiamente creado
 * 
 * Esta función ejecuta el turno del jugador al que se llama
 */
void player_Turn(char player, char *board){
    int number;
    do{
    cout<<"Ingrese un numero (1-9)";
    cin>>number;
    number--;
    if(number >= 0 && number < 9 && board[number]== ' '){
    board[number] = player;
    break;
    }else{
        cout<<"Movimiento inválido, ingrese otro numero\n";
    }} while(!number >= 0 || !number < 9);
}

/**
 * @brief Se ejecuta el turno del ordenador
 * 
 * @param computer La simbolización del ordenador
 * @param board Para rellenar el tablero propiamente creado
 * 
 * Esta función ejecuta el turno del ordenador
 * 
 */
void computer_Turn(char computer, char *board){
int number;
srand(time(0));

while (true){
    number = rand() % 9;
    if (board[number] == ' '){
        board[number] = computer;
        break;
    }
    
}

}

/**
 * @brief Se verifica si se ha ganado la partida
 * 
 * @param player La simbolización del jugador
 * @param board El tablero de juego
 * 
 * @return true si se continua la partida, false en caso contrario
 * 
 * Esta función verifica si se ha ganado la partida, si ha perdido o
 * si se ha quedado empate en el modo solitario
 */
bool check_Play(char player, char *board){
    int wins[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for(auto&win : wins){
        if (board[win[0]] == player && board[win[1]] == player && board[win[2]] == player){
            cout << (player == player1 ? "GANASTE\n" : "PERDISTE\n");
            return true;
        }   
    }
    return false;
}

/**
 * @brief Se verifica el empate 
 * 
 * @param board El tablero de juego
 * 
 * @return true si se continua la partida, false en caso contrario
 * 
 * Esta función verifica si se ha conseguido un empate
 */
bool check_Tied_Play(char *board){
    for (int i = 0; i < 9; i++){
        if(board[i] == ' '){
            return false;
        }   
    }
    cout<<"Esto es un empate!\n";
    return true;
    
}
