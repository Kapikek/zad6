#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>

using namespace std;
class student
{
private:
	string nazwisko;
	string imie;
	int nr_albumu = int(5);
	string grupa;
	int rok;

public:

	int returnNr_Albumu() {
		return nr_albumu;
	}


	friend ostream& operator << (ostream& os, student& st_out) {
		cout << "\u001b[33m";
		os << st_out.nazwisko << " " << st_out.imie << " " << st_out.nr_albumu << " " << st_out.grupa << " " << st_out.rok << endl;
		cout << "\u001b[0m";
		return os;
	}
	friend ofstream& operator << (ofstream& ofs, student& st_out) {
		ofs << st_out.nazwisko << " " << st_out.imie << " " << st_out.nr_albumu << " " << st_out.grupa << " " << st_out.rok << endl;
		return ofs;
	}
	friend istream& operator >> (istream& is, student& st_in) {
		cout << "Nazwisko: " << endl;
		is >> st_in.nazwisko;
		cout << "Imie: " << endl;
		is >> st_in.imie;
		cout << "Nr. Albumu: " << endl;
		is >> st_in.nr_albumu;
		cout << "Grupa: " << endl;
		is >> st_in.grupa;
		cout << "Rok: " << endl;
		is >> st_in.rok;
		cout << endl;
		return is;
	}
	friend ifstream& operator >> (ifstream& ifs, student& st_in) {
		ifs >> st_in.nazwisko >> st_in.imie >> st_in.nr_albumu >> st_in.grupa >> st_in.rok;
		return ifs;
	}
	void operator () (student& st) {
		cout << st;
	}
};