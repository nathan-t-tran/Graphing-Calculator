#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"

using namespace std;

class ShuntingYard
{
public:
    ShuntingYard(){}
    ShuntingYard(Queue<Token *> infix)
    {
        _infix_q = infix;
    }
    Queue<Token *> postfix(Queue<Token*> infix)
    {
        //Sets new infix.
        _infix_q = infix;

        //Creates stack and queue for ops and integers.
        Stack<Token *> op_stack;
        Queue<Token *> postfix;
        Token* pop_val;


        //Organizes stacks and queues.
        while (!_infix_q.empty())
        {
            pop_val = _infix_q.pop();
            switch (pop_val->TypeOf())
            {
                case 1:                     // Pushes integers into postfix queue.
                    postfix.push(pop_val);
                    break;
                case 2:                     //Pushes operators/functions into op stack.
                    if (static_cast<Operator*>(pop_val)->get_prec() == -1)
                    {
                        postfix.push(pop_val);
                    }
                    else 
                    {
                        while (!op_stack.empty())
                        {
                            if (op_stack.top()->TkStr() == "(")
                            {
                                break;
                            }
                            int pop_prec = static_cast<Operator*>(pop_val)->get_prec();
                            int op_prec = static_cast<Operator*>(op_stack.top())->get_prec();
                            if (op_prec < pop_prec)
                            {
                                break;
                            }
                            postfix.push(op_stack.pop());
                        }
                        op_stack.push(pop_val);
                    }
                    break;       
                case 3:                     //Pushes left parenthesis into op_stack.
                    op_stack.push(pop_val);
                    break;
                case 4:                     //Pops stack when right parenthesis is seen.
                    while (op_stack.top()->TkStr() != "(")
                    {
                        postfix.push(op_stack.pop());
                    }
                    op_stack.pop(); //disposes of left parenthesis.
                    break;        
                default:
                    break;
            }
        }
        //Pops operators into postfix
        while (!op_stack.empty())
        {
            pop_val = op_stack.pop();
            postfix.push(pop_val);
        }
        return postfix;
    }
    Queue<Token *> postfix()
    {
        return postfix(_infix_q);
    }

    void infix (Queue<Token*> infix)
    {
        _infix_q = infix;
    }

private:
    Queue<Token *> _infix_q;
};


#endif