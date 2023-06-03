#include <string>
#include <iostream>


class Utile {
    private :
        static std::string const WARNING;
    public :


        /**
         * \brief affiche un message d'erreur
         * \param fonction nom de la fonction dans laquelle l'erreur a ete detectee,
         * __func__ peut etre utilise
         * \param message message d'erreur
        */
        static void warning(std::string fonction, std::string message) {std::cerr << WARNING<<fonction<<" -> "<<message<<std::endl; }
        

        /**
         * \brief affiche un message d'erreur et lance une exception
         * \param fonction nom de la fonction dans laquelle l'erreur a ete detectee,
         * __func__ peut etre utilise
         * \param message message d'erreur
        */
        static void erreur(std::string fonction, std::string message) {
            throw std::runtime_error(fonction+ " -> " +message+"\n");}
};







