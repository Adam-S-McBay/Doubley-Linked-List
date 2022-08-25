#include "DoublyLinked.h"
/*DoublyLinkedList::DoublyLinkedList()
 creates a doubly linked list
*/
DoublyLinkedList::DoublyLinkedList() {
  head = nullptr;
  tail = nullptr;
}
/*DoublyLinkedList::~DoublyLinkedList()
 destroys a doubly linked list
*/
DoublyLinkedList::~DoublyLinkedList() {
  head = nullptr;
}
/*DoublyLinkedList::Front()
  return the front
*/
int DoublyLinkedList::Front() {
  return (head ? head->data : 0);
}
/*DoublyLinkedList::PushFront()
  creates a new head and sets it to n. If there is no head then it sets n to the head and tail.
*/
void DoublyLinkedList::PushFront(int n) {
  Node *newNode = new Node;
  newNode->data = n;
  if (!head) {
    head = newNode;
    tail = newNode;
    newNode->prev=NULL;
  } else {
    newNode->next = head;
    head = newNode;
    newNode->prev=NULL;
  }
}
/*DoublyLinkedList::PopFront()
  moves head up one in the list and makes the new head prev NULL
*/
void DoublyLinkedList::PopFront() {
  if (head) {
    Node *oldNode = head;
    head = head->next;
    head->prev = NULL;
    delete oldNode;
  }
}
/*DoublyLinkedList::PushBack(n)
  creates newNpode n and makes it the new tail. If there is no tail then n is the new haed and tail
*/
void DoublyLinkedList::PushBack(int n) {
  Node *newNode = new Node;
  newNode->data = n;
  if (!tail) {
    head = newNode;
    tail = newNode;
    newNode->prev=NULL;
  } else {
    newNode->prev = tail;
    tail = newNode;
    newNode->next=NULL;
  }
}
/*DoublyLinkedList::PopBack()
  if there is a node before tail then it sets atil back one and then makes tail->next be null
*/
void DoublyLinkedList::PopBack() {
  if (tail->prev) {
    Node *oldNode = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete oldNode;
  }
}
/*DoublyLinkedList::Size()
  counts through the list while curr is not null
*/
int DoublyLinkedList::Size() {
  Node *curr = head;
  int _size = 0;
  while (curr) {
    _size++;
    curr = curr->next;
  }
  return _size;
}
/*DoublyLinkedList::Print()
  prints the elemnt of the list while temp is not null, then temp=->next
*/
void DoublyLinkedList::Print(){
  Node *temp = head;
  while (temp != NULL){
    std::cout << temp->data << " ";
    temp=temp->next;
  }
  std::cout<<endl;
}
public boolean computeStats() {
    
    int size = this.ratingList.size();
    String idInput, reviewerIdInput;
    float ratingInput;
    
    
    for(int i=0;i<size;i++){
        
        Rating rate = this.ratingList.get(i);
        idInput = rate.getProductID();
        reviewerIdInput = rate.getReviewerID();
        ratingInput =rate.getRating();
        ArrayList<Rating> rawRatings = new ArrayList<Rating>();
        Rating find = new Rating(reviewerIdInput, idInput, ratingInput);
        rawRatings.add(find);
        new RatingSummary(idInput,rawRatings);
        
        }
