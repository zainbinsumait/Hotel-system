#ifndef SYSTEM_H
#define SYSTEM_H
#include "client.h"
#include "room.h"
#include "hotel.h"
#include "date.h"
#include "reservation.h"
#include <iostream>
#include <vector>
#include<algorithm>
namespace Hotel_system {
	class System {
	public:
		//la fonction principale pour le system
		void system();

		// la fonction qui prend en parametre la date de fin et la date de debut pour afficher le nombre de nuit entre ces deux dates
		void nombreNuits(date::Date fin, date::Date debut);

		// la fonction qui permet de saisir au clavier la date de debut et de fin en les passant par la fonction checkDate
		void checkFinDate();
		void checkDebutDate();

		//qeustion 8.b
		//la fonction qui verifier l'existance de chambre du type selectionne 
		//elle return true s'elle existe en la mettant dans room_selectionne  sinon il return un false
		bool chambreDispo(Typeroom type);

		// la fonction getter de la liste des chambres de l'hotel selectionne
		std::vector<Room> getRlist();

		// la fonction getter de la liste des clients dans l'hotel selectionne
		std::vector<Client> getClist();

		// la fonction setter de la liste des clients dans l'hotel selectionne
		void setClientlist(std::vector<Client> list);

		// la fonction setter de l'hotel selectionne
		void setHotel(Hotel);

		//la fonction qui prend en parametre un string et elle return un typeroom
		//elle return le type unknown si le string ne correspond pas a un typeroom des trois ( Single, Double , Suit)
		Typeroom stringtoType(std::string type);

		// une fonction qui trie la liste des chambres en mettant les numeros des chambres Singles dans le vecteur single_room,
		//les numeros des chambres Doubles dans le vecteur double_room .. etc
		void getRpositions();

		//la fonction qui prend en parametre un nombre et return la chambre (de la liste) possedant ce nombre 
		Room getRoom(int roomnmbr);

		//la fonction qui indique a l'utilisateur que la date de fin choisie n'est pas valide
		//et qui lui demande sois de choisir une autre date de fin ou deresaisir la date de debut
		void sidateFininvalide();

		//la fonction qui prend en parametre le nom d'un clientet qui return les nombres de clients dans la listes ayant ce nom
		int clientsPotentiels(std::string name);

		//la fonction qui prend en parametre l'identifiant d'un client et elle return ce client
		Client getClient(int clientnbr);

		//la fonction qui permet d'ajouter la nouvelle reservation a la liste des reservations (_booking)
		void newBooking();

		//la fonction qui permet d'ajouter un nouveau client (dont l'information sera saissite par l'utilisateur) a la liste des reservations (_booking)
		//et on le mettant en plus dans le variable client_selectionne
		void newClient();

		//Question 11.a afficher toutes les reservations en cours
		void affichReservation();

		//Question 11.b afficher la reservation numero 
		void affichReservationnbr(int nbr_reservation);

		//Question 11.c afficher toutes les reservations d'un client par son id ou son nom
		void affichReservationClient(int Id_client);
		void affichReservationClient(std::string nom_client);

		//Q 11.e annuler une reservation
		void annulerReservation(int ID);


	private:
		date::Date _fin;
		date::Date _debut;
		std::vector<Booking> _booking;
		std::vector<Room> R_list;
		std::vector<Client> C_list;

		std::vector<int> single_room;
		std::vector<int> double_room;
		std::vector<int> suit_room;
		Typeroom room_typeselectionne;
		std::string nom_clientchoisit;
		Room room_selectionne;
		Client client_selectionne;
		Hotel hotel_selectionne;
		
	};
}



#endif // !SYSTEM_H


