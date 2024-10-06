#include <iostream>

using namespace std;

#define SIZE 9
#define CERCHIO 'O'
#define CROCE 'X'

void printBoard();

void printBoard(char screen[], int size){
    cout << endl;
    for (int i = 0; i < 5; i++){
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < size; i++){
        cout << screen[i] << " ";
        if (i == 2 || i == 5) cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 5; i++){
        cout << "-";
    }
    cout << endl;
}

int ask(char screen[]){
    int id;
    cout << "Inserisci il numero" << endl;
    cin >> id;
    if (screen[id] == CERCHIO || screen[id] == CROCE){
        cout << "Casella occupata" << endl;
        return ask(screen);
    }
    return id;
}
bool checkWin(char screen[]){
    if (screen[0] == screen[1] && screen[1] == screen[2] || screen[3] == screen[4] && screen[4] == screen[5] || screen[6] == screen[7] && screen[7] == screen[8] ) return true;
    if (screen[0] == screen[4] && screen[4] == screen[8] || screen[2] == screen[4] && screen[4] == screen[6] ) return true;
    if (screen[0] == screen[3] && screen[3] == screen[6] || screen[1] == screen[4] && screen[4] == screen[7] || screen[2] == screen[5] && screen[5] == screen[8] ) return true;
    return false;
}

bool checkDraw(char screen[]){
    int a = 0;
    for (int i = 0; i < sizeof(screen) / sizeof(screen[0]); i++){
        if (screen[i] == CERCHIO || screen[i] == CROCE) {
            a++;
        }
    }
    cout << a << endl;
    return a == 8;
}

int main() { 
    bool finish = false;
    char turno = CERCHIO;
    int id;
    char screen[SIZE];

    for (int i = 0; i < SIZE; i++){
        screen[i] = i + '0';
    }

    while (!finish){
        printBoard(screen, sizeof(screen) / sizeof(screen[0]));

        int id = ask(screen);

        screen[id] = turno;

        finish = checkWin(screen);

        if (finish){
            cout << "Ha vinto il giocatore " << turno << endl;
        } else if (checkDraw(screen)) {
            cout << "Pareggio!" << endl;
            finish = true;
        } else {
            if (turno == CERCHIO){
                turno = CROCE;
            } else {
                turno = CERCHIO;
            }
            cout << "Turno del giocatore " << turno << endl;
        }
    }
    return 0;
}