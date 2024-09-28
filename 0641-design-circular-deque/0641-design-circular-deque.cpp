class node {
public:
    int data; node *prev; node *next;

    node(int d, node *p=0, node*n=0)
    {
        data = d;
        prev = p;
        next = n;
    }
};

class MyCircularDeque {
public:
    node* head; node* tail; int k,len;

    MyCircularDeque(int k) : k(k), head(0), tail(0), len(0){}
    
    bool insertFront(int value) {
        if(isFull()){
            return 0;
        }

        node *temp = new node(value);
        if(isEmpty()){
            head = temp;
            tail = temp;
            len ++;
            return 1;
        }
        else{
            temp->prev=head->prev;
            temp->next = head;
            head->prev=temp;
            head=temp;
            tail->next=head;
            len++;
            return 1;
        }
        
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return 0;
        }

        node *temp = new node(value);

        if(isEmpty()){
            head = temp;
            tail = temp;
            len++;
            return 1;
        }
        else{
            temp->next=tail->next;
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
            len++;
            return 1;
        }
        
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return 0;
        }
        else if(head==tail){
            node *temp = head;
            head = 0;
            tail = 0;
            delete temp;
            len --;
            return 1;
        }
        else{
            node *temp = head;
            head = head->next;
            head->prev = tail;
            delete temp;
            len--;
            return 1;
        }
        
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return 0;
        }
        else if(head==tail){
            node *temp = tail;
            head = 0;
            tail = 0;
            delete temp;
            len--;
            return 1;
        }
        else{
            node *temp = tail;
            tail = tail->prev;
            tail->next = temp->next;
            delete temp;
            len--;
            return 1;
        }
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        else{
            return head->data;
        }
        
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        else{
            return tail->data;
        }
        
    }
    
    bool isEmpty() {

        if(head == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
    bool isFull() {
        if(len==k){
            return true;
        }
        else {
            return false;
        }
    }
};