
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        static const int len = 100;
        std::string ideas[len];
    public:
        Brain();
        Brain(Brain const &src);
        ~Brain();
        Brain &operator=(Brain const &src);
        const std::string getIdea(int i) const;
        void setIdea(int i, std::string idea);
};


#endif