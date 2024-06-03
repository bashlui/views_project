# include "Video.h"

Video::Video() {
    videoId = 0;
    videoName = "";
    videoLength = 0;
    videoGenre = "";
    videoRating = 0.0;
}

Video::Video(int id, std::string name, int length, std::string genre, float rating) {
    videoId = id;
    videoName = name;
    videoLength = length;
    videoGenre = genre;
    videoRating = rating;
}


