#ifndef ROOM_H
#define ROOM_H
#include <string>

namespace Hotel_system {
    
    enum Typeroom {
        unknown,
        Single,
        Double,
        Suit
    };
    class Room {
    public:
        Room(int roomnbr = 0, Typeroom type = unknown, double price = 0.0);
        int getRoomNomber() const;
        Typeroom getRoomType() const;
        double getRoomPrice() const;
        void roomString();
        std::string roomtoString();
        void updateRnomber(int roomnmbr);
        void updateRtype(Typeroom type);
        void updateRprice(double roomprice);
        void updateRoom(int rn, Typeroom type, double price);


    private:
        int room_nomber;
        Typeroom room_type;
        double room_price;
    };
    //surcharge l'operateur <<
    void operator<<(std::ostream &, Room &);

}
#endif