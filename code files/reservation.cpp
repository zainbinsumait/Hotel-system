#include "reservation.h"
#include "hotel.h"
#include "date.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

namespace Hotel_system {
	Booking::Booking(int bid, date::Date debut, date::Date fin,
		Hotel hotel, Client client, Room room) :booking_id(bid), date_debut(debut),
		date_fin(fin), _hotel(hotel),_room(room),_client(client),prix_totale((fin-debut)* room.getRoomPrice()){
		
	}
	int Booking::getBid() const
	{
		return booking_id;
	}
	date::Date Booking::getDatedebut() const
	{
		return date_debut;
	}
	date::Date Booking::getDatefin() const
	{
		return date_fin;
	}
	long int Booking::getHid() const
	{
		return _hotel.getHid();
	}
	int Booking::getCid() const
	{
		return _client.getId();
	}
	int Booking::getRid() const
	{
		return _room.getRoomNomber();
	}
	double Booking::getTotalprice() const
	{
		return prix_totale;
	}
	void Booking::setDate(date::Date debut, date::Date fin)
	{
		date_debut = debut;
		date_fin = fin;
	}
	void Booking::affichageBooking()
	{
		std::cout << "Booking info :\n Booking number: "
			<< booking_id << "\t Date de debut: " << date_debut.date::Date::toString() << "\t Date de fin : " <<
			date_fin.date::Date::toString() << "\t nom de l'hotel: " << _hotel.getHnom() << "\n Id client: " << _client.getId() <<"\t Nom du client :  "<<_client.getNom() << "\t numero de chambre : " << _room.getRoomNomber()
			<< " \t Le montant totale: " << prix_totale <<"$"<< std::endl;
	}
	void Booking::setRoomnumber(int rid)
	{ 
		_room.updateRnomber(rid);
	}
	bool Booking::dateInclude(date::Date debut, date::Date fin)
	{
		if (debut < date_fin && fin > date_debut) {
			return true;
		}
		else {
			return false;
		}
		
	}
	void Booking::totalPrice()
	{
		int nuit = date_fin - date_debut;
		prix_totale = nuit*_room.getRoomPrice();

		if (_client.getNombreReserv() > 0) {
			prix_totale = prix_totale - (prix_totale * 10 / 100);
			std::cout << "Super, vous beneficiez de 10% de reduction\n";
			std::cout << "le prix total apres la reduction est :\t" << prix_totale << "$\n";
			std::cout << "\n";
		}
		
	}
}