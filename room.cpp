#include "room.h"
#include <iostream>
#include <iomanip> //pour limiter le nombre apres la vigule  std::setprecision

namespace Hotel_system {
    //constructeur
    Room::Room(int nbr, Typeroom typeroom, double price) : room_nomber(nbr), room_type(typeroom), room_price(price) {}
    int Room::getRoomNomber() const {
        return room_nomber;
    }
    double Room::getRoomPrice() const {
        return room_price;
    }
    Typeroom Room::getRoomType() const {
        return room_type;
    }
    void Room::roomString() {
        std::cout << "Room info :\t Room nomber : " << room_nomber << "\t Room type : " << room_type << "\t Room price : "<<std::setprecision(4) << room_price << " $" << std::endl;
    }
    std::string Room::roomtoString()
    {
        //une manière pour convertir en string un double en limitant les nombres après la virgule
        std::string price = std::to_string(room_price);
        std::string info = "Room info :\t Room nomber : " + std::to_string(room_nomber)
            + "\t Room type : " + std::to_string(room_type) + "\t Room price per night : " + price.substr(0, price.find(".") + 3) + " $\n";
        return info;
    }
    void Room::updateRnomber(int roomnmbr) {
        room_nomber = roomnmbr;
    }
    void Room::updateRtype(Typeroom roomtype) {
        room_type = roomtype;
    }
    void Room::updateRprice(double roomprice) {
        room_price = roomprice;
    }
    void Room::updateRoom(int rn, Typeroom rt, double rp) {
        updateRprice(rp);
        updateRtype(rt);
        updateRnomber(rn);
    }

    void operator<<(std::ostream& os, Room& room)
    {
        os << "Room info :\t Room nomber : " << room.getRoomNomber() << "\t Room type : " << room.getRoomType() << "\t Room price : " << room.getRoomPrice()<< " $" << std::endl;

    }

}