# ifndef VIDEO_H
# define VIDEO_H
# include <string>

class Video {
    protected:
        int videoId;
        std::string videoName;
        int videoLength;
        std::string videoGenre;
        float videoRating;

    public:
        Video();
        Video(int, std::string, int, std::string, float);
        virtual void display();
        virtual void getVideoId() = 0;
        virtual void getVideoName() = 0;
        virtual void getVideoLength() = 0;
        virtual void getVideoGenre() = 0;
        virtual void getVideoRating() = 0;
};

# endif // VIDEO_H