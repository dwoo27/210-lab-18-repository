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

void addToHead(Node*& head, double rating, string comment) {
    Node* newReview = new Node;
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = nullptr;

    if (!head) { //if list empty, make new review head
        head = newReview;
    }
    else { //otherwise, set new review to be before head, make it new head
        newReview->next = head;
        head = newReview;
    }
}

void addToTail(Node*& head, double rating, string comment) {
    Node* newReview = new Node;
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = nullptr;
    
    if (!head) { //if list empty, make new review head
        head = newReview;
    }
    else {
        Node* traverse = head; //create node for traversing list
        while (traverse->next) { //while traverse pointer doesn't point to null
            traverse = traverse->next; //traverse through list
        }
        traverse->next = newReview; //tail points to new review to become new tail
    }

}

void outputRevs(Node*& head) {
    if (!head) {
        cout << "No reviews" << endl;
        return;
    }

}