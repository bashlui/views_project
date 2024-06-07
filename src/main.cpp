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
# include <fstream>
# include <sstream>
# include "Classes/Video.h"

using namespace std;

string trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

void showMoviesByRate() {
    ifstream file("Data/Peliculas.txt");
    if(!file.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    vector<Video> videos;
    string line;

    while(getline(file, line)) {
        stringstream ss(line);
        string ignore, title, genre, duration, rating;
        int movieRate;

        if (getline(ss, ignore, ',') &&
        getline(ss, title, ',') &&
        getline(ss, duration, ',') &&
        getline(ss, genre, ',') &&
        getline(ss, rating, ',')) {

            title = trim(title);
            genre = trim(genre);
            duration = trim(duration);
            rating = trim(rating);

            try {
                movieRate = stoi(rating);
                Video video(title, genre, duration, movieRate);
                videos.push_back(video);
            } catch (const invalid_argument &e) {
                cout << "Error al convertir el rating a entero: " << title << endl;
                continue;
            }
        } else {
            cout << "Error al leer la línea: " << line << endl;
            continue;
        }
    }
    for (const Video &video : videos) {
        cout << "Títle: " << video.getTitle() << endl;
        cout << "Genre: " << video.getGenre() << endl;
        cout << "Duration: " << video.getDuration() << endl;
        cout << "Rating: " << video.getRating() << endl;
        cout << "--------------------------------" << endl;
    }
}

void home(){
    string red = "\033[31m";
    string yellow = "\033[33m";
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
    cout << "Welcome to \"Views\", the largest video streaming platform in history." << endl;
    cout << "We offer the following services, please select one: " << endl;
    int option;
    do {
        cout << red;
        cout << "1. View the list of movies" << endl;
        cout << "2. View the list of series" << endl;
        cout << "3. Ratings of movies and series" << endl;
        cout << "4. Rate a movie or series" << endl;
        cout << "0. Exit" << endl;
        cout << reset;
        cin >> option;
        switch (option) {
            case 1:
                cout << "TEST" << endl;
                break;
            case 2:
                cout << "TEST2" << endl;
                break;
            case 3:
                cout << yellow << R"(
        ░▒▓██████████████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓████████▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓███████▓▒░▒▓████████▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░         ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░         ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░        ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓██████▓▒░   ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▓█▓▒░ ░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▓█▓▒░ ░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░   ░▒▓██▓▒░  ░▒▓█▓▒░▒▓████████▓▒░      ░▒▓████████▓▒░▒▓█▓▒░▒▓███████▓▒░   ░▒▓█▓▒░
                )" << reset << endl;
                showMoviesByRate();
                break;
            case 4:
                cout << "TEST4" << endl;
                break;
            case 0:
                cout << yellow << R"(
                     ░▒▓███████▓▒░▒▓████████▓▒░▒▓████████▓▒░      ░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░░▒▓█▓▒░
                    ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░
                    ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░
                     ░▒▓██████▓▒░░▒▓██████▓▒░ ░▒▓██████▓▒░         ░▒▓██████▓▒░░▒▓████████▓▒░▒▓█▓▒░
                           ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░
                           ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░                ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░
                    ░▒▓███████▓▒░░▒▓████████▓▒░▒▓████████▓▒░         ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░
                )" << reset << endl;
                break;
            default:
                cout << "Opción no válida, por favor seleccione una opción válida." << endl;
                break;
        }
    } while (option != 0);
}

int main() {
    home();
    return 0;
}