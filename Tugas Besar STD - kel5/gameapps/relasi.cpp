#include "gameapps.h"

void createList_R(List_R &L) {
    first(L) = NULL;
}

adr_Relasi alokasi(adrg P, adrp C) {
    adr_Relasi newNode = new ElmRelasi;
    parent(newNode) = P;
    child(newNode) = C;
    next(newNode) = NULL;
    prev(newNode) = NULL;
    return newNode;
}

void insertFirst_R(List_R &L, adr_Relasi P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void deleteElement(List_R &L, adr_Relasi &P) {
    if (P != NULL) {
        if (P == first(L)) {
            if (next(P) != NULL) {
                first(L) = next(P);
                prev(next(P)) = NULL;
            } else {
                first(L) = NULL;
            }
        } else {
            adr_Relasi Q = first(L);
            while (Q != NULL && Q != P) {
                Q = next(Q);
            }
            if (Q != NULL) {
                prev(next(Q)) = prev(Q);
                next(prev(Q)) = next(Q);
            }
        }
        delete P;
    }
}

void deleteElementP(List_R &L, adrp child) {
    adr_Relasi current = L.first;
    adr_Relasi prev = NULL;

    // Search for the element with the specified child
    while (current != NULL && child(current) != child) {
        prev = current;
        current = next(current);
    }

    // If found, delete the element
    if (current != NULL) {
        if (prev == NULL) {
            // The element is the first in the list
            L.first = next(current);
            if (L.first != NULL) {
                prev(L.first) = NULL;
            }
        } else {
            // The element is in the middle or the end of the list
            next(prev) = next(current);
            if (next(current) != NULL) {
                prev(next(current)) = prev;
            }
        }

        delete current;
    }
}

adr_Relasi findElement(List_R L, infotypeg px, infotypep cx) {
    adr_Relasi P = first(L);
    while (P != NULL) {
        if (info(child(P)).nickname == cx.nickname && info(parent(P)).judul == px.judul) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void connect(List_R &L, listg LG, listp LP, string px, int cx) {
    adrg G = searchg(LG, px);
    adrp P = searchp(LP, cx);
    if (G != NULL && P != NULL) {
        adr_Relasi R = alokasi(G, P);
        insertFirst_R(L, R);
    }
}

void disconnect(List_R &L, infotypeg px, infotypep cx) {
    adr_Relasi P = findElement(L, px, cx);
    deleteElement(L, P);
}

int countPlayersForGame(List_R &LR, adrg parentGame) {
    int count = 0;
    adr_Relasi current = LR.first;

    while (current != NULL) {
        if (parent(current) == parentGame) {
            count++;
        }
        current = next(current);
    }

    return count;
}


void printRelasi(List_R LR, listg LG, listp LP) {
    adr_Relasi P = first(LR);

    while (P != NULL) {
        adrg gameNode = parent(P);
        adrp playerNode = child(P);

        cout << "Judul game: " << info(gameNode).judul << ", Player: ";

        while (playerNode != NULL) {
            cout << info(playerNode).nickname;
            playerNode = next(playerNode);

            if (playerNode != NULL) {
                cout << ", ";
            }
        }

        cout << endl;

        P = next(P);
    }
}

void displayAllData(listg &LG, listp &LP, List_R &LR) {
    adrg currentGame = LG.first;

    while (currentGame != NULL) {
        cout << "Judul game: " << info(currentGame).judul << endl;

        // Count the number of players for the current game
        int playerCount = countPlayersForGame(LR, currentGame);

        cout << "Jumlah pemain: " << playerCount << endl;
        cout << "List pemain:" << endl;

        adr_Relasi currentRelasi = LR.first;
        int playerNumber = 1;

        while (currentRelasi != NULL) {
            if (parent(currentRelasi) == currentGame) {
                cout << playerNumber << ". " << info(child(currentRelasi)).nickname << endl;
                playerNumber++;
            }

            currentRelasi = next(currentRelasi);
        }

        cout << endl;

        currentGame = next(currentGame);
    }
}

