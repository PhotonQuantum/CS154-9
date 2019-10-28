#include <iostream>
using namespace std;
struct node{
    int data;
    node *next;
};

int main(){
    int input;
    cin >> input;
    node *head = new node;
    head->data = input;
    head->next = NULL;
    while (true){
        cin >> input;
        if (input != -1){
            node *tmp = head;
            head = new node;
            head->data = input;
            head->next = tmp;
        } else {
            break;
        }
    }
    node *i;
    for (i=head; i->next != NULL; i=i->next)
        cout << i->data << " ";
    cout << i->data;
    return 0;
}
