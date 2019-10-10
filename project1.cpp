#include <iostream>
#include <fstream>
using namespace std;

class Listnode{
    friend class Listrow;
public:
    Listnode():data(nullptr),col(0),next(nullptr),prev(nullptr){};
    Listnode(int a){
        col = a;
        data = new bool[col];
        for(int i = 0; i<col; i++)
            data[i] = 0;
        next = nullptr;
        prev = nullptr;
    }
private:
    bool* data;
    int col;
    Listnode* next, prev;
};

class Listrow{
private:
    int row, col;
    Listnode* head;
    Listnode* delpos[4];
    void reset(){
        cin >> row >> col;
        row = row+4;  //多開四格當作讀入時的臨時額外空間
        head = nullptr;
        
        
        
        
        for(int i = 0; i<4; i++)
            delpos[i] = nullptr;
    }
    void clean(){
        Listnode* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
public:
    Listrow(){
        reset();
    };
    ~Listrow(){
        clean();
    }
};


int main()
{
    
    return 0;
}
