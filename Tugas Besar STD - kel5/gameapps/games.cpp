#include "gameapps.h"

//  Function Procedure List Game
bool isEmptyg(listg LG) {
    return (LG.first == NULL);
}

void createListg(listg &LG) {
    LG.first = NULL;
    LG.last = NULL;
}

adrg allocateg(string G) {
    adrg newNode = new elmg;
    info(newNode).judul = G;
    next(newNode) = NULL;
    return newNode;
}

void deallocateg(adrg G) {
    delete G;
}

void insertFirstg(listg &LG, adrg G){
    if (isEmptyg(LG)) {
        LG.first = G;
        LG.last = G;
    } else {
        next(G) = LG.first;
        LG.first = G;
    }
}

void insertLastg(listg &LG, adrg G) {
    if (isEmptyg(LG)) {
        LG.first = G;
        LG.last = G;
    } else {
        next(LG.last) = G;
        LG.last = G;
    }
}

void deleteFirstg(listg &LG, adrg &G) {
    if (!isEmptyg(LG)) {
        G = LG.first;
        if (LG.first == LG.last) {
            LG.first = NULL;
            LG.last = NULL;
        } else {
            LG.first = next(G);
            next(G) = NULL;
        }
        deallocateg(G);
    }
}

void printInfog(listg LG) {
    adrg G = LG.first;
    while (G != NULL) {
        // Tampilkan informasi game sesuai kebutuhan
        cout << "Game Judul: " << info(G).judul << endl;
        G = next(G);
    }
}

int nListg(listg LG) {
    int count = 0;
    adrg G = LG.first;
    while (G != NULL) {
        count++;
        G = next(G);
    }
    return count;
}

adrg searchg(listg LG, string x) {
    adrg P = first(LG);
    while (P != NULL) {
        if (info(P).judul == x) {
            return P;  // Elemen ditemukan
        }
        P = next(P);
    }
    return NULL;  // Elemen tidak ditemukan
}
