#include <iostream>
#include <ostream>
using namespace std;



class Node{
  private:
    Node * next = NULL;
    Node * previous = NULL; 
    int data;
  public:  
    ~Node(){
      delete next;
      delete previous;
    }
    Node(int d){
      data = d;
    }
    void setNext(Node* n){
      this->next = n;
    }
    
    void setPrev(Node* n){
      this->previous = n;
    }
    int getData(){
      return data;
    }
    Node *getNext(){
      return this->next;
    }
    
};

class SingleLinkedList{
  private:
    Node* head = NULL;
    Node* tail = NULL;
  public:
    
    void setHead(Node *n){
      this->head = n;
    }
    void setTail(Node *n){
      this->tail = n;
    }
    Node *getTail(){
      return this->tail;
    }
    Node *getHead(){
      return this->head;
    }
    void deleteNode(int i){
      
      Node*n = this->head;
      if(this->head->getData() == i){
        setHead(n->getNext());
        delete n;
        return;
      }
      while( n != NULL){
        if(n->getNext()->getData() == i){
            if(n->getNext() == this->getTail()){
              setTail(n);
            }
            Node* temp= n->getNext();
            n->setNext(temp->getNext());
            delete temp;
            return;
        }
        n = n->getNext();
      }
    }

    friend ostream& operator<<(ostream& os, const SingleLinkedList& sll)  {  
        Node*n = sll.head;
        while( n != NULL){
        os<<n->getData()<<"->";
        n = n->getNext();
      }
      return os;
    }  

};


int main(){
  Node* n1 = new Node(1234);
  Node* n2 = new Node(5678);
  Node* n3 = new Node(999);
  SingleLinkedList SLL;
  SLL.setHead(n1);
  n1->setNext(n2);
  n2->setNext(n3);
  SLL.setTail(n3);
  

  SLL.deleteNode(1234);

    Node*n = SLL.getHead();
        while( n != NULL){
        cout<<n->getData()<<"->";
        n = n->getNext();
      }
  return 0;

}
