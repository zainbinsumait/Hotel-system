#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "date.h"
#include "client.h"
#include "hotel.h"
#include "Room.h"

namespace Hotel_system {
	class Booking {
	public:
		Booking(int bid, date::Date debut, date::Date fin, Hotel A, Client client, Room room);
		//identifiant de la reservation(booking)
		int getBid() const;
		date::Date getDatedebut() const;
		date::Date getDatefin() const;
		//identifiant de l'hotel
		long int getHid() const;
		int getCid() const;
		int getRid() const;
		double getTotalprice() const;
		//question 5.b)
		void setDate(date::Date debut, date::Date fin);
		void affichageBooking();
		//question 5.c)
		void setRoomnumber(int rid);
		//la fonction qui return true si les dates en parametres et les dates de variables membres ont une periode commun
		//false sinon
		bool dateInclude(date::Date debut, date::Date fin);
		//5.d) pour calculer le prix total et faire la reduction de fidélité
		void totalPrice();

	private:
		date::Date date_debut;
		date::Date date_fin;
		int booking_id; 
		double prix_totale;
		Client _client;
		Hotel _hotel;
		Room _room;


	};
}
#endif // !RESERVATION_H

