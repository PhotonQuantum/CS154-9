#include <iostream>
#include <cstring>
using namespace std;
struct node{
    char name[30];
    int population;
    node *next;
};

int main(){
    node *linkedlist = new node;
    node *head = linkedlist;
    cin >> head->name >> head->population;
    while (true){
        char str_tmp[30];
        cin >> str_tmp;
        if (str_tmp[0] == '@')
            break;
        node *tmp = head;
        head = new node;
        tmp->next = head;
        head->next = NULL;
        strcpy(head->name, str_tmp);
        cin >> head->population; 
    }

    bool is_swaped = true;
    while (is_swaped == true){
        is_swaped = false;
        head = linkedlist;
        while (head->next != NULL){
            if (head->population < head->next->population){
                char tmp_name[30];
                int tmp_population;
                strcpy(tmp_name, head->name);
                tmp_population = head->population;
                strcpy(head->name, head->next->name);
                head->population = head->next->population;
                strcpy(head->next->name, tmp_name);
                head->next->population = tmp_population;
                is_swaped = true;
            }
            head = head->next;
        }
    }
    head = linkedlist;
    while (head->next->next != NULL){
        cout << head->name << " ";
        head = head->next;
    }
    cout << head->name;
}
