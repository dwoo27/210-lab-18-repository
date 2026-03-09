#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct Node{
    double rating;
    string comment;
    Node* next;
};

void addToHead(Node*&, double, string);
void addToTail(Node*&, double, string);
void outputRevs(Node*);

int main()
{
    Node* head = nullptr;
    string buf;
    int choice;
    char yn = 'y';
    double rating;
    string comment;
    bool valid = false;

    while (!valid) {
        cout << "Which linked list method should we use?" << endl;
        cout << "\t[1] New nodes are addes at the head of the linked list" << endl;
        cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
        cout << "\tChoice: ";
        cin >> buf; choice = atoi(buf.c_str());
        cin.ignore(1000, 10);

        if (choice == 1 || choice == 2) {
            valid = true;
            break;
        }

        cout << "Invalid choice" << endl;
    }
    
    
    while (yn == 'y' || yn == 'Y') {
        cout << "Enter review rating 0-5: ";
        cin >> buf; rating = atof(buf.c_str());
        cin.ignore(1000, 10);

        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1) {
            addToHead(head, rating, comment);
        }
        else{
            addToTail(head, rating, comment);
        }


        cout << "Enter another review? Y/N: ";
        cin >> yn;
        cin.ignore(1000, 10);
    }
    outputRevs(head);

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

void outputRevs(Node* head) {
    if (!head) { //check for empty list
        cout << "No reviews" << endl;
        return;
    }
    Node* traverse = head; //node for traversing list
    int count = 0;
    double total = 0;
    
    cout << "Outputting all reviews: " << endl;
    while (traverse) { //while traverse isn't beyond tail
        cout << "\t> Review #" << ++count << ": " << traverse->rating
            << ": " << traverse->comment << endl;
        total += traverse->rating;
        traverse = traverse->next;
    }

    cout << "\t> Average: " << (total / count) << endl;

}