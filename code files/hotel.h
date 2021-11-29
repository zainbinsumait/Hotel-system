#ifndef HOTEL_H
#define HOTEL_H
#include <string>
#include "Room.h"
#include <vector>
#include <iostream>

namespace Hotel_system {
	class Hotel {
	public:
		Hotel();
		Hotel(long int id, std::string ville, std::string nom , std::vector<Room> list);
		long int getHid() const;
		std::string getVille() const;
		std::string getHnom() const;
		std::vector<Room> getList() const;
		void setVille(std::string ville);
		void setHnom(std::string nom);
		void setHid(long int id);
		//Question 4.b
		void addtoRoomlist(Room room);
		void setList(std::vector<Room> list);
		void hotelString();

	private:
		std::string _ville;
		std::string _nom;
		//on a choisit le long int au lieu de l'int pour permettre a saisir
		//les numeros qui commence par zero ou double zero 
		long int h_id;
		std::vector<Room> _list;
	};
	void operator<<(std::ostream&, Hotel&);
}
#endif