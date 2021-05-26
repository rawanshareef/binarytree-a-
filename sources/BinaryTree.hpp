#pragma once
#include <iostream>

namespace ariel
{
    template <typename T>
    class BinaryTree
    {

    private:
        struct Node //class for  Node
        {
            T data;//the value of node
            Node *left;//left child
            Node *right;//right child
            Node *parent;//the parent
            Node(T val) : data(val) ,left(NULL), right(NULL), parent(NULL){};//constructor
        };
        Node *root; //the root of the tree

    public:
        BinaryTree<T>() {}

        //1//
        BinaryTree &add_root(const T &new_root)
        { //add the new_root to thr root
            return *this;
        }
        //2//
        BinaryTree &add_left(const T &father, const T &left)
        { //add the father the left node if there is a left child then bully him
            return *this;
        }
        //3//
        BinaryTree &add_right(const T &father, const T &right)
        { //add the father the r night node if there is a right child then bully him
            return *this;
        }
        //********************************************************
        //-------------------class preorder iterator----------------------
        //********************************************************

        //preorder iterator
        class preorder_iterator
        {

        private:
            Node *pointer_to_preorder;

        public:
            preorder_iterator(Node *ptr = nullptr) : pointer_to_preorder(ptr){}; //indicates thecurrent junction
            T &operator*() const { return pointer_to_preorder->data; }
            T *operator->() const { return &(pointer_to_preorder->data); }

            preorder_iterator &operator++()
            { //++x
                return *this;
            }
            const preorder_iterator &operator++(int x)
            { //x++
                return *this;
            }
            bool operator==(const preorder_iterator &a) const
            {
                return false;
            }
            bool operator!=(const preorder_iterator &a) const
            {
                return false;
            }
        };
        //********************************************************
        //-------------------class inorder iterator----------------------
        //********************************************************

        //inorder iterator
        class inorder_iterator
        {

        private:
            Node *pointer_to_inorder;

        public:
            inorder_iterator(Node *ptr = nullptr) : pointer_to_inorder(ptr){}; //indicates thecurrent junction
            T &operator*() const { return pointer_to_inorder->data; }
            T *operator->() const { return &(pointer_to_inorder->data); }

            inorder_iterator &operator++()
            { //++x
                return *this;
            }
            const inorder_iterator &operator++(int x)
            { //x++
                return *this;
            }
            bool operator==(const inorder_iterator &a) const
            {
                return false;
            }
            bool operator!=(const inorder_iterator &a) const
            {
                return false;
            }
        };
        //********************************************************
        //-------------------class postorder iterator----------------------
        //********************************************************

        //postorder iterator
        class postorder_iterator
        {

        private:
            Node *pointer_to_postorder;

        public:
            postorder_iterator(Node *ptr = nullptr) : pointer_to_postorder(ptr){}; //indicates thecurrent junction
            T &operator*() const { return pointer_to_postorder->data; }
            T *operator->() const { return &(pointer_to_postorder->data); }

            postorder_iterator &operator++()
            { //++x
                return *this;
            }
            const postorder_iterator &operator++(int x)
            { //x++
                return *this;
            }
            bool operator==(const postorder_iterator &a) const
            {
                return false;
            }
            bool operator!=(const postorder_iterator &a) const
            {
                return false;
            }
        };

        //---------------------------------------------------------//
        //------------------return iterator----- ------------------//
        //---------------------------------------------------------//
        //preorder
        preorder_iterator begin_preorder()
        {
            return preorder_iterator(root);
        }
        preorder_iterator end_preorder()
        {
            return preorder_iterator(nullptr);
        }

        //inorder
        inorder_iterator begin_inorder()
        {
            return inorder_iterator(root);
        }
        inorder_iterator end_inorder()
        {
            return inorder_iterator(nullptr);
        }

        //postorder
        postorder_iterator begin_postorder()
        {
            return postorder_iterator(root);
        }
        postorder_iterator end_postorder()
        {
            return postorder_iterator(nullptr);
        }

        inorder_iterator begin()
        {
            return begin_inorder();
        }

        inorder_iterator end()
        {
            return end_inorder();
        }

        friend std::ostream &
        operator<<(std::ostream &os, const BinaryTree<T> &my_tree) //print the tree
        {
            return os;
        }
    };
}