template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr) { }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);

    if (head == nullptr) {
        head = n;
    }
    else {
        Node* curr = head;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = n;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;

    while (head != nullptr) {
        prev = head;
        head = head->next;
        delete prev;
    }

    this->length = 0;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    // TODO
    head = nullptr;      // start with empty list and then alkso make length 0
    this->length =0;
    Node* curr = copyObj.head;     // make pointer that will walk through the list as copying is done

    while(curr != nullptr){
        append(curr->value);            // use the append func to create a new node 
        curr = curr-> next;                     // move over to next node and then this stuff happens over and over till done
    }
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: error, position out of bounds");
    }
    
    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
void LinkedList<T>::insert(int position, const T& elem) {
    // TODO
    if(position < 0 || position > this->length){    // checking if valid input and throwing if not
        throw string("Error: out of bounds");
    }

    Node* n = new Node(elem);       // make new node with value 
    if(position == 0){
        n->next = head;     // if insert if at the front then make new node point to the old head and head becomes the new node
        head = n;       
    }
    else{
        Node* curr = head;      // make node for curr
        for(int i = 0; i < position - 1; i++){      // moves it right before where we want to insert
            curr = curr->next;
        }
        n->next = curr->next;       // new node points to the next node         // basiacallt inserting it
        curr->next = n;         // previous one points to new
    }
    this->length++;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::remove(int position) {
    // TODO
        if(position < 0 || position >= this->length){    // checking if valid input and throwing if not
        throw string("Error: out of bounds");
    }

                    // if remove first node at 0
    if(position == 0){
        Node* temp = head;      // save old head
        head = head->next;      // move head forward
        delete temp;        // delete old one
    }
    else{
        Node* curr = head;      // make node for curr
        for(int i = 0; i < position - 1; i++){      // moves it right before where we want to insert
            curr = curr->next;
        }
        
        Node* temp = curr->next;    // make it the node to delete
        curr->next = temp->next;        // skip dedleted one

        delete temp;        // detlte old one
    }
    this->length--;
}


template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: error, position out of bounds");
    }

    Node* curr = head;

    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
