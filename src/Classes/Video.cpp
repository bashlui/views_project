# include "Video.h"
# include <iostream>
# include <string>

Video::Video(){
    id = 0;
    title = "";
    genre = "";
    duration = "";
    rating = 0.0;
}

Video::Video(int &_id, std::string &_title, std::string &_genre, std::string &_duration, double &_rating){
    id = _id;
    title = _title;
    genre = _genre;
    duration = _duration;
    rating = _rating;
}

int Video::getId() const{
    return id;
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

double Video::getRating() const{
    return rating;
}

void display(){

}
