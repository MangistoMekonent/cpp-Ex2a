#include <iostream>
#include <string>
#include "FamilyTree.hpp"
using namespace family;


family::Tree::Tree(std::string name_)
{
    name = name_;
    left = NULL;
    right = NULL;
}
Tree& family::Tree::addFather(std::string son,std::string father)
{
    if (this->name.compare(son) == 0 && this->left == NULL)
    {
        this->left = new Tree(father);
        return *this;
    }
    return *this;
    
}
Tree& family::Tree::addMother(std::string son,std::string mother)
{
    if (this->name.compare(son) == 0 && this->right == NULL)
    {
        this->right = new Tree(mother);
        return *this;
    }
    return *this;
}
void family::Tree::display()
{
    return;
}
std::string family::Tree::relation(std::string name)
{
    return "say what";
}
std::string family::Tree::find(std::string name)
{
    return "found";
}
void family::Tree::remove(std::string name)
{
    return;
}
std::string family::Tree::getName()
{
    return name;
}
void family::Tree::setName(std::string name_)
{
    this->name = name_;
}





