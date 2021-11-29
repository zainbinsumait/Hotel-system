#include "hotel.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

namespace Hotel_system {
	//constructeur par defaut vide pour seulement permettre de creer un objet et l'initialiser apres
	Hotel::Hotel():h_id(0)
	{
	}
	Hotel::Hotel::Hotel(long int id, std::string ville, std::string nom, std::vector<Room> list) :
		h_id(id), _ville(ville), _nom(nom), _list(list) {}

	long int Hotel::Hotel::getHid() const
	{
		return h_id;
	}

	

	std::string Hotel::Hotel::getVille() const
	{
		return _ville;
	}

	std::string Hotel::Hotel::getHnom() const
	{
		return _nom;
	}

	std::vector<Room> Hotel::Hotel::getList() const
	{
		return _list;
	}
	void Hotel::setVille(std::string ville)
	{
		_ville = ville;
	}
	void Hotel::setHnom(std::string nom)
	{
		_nom = nom;
	}
	void Hotel::setHid(long int id)
	{
		h_id = id;
	}
	void Hotel::addtoRoomlist(Room room)
	{
		_list.push_back(room);
	}
	void Hotel::setList(std::vector<Room> list)
	{
		_list = list;
	}
	void Hotel::hotelString()
	{
		std::cout << "Hotel info :\n Nom de l'hotel: " << _nom << "\t La ville:  " << _ville
			<< "\t L'identifiant: " << h_id << std::endl;
	}

	//afficher toutes les informations de l'hotel en triant la liste des chambres par ordre croissant de leurs nombres
	void operator<<(std::ostream& os, Hotel& hotel)
	{
		std::string list;
		int i = 0;
		
		os << "Hotel info :\n Nom de l'hotel: " << hotel.getHnom() << "\t La ville:  " << hotel.getVille()
			<< "\t L'identifiant: " << hotel.getHid() << "\n Room list :\n";
		while (i < hotel.getList().size()) {
			for (int l = 0; l < hotel.getList().size() ; l++) {
				if (hotel.getList().at(l).getRoomNomber() == i + 1) {
					os << std::setprecision(3) << hotel.getList().at(l).roomtoString();
					i++;
				}	
			}	
		}
	}
}