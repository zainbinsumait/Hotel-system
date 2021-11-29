#include "system.h"
#include "room.h"
#include <limits>
#include <iomanip>


void Hotel_system::System::system()
{
    //Partie du code pour la question 7.a 
    //la saisie des dates
    checkDebutDate();
    std::cout << "\n";
    checkFinDate();
    //loop (redamande de saisir) si la date de fin est avant la date de debut
    while (_fin<_debut)
    {
        sidateFininvalide();
    }
    std::cout << "la date de fin choisit est: " << _fin.toString() << std::endl;
    std::cout << "\n";
    //la fonction 7.b le calcule de nombre de nuit
    nombreNuits(_fin, _debut);
    std::cout << "\n";
    //Partie du code pour la question 8.a
    //la saisie de type de la chambre 
    std::string type;
    std::cout << "Veuillez saisir le type de chambre souhaiteé (Single , Double , Suit) attention aux majuscules:" << std::endl;
    std::cin >> type;
    std::cout << "\n";
    //convertir le string en typeroom
    room_typeselectionne = stringtoType(type);

    // le loop si aucune chambre de type selectionne n'est disponible
    while (!chambreDispo(room_typeselectionne))
    {
        std::cout << " Aucun chambre de ce type n'est disponible , veuillez selectionner un autre type \n";
        std::cin >> type;
        room_typeselectionne = stringtoType(type);
    }
    // la saisie du client 
    std::cout << "\n";
     int answer = 0;
     int choice = 0;
     std::cout << " Veuillez entrer le nom du client (sans espace) :";
     std::cin >> nom_clientchoisit;
     std::cout << "\n";
     int nbr_deClientPotentiels = 0;
     do { nbr_deClientPotentiels = clientsPotentiels(nom_clientchoisit);
         switch (nbr_deClientPotentiels)
         {
         case 0:
             int choix;
             std::cout << "le client n'est pas dans la list\t veuillez taper :\n 1 pour entrer un autre nom\n 2 pour ajouter un nouveau client\n";
             std::cin >> choix;
             switch (choix)
             {
             case 2:
                 newClient(); //client_selectionne = nouveau client
                 nbr_deClientPotentiels = 3; //pour casser le loop
                 break;
             default:
                 std::cout << "veuillez entrer un autre nom : \n";
                 std::cin >> nom_clientchoisit; //loop car nbr_deClientPotentiels = 0
                 break;
             }
             break;
         case 1: // dans ce cas le cariable client_selectionne est deja ce client unique
             std::cout << "Est-ce-que c'est le client que vous voulez saisir? :\n 1- oui \n 2- non je rentre un autre nom \n 3- non j'ajoute un nouveau client\n";
             std::cin >> answer;
             if (answer == 1) {
                 std::cout << "tres bien !\n";
             }
             else if(answer==3){
                 newClient();  //client_selectionne = nouveau client
             }
             else {
                 std::cout << "veuillez entrer un autre nom : \n";
                 std::cin >> nom_clientchoisit;
                 nbr_deClientPotentiels = 0;  //loop car nbr_deClientPotentiels = 0
             }
             break;
         default:
             std::cout << "\n Choisissez le nomero qui correspond a votre client : \n";
             std::cin >> choice;
             break;
         }
     } while (nbr_deClientPotentiels == 0 );
     std::cout << "\n";
     //si choice n'est pas nul on met le client choisit dans la variable client_selectionne et on l'affiche
     if (choice != 0) {
         std::cout << "client selectionne : " << getClient(choice).clientString();
         client_selectionne = getClient(choice);
     }
     //le client est bien choisit
     //afficher le prix total avec 7 nombres de precision
     std::cout << "Le prix total est :\t  " <<std::setprecision(7) <<(_fin - _debut) * room_selectionne.getRoomPrice()<<" $\n";
     std::cout << "\n";
     //creer la reservation et l'afficher
     newBooking();
     std::cout << "\n";
     choice = 0;
     do
     {
         std::cout << "vous voulez confirmer la reservation ?\n1- Oui\n2- Non supprimer la reservation \n";
         std::cin >> choice;
         switch (choice)
         {
             
         case 1:
             std::cout << " la reservation a ete bien enregistree \n";
             //syntax pour incrementer le nombre de reservation du client selectionnee
             for (int i = 0; i < C_list.size(); i++) {
                 if (C_list[i].getId() == client_selectionne.getId()) {
                     C_list[i].incrementerNombreReservation();
                 }
             }
             break;
         case 2:
             std::cout << " la reservation a ete bien supprimee \n";
             //supprimer la reservation
             _booking.pop_back();
             break;
         }
     } while (choice != 1 && choice != 2);   
     std::cout << "\n";
}

