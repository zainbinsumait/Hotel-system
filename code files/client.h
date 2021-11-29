#ifndef CLIENT_H
#define CLIENT_H
#include <string>

namespace Hotel_system {
    class Client {
    public:
        Client(int id = 0, std::string nom = "inconnu", std::string prenom = "inconnu", int nbr = 0);
        int getId() const;
        std::string getNom() const;
        std::string getPrenom() const;
        int getNombreReserv() const;
        std::string clientString();
        void affClient();
        void updateClient(int id, std::string nom, std::string prenom, int nbr);
        void incrementerNombreReservation();


    private:
        int c_identifiant;
        std::string c_nomc;
        std::string c_prenoc;
        int c_nbr;
    };
    void operator<<(std::ostream&, Client&);

}
#endif