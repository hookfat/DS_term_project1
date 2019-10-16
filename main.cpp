#include <iostream>
#include <fstream>
#include "p1.h"
//#include "readblock.cpp"
using namespace std;

int col_out;
int main()
{
    ifstream in;
    //ofstream out;
    in.open("Tetris.data");
    //out.open("output1.OUTPUT");
    int row, col;
    char c[5];
    in >> row >> col;
    col_out = col;
    Listnode* head = new Listnode(col);
    Listnode* temp = head;

    for(int i = 0; i<row+3; i++){
        temp->next = new Listnode(col);
        temp->next->prev = temp;
        temp = temp->next;
    }
    in.getline(c, 1);
    while(!in.eof()){
        in.getline(c, 1003);
        //READ
        if(c[0]=='E')
            break;
        block down_block[4];
        int bottom_block_num = Readblock(c, down_block);
        //READ over
        //block down
        head = blockdown(bottom_block_num, down_block, head, col_out);

        //block down over

        //check lose
        bool lose = 0;
        for(int i = 0; i<4; i++){
            if(down_block[i].row < 0){
                Listnode* temp1 = head;
                for(int j = -4; j<down_block[i].row; j++){
                    temp1 = temp1->next;
                }
                if(temp1->data[down_block[i].col] == 1){
                    lose = 1;
                    break;
                }
            }
        }
        if(lose)
            break;
        //check lose over
    }
    //print output
    print_output(head->next->next->next->next, col_out);

    //free memory
    Listnode* temp1 = head->next;
    while(temp1!=nullptr){
        temp1->prev->~Listnode();
        delete temp1->prev;
        temp1 = temp1->next;
    }


    return 0;
}

void print_output(Listnode* head, int num)
{
    Listnode* temp = head;
    while(temp != nullptr){
        for(int i = 0; i<num; i++)
            cout << temp->data[i];
        cout << endl;
        temp = temp->next;
    }
}

/*
void print_output(Listnode* head, int num)
{
    ofstream out;
    out.open("Tetris.final");
    Listnode* temp = head;
    while(temp != nullptr){
        for(int i = 0; i<col_out; i++)
            out << temp->data[i];
        out << endl;
        temp = temp->next;
    }
}
*/
