#include <iostream>
using namespace std;

struct IntArray {
    int size;
    int capacity;
    int *contents;
};

IntArray readIntArray();
void addToIntArray(IntArray& ia);
void printIntArray(const IntArray& ia);


// Do not change this function!
int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = 0;

  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents;
        a[which-'a'].contents = 0;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}

/*  Function:   readIntArray
    Purpose:    Read input as an IntArray structure. Terminate when the input is non-integer.
    Return:     The IntArray structure read. If the input is empty, 
                then a structure of size 0, capacity 0 will return,
                and the contents is a null pointer.
                Otherwise, the capacity will be 5*2^quot(size-1/5)
    Dependency: addToIntArray   */
IntArray readIntArray() {
    // init
    IntArray a;
    a.size = 0;
    a.capacity = 0;
    a.contents = NULL;
    addToIntArray(a); // minimal definition
    return a;
}

/*  Function:   printIntArray
    Parameter:  const IntArray to be printed
    Purpose:    Print an IntArray. Each element is followed by a whitespace character.  */
void printIntArray(const IntArray& ia) {
    for (int i = 0; i < ia.size; i++) {cout << ia.contents[i] << " ";}
    cout << endl;
}

/*  Function:   addToIntArray
    Purpose:    Read integers from input and add them into an IntArray.
    Parameter:  IntArray& a - the target array adding to. 
                If the input is empty then the IntArray is unchanged,
                otherwise the new capacity will be 5*2^quot(new size-1/5).  */
void addToIntArray(IntArray& a) {
    int tmp; // test if the input is integer
    while (cin >> tmp) {
        if (a.capacity == 0) {
            a.capacity = 5;
            a.contents = new int[5];
        } else
        if (a.size == a.capacity) {
            int* b = a.contents;
            a.contents = new int[a.capacity *= 2];
            for (int i = 0; i < a.size; i++) {a.contents[i] = b[i];}
            delete [] b;
        }
        a.contents[a.size++] = tmp;
    }
    cin.clear();
    cin.ignore();
}