void Hotel_system::System::nombreNuits(date::Date fin, date::Date debut)
{
	std::cout << "le nombre de nuits de la réservation est :" << fin - debut << std::endl;
}

void Hotel_system::System::checkFinDate()
{
    std::cout << "veuiller entrer la date de fin de votre reservation dans l'hotel (sous forme jour/mois/annee) :\n";
    std::cin >> _fin;
    while (!_fin.checkDate2()) {

        std::cout << "date invalide\n";
        std::cout << "veuiller entrer la date de fin de votre reservation dans l'hotel  (sous forme jour/mois/annee) :\n";
        std::cin >> _fin;
    }
}

void Hotel_system::System::checkDebutDate()
{
    std::cout << "veuiller entrer la date de debut de votre reservation dans l'hotel (sous forme jour/mois/annee) :\n";
    std::cin >> _debut;
    //loop si la date n'est pas valide
    while (!_debut.checkDate2()) {

        std::cout << "date invalide\n";
        std::cout << "veuiller entrer la date de debut de votre reservation dans l'hotel (sous forme jour/mois/annee) :\n";
        std::cin >> _debut;
    }
    std::cout << "la date de debut choisit est : " << _debut.toString() << std::endl;
}

bool Hotel_system::System::chambreDispo(Typeroom type)
{
    
        if (type == Suit) {
            std::vector<int> chambre_dispo = suit_room;
            for (int i = 0; i < _booking.size(); i++) {
                for (int t = 0; t < suit_room.size(); t++) {

                    if ((_booking[i].getRid() == suit_room[t] && _booking[i].dateInclude(_debut, _fin))) {
                        chambre_dispo.erase(std::remove(chambre_dispo.begin(), chambre_dispo.end(), suit_room[t]), chambre_dispo.end());                      
                    }//si le numero de chambre d'une reservation dans la liste des reservations est le meme que 
                        //le numero present dans le vecteur suit_room  et que la date de cette reservation est inclue dans la date de la nouvelle reservation 
                        //on enleve ce numero du vecteur chambre_dispo 
                }
            }
            if (chambre_dispo.size() == 0) {
                return false; //si la taille du vecteur chambre_dispo est nulle donc aucun chambre de ce type n'est disponible
            }
            else {//sinon on affiche les informations de la premiere chambre disponible et on la met dans le variable room_selectionne
                std::cout << "Nous avons une chambre disponible de ce type \n"  << getRoom(chambre_dispo.front()).roomtoString();
                room_selectionne = getRoom(chambre_dispo.front());
                return true;
            }
        }else if (type == Single) {
            std::vector<int> chambre_dispo = single_room;
            for (int i = 0; i < _booking.size(); i++) {
                for (int t = 0; t < single_room.size(); t++) {

                    if ((_booking[i].getRid() == single_room[t] && _booking[i].dateInclude(_debut, _fin))) {
                        chambre_dispo.erase(std::remove(chambre_dispo.begin(), chambre_dispo.end(), single_room[t]), chambre_dispo.end());
                        //si le numero de chambre d'une reservation dans la liste des reservations est le meme que 
                        //le numero present dans le vecteur single_room  et que la date de cette reservation est inclue dans la date de la nouvelle reservation 
                        //on enleve ce numero du vecteur chambre_dispo 
                    } 
                }
            }if (chambre_dispo.size() == 0) {
                return false;//si la taille du vecteur chambre_dispo est nulle donc aucun chambre de ce type n'est disponible
            }
            else {//sinon on affiche les informations de la premiere chambre disponible et on la met dans le variable room_selectionne 
                std::cout << "Nous avons une chambre disponible de ce type \n"  << getRoom(chambre_dispo.front()).roomtoString();
                room_selectionne = getRoom(chambre_dispo.front());
                return true;
            }
        }else if (type == Double) {
            std::vector<int> chambre_dispo = double_room;
            for (int i = 0; i < _booking.size(); i++) {
                for (int t = 0; t < double_room.size(); t++) {

                    if ((_booking[i].getRid() == double_room[t] && _booking[i].dateInclude(_debut, _fin))) {
                        chambre_dispo.erase(std::remove(chambre_dispo.begin(), chambre_dispo.end(), double_room[t]), chambre_dispo.end());
                    } //si le numero de chambre d'une reservation dans la liste des reservations est le meme que 
                        //le numero present dans le vecteur double_room  et que la date de cette reservation est inclue dans la date de la nouvelle reservation 
                        //on enleve ce numero du vecteur chambre_dispo 
                }
            }
            if (chambre_dispo.size() == 0) {
                return false;//si la taille du vecteur chambre_dispo est nulle donc aucun chambre de ce type n'est disponible
            }
            else {//sinon on affiche les informations de la premiere chambre disponible et on la met dans le variable room_selectionne
                std::cout << "Nous avons une chambre disponible de ce type \n"  << getRoom(chambre_dispo.front()).roomtoString();
                room_selectionne = getRoom(chambre_dispo.front());
                return true;
            }
        }else {//si le type n'est pas valide
            std::cout << "type invalide, faites attention aux majuscules";
            return false;
        }  
}


