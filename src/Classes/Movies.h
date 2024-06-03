# ifndef MOVIES_H
# define MOVIES_H

# include "Video.h"
# include <vector>

/*
Para poder añadir las películas en forma de lista, necesito un vector de objetos de la clase Movies que hereden los atributos de la clase Video \
que se encargue de almacenar las películas que se encuentran en el archivo de texto "Peliculas.txt".
Además, necesito un método que me permita añadir una película a la lista de películas, que reciba como parámetro un objeto de la clase Movies y lo añada al vector.
Esto para que cuando el usuario quiero calificar la película, pueda acceder a ella y modificar su calificación.
Una vez la calificación modificada, se verá reflejada a la calificación de la película en la lista. 
*/


class Movies : public Video {
    private:
        std::vector<Movies*> moviesList;
    public:
        Movies();
        
    
};



# endif // MOVIES_H