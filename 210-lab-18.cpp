#include <iostream>
using namespace std;

struct Node{
    double rating;
    string comment;
    Node* next;
};

void addToHead(Node*&, double, string);
void addToTail(Node*&, double, string);
void outputRevs(Node*&);

int main()
{
    std::cout << "Hello World!\n";
}

