#include "gameapps.h"

void displayMenu(listp &LP, listg &LG, List_R &LR) {
    cout << "=========Main menu=========\n";
    int tp ;
    int tg;

    tg = nListg(LG);
    tp = nListp(LP);

    cout << "Menu:\n";
    cout << "1. Add Game            || Total Game : "<< tg << endl;
    cout << "2. Add Player          || Total Player : "<< tp <<endl;
    cout << "3. Display Games\n";
    cout << "4. Display Players\n";
    cout << "5. Player's games\n";
    cout << "6. Delete\n";
    cout << "7. Display All Data\n";
    cout << "0. Exit\n";

    inputmainmenu(LP, LG, LR);
}

void inputmainmenu(listp &LP, listg &LG, List_R &LR){
    int inpt;
    cout << "Input :";
    cin >> inpt;
    cout << endl;
    if (inpt == 1){
        menu1(LP,LG,LR);
    }else if (inpt == 2){
        menu2(LP,LG,LR);
    }else if (inpt == 3){
        printInfog(LG);
        displayMenu(LP,LG,LR);
    }else if (inpt == 4){
        printInfop(LP);
        displayMenu(LP,LG,LR);
    }else if (inpt == 5){
        menu5(LP,LG,LR);
    }else if (inpt == 6){
        menu6(LP,LG,LR);
    }else if (inpt == 7){
        displayAllData(LG, LP, LR);
    }else if (inpt == 0){
        cout << "bye~"<< endl;
    }else{
        cout << "input tidak valid!" << endl;
        cout << "silahkan coba lagi!"<< endl;
        inputmainmenu(LP,LG,LR);
    }
}
void menu1(listp &LP, listg &LG, List_R &LR){
    cout << "===============================" << endl;
    cout << "        insert game" << endl;
    cout << "===============================" << endl;
    cout << "1. insert last" << endl;
    cout << "2. insert first" << endl;
    cout << "0. Back"<< endl;

    inputmenu1(LP,LG,LR);


}
void inputmenu1(listp &LP, listg &LG, List_R &LR) {
    int inpt;
    string judul;
    adrg G;

    cout << "input :";
    cin >> inpt;
    cout << endl;

    if (inpt == 1) {
        cout << "Judul Game :";
        cin.ignore();
        getline(cin, judul);
        cout << endl;

        G = allocateg(judul);
        insertLastg(LG, G);
        menu1(LP,LG,LR);
    } else if (inpt == 2) {
        cout << "Judul Game :";
        cin.ignore();
        getline(cin, judul);
        cout << endl;

        G = allocateg(judul);
        insertFirstg(LG, G);
        menu1(LP,LG,LR);
    } else if (inpt == 0) {
        displayMenu(LP, LG, LR);
    } else {
        cout << "Input tidak valid, silahkan coba lagi!" << endl;
        inputmenu1(LP, LG, LR);
    }

    displayMenu(LP, LG, LR);
}

void menu2(listp &LP,listg &LG, List_R &LR){
    cout << "===============================" << endl;
    cout << "        Insert player" << endl;
    cout << "===============================" << endl;
    cout << "1. yes" << endl;
    cout << "0. Back"<< endl;

    inputmenu2(LP,LG,LR);
}
void inputmenu2(listp &LP, listg &LG, List_R &LR) {
    int userid;
    string username;
    adrp P;

    int inpt;

    cout << "input :";
    cin >> inpt;
    cout << endl;

    if (inpt == 1) {
        cout << "User name :";
        cin >> username;
        cout << "User ID :";
        cin >> userid;
        cout << endl;

        P = allocatep(username, userid);
        insertLastp(LP, P);
        menu2(LP,LG,LR);
    } else if (inpt == 0) {
        displayMenu(LP, LG, LR);
    } else {
        cout << "Input tidak valid, silahkan coba lagi!" << endl;
        inputmenu2(LP, LG, LR);
    }
}


void menu5(listp &LP, listg &LG, List_R &LR){
    cout << "===============================" << endl;
    cout << "        Player's Game" << endl;
    cout << "===============================" << endl;
    cout << "1. add player game" << endl;
    cout << "2. show player game" << endl;
    cout << "0. Back"<< endl;

    inputmenu5(LP,LG,LR);
}
void inputmenu5(listp &LP, listg &LG, List_R &LR) {
    adrg g;
    adrp p;
    adr_Relasi R;
    int inpt;
    int id;
    string judul;

    cout << "input :";
    cin >> inpt;
    cout << endl;

    if (inpt == 1) {
        cout << "id player : ";
        cin >> id;
        cout << endl;

        p = searchp(LP, id);
        if (p == NULL) {
            cout << " Player Tidak ditemukan";
        }

        cout << "Judul : ";
        cin.ignore(); // Ignore any previous newline character
        getline(cin, judul); // Read the entire line, including spaces
        cout << endl;

        g = searchg(LG, judul);
        if (g == NULL) {
            cout << "Game tidak ditemukan";
        }

        R = alokasi(g, p);
        insertFirst_R(LR, R);

        displayMenu(LP, LG, LR);
    } else if (inpt == 2) {
        printRelasi(LR, LG, LP);
        displayMenu(LP, LG, LR);
    } else {
        cout << "input tidak valid! silahkan coba lagi" << endl;
        inputmenu5(LP, LG, LR);
    }
}

void menu6(listp &LP, listg &LG, List_R &LR){
    cout << "===============================" << endl;
    cout << "          Delete" << endl;
    cout << "===============================" << endl;
    cout << "1. Player" << endl;
    cout << "2. Game" << endl;
    cout << "0. Back"<< endl;

    inputmenu6(LP,LR,LG);
}

void inputmenu6(listp &LP, List_R &LR, listg &LG) {
    string judul;
    cout << "Masukkan Judul Game untuk Menghapus Pemain dan Relasinya: ";
    cin.ignore();
    getline(cin, judul);

    adrg parentGame = searchg(LG, judul);

    if (parentGame != NULL) {
        adrp playerToDelete = LP.first;

        while (playerToDelete != NULL) {
            adrp nextPlayer = next(playerToDelete);

            if (nextGame(playerToDelete) == parentGame) {
                deleteElementP(LR, playerToDelete); // Corrected type
            }

            playerToDelete = nextPlayer;
        }
    } else {
        cout << "Game dengan judul " << judul << " tidak ditemukan." << endl;
    }
}
