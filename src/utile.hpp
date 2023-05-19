#include <string>
#include <iostream>


class Utile {
    private :
        static std::string const WARNING;
    public :

        // mettre __func__ comme argument pour fonction
        static void warning(std::string fonction, std::string message) {std::cerr << WARNING<<fonction<<" -> "<<message<<std::endl; }
        
        // mettre __func__ comme argument pour fonction
        static void erreur(std::string fonction, std::string message) {
            throw std::runtime_error(fonction+ " -> " +message+"\n");}
};







