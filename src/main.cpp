/*
    Project: Views - Streaming Platform
    Created by: Luis Antonio Bolaina Domínguez, Freda Nicole Blanco
*/

# include <iostream>
# include <vector>
# include <string>
# include <sstream>
# include "Classes/Video.h"
# include "Classes/Video2.h"
# include "Classes/Movies.h"
# include "Classes/Series.h"
# include "Classes/Episodes.h"

using namespace std;

vector<Video> movies;
vector<Video> moviesByRating;
vector<Video2*> series;
vector<Episodes *> episodes;

void showMovieList() {
  Movies movieInstance;
  movieInstance.showMovieList(movies);
}

void seriesList() {
    Series seriesInstance;
    seriesInstance.showSeriesList(series);
}

void showSeriesByGenres(vector<string> &genres){
    Series seriesInstance;
    seriesInstance.showSeriesByGenre(genres, series);
}

void showMovieByRating(int rating){
    Movies movieInstance;
    movieInstance.showMovieByRating(moviesByRating, rating);
}

void showMovieByGenres(vector<string> &genres){
    Movies movieInstance;
    movieInstance.showMovieByGenre(genres, movies);
}

void rateMovie(const string &title, int rate){
    Movies movieInstance;
    movieInstance.rateMovie(movies, title, rate);
}

void showEpisodeBySeriesId(int id){
    Episodes episodeInstance;
    episodeInstance.showEpisodesListBySeriesId(episodes, id);
}

void home(){
    string title;
    int id;
    int rating;
    string genresStr;
    string genre;
    vector<string> genres;
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
        cout << "1. Show movie list" << endl;
        cout << "2. Filter movies by rating" << endl;
        cout << "3. Filter movies by genre" << endl;
        cout << "4. Show series list" << endl;
        cout << "5. Filter series by genre" << endl;
        cout << "6. Show episodes of a series" << endl;
        cout << "7. Rate a video" << endl;
        cout << "0. Exit" << endl;
        cout << reset;
        cin >> option;
        switch (option) {
            case 1:
                cout << yellow << R"(
        ░▒▓██████████████▓▒░ ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓████████▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓███████▓▒░▒▓████████▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░         ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░         ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░        ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓██████▓▒░   ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▓█▓▒░ ░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▓█▓▒░ ░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░
        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░░▒▓██████▓▒░   ░▒▓██▓▒░  ░▒▓█▓▒░▒▓████████▓▒░      ░▒▓████████▓▒░▒▓█▓▒░▒▓███████▓▒░   ░▒▓█▓▒░
                )" << reset << endl;
                showMovieList();
                break;
            case 2:
                cout << "Choose a rating between 1 and 10: " << endl;
                cin >> rating;
                cout << "Movies with a rating of " << rating << " are: " << endl;
                showMovieByRating(rating);
                break;
            case 3:
                cout << "List of genres: " << endl;
                cout << "Acción | Drama | Science Fiction | Comedy | Horror "
                        "| Adventure | Thriller | Sci-Fi | Animation | Fantasy | Musical" << endl;
                cout << "Type the genre of the movies, separated by commas: " << endl;
                cin.ignore();
                genres.clear();
                getline(cin, genresStr);
                {
                    stringstream ss(genresStr);
                    while (getline(ss, genre, ',')) {
                        genres.push_back(Movies::trim(genre));
                    }
                }
                movies.clear();
                Movies::loadMovies(movies);
                showMovieByGenres(genres);
                break;
            case 4:
                cout << yellow << R"(
             ░▒▓███████▓▒░▒▓████████▓▒░▒▓███████▓▒░░▒▓█▓▒░▒▓████████▓▒░░▒▓███████▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓███████▓▒░▒▓████████▓▒░
            ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░         ░▒▓█▓▒░
            ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░▒▓█▓▒░         ░▒▓█▓▒░
             ░▒▓██████▓▒░░▒▓██████▓▒░ ░▒▓███████▓▒░░▒▓█▓▒░▒▓██████▓▒░  ░▒▓██████▓▒░       ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓██████▓▒░   ░▒▓█▓▒░
                   ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░
                   ░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░
            ░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓████████▓▒░▒▓███████▓▒░       ░▒▓████████▓▒░▒▓█▓▒░▒▓███████▓▒░   ░▒▓█▓▒░
                )" << reset << endl;
                seriesList();
                break;
            case 5:
                cout << "List of genres: " << endl;
                cout << "Acción | Drama | Science Fiction | Comedy | Horror "
                        "| Adventure | Thriller | Sci-Fi | Animation | Fantasy | Musical" << endl;
                cout << "Type the genre of the series, separated by commas: " << endl;
                cin.ignore();
                genres.clear();
                getline(cin, genresStr);
                {
                    stringstream ss(genresStr);
                    while (getline(ss, genre, ',')) {
                        genres.push_back(Series::trim(genre));
                    }
                }
                series.clear();
                Series::loadSeries(series);
                showSeriesByGenres(genres);
                break;
            case 6:
                cout << "Type the series ID: ";
                cin >> id;
                episodes.clear();
                Episodes::loadEpisodes(episodes);
                showEpisodeBySeriesId(id);
                break;
            case 7:
                cout << "What movie do you want to rate? ";
                cin.ignore();
                getline(cin, title);
                cout << "What rating do you want to give it (1-10)?: ";
                cin >> rating;
                movies.clear();
                Movies::loadMovies(movies);
                rateMovie(title, rating);
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
    Movies::loadMovies(movies);
    Series::loadSeries(series);
    home();
    return 0;
}