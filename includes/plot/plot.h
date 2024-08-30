#ifndef PLOT_H
#define PLOT_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../includes/coord_translate/coord_translate.h"
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "../../includes/rpn/rpn.h"
#include "../../includes/token/token.h"
#include "../../includes/tokenizer/tokenizer.h"
#include "../../includes/vector/vector_class.h"

using namespace std;

class Plot
{
public:
    Plot(){}
    Plot(graph_info* info)
    {
        set_info(info);
    }

    void set_info(graph_info* info)
    {
        //cout << "PLOT: CREATING PLOT" << endl;
        Queue<Token*> infix;
        _info = info;   //Stores graph info into _info
        string equation = _info->_equation; //Gets equation string from info

        //Tokenizes string
        Tokenizer tokenizer(equation);
        infix = tokenizer.infix_me();

        //gets postfix from infix
        ShuntingYard shuntingYard(infix);
        _postfix = shuntingYard.postfix();
        //cout << _postfix << endl;

        //cout << "PLOT: CREATED PLOT" << endl;
    }

    Vector<sf::Vector2f> get_coords()
    {
        //cout << "PLOT: GETTING COORDS" << endl;
        
        Vector<sf::Vector2f> calculated_points;
        double minimum = _info->_domain.x;
        double maximum = _info->_domain.y;
        double total_points = maximum-minimum;
        double spaces_between = total_points/WORK_PANEL;

        //cout << "PLOT: CALCULATING COORDS" << endl;
        while (minimum+1 <= _info->_domain.y+1)
        {   
            RPN rpnMe(_postfix);
            //cout << "I HAPPEN" << endl;
            double y_coord = rpnMe(minimum);
            calculated_points.push_back(sf::Vector2f(minimum, -1 * y_coord));
            //cout << "GET_COORDS: I AM BEING PUSHED: ( " << minimum << " , " << y_coord << " )" << endl;
            minimum += spaces_between;
        }
        //cout << "PLOT: CALCULATED COORDS" << endl;

        coord_translate translator(_info);
        //cout << "PLOT: GOT COORDS" << endl;
        return translator.translate(calculated_points);

    }
private:

    graph_info* _info;
    Queue<Token*> _postfix;
};

#endif