#pragma once

#include "Node.hpp"
#include <stack>

namespace ariel
{
    template<typename T>
    class inorder_iterator
    {
        private:
        std::stack<Node<T>* > nodes;
        
        public:
        inorder_iterator(){};
        inorder_iterator(Node<T>* node)
        {
            while(node != nullptr)
            {
                nodes.push(node);
                node = node->left;
            }
        };

        inorder_iterator<T>& operator ++ ()
        {
            Node<T> *current_node = nodes.top()->right;
            nodes.pop();
            while (current_node != nullptr)
            {
                nodes.push(current_node);
                current_node = current_node->left;
            }
            return (*this);
        }

        inorder_iterator<T> operator ++ (int dummy)
        {
            inorder_iterator<T> temp = (*this);
            Node<T>* current_node = nodes.top()->right;
            nodes.pop();
            while (current_node != nullptr)
            {
                nodes.push(current_node);
                current_node = current_node->left;
            }
            return temp;
        }

        T& operator * ()
        {
            return nodes.top()->data;
        }

        T* operator -> ()
        {
            return &(nodes.top()->data);
        } 

        bool operator != (const inorder_iterator& other) const
        {
            if(this->nodes.empty() && other.nodes.empty())
            {
                return false;
            }
            if(this->nodes.empty() || other.nodes.empty())
            {
                return true;
            }
            if(this->nodes.top() != other.nodes.top())
            {
                return true;
            }
            return false;
        }

        bool operator == (const inorder_iterator& other) const
        {
            // return !(this->operator!= other);
            return !(*this != other);
        }

        Node<T>* get_node()
        {
            return nodes.top();
        }
    };
};