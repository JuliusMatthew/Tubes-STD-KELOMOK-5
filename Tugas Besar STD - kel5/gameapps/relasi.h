#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
//#include <iostream>
#include "gameapps.h"
//using namespace std;
#define parent(p) p->parent
#define child(p) p->child
#define prev(p) p->prev

typedef struct ElmRelasi *adr_Relasi;
struct ElmRelasi {
    adrg parent;
    adrp child;
    adr_Relasi next;
    adr_Relasi prev;
};

struct List_R {
    adr_Relasi first;
};

// Relasi
void createList_R(List_R &L);
adr_Relasi alokasi(adrg P, adrp C);
void insertFirst_R(List_R &L, adr_Relasi P);
void deleteElement(List_R &L, adr_Relasi &P);
void deleteElementP(List_R &L, adrp child);

adr_Relasi findElement(List_R L, infotypeg px, infotypep cx);

void connect(List_R &L, listg LK, listp LP, infotypeg px, infotypep cx);
void disconnect(List_R &L, infotypeg px, infotypep cx);

int HitungJumlahPlayerPadaGame(List_R LR, listg LG, adrg currentGame)

void printRelasi(List_R LR, listg LG, listp LP);
void displayAllData(listg &LG, listp &LP, List_R &LR);
#endif // RELASI_H_INCLUDED
