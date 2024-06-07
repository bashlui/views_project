# include <iostream>
# include <fstream>
# include <vector>

# include "Video.h"

Video::Video(){
    title = "";
    genre = "";
    duration = "";
    rating = 0.0;
}

Video::Video(std::string &_title, std::string &_genre, std::string &_duration, int &_rating){
    this->title = _title;
    this->genre = _genre;
    this->duration = _duration;
    this->rating = _rating;
}

std::string Video::getTitle() const{
    return title;
}

std::string Video::getGenre() const{
    return genre;
}

std::string Video::getDuration() const{
    return duration;
}

int Video::getRating() const{
    return rating;
}


