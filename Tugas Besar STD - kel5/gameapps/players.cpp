#include "gameapps.h"

// Function Procedure List Player
bool isEmptyp(listp LP) {
    return (first(LP) == NULL);
}

void createListp(listp &LP) {
    first(LP) = NULL;
    last(LP) = NULL;
}

adrp allocatep(string nick, int id) {
    adrp newNode = new elmp;
    info(newNode).userid = id;
    info(newNode).nickname = nick;
    next(newNode) = NULL;
    nextGame(newNode) = NULL;
    return newNode;
}

void deallocatep(adrp P) {
    delete P;
}
void insertFirstp(listp &LP, adrp P){
    if (isEmptyp(LP)) {
        first(LP) = P;
        last(LP) = P;
    } else {
        next(P) = first(LP);
        first(LP) = P;
    }
}

void insertLastp(listp &LP, adrp P) {
    if (isEmptyp(LP)) {
        first(LP) = P;
        last(LP) = P;
    } else {
        next(last(LP)) = P;
        last(LP) = P;
    }
}

void deleteFirstp(listp &LP) {
     adrp P;
    if (!isEmptyp(LP)) {
        P = first(LP);
        if (first(LP) == last(LP)) {
            first(LP) = NULL;
            last(LP) = NULL;
        } else {
            first(LP) = next(P);
            next(P) = NULL;
        }
        deallocatep(P);
    }
}

void deleteAfterp(listp &LP, adrp &P, int x){
    adrp prec;
    prec = first(LP);
    while (next(prec) != P){
        prec = next(prec);
    }
    next(prec) = next(P);
    next(P) = NULL;
    deallocatep(P);
}
void printInfop(listp LP) {
    adrp P = first(LP);
    while (P != NULL) {
        // Tampilkan informasi player sesuai kebutuhan
        cout << "Nickname: " << info(P).nickname << ", UserID: " << info(P).userid << endl;
        P = next(P);
    }
}

int nListp(listp LP) {
    int count = 0;
    adrp P = first(LP);
    while (P != NULL) {
        count++;
        P = next(P);
    }
    return count;
}

adrp searchp(listp LP, int x) {
    adrp P = first(LP);
    while (P != NULL) {
        if (info(P).userid == x) {
            return P;  // Elemen ditemukan
        }
        P = next(P);
    }
    return NULL;  // Elemen tidak ditemukan
}

