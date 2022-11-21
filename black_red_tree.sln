#include <iostream>
#include <vector>

using namespace std;
/*Реализовать
«Красно - чёрное дерево»
Реализовать необходимые класса функции :
конструкторы, деструкторы, 
нужные методы :
добавление, удаление, поиск минимума максимума

Добавьтe итераторы для перечисления элементов дерева

Оптимизировать построенный код : 
1) по производительности,
2) по потреблению*/

class TreeIterator;
enum NodeColor{Black,Red};

class BRNode {
public:
    BRNode(int value, NodeColor color, BRNode* left = nullptr, BRNode* right = nullptr, BRNode* parent = nullptr) : _value(value), _color(color), _left(nullptr),_right(nullptr),_parent(parent){}

    int _value;
    NodeColor _color;
    BRNode* _left, * _right,* _parent;
};


class TreeIterator :public std::iterator<std::input_iterator_tag, BRNode> {
    BRNode* node;
public:
    TreeIterator(BRNode* node_ = nullptr) : node(node_) {}
    TreeIterator(const TreeIterator& T) : node(T.node) {}

    bool operator== (const TreeIterator& T) const { return node == T.node; }
    bool operator!= (const TreeIterator& T) const { return node != T.node; }

    int& operator* () { return node->_value; }
    const int& operator* () const { return node->_value; }

    TreeIterator& operator++() {
        if (node->_right) {
            node = node->_right;
            while (node->_left) {
                node = node->_left;
            }
        }
        else
        {
            BRNode* t = node->_parent;
            while (t && t->_right == node) {
                node = t;
                t = node->_parent;
            }
            if (node->_right != t) {
                node = t;
            }
        }
        return *this;
    }

    TreeIterator& operator--() {
        if (node->_left) {
            node = node->_left;
            while (node->_right) {
                node = node->_right;
            }
        }
        else
        {
            BRNode* t = node->_parent;
            while (t && t->_left == node) {
                node = t;
                t = node->_parent;
            }
            if (node->_left != t) {
                node = t;
            }
        }
        return *this;
    }

    TreeIterator operator++(int) {
        TreeIterator old(node);
        ++* this;
        return old;
    }

    TreeIterator operator--(int) {
        TreeIterator old(node);
        --* this;
        return old;
    }
};

class BRTree {
private:
    BRNode* root;
    friend TreeIterator;
public:
    BRTree() : root(nullptr) {};
    BRTree(std::vector<int>& v) {
        if (!v.empty()) {
            for (auto it : v)
                InsertNode(it);
        }
    }
    void InsertNode(int value) {
        BRNode* n = new BRNode(value, Red);
        BRNode* r = root;
        BRNode* p = nullptr;
       
        while (r) {
            p = r;
            n->_value > r->_value ? r = r->_right : r = r->_left;
        }
        n->_parent = p;
        if (p) {
            n->_value > p->_value ? p->_right = n : p->_left = n;
        }
        else {
            root = n;
        }
        n->_color = Red;
        fixTree(n); 
        std::cout << n->_value << "\t" << n->_color<<"\troot" << root->_value<<"\n";
        
    }

    void fixTree(BRNode* N) {
        BRNode* parent = N->_parent;
        while (N != root && parent->_color == Red) {
            BRNode* grandparent = parent->_parent;
            BRNode* uncle;
            if (grandparent) {
                grandparent->_left == parent ? uncle = grandparent->_right : uncle = grandparent->_left;
                if (uncle && uncle->_color == Red) {
                    parent->_color = Black;
                    grandparent->_color = Red;
                    uncle->_color = Black;
                    N = grandparent;
                }
                else { 
                    if (N->_value > grandparent->_value) {                   
                        if (N == N->_parent->_right) {

                            LeftTurn(parent,root);
                            std::swap(parent, root);
                           /* std::cout << N->_value << "\t" << N->_color << "\n";
                            std::cout << parent->_value << "\t" << parent->_color << "\n";
                            std::cout << grandparent->_value << "\t" << grandparent->_color << "\n";
                            //std::cout << uncle->_value << "\t" << uncle->_color << "\n";
                            std::cout << root->_value << "\t" << root->_color << "\n";*/
                            parent->_color = Red;
                            root->_color = Black;
                        }
                        else {
                            RightTurn(N, parent);
                            std::swap(N, parent);
                            std::cout << N->_value << "\t" << N->_color << "\n";
                            std::cout << parent->_value << "\t" << parent->_color << "\n";
                            std::cout << grandparent->_value << "\t" << grandparent->_color << "\n";
                            //std::cout << uncle->_value << "\t" << uncle->_color << "\n";
                         }
                    }
                    else {
                        if (N == N->_parent->_left) {

                            RightTurn(parent, root);
                            std::swap(parent, root);
                            /* std::cout << N->_value << "\t" << N->_color << "\n";
                             std::cout << parent->_value << "\t" << parent->_color << "\n";
                             std::cout << grandparent->_value << "\t" << grandparent->_color << "\n";
                             //std::cout << uncle->_value << "\t" << uncle->_color << "\n";
                             std::cout << root->_value << "\t" << root->_color << "\n";*/
                            parent->_color = Red;
                            root->_color = Black;
                        }
                        else {
                            LeftTurn(N, parent);
                            std::swap(N, parent);
                            std::cout << N->_value << "\t" << N->_color << "\n";
                            std::cout << parent->_value << "\t" << parent->_color << "\n";
                            std::cout << grandparent->_value << "\t" << grandparent->_color << "\n";
                            //std::cout << uncle->_value << "\t" << uncle->_color << "\n";
                        }
                       

                    }
                    
                    }
                }

            }
            root->_color = Black;     
    }