std::vector<Hotel_system::Room> Hotel_system::System::getRlist()
{
    return R_list;
}

std::vector<Hotel_system::Client> Hotel_system::System::getClist()
{
    return C_list;
}

void Hotel_system::System::setClientlist(std::vector<Client> list)
{
    C_list = list;
}

Hotel_system::Typeroom Hotel_system::System::stringtoType(std::string type)
{
    if (type == "Suit") {
        return Suit;
    }
    else if (type == "Single") {
        return Single;
    }
    else if (type == "Double") {
        return Double;
    }
    else {
        return unknown;
    }
}



void Hotel_system::System::getRpositions()
{
    int S = R_list.size();
    for (int i = 0; i < S; i++) {
        if (R_list[i].getRoomType() == Single) {
            single_room.push_back(R_list[i].getRoomNomber());
            //mettre les numeros des chambres Single dans le vecteur single_room
        }else if(R_list[i].getRoomType() == Suit) {
            suit_room.push_back(R_list[i].getRoomNomber());
            //mettre les numeros des chambres Suit dans le vecteur suit_room
        }
        else if (R_list[i].getRoomType() == Double) {
            double_room.push_back(R_list[i].getRoomNomber());
            //mettre les numeros des chambres Double dans le vecteur double_room
        }
    }
    //on trie les nombres de chambres par ordre croissant pour bien choisir la premiere chambre disponible
    std::sort(single_room.begin(), single_room.end());
    std::sort(double_room.begin(), double_room.end());
    std::sort(suit_room.begin(), suit_room.end());
}

Hotel_system::Room Hotel_system::System::getRoom(int roomnmbr)
{
    Room s;
    for (int t = 0; t < R_list.size(); t++) {
        if (R_list[t].getRoomNomber()== roomnmbr) {
            s = R_list[t];
        }//mettre la chambre dont le numero est roomnmbr dans le variable s 
    }
    return s;
}

