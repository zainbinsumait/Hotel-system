#include "client.h"
#include "room.h"
#include "hotel.h"
#include "date.h"
#include "reservation.h"
#include"system.h"
#include <iostream>
#include <array>
#include <vector>
using namespace Hotel_system;

   


int main() {

    //les test
    //la classe date :
    date::Date date1(2020,1,2);
    std::cout <<"la premiere date "<< date1.toString()<<"\n";
    date1.setDay(8);
    std::cout << "la premiere date apres avoir mis le jour a 8 : \t" << date1.toString() << "\n";
    std::cout <<"le bool checkDate(2200,22,20) : "<< date1.checkDate(2200 ,22,20) << "\n";
    date1.nextDay();
    std::cout << "la premiere date apres nextDay " << date1.toString() << "\n";

    //classe client :
    std::cout << " \n";
    std::cout << "le test client \n";

    Client test(1, "NOVO", "lucas", 5);
    std::cout << "les info du client 2 : \n" << test;

    test.updateClient(5, "BIN SUMAIT", "zain", 8);
    std::cout << "les info du client 2 apres la mise a jour : \n" << test;





    //la base de donnees

    //les clients de hotel_1 
    Client one(1, "Hahou", "mehdi", 1);
    Client two(2, "BIN SUMAIT", "zain", 10);
    Client three(3, "Novo", "lucas", 55);
    Client four(4, "Novo", "alice", 2);
    Client five(5, "Hahou", "asma", 1);
    Client six(6, "Hahou", "nicolas", 1);
    Client seven(7, "BIN SUMAIT", "mona", 0);
    Client eight(8, "SUMAIT", "mona", 0);
    std::vector<Client> c_list1 = { one ,two ,three ,four,five,six,seven,eight};

    //les chambres du hotel_1
    Room a_S(1, Single, 100); Room  b_S(5, Single, 100);
    Room c_S(10, Single, 100);
    Room d_D(2, Double, 125); Room e_D(3, Double, 125);
    Room f_D(4, Double, 125); Room g_D(6, Double, 125);Room h_D(7, Double, 125);
    Room i_S(8, Suit, 210); Room j_S(9, Suit, 210);
    std::vector<Room> r_list1 = { a_S,b_S,c_S,d_D,e_D,f_D,g_D,h_D,j_S,i_S };

    //hotel_1
    Hotel cinqetoiles(11155, "dijon", "Jeunesse", r_list1);
    std::cout <<"le premiere hotel" << cinqetoiles;
    std::cout << "\n";

    // initialiser les variables membres de hotel_1
    System hotel_1;
    hotel_1.setHotel(cinqetoiles);
    hotel_1.setClientlist(c_list1);
    hotel_1.getRpositions();

    //les clients de hotel_2
    Client one_2(1, "Juste", "marwan", 1);
    Client two_2(2, "Novo", "zain", 10);
    Client three_2(3, "Sumait", "lucas", 55);
    Client four_2(4, "Sumait", "alice", 2);
    Client five_2(5, "Hahou", "asma", 1);
    Client six_2(6, "Hahou", "nicolas", 1);
    Client seven_2(7, "Ben", "mona", 0);
    Client eight_2(8, "Sumait", "mona", 0);
    std::vector<Client> c_list2 = { one_2 ,two_2 ,three_2 ,four_2,five_2,six_2,seven_2,eight_2 };

    //les chambres du hotel_2
    Room a2_S(1, Single, 100); Room  b2_S(5, Single, 100);
    Room c2_S(10, Single, 100);
    Room d2_D(2, Double, 125); Room e2_D(3, Double, 125);
    Room f2_D(4, Double, 125); Room g2_D(6, Double, 125); Room h2_D(7, Double, 125);
    Room i2_S(8, Suit, 210); Room j2_S(9, Suit, 210); Room q2_S(11, Suit, 210); Room w2_S(12, Single, 100);
    std::vector<Room> r_list2 = { a2_S,b2_S,c2_S,d2_D,e2_D,f2_D,g2_D,h2_D,i2_S,j2_S,q2_S,w2_S};

    //hotel_2
    Hotel helton(777, "dijon", "Helton", r_list2);
    std::cout <<"le deuxieme hotel" <<helton;
    std::cout << "\n";
    // initialiser les variables membres de hotel_2
    System hotel_2;
    hotel_2.setHotel(helton);
    hotel_2.setClientlist(c_list2);
    hotel_2.getRpositions();

    // le code principal
    
    bool start = true;
    while (start) {
        //le menu principal
        std::cout << "Bonjour \n\nBienvenu dans notre plateform de reservation \n ";
        std::cout << "\n";
        std::cout << "Veuillez choisir l'hotel\t tapez : \n\n1 - Pour l'hotel de Jeunesse \n2 - Pour l'hotel de Helton\n3 - Pour quitter le programme\n";
        int hotel_choisit;
        std::cin >> hotel_choisit;
        std::cout << "\n";
        bool hotel1_selectionne = true;
        bool hotel2_selectionne = true;
        switch (hotel_choisit)
        {
        case 1:
            while (hotel1_selectionne)
            {
                std::cout << "Veuillez taper : \n1 - Pour faire une reservation \n2 - Pour modifier une reservation\n3 - Pour annuler une reservation \n4 - Pour afficher toutes les reservation en cours\n5 - Pour afficher toutes les reservation d'un client\n6 - Pour revenir au menu principal \n ";
                int choix;
                std::cin >> choix;
                std::cout << "\n";
                switch (choix)
                {
                case 1:
                    //toutes les autres fonctions sona dans la fonction system de la classe system
                    hotel_1.system();
                    std::cout << "merci d'avoir choisir notre hotel , nous vous souhaitons un excellent sejour\n ";
                    std::cout << "\n";
                    break;
                case 2:

                    break;
                case 3:
                    int ID;
                    std::cout << "Veuillez entrer le Id de la reservation\n";
                    std::cin >> ID;
                    hotel_1.annulerReservation(ID);
                    break;
                case 4:
                    hotel_1.affichReservation();
                    break;
                case 5:
                    int h;
                    std::cout << "Si vous avez le nom du client tapez 1 \n si vous avez son ID tapez 2\n ";
                    std::cin >> h;
                    if (h == 1) {
                        std::string nom;
                        std::cout << "Entrer le nom du client\n";
                        std::cin >> nom;
                        hotel_1.affichReservationClient(nom);
                    }
                    else if (h == 2) {
                        int ID;
                        std::cout << "Entrer le ID du client\n";
                        std::cin >> ID;
                        hotel_1.affichReservationClient(ID);
                    }
                    break;
                case 6:
                    std::cout << "nous vous souhaitons une bonne journee\n";
                    hotel1_selectionne = false; //pour casser le loop de hotel 1
                    break;
                default:
                    std::cout << "Excusez-nous , nous avons pas compris votre choix\n";
                    hotel1_selectionne = false; // pour casser le loop de hotel 1
                    break;
                }
            }
            break;
            
        case 2:
            
            while (hotel2_selectionne) {
                std::cout << "Veuillez taper : \n1 - Pour faire une reservation \n2 - Pour modifier une reservation\n3 - Pour annuler une reservation \n4 - Pour afficher toutes les reservation en cours\n5 - Pour afficher toutes les reservation d'un client\n6 - Pour revenir au menu principal \n ";
                int choix2;
                std::cin >> choix2;
                std::cout << "\n";
                switch (choix2)
                {
                case 1:
                    //toutes les autres fonctions sona dans la fonction system de la classe system
                    hotel_2.system();
                    std::cout << "merci d'avoir choisir notre hotel , nous vous souhaitons un excellent sejour\n ";
                    std::cout << "\n";
                    break;
                case 2:

                    break;
                case 3:
                    int ID;
                    std::cout << "Veuillez entrer le Id de la reservation\n";
                    std::cin >> ID;
                    hotel_2.annulerReservation(ID);
                    break;
                case 4:
                    hotel_2.affichReservation();
                    break;
                case 5:
                    int h;
                    std::cout << "Si vous avez le nom du client tapez 1 \n si vous avez son ID tapez 2\n ";
                    std::cin >> h;
                    if (h == 1) {
                        std::string nom;
                        std::cout << "Entrer le nom du client\n";
                        std::cin >> nom;
                        hotel_2.affichReservationClient(nom);
                    }
                    else if (h == 2) {
                        int ID;
                        std::cout << "Entrer le ID du client\n";
                        std::cin >> ID;
                        hotel_2.affichReservationClient(ID);
                    }
                    break;
                case 6:
                    std::cout << "nous vous souhaitons une bonne journee\n";
                    hotel2_selectionne = false;// pour casser le loop de hotel 2
                    break;
                default:
                    std::cout << "Excusez-nous , nous avons pas compris votre choix\n";
                    hotel2_selectionne = false;// pour casser le loop de hotel 2
                    break;
                }
            }
            break;
        case 3:
            std::cout << "Merci pour votre visit , nous vous souhaitons une bonne journee\n";
            start = false;
            break;
        default:
            std::cout << "Excusez-nous , nous avons pas compris votre choix\n";
            start = false;
            break;
        }   
   }
    return 0;
}