    void RightTurn(BRNode* a, BRNode* b) {
        if (b->_parent != nullptr)
            b->_parent->_left = a;
        a->_parent = b->_parent;
        if (a->_right != nullptr) {
            b->_left = a->_right;
            a->_right->_parent = b;
        }
        else
            b->_left = nullptr;
        a->_right = b;
        b->_parent = a;
       /* std::cout << a->_value<<"\t" << a->_color << "\n";
        std::cout << a->_parent->_value << "\t" << a->_parent->_color << "\n";
        //std::cout << a->_left->_value << "\t" << a->_left->_color << "\n";
        std::cout << a->_right->_value << "\t" << a->_right->_color << "\n";
        std::cout << b->_value << "\t" << b->_color << "\n";
        std::cout << b->_parent->_value << "\t" << b->_parent->_color << "\n";
        //std::cout << b->_left->_value << "\t" << b->_left->_color << "\n";
        //std::cout << b->_right->_value << "\t" << b->_right->_color << "\n";*/
    }

    void LeftTurn(BRNode* a, BRNode* b) {
        if(b->_parent !=nullptr)
            b->_parent->_right = a;
        a->_parent = b->_parent;
        if (a->_left != nullptr) {
            b->_right = a->_left;
            a->_left->_parent = b;
        }
        else 
            b->_right = nullptr;
        a->_left = b;
        b->_parent = a;
    }

    /*void RightTurnTriangle(BRNode* a, BRNode* b) {
        b->_parent->_right = a;
        a->_parent = b->_parent;
        if (a->_right != nullptr) {
            b->_left = a->_right;
            a->_right->_parent = b;
        }
        else
            b->_left = nullptr;
        a->_right = b;
        b->_parent = a;
        }

    void LeftTurnTriangle(BRNode* a, BRNode* b) {
        b->_parent->_left = a;
        a->_parent = b->_parent;
        if (a->_left != nullptr) {
            b->_right = a->_left;
            a->_left->_parent = b;
        }
        else
            b->_right = nullptr;
        a->_left = b;
        b->_parent = a;
    }*/
    BRNode* Min() {
        BRNode* t = root;
        if (!t) return nullptr;
        while (t->_left) {
            t = t->_left;
        }
        return t;
    }
    BRNode* Max() {
        BRNode* t = root;
        if (!t) return nullptr;
        while (t->_right) {
            t = t->_right;
        }
        return t;
    }
    void print() {
        if (!root)
            std::cout << "Empty Tree";
        else
            print(root);
    }
    void print(BRNode* node) const {
        if (!node)
            return ;
        if (!node->_parent)
            std::cout << node->_value << ":" << node->_color << "- root" << "\n";
        else {
            if (node->_parent->_left == node) 
                std::cout<< node->_value << ":" << node->_color << "- left child of the" <<node->_parent->_value<< "\n";
            else
                std::cout << node->_value << ":" << node->_color << "- right child of the" << node->_parent->_value << "\n";
        }
        print(node->_left);
        print(node->_right);
    }

    TreeIterator begin() { return  TreeIterator(Min()); }
    TreeIterator end() { return TreeIterator(); }

};


int main()
{
    unsigned int start_time = clock();
    std::cout << "Start\n";
    std::vector<int> nums{5,8,15,12,9};
    BRTree tree(nums);
    std::cout << "\nPrint\n";
    int count = 0;
    for (auto it = tree.begin(); it != tree.end(); ++it) {
        std::cout << *it << "\t";
        count++;
        if (count == 15)
        {
            break;
        }
       
    }
    tree.print();



}
