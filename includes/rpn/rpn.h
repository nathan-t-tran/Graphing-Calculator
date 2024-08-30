#ifndef RPN_H
#define RPN_H
#include <iostream>
#include "../../includes/queue/MyQueue.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/token/token.h"
#include "../../includes/token/operator.h"
#include "../../includes/token/integer.h"
#include <cmath>

using namespace std;

class RPN
{
public:
    RPN(Queue<Token *> Q)
    {
        _Queue = Q;
    }

    double operator () (double value = 1)
    {
        const bool debug = false;
        Stack<Token *> eval_stack; //Initializes evaluation stack
        Token* pop_val; //Initializes popped value from _Queue
        
        while (!_Queue.empty()) //While the queue is not empty
        {
            pop_val = _Queue.pop(); //pop_val holds popped value from _Queue

            switch (pop_val->TypeOf()) //Switch cases depending on what type is pop_val.
            {
                case 1: //When pop_val is an integer.
                {
                    if (debug) //debug
                    {
                        cout << "DEBUG: Case Int: pushing " << pop_val->TkStr() << endl;
                    }

                    eval_stack.push(pop_val); //Pushes integer into eval stack.

                    if (debug) //debug
                    {
                        for (Stack<Token *>::Iterator it = eval_stack.begin(); it != eval_stack.end(); it++)
                        {
                            cout <<setw(3)<< **it;
                        }
                        cout << endl;
                    }
                    break;
                }
                case 2: //When pop_val is an operator.
                {
                    if (debug) //debug
                    {
                        cout << "DEBUG: Case Op: " << pop_val->TkStr() << endl;
                    }
                    
                    Token* op = pop_val; //Gets operator token from pop_val

                    bool return_the_result = false; //Initializes a bool to return the results of calculations.
        
                    int op_prec = static_cast<Operator*> (op)->get_prec(); //Checks operator's precedence.
                    string op_type = static_cast<Operator*> (op)->op(); //Gets operator's string type.

                    
                    double result; //Declares result for calculations
                    
                    switch (op_prec) //Evaluates
                    {
                        case -1: // X or x
                        {
                            if (debug) //debug
                            {
                                cout << "DEBUG: Case Op: X: pushing " << value << endl;
                            }

                            eval_stack.push(new Integer(value)); //pushes given value when x is seen

                            break;
                        }
                        case 2: // + or -
                        {
                            if (op_type == "+") //if operator is +
                            {
                                Token* right_side = eval_stack.pop(); //Gets right_side token
                                Token* left_side = eval_stack.pop(); //Gets left_side token
                                double right_num = static_cast<Integer*> (right_side)->Num(); //Gets right number
                                double left_num = static_cast<Integer*> (left_side)->Num(); //Gets left number
                                result = left_num + right_num; //Sets result equal to sum of left and right number.
                                return_the_result = true; //Sets return bool as true
                            }
                            else if (op_type == "-") //if operator is -
                            {
                                //Gets value of two integers in stack
                                Token* right_side = eval_stack.pop();
                                Token* left_side = eval_stack.pop();
                                double right_num = static_cast<Integer*> (right_side)->Num();
                                double left_num = static_cast<Integer*> (left_side)->Num();
                                result = left_num - right_num;
                                return_the_result = true; 
                            }

                            if (debug) //debug
                            {
                                cout << "DEBUG: Case Op: +/-: pushing " << result << endl;
                            }

                            break;
                        case 3: // * or /
                            if (op_type == "*") //if operator is *
                            {   
                                Token* right_side = eval_stack.pop(); //gets right token
                                Token* left_side = eval_stack.pop(); //gets left token
                                double right_num = static_cast<Integer*> (right_side)->Num(); //get right number
                                double left_num = static_cast<Integer*> (left_side)->Num(); //get left number
                                result = left_num * right_num; //Sets result equal to product of left and right number
                                return_the_result = true; //sets return bool as true.
                            } 
                            else if (op_type == "/") //if operator is /
                            {
                                Token* right_side = eval_stack.pop(); //gets right token
                                Token* left_side = eval_stack.pop(); //gets left token
                                double right_num = static_cast<Integer*> (right_side)->Num(); //gets right number
                                double left_num = static_cast<Integer*> (left_side)->Num(); //gets left number
                                result = left_num / right_num; //sets result equal to quotient of left and right number
                                return_the_result = true; //sets return bool to true
                            }

                            if (debug) //debug
                            {
                                cout << "DEBUG: Case Op: *//: pushing " << result << endl;
                            }

                            break;
                        }
                        case 4:
                        {
                            if (op_type == "^")
                            {
                                Token* right_side = eval_stack.pop(); //gets right token
                                Token* left_side = eval_stack.pop(); //gets left token
                                double right_num = static_cast<Integer*> (right_side)->Num(); //gets right number
                                double left_num = static_cast<Integer*> (left_side)->Num(); //gets left number
                                result = pow(left_num,right_num); //sets result equal to quotient of left and right number
                                return_the_result = true; //sets return bool to true
                            }
                            break;
                        }
                        case 5: // sin, cos, tan, abs
                        {
                            if (op_type == "sin") //when operator is sin
                            {
                                Token* number_token = eval_stack.pop(); //gets token for number
                                double insert_number = static_cast<Integer*>(number_token)->Num(); //gets inserted number
                                result = sin(insert_number); //sets result equal to sin of inserted number
                                return_the_result = true; //sets result to true.
                            }
                            if (op_type == "csc") //when operator is sin
                            {
                                Token* number_token = eval_stack.pop(); //gets token for number
                                double insert_number = static_cast<Integer*>(number_token)->Num(); //gets inserted number
                                result = 1/(sin(insert_number)); //sets result equal to sin of inserted number
                                return_the_result = true; //sets result to true.
                            }
                            else if (op_type == "cos")
                            {
                                Token* number_token = eval_stack.pop();
                                double insert_number = static_cast<Integer*>(number_token)->Num();
                                result = cos(insert_number);
                                return_the_result = true;
                            }
                            else if (op_type == "sec")
                            {
                                Token* number_token = eval_stack.pop();
                                double insert_number = static_cast<Integer*>(number_token)->Num();
                                result = 1/(cos(insert_number));
                                return_the_result = true;
                            }
                            else if (op_type == "tan")
                            {
                                Token* number_token = eval_stack.pop();
                                double insert_number = static_cast<Integer*>(number_token)->Num();
                                result = tan(insert_number);
                                return_the_result = true;
                            }
                            else if (op_type == "cot")
                            {
                                Token* number_token = eval_stack.pop();
                                double insert_number = static_cast<Integer*>(number_token)->Num();
                                result = 1/(tan(insert_number));
                                return_the_result = true;
                            }
                            else if (op_type == "abs")
                            {
                                Token* number_token = eval_stack.pop();
                                double insert_number = static_cast<Integer*>(number_token)->Num();
                                result = abs(insert_number);
                                return_the_result = true;
                            }
                            if (debug)
                            {
                                cout << "DEBUG: Case Op: trig/abs: pushing: " << result << endl;
                            }

                            break;
                        }
                        case 6: //log
                        {
                            Token* log_token = eval_stack.pop();
                            double log_number = static_cast<Integer*>(log_token)->Num();
                            result = log(log_number);
                            return_the_result = true;
                            break;
                        }
                        default:
                            break;
                    }

                    if (return_the_result == true)
                    {
                        eval_stack.push(new Integer(result));
                    }

                    if (debug) //debug
                    {
                        cout << endl;
                        cout << "Current Eval Stack: ";
                        for (Stack<Token *>::Iterator it = eval_stack.begin(); it != eval_stack.end(); it++)
                        {
                            cout <<setw(3)<< **it;
                        }
                        cout << endl << endl;
                    }
                    break;
                }
                default:
                    break;
            }
        }
        //cout << "I AM POPPING THE STACK: " << eval_stack << endl;
        Token* result = eval_stack.pop();
        double return_val = static_cast<Integer*>(result)->Num();    
        return return_val;
    }

    void set_input (Queue<Token *> q)
    {
        _Queue = q;
    }

    friend ostream& operator <<(ostream& outs, RPN queue)
    {
        outs << *(queue._Queue.front());
        return outs;
    }

private:
    Queue<Token *> _Queue;
};

#endif