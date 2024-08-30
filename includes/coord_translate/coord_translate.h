#ifndef COORD_TRANSLATE_H
#define COORD_TRANSLATE_H

#include <iostream>
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/vector/vector_class.h"
#include "SFML/Graphics.hpp"

using namespace std;

class coord_translate
{
public:
    coord_translate(){}
    coord_translate(graph_info* info)
    {
        _info = info;
    }
    Vector<sf::Vector2f> translate (Vector<sf::Vector2f> points)
    {
        //cout << "COORD_TRANSLATE: TRANSLATING COORDS" << endl;

        //Declares and intializes vars
        Vector<sf::Vector2f> translated_points;
        sf::Vector2f point_to_translate;
        double x = -3;

        //Finds how many spaces between each points given domain
        float number_of_points = _info->_domain.y - _info->_domain.x;
        float spaces_between_points = WORK_PANEL/(number_of_points + 1);

        //Translates points.
        for (int i = 0; i < points.size(); i++)
        {
            point_to_translate = points[i];
            point_to_translate.x = (spaces_between_points * point_to_translate.x) + 560; 
            point_to_translate.y = ((spaces_between_points * point_to_translate.y) + 400) + (_info->_shifter*_info->_points)-2;
            //cout << "TRANSLATED POINTS: ( " << point_to_translate.x << " , " << point_to_translate.y << " )" << endl;
            translated_points.push_back(point_to_translate);
        }

        //cout << "COORD_TRANSLATE: TRANSLATED COORD" << endl;
        return translated_points;
    }
    
private:
    graph_info* _info;
};


#endif