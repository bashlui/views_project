
# include "Movies.h"
# include <iostream>
# include <vector>

Movies::Movies() : Video() {
    releaseDate = "";
}

Movies::Movies(int &_id, std::string &_title, std::string &_genre, std::string &_duration, double &_rating, std::string &_releaseDate) : Video(_id, _title, _genre, _duration, _rating) {
    releaseDate = _releaseDate;
}

std::string Movies::getMovieReleaseDate() {
    return releaseDate;
}

void display(){

}