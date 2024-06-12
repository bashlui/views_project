# include "Video2.h"

Video2::Video2(){
    id = 0;
    title = "";
    genre = "";
}

Video2::~Video2()= default;

Video2::Video2(int &_id, std::string &_title, std::string &_genre){
    this->id = _id;
    this->title = _title;
    this->genre = _genre;
}

int Video2::getId2() const{
    return id;
}

std::string Video2::getTitle2() const{
    return title;
}

std::string Video2::getGenre2() const{
    return genre;
}