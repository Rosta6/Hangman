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
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>      /* printf, NULL */
using namespace std;
int zivoty = 5;                     //nastaveni poctu zivotu
char pismeno;                       //pismeno nactene z klavesnice
bool game = true;                   //podminka pro while cyklus
bool podminka;                      //podminka pro odecitani zivotu
string arr_slova[10];
int vstup;

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
    start:srand (time(NULL));
    zivoty = 5;
    int n = rand()%10 + 1;
    ifstream file("slova.txt");
    if(file.is_open())
    {

        for(int i = 0; i < 10; i++)
        {
            file >> arr_slova[i];
        }
    }
    string vybraneSlovo = arr_slova[n];
    char hledaneSlovo[vybraneSlovo.length()];
    strcpy(hledaneSlovo, vybraneSlovo.c_str()); 
   
    char odkryvaneSlovo[strlen(hledaneSlovo)];
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
        if(end_game == vybraneSlovo.length()){
           cout << "Gratuluji, vyhral si!" << endl;
           cout << "Chces hrat znovu? \n(1) Ano\n(2) Ne"<< endl;
           cin >> vstup;
           switch (vstup)
           {
            case 1:
               system("cls");
               goto start;  
            break;
            case 2:
                game = false;
            break;
           
           default:
               game = false;
               break;
           }
       }
        if(zivoty == 0){
            cout << "Smolik, prohral jsi." << endl;
            cout << "Chces hrat znovu? \n(1) Ano\n(2) Ne"<< endl;
           cin >> vstup;
           switch (vstup)
           {
            case 1:
               system("cls");
               goto start;  
            break;
            case 2:
                game = false;
            break;
           
           default:
               game = false;
               break;
           }
        }
    }   
    
    return 0;
}