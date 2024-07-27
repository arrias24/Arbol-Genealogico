template<class T>
class NodeTree{
    private:
        T data;
        int heigth = 0;
        int fe = 0;
        NodeTree<T> *left=NULL;
        NodeTree<T> *right=NULL;
        int autoHeight();
    public:
        NodeTree(T,NodeTree<T>*,NodeTree<T>*);
        ~NodeTree();
        NodeTree<T>* getChildren(int);
        void setData(T);
        T getData();
        void setChildren(NodeTree<T>*,NodeTree<T>*);
        void print();
        void setFe();
        void setFe(int);
        int getFe();
        void setHeigth(int);
        int calculate_Heigth(NodeTree<T>*);
        int getHeigth();
        bool isLeaf();
        void setRight(NodeTree<T>*);
        void setLeft(NodeTree<T>*);
};