#include <iostream>
#include <fstream>
using namespace std;

class Listnode{
public:
    Listnode(){
        next = nullptr;
        prev = nullptr;
        data = nullptr;
    }
    Listnode(int col){
        next = nullptr;
        prev = nullptr;
        data = new bool[col];
        for(int i = 0; i<col; i++)
            data[col] = 0;
    }
    ~Listnode(){
        delete[] data;
    }
    Listnode* next;
    Listnode* prev;
    bool* data;
};



int main()
{
    ifstream in;
    ofstream out;
    in.open("1.DATA");
    //out.open("output1.OUTPUT");
    int row, col;
    char c[5];
    in >> row >> col;
    Listnode* head = Listnode(col);
    Listnode* temp = head;
    
    for(int i = 0; i<row+3; i++){
        temp->next = Listnode(col);
        temp->next->prev = temp;
        temp = temp->next;
    }
    
    in.getline(c, 1);
    while(!in.eof()){
        in.getline(c, 1003);
        

    }


    return 0;
}
