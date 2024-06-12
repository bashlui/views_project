# include "Video2.h"

Video2::Video2(){
    title = "";
    genre = "";
}

Video2::~Video2()= default;

Video2::Video2(std::string &_title, std::string &_genre){
    this->title = _title;
    this->genre = _genre;
}

std::string Video2::getTitle2() const{
    return title;
}

std::string Video2::getGenre2() const{
    return genre;
}