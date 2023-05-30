#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
	int data { };
	Node* next { };
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data <<" at address "<< this<< "\n";
	}
};

class LinkedLista{
    private:
        Node *head{};
        Node *tail{};
        int length = 0;
    public:
        
        void delete_front()
        {
            Node *tempa = head;
            head = head->next;
            delete tempa;
        }
        
        void insert_front(int value)
        {
            Node *item = new Node(value);
            if (!head){
                head = tail = item;
            }
            else{
                item->next=head;
                head=item;
            }

            if (length==1)
            {
                head = tail = item;
            }
            length++;
        }

        void insert_end(int value){
            Node *item = new Node(value);
            if (!head){
                head = tail = item;
            }
            else{
                tail->next = item;
                tail = item;
            }
            length++;
        }

        void printLista(){
            Node *tempa = head;
            for (tempa ; tempa ; tempa=tempa->next)
            {
                cout<<tempa->data<<" ";
            }
            cout<<"\n";
        }

        Node *get_nth_node(int n){
            Node *tempa = head;
            int count =0;
            for (tempa ; tempa ; tempa=tempa->next)
            {
                if (++count==n)
                {
                    return tempa;
                }
            }
            return nullptr;
        }
};
int main()
{
 LinkedLista listaya ;
 listaya.insert_front(1);
 listaya.insert_front(2);
 listaya.insert_front(3);
 listaya.insert_front(4);
 listaya.insert_front(5);
 //listaya.printLista();//5 4 3 2 1
 listaya.delete_front();
 listaya.printLista();
}

