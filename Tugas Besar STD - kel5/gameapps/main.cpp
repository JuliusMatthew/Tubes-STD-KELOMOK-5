#include "gameapps.h"

int main(){
    listp LP;
    listg LG;
    List_R LR;

    adrg ADRG;
    adrp ADRP;

    createListg (LG);
    createListp (LP);
    createList_R (LR);


    cout << "Kelompok 5 - Data game apps - player" << endl;
    cout << "Julius Matthew - 1303223010" << endl;
    cout << "Muhamad Rizki Ilahi - 1303220094" << endl;
    cout << "======***======" << endl;
    cout << "START THE GAME" << endl;
    cout << "======***======" << endl;
    displayMenu(LP,LG,LR);

    return 0;
}