void Hotel_system::System::sidateFininvalide()
{
    std::cout << "date de fin invalide" << std::endl;
    std::cout << "Veillez tapez 1 pour modifier la date de debut ou 2 pour resaisir la date de fin :" << std::endl;
    int ch;
    std::cin >> ch;
    switch (ch)
    {
    case 1 :
        checkDebutDate();
        checkFinDate();
        break;
    case 2 :
        checkFinDate();
        break;
    default:
        std::cout << "Veillez tapez 1 pour modifier la date de debut ou 2 pour resaisir la date de fin :" << std::endl;
        std::cin >> ch;
        break;
    }
}

int Hotel_system::System::clientsPotentiels(std::string name)
{
    int nbr = 0;
    for (int i = 0; i < C_list.size(); i++) {
        if (C_list[i].getNom() == name) {
            std::cout << C_list[i];
            nbr++;
            client_selectionne = C_list[i];
        }
    }
    return nbr;
}

Hotel_system::Client Hotel_system::System::getClient(int clientnbr)
{
    Client c;
    for (int t = 0; t < C_list.size(); t++) {
        if (C_list[t].getId() == clientnbr) {
            c = C_list[t];
        }
    }
    return c;
}

void Hotel_system::System::newBooking()
{
    int id = 1;
    if (_booking.size()==0) {
        
    }
    else {
        id = _booking.back().getBid() + 1;
    }
    
    Booking nouveau(id, _debut, _fin, hotel_selectionne, client_selectionne, room_selectionne);
    nouveau.totalPrice();
    _booking.push_back(nouveau);
    nouveau.affichageBooking();
}

void Hotel_system::System::setHotel(Hotel hotel)
{
    hotel_selectionne = hotel;
    R_list = hotel.getList();
}

void Hotel_system::System::newClient()
{
    std::string prenom;
    std::cout << "Veuiller entrer le nom du nouveau client : \n";
    std::cin >> nom_clientchoisit;
    std::cout << "Veuiller entrer le prenom du nouveau client : \n";
    std::cin >> prenom;
    Client nouveau(C_list.size()+1, nom_clientchoisit, prenom);
    C_list.push_back(nouveau);
    std::cout << nouveau;
    client_selectionne = nouveau;
}

void Hotel_system::System::affichReservation()
{
    std::cout << "les reservations en cours :\n";
    for (int i = 0; i < _booking.size();i++) {    
         _booking[i].affichageBooking();
         std::cout << "\n";
    }
}

void Hotel_system::System::affichReservationnbr(int nbr_reservation)
{ 
    for (int i = 0; i < _booking.size(); i++) {
        if (_booking[i].getBid()== nbr_reservation) {
            std::cout << "la reservation numero : " << nbr_reservation << std::endl;
            _booking[i].affichageBooking();
        }
    }
}

void Hotel_system::System::affichReservationClient(int Id_client)
{
    std::cout << "Toutes les reservations du client dont l'ID est : " << Id_client << std::endl;
    for (int i = 0; i < _booking.size(); i++) {
        if (_booking[i].getCid() == Id_client) {
            _booking[i].affichageBooking();
            std::cout << "\n";
        }
    }
}

void Hotel_system::System::affichReservationClient(std::string nom_client)
{
    //chercher toutes les reservations dont le nom du client est le meme que le nom entre en parametre
    std::cout << "Toutes les reservations du client dont le nom est : " << nom_client << std::endl;
    for (int i = 0; i < _booking.size(); i++) {
        if (getClient(_booking[i].getCid()).getNom() == nom_client) {
            _booking[i].affichageBooking();
            std::cout << "\n";
        }
    }
}

void Hotel_system::System::annulerReservation(int ID)
{
    for (int i = 0; i < _booking.size(); i++) {
        if (_booking[i].getBid() == ID) {
            _booking.erase(_booking.begin()+ i);
            std::cout << "la reservation a ete bien annulee\n";
        }
    } 
}



