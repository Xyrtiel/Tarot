#pragma once
#include "Joueur.h"
#include <vector>
enum contrat {passe , prise , garde, garde_sans , garde_contre};
enum poignee {Sans , Simple , Double ,Triple };
enum camp {personne , preneur , defenseur};
enum chelem {sans, reussi, perdu, sansAnnonce};

class CDonne
{
private:
	CJoueur *leDonneur;
	CJoueur *lePreneur;
	vector<CJoueur *>lesDefenseurs;
	contrat Contrat;
	int NbBouts;
	int NbPoints;
	int Points;
	poignee TypePoignee;
	camp CampPoignee;
	camp CampPetitAuBout;
	int PointsChelem;
	chelem Chelem;


public:
	CDonne(CJoueur *donneur);
	~CDonne(void);
	void DefinirPreneur(CJoueur * donneur,vector<CJoueur *>defensseurs,contrat); 
	void BilanPartie (int NbPoints, int NbBouts);
	camp Resultat();
	void DeclarationPoignee( poignee, camp = preneur);
	void DeclarationPetitAuBout( camp = preneur);
	void DeclarationPoignee( poignee, CJoueur);
	void DeclarationPetitAuBout( CJoueur);
	void DeclarationChelem (chelem,camp=preneur);
	void DeclarationChelem (chelem,CJoueur);
	int LirePoints();
	CJoueur LireDonneur();
	CJoueur LirePreneur();
	contrat LireContrat();
	vector<CJoueur> LireDefenseurs(); 
};

