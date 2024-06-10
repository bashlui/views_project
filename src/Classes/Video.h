# ifndef VIDEO_H
# define VIDEO_H
# include <vector>
# include <string>

class Video {
    protected:
        std::string title;
        std::string genre;
        std::string duration;
        int rating;
    public:
        Video();
        Video(std::string&, std::string&, std::string&, int&);
        std::string getTitle() const;
        std::string getGenre() const;
        std::string getDuration() const;
        int getRating() const;
};

# endif // VIDEO_H