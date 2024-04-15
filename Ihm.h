#pragma once
#include "joueur.h"
#include "Partie.h"

#include <iostream>
//#include <iomanip>
#include <string>

using namespace std;

class CIhm
{
private :
	vector <CJoueur > lesJoueurs;
	CPartie * laPartie;

	

public:
	CIhm(void);
	~CIhm(void);
	void SaisirJoueurs(); 
	void Jouer();
	void NouvelleDonne();
	bool SaisirPrise();
	void SaisirResultats();
	CJoueur ChoixJoueur(string);
	void AfficherJoueurs();
	void AfficherResultatDonnes();
	void AfficherResultatDerniereDonne();
	void AfficherResultatJoueurs();
};

