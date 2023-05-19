#include "commande_construct_caserne.hpp"
#include "../UserInterface/UserInterface.hpp"
#include "commande_square.hpp"
#include "../AffichableOnMap/caserne.hpp"

const std::string CommandeConstructCaserne::TEXTURE_NAME = "caserne_icone_big.png";


CommandeConstructCaserne::CommandeConstructCaserne() : CommandeSquare(TEXTURE_NAME, "[!] A COMPLETER") {

}

void CommandeConstructCaserne::execute() {std::cout << "acheter caserne"<<std::endl;};