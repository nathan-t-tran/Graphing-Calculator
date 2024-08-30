#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "graph_info/graph_info.h"
#include "graph/graph.h"
#include "random.h"
#include "constants.h"

using namespace std;
class System
{
public:
    System(){}
    System(graph_info* info)
    {
        cout << "SYSTEM: CREATING SYSTEM" << endl;
        set_info(info);
        _graph = Graph(info);
        Random r;
        int xpos = 100;
        int ypos = 100;
        //the shape of the object, along with its velocity, acceleration,
        //position, etc. should be part of the individual object.
        shape = sf::CircleShape(10);
        shape.setPosition(sf::Vector2f(xpos, ypos));
        vel = sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity
        int r_ = r.Next(0,255);
        int g_ = r.Next(0,255);
        int b_ = r.Next(0,255);
        shape.setFillColor(sf::Color(r_, g_, b_));
        cout << "SYSTEM: CREATED SYSTEM" << endl;
    }

    void set_info (graph_info* info)
    {
        _info = info;
    }

    void Step(int command, graph_info* info)
    {
        _graph.update(info);
        //all this is the responsibility of the 
        // individual object:
        shape.move(vel);
        sf::Vector2f pos = shape.getPosition();
        if ((pos.x)>=WORK_PANEL-20)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if (pos.x<=0)
            vel = sf::Vector2f(-1*vel.x,1*vel.y);
        if ((pos.y)>=SCREEN_HEIGHT-20)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
        if (pos.y<=0)
            vel = sf::Vector2f(1*vel.x,-1*vel.y);
    }
    int Size();
    void Draw(sf::RenderWindow& window)
    {
        _graph.draw(window);
        //window.clear();
        //window.draw(shape);
    }
private:
//    vector<Particle> system;
    sf::CircleShape shape;
    sf::Vector2f vel;
    graph_info* _info;
    Graph _graph;
};

#endif // SYSTEM_H
