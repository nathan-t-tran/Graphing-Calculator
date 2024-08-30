#ifndef GRAPH_H
#define GRAPH_H
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/vector/vector_class.h"
#include "SFML/Graphics.hpp"
#include "../../includes/animate.h"
#include "../../includes/constants.h"
#include "../../includes/system.h"
#include "../../includes/plot/plot.h"

using namespace std;

class Graph
{
public:
    Graph(){}
    Graph(graph_info* info)
    {
        cout << "GRAPH: CREATING GRAPH" << endl;
        set_info(info);
        _plotter = Plot(_info);
        _points = _plotter.get_coords();
        cout << "GRAPH: CREATED GRAPH" << endl;
    }

    void set_info(graph_info* info)
    {
        _info = info;
    }
    void update(graph_info* info)
    {
        set_info(info);
        _plotter = Plot(_info);
        _points = _plotter.get_coords();
    }
    void draw(sf::RenderWindow& window)
    {
        //cout << "GRAPH: DRAWING GRAPH" << endl;
        window.clear();
        
        //cout << "GRAPH: DRAWING AXISES" << endl;
        sf::RectangleShape xaxis;
        sf::RectangleShape yaxis;

        xaxis.setPosition(sf::Vector2f(0,SCREEN_HEIGHT/2 + (_info->_shifter*_info->_points)));
        xaxis.setSize(sf::Vector2f(SCREEN_WIDTH-SIDE_BAR, 1));
        xaxis.setFillColor(sf::Color::White);

        yaxis.setRotation(90);
        if(_info->_domain.x<0){
            yaxis.setPosition(((WORK_PANEL/(abs(_info->_domain.x-_info->_domain.y)))*(abs(0+_info->_domain.x))), 0.f);
        } else {
            yaxis.setPosition(((WORK_PANEL/(abs(_info->_domain.x-_info->_domain.y)))*(0-_info->_domain.x)), 0.f);
        }
        yaxis.setSize(sf::Vector2f(SCREEN_HEIGHT, 1));
        yaxis.setFillColor(sf::Color::White);

        window.draw(xaxis);
        window.draw(yaxis);
        //cout << "GRAPH: DREW AXISES" << endl;
        cout << "GRAPH: XSHIFTER: " << _info->xshifter << endl;
        //cout << "GRAPH: DRAWING POINTS" << endl;
        for (int i = 0; i < _points.size(); i++)          //Draws points onto graph.
        {
            //cout << "I HAPPEN" << endl;
            sf::CircleShape points;
            points.setFillColor(sf::Color::White);
            points.setRadius(2);
            //cout << "I AM BEING DRAWN: ( " << _points[i].x << " , " << _points[i].y << " )" << endl;
            points.setPosition((_points[i].x + _info->xshifter),_points[i].y);
            window.draw(points);
        }
        //cout << "GRAPH: DREW GRAPH" << endl;
        //user equation box and text
        //cout << "INPUT BOOL: " << _info->userInput << endl;
        
        if(_info->userInput == 1){
            sf::RectangleShape inputBox;
            sf::Text input;
            sf::Font font;
            if (!font.loadFromFile("arial.ttf")){
                cout<<"System() CTOR: Font failed to load"<<endl;
                cin.get();
                exit(-1);
            }
            inputBox.setSize(sf::Vector2f(300,50));
            inputBox.setPosition(850, 720);
            inputBox.setFillColor(sf::Color::Black);
            inputBox.setOutlineColor(sf::Color::White);
            inputBox.setOutlineThickness(1);

            input = sf::Text("y = " +_info->_userEquation, font);
            input.setCharacterSize(30);
            input.setPosition(850, 720);
            input.setFillColor(sf::Color::White);

            window.draw(inputBox);
            window.draw(input);
        }
    }
private:
    Plot _plotter;
    Vector<sf::Vector2f> _points;
    graph_info* _info;

};
#endif