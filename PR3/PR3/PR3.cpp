#include <iostream>    
#include <iomanip>

using namespace std;

const int N = 2;               // Количество элементов в массиве

struct Node {

    int data;     //информационное поле
    Node* next;  //указатель на следующий узел
    Node* prev;  //указатель на предыдущий узел 

};



void outListHead(Node* head, Node* tail) {
    Node* temp = head;
    if (temp == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    cout << temp->data << ' ';
    temp = temp->next;
    while (temp != head) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

void outListTail(Node* head, Node* tail) {
    Node* temp = tail;
    if (temp == NULL) {
        cout << "Список пуст" << endl;
        return;
    }
    cout << temp->data << ' ';
    temp = temp->prev;
    while (temp != tail) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

void addHead(Node*& head, Node*& tail, int val) {
    Node* temp = new Node;
    temp->data = val;
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp->next = temp;
        temp->prev = temp;
    }
    else {
        temp->next = head;
        temp->prev = tail;
        head->prev = temp;
        head = temp;
        tail->next = head;
    }
}


void addTail(Node*& head, Node*& tail, int val) {
    Node* temp = new Node;
    temp->data = val;
    if (head == NULL) {
        head = temp;
        tail = temp;
        temp->prev = temp;
        temp->next = temp;
    }
    else {
        tail->next = temp;
        temp->prev = tail;
        temp->next = head;
        tail = temp;
        head->prev = temp;
    }
}


Node* findDataHead(Node* head, int val) {
    Node* temp = head;
    temp = temp->next;
    while (temp != head) {
        if (temp->data == val)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

Node* findDataTail(Node* tail, int val) {
    Node* temp = tail;
    temp = temp->prev;
    while (temp != tail) {
        if (temp->data == val)
            return temp;
        temp = temp->prev;
    }
    return NULL;
}

Node* findPosHead(Node* head, int pos) {
    Node* temp = head;
    while (pos > 1) {
        temp = temp->next;
        pos--;
    }
    return temp;
}

Node* findPosTail(Node* head, Node* tail, int pos) {
    Node* temp = head;
    int count = 0;
    while (temp != head) {
        temp = temp->next;
        count++;
    }
    temp = tail;
    while (pos > 1) {
        temp = temp->prev;
        pos--;
    }
    return temp;
}

void removeHead(Node*& head, Node* tail) {
    if (head == NULL)
        return;
    Node* temp = head;
    head = temp->next;
    if (head != NULL) {
        head->prev = tail;
        tail->next = head;
    }
    delete temp;
}

void removeTail(Node* head, Node*& tail) {
    if (head == NULL)
        return;
    else {
        Node* temp = tail;
        temp = temp->prev;
        temp->next = head;
        delete tail;
        tail = temp;
        head->prev = tail;
    }
}

void removeAll(Node*& head, Node*& tail) {
    int count = 0;
    if (head != tail) {
        Node* temp = head;
        temp = temp->next;
        while (temp->next != head) {
            temp = temp->next;
            count++;
        }
    }
    for (int i = 0; i <= count + 1; i++) {
        removeHead(head, tail);
    }
    head = NULL;
    tail = NULL;
}



bool insert(Node*& head, Node*& tail, int pos, int val) {
    if (pos == 1) {
        addHead(head, tail, val);
    }
    else {
        Node* p = findPosHead(head, pos);
        if (p == NULL)
            return false;
        Node* temp = new Node;
        temp->data = val;
        temp->next = p;
        temp->prev = p->prev;
        p->prev->next = temp;
        p->prev = temp;
        return true;
    }
}

void remove(Node*& head, Node*& tail, int pos) {
    Node* p = findPosHead(head, pos);
    if (head == p) {
        removeHead(head, tail);
        return;
    }
    if (tail == p) {
        removeTail(head, tail);
        return;
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}

bool isEmpty(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        return true;
    }
    return false;
}


//-------------------------------------------------------------
int retrieve(Node* head, int pos) {
    Node* p = findPosHead(head, pos);
    return p->data;
    return 0;
}



//-------проверка работы функций------------------------------------
int main() {


    Node* head = NULL, * tail = NULL;

    addTail(head, tail, 5);   
    addTail(head, tail, 1);
    addTail(head, tail, -4);
    addTail(head, tail, 2);
    outListHead(head, tail);

    insert(head, tail, 2, 10);
    outListHead(head, tail);

    cout << "Number 8: " << findPosHead(head, 8)->data << endl;


    

}
//-------------------------------------------------------------

