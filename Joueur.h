#pragma once
#include <iostream>
#include <string>
using namespace std;

class CJoueur
{
private:
	string Nom;
	int Score;
public:
	CJoueur();
	CJoueur(string , int = 0);
	CJoueur(char * , int = 0);
	~CJoueur(void);

	string LireNom();
	int LireScore();
	void MajScore(int );
};

