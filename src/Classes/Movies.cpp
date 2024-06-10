
# include "Movies.h"
# include <iostream>
# include <fstream>
# include <sstream>
# include <utility>
# include <vector>
# include <algorithm>

using namespace std;

string red = "\033[31m";
string reset = "\033[0m";

Movies::Movies() : Video() {
    releaseDate = "";
}

Movies::Movies(std::string &_title, std::string &_genre, std::string &_duration, int &_rating, std::string &_releaseDate)
: Video(_title, _genre, _duration, _rating) {
    releaseDate = _releaseDate;
}

void Movies::setMovieReleaseDate(std::string date) {
    releaseDate = std::move(date);
}

std::string Movies::getMovieReleaseDate() {
    return releaseDate;
}

// Trim leading and trailing spaces
string Movies::trim(const string &str) {
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first) {
        return "";
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Load movies from file
void Movies::loadMovies(vector<Video> &videos) {
    ifstream file("Data/Peliculas.txt");
    if (!file.is_open()) {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
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
                videos.emplace_back(title, genre, duration, movieRate);
            } catch (const invalid_argument &e) {
                cout << "Error al convertir el rating a entero: " << title << endl;
                continue;
            }
        }
    }
    file.close();
}

// Show movies list
void Movies::showMovieList(vector<Video> &videos) {
    loadMovies(videos);

    for (const auto &video : videos) {
        cout << "Title: " << video.getTitle() << endl;
        cout << "Genre: " << video.getGenre() << endl;
        cout << "Duration: " << video.getDuration() << endl;
        cout << "Rating: " << video.getRating() << endl;
        cout << "--------------------------------" << endl;
    }
}

// Show movies by rating
void Movies::showMovieByRating(vector<Video> &movies, int sRate) {
    loadMovies(movies);

    for (const auto &movie : movies) {
        if (movie.getRating() == sRate) {
            cout << "Title: " << movie.getTitle() << endl;
            cout << "Genre: " << movie.getGenre() << endl;
            cout << "Duration: " << movie.getDuration() << endl;
            cout << "Rating: " << red << movie.getRating() << reset << endl;
            cout << "--------------------------------" << endl;
        }
    }
}

void Movies::showMovieByGenre(vector<string> &genres, vector<Video> &movies) {
    for (const auto &movie : movies) {
        if (find(genres.begin(), genres.end(), movie.getGenre()) != genres.end()) {
            cout << "Title: " << movie.getTitle() << endl;
            cout << "Genre: " << red << movie.getGenre() << reset << endl;
            cout << "Duration: " << movie.getDuration() << endl;
            cout << "Rating: " << movie.getRating() << endl;
            cout << "--------------------------------" << endl;
        }
    }
}
