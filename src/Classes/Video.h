# ifndef VIDEO_H
# define VIDEO_H
# include <string>

class Video {
    protected:
        Video();
        int id;
        std::string title;
        std::string genre;
        std::string duration;
        double rating;
    public:
        Video(int&, std::string&, std::string&, std::string&, double&);
        virtual void setId() = 0;
        virtual void setTitle() = 0;
        virtual void setDuration() = 0;
        virtual void setGenre() = 0;
        virtual void setRating() = 0;

        int getId() const;
        std::string getTitle() const;
        std::string getGenre() const;
        std::string getDuration() const;
        double getRating() const;
        virtual void display() = 0;
};

# endif // VIDEO_H