#include <array>
#include <string>
#include "BinaryTree.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

//inorder:left,root,right
//preorder:root,left,right
//postorder:left,right,root

TEST_CASE("check the tree ")
{
    BinaryTree<int> my_tree;
    CHECK_THROWS(my_tree.add_right(1, 2));  //exepction
    CHECK_THROWS(my_tree.add_right(10, 7)); //exepction
    CHECK_THROWS(my_tree.add_left(2, 5));   //exepction
    CHECK_THROWS(my_tree.add_left(7, 3));   //exepction
}
TEST_CASE("vertex connction error ")
{
    BinaryTree<int> my_tree;
    my_tree.add_root(7);
    CHECK_THROWS(my_tree.add_right(1, 2));  //exepction 1 not a root
    CHECK_NOTHROW(my_tree.add_right(7,2));
    CHECK_NOTHROW(my_tree.add_left(2,1));//true 

}



TEST_CASE("check the root tree ")
{
    BinaryTree<int> my_tree;
    my_tree.add_root(7);
    CHECK_EQ(*my_tree.begin(), 7);
    CHECK_NE(*my_tree.begin(), 6);
    my_tree.add_root(6);
    CHECK_EQ(*my_tree.begin(), 6);
    CHECK_NE(*my_tree.begin(), 7);
}
TEST_CASE("check the left child in the tree ")
{
    BinaryTree<int> my_tree;
    int the_left;
    my_tree.add_root(7);
    my_tree.add_left(7,3);//now the left it 3
    the_left=3;
    CHECK_EQ(3,the_left);
    my_tree.add_left(7,2);//now the left it 2
    the_left=2;
    CHECK_EQ(2,the_left);
}

//------------------------------------------------------
//-----------------------int-----------------------------
TEST_CASE("check inorder tree(int) ")
{
    BinaryTree<int> my_tree;

    /*
                              1
                           /     \
                          2       3 
                         / \     / \
                        4   5   6   7
    */

    array<int, 7> inorder_tree{4, 2, 5, 1, 6, 3, 7};
    //bulid tree
    CHECK_NOTHROW(my_tree.add_root(1));
    CHECK_NOTHROW(my_tree.add_right(1, 3));
    CHECK_NOTHROW(my_tree.add_left(1, 2));
    CHECK_NOTHROW(my_tree.add_right(3, 7));
    CHECK_NOTHROW(my_tree.add_left(3, 6));
    CHECK_NOTHROW(my_tree.add_right(2, 5));
    CHECK_NOTHROW(my_tree.add_left(3, 4));

    unsigned long check = 0;
    for (auto it = my_tree.begin_inorder(); it != my_tree.end_inorder(); ++it)
    {
        CHECK_EQ((*it), inorder_tree.at(check++));
    }
}

TEST_CASE("check preorder tree(int) ")
{
    BinaryTree<int> my_tree;

    /*
                              1
                           /     \
                          2       3 
                         / \     / \
                        4   5   6   7
    */

    array<int, 7> preorder_tree{1, 2, 4, 5, 3, 6, 7};
    //bulid tree
    CHECK_NOTHROW(my_tree.add_root(1));
    CHECK_NOTHROW(my_tree.add_right(1, 3));
    CHECK_NOTHROW(my_tree.add_left(1, 2));
    CHECK_NOTHROW(my_tree.add_right(3, 7));
    CHECK_NOTHROW(my_tree.add_left(3, 6));
    CHECK_NOTHROW(my_tree.add_right(2, 5));
    CHECK_NOTHROW(my_tree.add_left(3, 4));

    unsigned long check = 0;
    for (auto it = my_tree.begin_preorder(); it != my_tree.end_preorder(); ++it)
    {
        CHECK_EQ((*it), preorder_tree[check++]);
    }
}
TEST_CASE("check postorder tree(int)")
{
    BinaryTree<int> my_tree;

    /*
                              1
                           /     \
                          2       3 
                         / \     / \
                        4   5   6   7
    */

    array<int, 7> postorder_tree{7, 6, 3, 5, 4, 2, 1};
    //bulid tree
    CHECK_NOTHROW(my_tree.add_root(1));
    CHECK_NOTHROW(my_tree.add_right(1, 3));
    CHECK_NOTHROW(my_tree.add_left(1, 2));
    CHECK_NOTHROW(my_tree.add_right(3, 7));
    CHECK_NOTHROW(my_tree.add_left(3, 6));
    CHECK_NOTHROW(my_tree.add_right(2, 5));
    CHECK_NOTHROW(my_tree.add_left(3, 4));

    unsigned long check = 0;
    for (auto it = my_tree.begin_postorder(); it != my_tree.end_postorder(); ++it)
    {
        CHECK_EQ((*it), postorder_tree.at(check++));
    }
}
//**************************************************
//****************string****************************
TEST_CASE("check inorder+postorder+preorder tree(string) ")
{
    BinaryTree<int> my_tree;

    /*
                              a
                           /     \
                          b       c 
                         / \     / \
                        d   e   f   g
    */

    array<int, 7> inorder_tree{'d', 'b', 'e', 'a', 'f', 'c', 'g'};
    array<int, 7> postorder_tree{'g', 'f', 'c', 'e', 'd', 'b', 'a'};
    array<int, 7> preorder_tree{'a', 'b', 'd', 'e', 'c', 'f', 'g'};

    //bulid tree
    CHECK_NOTHROW(my_tree.add_root('a'));
    CHECK_NOTHROW(my_tree.add_right('a', 'c'));
    CHECK_NOTHROW(my_tree.add_left('a', 'b'));
    CHECK_NOTHROW(my_tree.add_right('c', 'g'));
    CHECK_NOTHROW(my_tree.add_left('c', 'f'));
    CHECK_NOTHROW(my_tree.add_right('b', 'e'));
    CHECK_NOTHROW(my_tree.add_left('c', 'd'));

    unsigned long check = 0;
    for (auto it = my_tree.begin_inorder(); it != my_tree.end_inorder(); ++it)
    {
        CHECK_EQ((*it), inorder_tree.at(check++));
    }
    unsigned long check2 = 0;
    for (auto it = my_tree.begin_postorder(); it != my_tree.end_postorder(); ++it)
    {
        CHECK_EQ((*it), postorder_tree.at(check2++));
    }
    unsigned long check3 = 0;
    for (auto it = my_tree.begin_preorder(); it != my_tree.end_preorder(); ++it)
    {
        CHECK_EQ((*it), preorder_tree.at(check3++));
    }
}
