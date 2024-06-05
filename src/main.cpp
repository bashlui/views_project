/* 


    Project: Views - Plataforma de streaming de videos
    Created by: Luis Antonio Bolaina Domínguez, Freda Nicole Blanco
    Los ratings van a ser del 1 al 10
    Mínimo que sean 10 películas


*/

# include <iostream>
# include <vector>
# include <string>
# include <algorithm>
# include <random>
# include <fstream>

using namespace std;

void showMovies() {

}

void home(){
    int opt;
    string temp = "";
    string red = "\033[31m";
    string reset = "\033[0m";

    cout <<red <<R"(

░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓███████▓▒░ 
░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
 ░▒▓█▓▒▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░        
 ░▒▓█▓▒▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░ ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░  
  ░▒▓█▓▓█▓▒░ ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░ 
  ░▒▓█▓▓█▓▒░ ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░ 
   ░▒▓██▓▒░  ░▒▓█▓▒░▒▓████████▓▒░░▒▓█████████████▓▒░░▒▓███████▓▒░  
                                                                                                                
)"<<reset << '\n' << endl;

    cout << red;
    cout << "Bienvenido a \"Views\", la plataforma de streaming de videos más grande de la historia." << endl;
    cout << "Contamos con los siguientes servicios, seleccione uno por favor: " << endl;
    cout << "1. Ver la lista de películas" << endl;
    cout << "2. Ver la lista de series" << endl;
    cout << "3. Calificación de las películas y series" << endl;
    cout << "4. Calificar una película o serie" << endl;
    cout << "0. Salir" << endl;
    cout << reset;

    do {
        getline(cin, temp);
        opt = stoi(temp);

        switch (opt) {
            case 1:
                cout << "Lista de películas" << endl;
                showMovies();
                break;
            case 2:
                cout << "Lista de series" << endl;
                break;
            case 3:
                cout << "Calificación de las películas y series" << endl;
                break;
            case 4:
                cout << "Calificar una película o serie" << endl;
                break;
            case 0:
                cout << "Gracias por usar \"Views\", esperamos que vuelvas pronto." << endl;
                break;
            default:
                cout << "Opción no válida, por favor seleccione una opción válida." << endl;
                break;
        }
    } while (opt != 0);
}


string returnLineCin() {
    string line;
    getline(cin, line);
    return line;
}



int main() {
    home();
    return 0;
}