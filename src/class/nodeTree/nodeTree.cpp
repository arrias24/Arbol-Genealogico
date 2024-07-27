#include<iostream>
#include "./nodeTree.hpp"
using namespace std;

template <class T>
NodeTree<T>::NodeTree(T data, NodeTree<T>* right, NodeTree<T>* left){
    this->data=data;
    if(right!=NULL){
        this->right=right;
    }
     if(left!=NULL){
        this->left=left;
    }
}
template<class T>
bool NodeTree<T>::isLeaf(){
    return right == NULL && left == NULL;
}
template <class T>
NodeTree<T>* NodeTree<T>::getChildren(int child){
    switch (child)
    {
    case 0:
        return this->left;
    case 1:
        return this->right;
    }
    return NULL;
}

template <class T>
void NodeTree<T>::setChildren(NodeTree<T>* right, NodeTree<T>* left){
    if(right != NULL && left!=NULL){
        this->right=right;
        this->left=left;
    }else if(left!=NULL){
        this->left=left;
    }
    else if(right != NULL){
          this->right=right;
    }else{
        this->right=NULL;
        this->left=NULL;
        heigth = 0;
    }
   this->heigth=autoHeight();
   
}

template <class T>
void NodeTree<T>::setRight(NodeTree<T>* right){
  
    this->right=right;
    this->heigth=autoHeight();
}

template <class T>
void NodeTree<T>::setLeft(NodeTree<T>* left){
  
        this->left=left;
        this->heigth=autoHeight();
}
template <class T>
int NodeTree<T>::autoHeight(){
  
    int h_left=calculate_Heigth(this->left);
    int h_right=calculate_Heigth(this->right);

   
   return  h_left<h_right ?  h_right : h_left;

}

template <class T>
void NodeTree<T>::setData(T data){
    this->data=data;
}


template <class T>
T NodeTree<T>::getData(){
   return this->data;
}



template<class T>
void NodeTree<T>::print(){
    cout<<this->data<<" "; //solo para datos simples
}
template <class T>
NodeTree<T>::~NodeTree(){
    this->right=NULL;
    this->left=NULL;
}

template<class T>
void NodeTree<T>::setFe(){
    if(this->right == NULL && this->left==NULL){
        this->fe=0;
    }
    else if(this->right != NULL && this->left!=NULL){
        this->fe=(this->right->higth)-(this->left->higth);
    }else if(this->right == NULL ){
        this->fe=-(this->left->higth);
    }
    else if( this->left==NULL){
        this->fe=(this->right->higth);
    }
}
template<class T>
void NodeTree<T>::setFe(int fe){
    this->fe = fe;
}

template<class T>
int NodeTree<T>::getFe(){
    return this->fe;  
}


template <class T>
void NodeTree<T>::setHeigth(int heigth){
    this->heigth=heigth;
}
template <class T>
int NodeTree<T>::getHeigth(){
    return heigth;
}

template <class T>
int NodeTree<T>::calculate_Heigth(NodeTree<T>* nodeTree){
 
    if (nodeTree == NULL) return 0 ;
    else{
        int heigthLeft = calculate_Heigth(nodeTree->left);
        int heigthRigth = calculate_Heigth(nodeTree->right);
        if (heigthLeft> heigthRigth)
            return heigthLeft + 1;
        else
            return heigthRigth + 1;
    }
}