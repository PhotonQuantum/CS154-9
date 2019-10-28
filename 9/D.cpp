#include <iostream>
using namespace std;

struct info_s{
    char id[4];
    char name[20];
    char sex[20];
    int age;
    int class_num;
};

struct mark_s{
    int english;
    int math;
    int physics;
};

struct student{
    info_s info;
    mark_s mark;
    int sum=-1;
    int rank=-1;
};

struct node{
    student data;
    node *next;
};

void input_node(node *head){
    cin >> head->data.info.id >> head->data.info.name >> head->data.info.sex >> head->data.info.age >> head->data.info.class_num;
    cin >> head->data.mark.english >> head->data.mark.math >> head->data.mark.physics;
}

// function a
void print_linkedlist(node *head){
    while (head != NULL){
        cout << head->data.info.id << ' ' << head->data.info.name << ' ' << head->data.info.sex << ' ' << head->data.info.age << ' ' << head->data.info.class_num;
        cout << ' ' << head->data.mark.english << ' ' << head->data.mark.math << ' ' << head->data.mark.physics;
        if (head->data.sum != -1)
            cout << ' ' << head->data.sum;
        if (head->data.rank != -1)
            cout << ' ' << head->data.rank;
        cout << endl;
        head = head->next;
    }
}

node *get_node_by_index(node *head, int index){
    int counter = 0;
    while (head != NULL){
        if (counter == index)
            return head;
        head = head->next;
        counter++;
    }
    return NULL;
}

// function b
node *add_node(node *head, int index){
    /*
     * index starts at 0.
     * new node will be inserted AFTER the selected node.
     * set index to -1 to add node to the begin of the linkedlist.
     */
    int counter = 0;
    if (index == -1){
        node *tmp = new node;
        input_node(tmp);
        tmp->next = head;
        return tmp;
    } else {
        node *begin = head;
        head = get_node_by_index(head, index);
        if (head == NULL){
            cout << "Invalid index!" << endl;
            return begin;
        }
        node *tmp = new node;
        input_node(tmp);
        tmp->next = head->next;
        head->next = tmp;
        return begin;
    }
}

// function c
node *del_node(node *head, int index){
    // index starts at 0.
    if (index == 0){
        if (head->next == NULL){
            cout << "Invalid operation!" << endl;
            return head;
        } else {
            node *out = head->next;
            delete head;
            return out;
        }
    }
    node *begin = head;
    head = get_node_by_index(head, index-1);
    if (head == NULL){
        cout << "Invalid index!" << endl;
        return begin;
    } else if (head->next == NULL){
        cout << "Invalid index!" << endl;
        return begin;
    } else {
        node *tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return begin;
    }
}

// function d
void calc_sum(node *head){
    while (head != NULL){
        head->data.sum = head->data.mark.english + head->data.mark.math + head->data.mark.physics;
        head = head->next;
    }
}

// function e
void sort_by_english(node *head){
    bool is_swaped = true;
    while (is_swaped){
        is_swaped = false;
        while (head->next != NULL){
            if (head->data.mark.english < head->next->data.mark.english){
                info_s tmp_info = head->data.info;
                mark_s tmp_mark = head->data.mark;
                head->data.info = head->next->data.info;
                head->data.mark = head->next->data.mark;
                head->next->data.info = tmp_info;
                head->next->data.mark = tmp_mark;
                is_swaped = true;
            }
            head = head->next;
        }
    }
}

// function f
void calc_rank(node *head){
    node *begin = head;
    node *head2 = head;
    int counter;
    while (head != NULL){
        counter = 0;
        head2 = begin;
        while (head2 != NULL){
            if (head2->data.mark.english + head2->data.mark.math + head2->data.mark.physics > head->data.mark.english + head->data.mark.math + head->data.mark.physics)
                counter++;
            head2 = head2->next;
        }
        head->data.rank = counter+1;
        head = head->next;
    }
}

void free_linkedlist(node *head){
    while (head != NULL){
        node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main(){
    int n;
    cin >> n;
    node *linkedlist = new node;
    node *head = linkedlist;
    input_node(head);
    head->next = NULL;
    for (int i=1;i<n;i++){
        node *tmp = head;
        head = new node;
        tmp->next = head;
        input_node(head);
        head->next = NULL;
    }
    cin.ignore();
    cin.ignore();
    char opt;
    bool is_exit = false;
    int index;
    while (!is_exit){
        cin >> opt;
        switch (opt){
            case 'a':
                print_linkedlist(linkedlist);
                break;
            case 'b':
                cin >> index;
                linkedlist = add_node(linkedlist, index);
                break;
            case 'c':
                cin >> index;
                linkedlist = del_node(linkedlist, index);
                break;
            case 'd':
                calc_sum(linkedlist);
                print_linkedlist(linkedlist);
                is_exit = true;
                break;
            case 'e':
                sort_by_english(linkedlist);
                print_linkedlist(linkedlist);
                is_exit = true;
                break;
            case 'f':
                calc_rank(linkedlist);
                print_linkedlist(linkedlist);
                is_exit = true;
                break;
        }
    }
    free_linkedlist(linkedlist);
    return 0;
}
