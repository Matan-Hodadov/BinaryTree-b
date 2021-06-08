#pragma once

#include "Node.hpp"
#include <list>

namespace ariel
{
    template <typename T>
    class postorder_iterator
    {
        private:
        std::list<Node<T>* > nodes;
        void postorder(Node<T>* current_node)
        {
            if (current_node != nullptr)
            {
                if (current_node->left != nullptr)
                {
                    postorder(current_node->left);
                }
                if (current_node->right != nullptr)
                {
                    postorder(current_node->right);
                }
                nodes.push_back(current_node);
            }
        }

        public:
        postorder_iterator(){};
        postorder_iterator(Node<T>* node)
        {
            postorder(node);
        };

        postorder_iterator<T>& operator ++ ()
        {
            nodes.pop_front();
            return (*this);
        }

        postorder_iterator<T> operator ++ (int dummy)
        {
            postorder_iterator<T> temp = (*this);
            nodes.pop_front();
            return temp;
        }

        T& operator * ()
        {
            return nodes.front()->data;
        }

        T* operator -> ()
        {
            return &(nodes.front()->data);
        }

        bool operator != (const postorder_iterator &other) const
        {
            if(this->nodes.empty() && other.nodes.empty())
            {
                return false;
            }
            if(this->nodes.empty() || other.nodes.empty())
            {
                return true;
            }
            if(this->nodes.front() != other.nodes.front())
            {
                return true;
            }
            return false;
        }

        bool operator == (const postorder_iterator& other) const
        {
            // return !(this->operator!= other);
            return !(*this != other);
        }

        Node<T>* get_node()
        {
            return nodes.front();
        }
    };
};