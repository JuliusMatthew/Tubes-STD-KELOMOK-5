#ifndef GAMEAPPS_H_INCLUDED
#define GAMEAPPS_H_INCLUDED
#include <iostream>
//#include "relasi.h"
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define nextGame(P) (P)->nextGame
#define first(L) (L).first
#define last(L) (L).last

#define parent(p) p->parent
#define child(p) p->child
#define prev(p) p->prev

struct infotypeg {
    string judul;
};

struct infotypep {
    string nickname;
    int userid;
};

typedef struct elmp *adrp;   // buat address player
typedef struct elmg *adrg;   // buat address game

struct elmg {
    infotypeg info;
    adrg next;
};

struct listg {
    adrg first;
    adrg last;
};

struct elmp {
    infotypep info;
    adrg nextGame;
    adrp next;
};

struct listp {
    adrp first;
    adrp last;
};

// relasi

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


// Function Procedure List Game
bool isEmptyg(listg LG);
void createListg(listg &LG);
adrg allocateg(string G);
void deallocateg(infotypeg G);
void insertFirstg(listg &LG, adrg G);
void insertLastg(listg &LG, adrg G);
void deleteFirstg(listg &LG, adrg &G);
void deleteAfterg(listg &LG, adrg &G, string x);
void printInfog(listg LG);
int nListg(listg LG);
adrg searchg(listg LG, string x);

// Function Procedure List Player
bool isEmptyp(listp LP);
void createListp(listp &LP);
adrp allocatep(string nick, int id);
void deallocatep(adrp P);
void insertFirstp(listp &LP, adrp P);
void insertLastp(listp &LP, adrp P);
void deleteFirstp(listp &LP);
void deleteAfterp(listp &LP, adrp &P,int x);
void printInfop(listp LP);
int nListp(listp LP);
adrp searchp(listp LP, int x);

//MENU
void displayMenu(listp &LP, listg &LG, List_R &LR);
void inputmainmenu(listp &LP, listg &LG, List_R &LR);
void menu1(listp &LP, listg &LG, List_R &LR);
void inputmenu1(listp &LP, listg &LG, List_R &LR);
void menu2(listp &LP, listg &LG, List_R &LR);
void inputmenu2(listp &LP, listg &LG, List_R &LR);
void menu5(listp &LP, listg &LG, List_R &LR);
void inputmenu5(listp &LP, listg &LG, List_R &LR);
void menu6(listp &LP, listg &LG, List_R &LR);
void inputmenu6(listp &LP, List_R &LR, listg &LG);


// Relasi
void createList_R(List_R &L);
adr_Relasi alokasi(adrg P, adrp C);
void insertFirst_R(List_R &L, adr_Relasi P);
void deleteElement(List_R &L, adr_Relasi &P);
void deleteElementP(List_R &L, adrp child);

adr_Relasi findElement(List_R L, infotypeg px, infotypep cx);

void connect(List_R &L, listg LK, listp LP, infotypeg px, infotypep cx);
void disconnect(List_R &L, infotypeg px, infotypep cx);

int HitungJumlahPlayerPadaGame(List_R LR, listg LG, adrg currentGame);

void printRelasi(List_R LR, listg LG, listp LP);
void displayAllData(listg &LG, listp &LP, List_R &LR);

#endif // GAMEAPPS_H_INCLUDED
