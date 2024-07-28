#ifndef NODETREE_HPP
#define NODETREE_HPP

template<class T>
class NodeTree {
private:
    T data;
    NodeTree<T>* left = NULL;
    NodeTree<T>* right = NULL;

public:
    NodeTree(T data, NodeTree<T>* left = NULL, NodeTree<T>* right = NULL);
    ~NodeTree();
    NodeTree<T>* getChildren(int child);
    void setData(T data);
    T getData();
    void print();
    void setChildren(NodeTree<T>* left, NodeTree<T>* right);

    NodeTree<T>* getLeft() { return left; }
    NodeTree<T>* getRight() { return right; }
    void setLeft(NodeTree<T>* node) { left = node; }
    void setRight(NodeTree<T>* node) { right = node; }    
};

#endif // NODETREE_HPP
