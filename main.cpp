/*
************************************************************
*                                                          *
*                 HANGMAN GAME BY ROSTA                    *
*                                                          *
************************************************************
 */

#include <iostream>
#include <string>
#include <cstring>                  //na pouziti strlen
using namespace std;
char hledaneSlovo[] = "lednice";    //hledane slovo
int zivoty = 5;                     //nastaveni poctu zivotu
char pismeno;                       //pismeno nactene z klavesnice
bool game = true;                   //podminka pro while cyklus
bool podminka;                      //podminka pro odecitani zivotu

void vykresli(char x[], char y[]){                  //vykraslovaci funkce
        cout << "** HANGMAN **" << endl;
        cout << "*************" << endl;
        for (unsigned i = 0; i < strlen(x); i++){
          cout << y[i];
        }
        cout << endl;
        cout << "*************" << endl;
}

int main(){
    char odkryvaneSlovo[strlen(hledaneSlovo)+1];
    for (unsigned i = 0; i < strlen(hledaneSlovo); i++){    //priprava prazdneho slova
        odkryvaneSlovo[i] = '_';
    }
    system("cls");
    vykresli(hledaneSlovo,odkryvaneSlovo);
    while(game){
        unsigned end_game = 0;                              //int pro vyhodnoceni dohrani hry
        podminka = true;
        cout << "Zadej pismeno: ";
        cin >> pismeno;
        system("cls");
        for (unsigned i = 0; i < strlen(hledaneSlovo); i++){    //loop na overeni, zda tam to pismeno je
        if(hledaneSlovo[i] == pismeno){
            odkryvaneSlovo[i] = pismeno;
            podminka = false;
        }
        }
        vykresli(hledaneSlovo,odkryvaneSlovo);
        if(podminka == true){
            zivoty = zivoty - 1;
            cout << "Spatna volba, zvol dalsi. Zbyvajici pocet zivotu: " << zivoty << endl; 
        }else{
            cout << "Spravne zvolene pismeno! Pokracuj!" << endl;
        }
        for (unsigned i = 0; i < strlen(hledaneSlovo); i++){    
        if(hledaneSlovo[i] == odkryvaneSlovo[i]){
            end_game = end_game + 1;
        }}
        if(end_game == strlen(odkryvaneSlovo)){
           game = false;
           cout << "Gratuluji, vyhral si!" << endl;
       }
        if(zivoty == 0){
            game = false;
            cout << "Smolik, prohral jsi." << endl;
        }
    }   
    system("pause");
    
    return 0;
}