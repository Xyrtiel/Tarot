#include "Donne.h"

camp CDonne::Resultat()
{
	camp resultat = personne;
	int score_preneur = 0;
	int score_defenseur = 0;
	int multiplicateur_petit_au_bout = 1;

	// Analyse des Bouts et des Points :
	// -----------------------------------------
	if (NbPoints >= 56 && NbBouts == 0) // Si pas de bouts et 56 points
	{
		score_preneur += ((25 + (NbPoints - 56)) * 3);
		score_defenseur -= (25 + (NbPoints - 56));
		camp resultat = preneur;
	}
	if (NbPoints >= 51 && NbBouts == 1) // Si 1 bout et 51 points
	{
		score_preneur += ((25 + (NbPoints - 51)) * 3);
		score_defenseur -= (25 + (NbPoints - 51));
		camp resultat = preneur;
	}
	if (NbPoints >= 41 && NbBouts == 2) // Si 2 bouts et 41 points
	{
		score_preneur += ((25 + (NbPoints - 41)) * 3);
		score_defenseur -= (25 + (NbPoints - 41));
		camp resultat = preneur;
	}
	if (NbPoints >= 36 && NbBouts == 3) // Si 3 bouts et 36 points
	{
		score_preneur -= ((25 + (NbPoints - 36)) * 3);
		score_defenseur += (25 + (NbPoints - 36));
		camp resultat = preneur;
	}

	if (NbPoints < 56 && NbBouts == 0) // Si pas de bouts et 56 points
	{
		score_preneur -= ((25 + (NbPoints - 56)));
		score_defenseur += (25 + (NbPoints - 56));
		camp resultat = defenseur;
	}
	if (NbPoints < 51 && NbBouts == 1) // Si 1 bout et 51 points
	{
		score_preneur -= ((25 + (NbPoints - 51)));
		score_defenseur += (25 + (NbPoints - 51));
		camp resultat = defenseur;
	}
	if (NbPoints < 41 && NbBouts == 2) // Si 2 bouts et 41 points
	{
		score_preneur -= ((25 + (NbPoints - 41)));
		score_defenseur += (25 + (NbPoints - 41));
		camp resultat = defenseur;
	}
	if (NbPoints < 36 && NbBouts == 3) // Si 3 bouts et 36 points
	{
		score_preneur -= ((25 + (NbPoints - 36)));
		score_defenseur += (25 + (NbPoints - 36));
		camp resultat = defenseur;
	}

	// -----------------------------------------
	// Type de Contrat à analyser : 
	// -----------------------------------------

	if(Contrat == garde_contre)
	{
		score_preneur = score_preneur * 6;
		score_defenseur = score_defenseur * 6;
		multiplicateur_petit_au_bout = 6;
	}
	if(Contrat == garde_sans)
	{
		score_preneur = score_preneur * 4;
		score_defenseur = score_defenseur * 4;
		multiplicateur_petit_au_bout = 4;
	}
	if(Contrat == garde)
	{
		score_preneur = score_preneur * 2;
		score_defenseur = score_defenseur * 2;
		multiplicateur_petit_au_bout = 2;
	}

	Points = -score_defenseur;

	// -----------------------------------------
	// Poignée : 
	// -----------------------------------------

	if (TypePoignee == Simple && CampPoignee == preneur)
	{
		score_preneur += (20*3);
		score_defenseur -= 20;
	}
	if (TypePoignee == Simple && CampPoignee == defenseur)
	{
		score_preneur -= 20;
		score_defenseur += 20;
	}
	if (TypePoignee == Double && CampPoignee == preneur)
	{
		score_preneur += (30 * 3);
		score_defenseur -= 30;
	}
	if (TypePoignee == Double && CampPoignee == defenseur)
	{
		score_preneur -= 30;
		score_defenseur -= 30;
	}
	if (TypePoignee == Triple && CampPoignee == preneur)
	{
		score_preneur += (40 * 3);
		score_defenseur -= 40;
	}
	if (TypePoignee == Triple && CampPoignee == defenseur)
	{
		score_preneur -= 40;
		score_defenseur += 40;
	}

	// -----------------------------------------
	// Petit au Bout :
	// -----------------------------------------

	if (CampPetitAuBout == preneur)
	{
		score_preneur += ((10 * multiplicateur_petit_au_bout)*3);
		score_defenseur -= (10 * multiplicateur_petit_au_bout);
	}
	if (CampPetitAuBout == defenseur)
	{
		score_preneur -= (10 * multiplicateur_petit_au_bout);
		score_defenseur += (10 * multiplicateur_petit_au_bout);
	}

	// -----------------------------------------
	// Chelem :
	// -----------------------------------------

	score_preneur = score_preneur + (PointsChelem*3);
	score_defenseur = score_defenseur - PointsChelem;

	// -----------------------------------------
	// Ajout des Points : 
	// -----------------------------------------

	lePreneur->MajScore(score_preneur);
	for (int i = 0; i < 3; i++)
	{
		lesDefenseurs[i]->MajScore(score_defenseur);
	}

	return resultat;
}



