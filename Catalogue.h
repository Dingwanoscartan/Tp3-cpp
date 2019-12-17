/*************************************************************************
Catalogue  -  description
-------------------
debut                : 20/11
copyright            : (C) 2019 par Muye HE, Tuoyuan TAN
e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( Catalogue_H )
#define Catalogue_H
//--------------------------------------------------- Interfaces utilisees
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <cstring>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Permet de stocker un ensemble de trajets, d'en ajouter, de les afficher ou d'effectuer une recherche
//----
class Catalogue{

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Methodes publiques
public:
	Catalogue();
	// Mode d'emploi :
	// constructeur de Catalogue par defaut
	//


	~Catalogue();
	// Mode d'emploi :
	// destructeur de Catalogue
	//

	void Afficher();
	// Mode d'emploi :
	// methode pour afficher tous les Trajet stocke dans la Catalogue et qui appele les methode afficher 
	//de chaque type de Trajet
	//

	void Chercher(char * Depart, char * Arrivee);
	// Mode d'emploi :
	// methode qui cherche les trajet correpondant a la demand de l'utilisateur
	// elle chercher simplement les trajets dont le depart et la arrivee sont les memes que 
	// ceux qui en parametres


	void ChercherAvancee(char * Depart, char * Arrivee);
	// Mode d'emploi :
	// methode de chercher qui peux combiner plusieurs Trajet pour essayer d'obtenir un nouveau
	// Trajet correspondant a nos besoin
	//
	
	void AjouterC(TrajetCompose* t);
	// Mode d'emploi :
	// methode qui ajoute les TrajetCompose dans la catalogue	
	//

	void AjouterS(TrajetSimple* t);
	// Mode d'emploi :
	// methode qui ajoute les TrajetSimple dans la catalogue	
	//

//---------------------------------------------------- Attributs publiques
public:
	Trajet** Trajets = new Trajet* [5];  // Nombre de Trajets maximum stockes dans le catalogue. Ce maximum peut etre change eventuellement
	int Nbtraj = 0; // Nombre de Trajets actuellement stockes dans le catalogue
	


				 
//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Methodes protected

private:
//------------------------------------------------------- Methodes prives
	void ChercherCorres(char* Depart, char* Arrivee, int* tab, int nbr, int* found);
	// Mode d'emploi :
	// methode recursive faisant partie de la recherche de version avance
	// Un algorithme DFS (Depth-First-Search) qui parcourt les Trajets et affiche les solutions qu'il trouve 
	// Contrat : utiliser dans la fonction ChercherAvancee
	//

protected:
//----------------------------------------------------- Attributs protected

private:
//------------------------------------------------------- Attributs prives
	int Max = 5; //Nombre maximum des trajets stocke dans la catalogue

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes prives

//----------------------------------------------------------- Types prives
};
//----------------------------------------- Types dependants de <Catalogue.h>
#endif // Catalogue_H