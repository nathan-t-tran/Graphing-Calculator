#ifndef GRAPH_INFO
#define GRAPH_INFO
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../includes/constants.h"

using namespace std;

struct graph_info
{
    graph_info()
    {
        //cout << "GRAPH_INFO: CREATING INFO" << endl;
        _equation = "x";
        _userEquation = "";
        _window_dimension.x = SCREEN_HEIGHT;
        _window_dimension.y = SCREEN_WIDTH;
        _origin.x = WORK_PANEL/2;
        _origin.y = SCREEN_HEIGHT/2;
        _points = 300;
        _shifter = 0;
        xshifter = 0;
        _domain.x = -5;
        _domain.y = 5;
        userHelp = 0;
        userInput = 0;
        moveRight = 0;
        moveLeft = 0;
        //cout << "GRAPH_INFO: CREATED INFO" << endl;
    }
    graph_info(double dmin, double dmax)
    {
        //cout << "GRAPH_INFO: CREATING INFO" << endl;
        _equation = "x";
        _userEquation = "";
        _window_dimension.x = SCREEN_HEIGHT;
        _window_dimension.y = SCREEN_WIDTH;
        _origin.x = WORK_PANEL/2;
        _origin.y = SCREEN_HEIGHT/2;
        _points = 300;
        _shifter = 0;
        xshifter = 0;
        _domain.x = dmin;
        _domain.y = dmax;
        userHelp = 0;
        userInput = 0;
        moveRight = 0;
        moveLeft = 0;
        cout << "GRAPH_INFO: CREATED INFO" << endl;
    }
    string _equation; //Inputted equation   
    string _userEquation; //user equation
    sf::Vector2f _window_dimension; //Dimension of the window
    sf::Vector2f _origin; //The origin of the graph given window
    sf::Vector2f _scale; //Scale of the graph
    sf::Vector2f _domain; //Gets domain of the graph
    int _points; //Gets the number of points in the graph.
    double _shifter;
    double xshifter;
    
    int userHelp;
    int userInput;
    int moveRight;
    int moveLeft;
};

#endif
