#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>
#include "../../includes/vector/vector_class.h"
#include "../../includes/system.h"
#include "../../includes/graph/graph.h"
#include "../../includes/graph_info/graph_info.h"
#include "../../includes/tokenizer/tokenizer.h"
#include "../../includes/queue/MyQueue.h"
#include "../../includes/token/token.h"
#include "../../includes/plot/plot.h"
#include "../../includes/shunting_yard/shunting_yard.h"
#include "SFML/Graphics.hpp"
using namespace std;

bool test_stub(bool debug = false)
{
  if (debug){
    cout << "testB:: test-sub() entering test_sub" << endl;
  }
  return true;
}

bool test_tokenizer(bool debug = false)
{
  Tokenizer tokenTest("2 + 5 / X * sin ( 5 )");
  tokenTest.infix_me();
  return true;
}

bool test_plot(bool debug = false)
{
  Queue<Token*> infixTest;
  Queue<Token*> postfixTest;

  Tokenizer tokenTest("2 + 5 / X * sin ( 5 )");
  infixTest = tokenTest.infix_me();
  ShuntingYard syTest(infixTest);
  postfixTest = syTest.postfix();

  //cout << postfixTest << endl;

  graph_info* info = new graph_info();
  Plot plotTest(info);
  plotTest.get_coords();

  return true;
}

bool test_graph(bool debug = false)
{
  
}

TEST(TEST_STUB, TestStub) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_stub(false));
}

TEST(TEST_FINAL, TestTokenizer) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_tokenizer(false));
}

TEST(TEST_FINAL, TestPlot) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_plot(false));
}

TEST(TEST_FINAL, TestGraph) {
  
  //EXPECT_EQ(0, <your individual test functions are called here>);

  EXPECT_EQ(1, test_graph(false));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}
 
