#pragma once
#include <vector>
#include <iostream>
#include "Joueur.h"
#include "Donne.h"
using namespace std;

class CPartie
{
private:
	vector <CJoueur *> lesJoueurs;
	vector <CDonne> lesDonnes;


public:
	CPartie(vector <CJoueur > );
	CPartie(vector <CJoueur * > );
	~CPartie(void);

	string NouvelleDonne();
	void DefPreneur( CJoueur & , contrat);
	void DefPreneur (string , contrat);
	void MajPoints ( int ,int);
	void AnnoncePetit(camp=preneur);
	void AnnoncePoignee(poignee,camp=preneur);
	void AnnoncePetit(CJoueur);
	void AnnoncePoignee(poignee,CJoueur);
	void AnnonceChelem(chelem = reussi,camp=preneur);
	void AnnonceChelem(chelem ,CJoueur);
	void CalculerDonne();

	CDonne LireDerniereDonne(); 
	vector <CDonne> LireDonnes();
	vector <CJoueur> LireJoueurs();
};

