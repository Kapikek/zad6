#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#include "student.h"


void menu() {
    cout << "\u001b[36m";
    cout << "(1) Wprowadz studentow recznie" << endl;
    cout << "(2) Wczytaj z pliku odczyt.txt" << endl;
    cout << "(3) Zapisz do pliku zapis.txt" << endl;
    cout << "(4) Wyswietl studentow" << endl;
    cout << "(5) Wyjdz z programu" << endl;
    cout << "\u001b[0m";
}

int main()
{

    int ex = 0;
    int option = 6;

    student st;
    vector<student> studenci;
    

    menu();

    while (option != 5) {
        cin >> option;
        if (option == 1) {

            cin >> st;
            studenci.push_back(st);
     
        }else
        if (option == 2) {
            ifstream file("odczyt.txt");
            while (file >> st)
            {
                studenci.push_back(st);
            }
            file.close();
            cout << "Wczytano z odczyt.txt" << endl;
        }else
        if (option == 3) {
            ofstream file2("zapis.txt");
            for (auto t : studenci) {
                file2 << t;
            }
            file2.close();
            cout << "Zapisano do zapis.txt" << endl;
        }else
        if (option == 4) {

                cout << "Liczba studentow " << count_if(studenci.begin(), studenci.end(), [=](student st) -> bool {return st.returnNr_Albumu(); }) << endl;
                for_each(studenci.begin(), studenci.end(), [](student st) {cout << st << endl; });
            
        }

        menu();
        

    }


}