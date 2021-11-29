#include "client.h"
#include <iostream>

namespace Hotel_system {
    
    Client::Client(int Id, std::string nom, std::string prenom, int nbr) : c_identifiant(Id), c_nomc(nom), c_prenoc(prenom), c_nbr(nbr) {}
    int Client::getId() const {
        return c_identifiant;
    }
    std::string Client::getNom() const {
        return c_nomc;
    }
    std::string Client::getPrenom() const {
        return c_prenoc;
    }
    int Client::getNombreReserv() const {
        return c_nbr;
    }
    std::string Client::clientString() {
        return "info client :\n id :" + std::to_string(c_identifiant) + "\t Nom de client : " 
            + c_nomc + "\t Prenom : " + c_prenoc + "\t Nombre de reservation :" + std::to_string(c_nbr)+"\n";
    }
    void Client::affClient() {
        std::cout << "info client :\n id :" << c_identifiant << "\t Nom :" << c_nomc << "\t prenom :" << c_prenoc << "\t Nombre de reservation :" << c_nbr << std::endl;
    }
    void Client::updateClient(int id, std::string nom, std::string prenom, int nbr) {
        c_identifiant = id;
        c_nomc = nom;
        c_prenoc = prenom;
        c_nbr = nbr;
    }

    void Client::incrementerNombreReservation()
    {
        c_nbr += 1;
    }

    void operator<<(std::ostream& os, Client& cl)
    {
        os<< "info client :\n id :" + std::to_string(cl.getId()) + "\t Nom de client : "
            + cl.getNom() + "\t Prenom : " + cl.getPrenom() + "\t Nombre de reservation :" + std::to_string(cl.getNombreReserv())+"\n";
    }

}
