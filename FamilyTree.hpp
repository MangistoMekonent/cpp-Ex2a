#ifndef FAMILYTREE_H
#define FAMILYTREE_H
#include <string>

namespace family
{
    class Tree
    {
    public:
        Tree();
        Tree(std::string name_);
        Tree& addFather(std::string son,std::string father);
        Tree& addMother(std::string son,std::string father);
        void display();
        std::string relation(std::string name);
        std::string find(std::string name);
        void remove(std::string name);
        std::string getName();
        void setName(std::string name_);
    
    private:
        std::string name;
        Tree *left;
        Tree *right;


    };
}

#endif