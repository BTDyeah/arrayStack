#include <iostream>
#define ADD 10

class Stack {
private:
    int* A;
    int top;
    int* newArray;
    int size;
public:

    Stack(){ //constructor for initializing values
        size = 10;
        top = -1;
        A = new int[size];
        newArray = new int[size += ADD];
    }

    ~Stack(){ //freeing the heap space
        delete A;    
    }

    void Push(int n){ //push a new element on to the stack
        if(top <= size) {
           top++;
           A[top] = n;
        }
        else 
            if(top >= size){
                std::copy(&A[0], &A[top], &newArray[0]);
                newArray = A;
                newArray[top] = n;
            }
    }

    void Pop(){ //removes top value only if stack is not empty
       try {
           if(top == -1)
            throw "There is nothing to delete in stack";
           else
            top--;
        }
       catch(const char* exp){
           std::cout << "Error " << exp << std::endl;
        }
    }

    void Top(){ //returns a top value as long as stack isn't empty
        try {
            if(top == -1)
                throw "There are no elements in the stack";
            else
                std::cout << A[top] << std::endl;    
        }
        catch(const char* exp){
            std::cout << "Error: " << exp << std::endl;
        }
    }

    bool isEmpty() { //check whether a stack is empty or not
        if(A == nullptr)
            return false;
        else
            return true;
    }

    void printStack() { //printing the stack
        for(int i = 0; i <= top; ++i){
            std::cout << A[i] << std::endl;
        }
    }

    void Test() { //function for testing implementation
        for(int i = 1; i <= 20; ++i){
            Push(i);
        }

        std::cout << "The top value is: ";
        Top();

        std::cout << "\nRemoving a top element with a pop, the new top is now: ";
        Pop();
        Top();

        std::cout << "\nIs stack empty? \n";
        std::cout << isEmpty() << std::endl;
        
        std::cout << "\nElements of the stack are: \n";
        printStack();
    }
};

int main() {
    Stack obj;
    obj.Test();
    return 0;
}