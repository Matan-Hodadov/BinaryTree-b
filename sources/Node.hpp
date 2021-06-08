#pragma once

namespace ariel
{
    template <typename T>
    class Node
    {
        public:

        T data;
        Node* left;
        Node* right;

        Node(Node* left = nullptr, Node* right = nullptr)
        :left(left), right(right)
        {
            // this->left = left;
            // this->right = right;
        }

        Node(const T& data)
        :data(data), left(nullptr), right(nullptr)
        {}
    };
};