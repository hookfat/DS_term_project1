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
typedef struct{
    int row;
    int col;
}block;

int main()
{
    ifstream in;
    ofstream out;
    in.open("1.DATA");
    //out.open("output1.OUTPUT");
    int row, col;
    char c[5];
    in >> row >> col;
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
        block down_block[4]; //用來記錄讀入的block的 row,col
        int bottom_block_num;  //用來記錄有幾個block在底部
        int down_col; //紀錄輸入的方格的col
        if(c[0] == 'T'){
            down_col = c[3] - '0' -1;
            if(c[1] == '1'){
                down_block[0].row = -2;
                down_block[0].col = down_col;
                down_block[1].row = -2;
                down_block[1].col = down_col+2;
                down_block[2].row = -1;
                down_block[2].col = down_col+1;
                down_block[3].row = -2;
                down_block[3].col = down_col+1;
                bottom_block_num = 3;
            }
            else if(c[1] == '2'){
                down_block[0].row = -2;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -2;
                down_block[2].col = down_col+1;
                down_block[3].row = -3;
                down_block[3].col = down_col+1;
                bottom_block_num = 2;
            }
            else if(c[1] == '3'){
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -1;
                down_block[2].col = down_col+2;
                down_block[3].row = -2;
                down_block[3].col = down_col+1;
                bottom_block_num = 3;
            }
            else if(c[1] == '4'){
                down_block[0].row = -2;
                down_block[0].col = down_col+1;
                down_block[1].row = -1;
                down_block[1].col = down_col;
                down_block[2].row = -2;
                down_block[2].col = down_col;
                down_block[3].row = -3;
                down_block[3].col = down_col;
                bottom_block_num = 2;
            }
        }
        else if(c[0] == 'L'){
            down_col = c[3] - '0' -1;
            if(c[1] == '1'){
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -2;
                down_block[2].col = down_col;
                down_block[3].row = -2;
                down_block[3].col = down_col;
                bottom_block_num = 2;
            }
            else if(c[1] == '2'){
                down_block[0].row = -2;
                down_block[0].col = down_col+1;
                down_block[1].row = -2;
                down_block[1].col = down_col+2;
                down_block[2].row = -1;
                down_block[2].col = down_col;
                down_block[3].row = -2;
                down_block[3].col = down_col;
                bottom_block_num = 3;
            }
            else if(c[1] == '3'){
                down_block[0].row = -3;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -2;
                down_block[2].col = down_col+1;
                down_block[3].row = -3;
                down_block[3].col = down_col+1;
                bottom_block_num = 2;
            }
            else if(c[1] == '4'){
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -1;
                down_block[2].col = down_col+2;
                down_block[3].row = -2;
                down_block[3].col = down_col+2;
                bottom_block_num = 3;
            }
        }
        else if(c[0] == 'J'){
            down_col = c[3] - '0' -1;
            if(c[1] == '1'){
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -2;
                down_block[2].col = down_col+1;
                down_block[3].row = -3;
                down_block[3].col = down_col+1;
                bottom_block_num = 2;
            }
            else if(c[1] == '2'){
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -1;
                down_block[2].col = down_col+2;
                down_block[3].row = -2;
                down_block[3].col = down_col;
                bottom_block_num = 3;
            }
            else if(c[1] == '3'){
                down_block[0].row = -3;
                down_block[0].col = down_col+1;
                down_block[1].row = -1;
                down_block[1].col = down_col;
                down_block[2].row = -2;
                down_block[2].col = down_col;
                down_block[3].row = -3;
                down_block[3].col = down_col;
                bottom_block_num = 2;
            }
            else if(c[1] == '4'){
                down_block[0].row = -2;
                down_block[0].col = down_col;
                down_block[1].row = -2;
                down_block[1].col = down_col+1;
                down_block[2].row = -1;
                down_block[2].col = down_col+2;
                down_block[3].row = -2;
                down_block[3].col = down_col+2;
                bottom_block_num = 3;
            }
        }
        else if(c[0] == 'S'){
            down_col = c[3] - '0' -1;
            if(c[1] == '1'){
                down_block[0].row = -2;
                down_block[0].col = down_col+2;
                down_block[1].row = -1;
                down_block[1].col = down_col;
                down_block[2].row = -1;
                down_block[2].col = down_col+1;
                down_block[3].row = -2;
                down_block[3].col = down_col+1;
                bottom_block_num = 3;
            }
            else if(c[1] == '2'){
                down_block[0].row = -2;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -2;
                down_block[2].col = down_col+1;
                down_block[3].row = -3;
                down_block[3].col = down_col;
                bottom_block_num = 2;
            }
        }
        else if(c[0] == 'Z'){
            down_col = c[3] - '0' -1;
            if(c[1] == '1'){
                down_block[0].row = -2;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -1;
                down_block[2].col = down_col+2;
                down_block[3].row = -2;
                down_block[3].col = down_col+1;
                bottom_block_num = 3;
            }
            else if(c[1] == '2'){
                down_block[0].row = -2;
                down_block[0].col = down_col+1;
                down_block[1].row = -1;
                down_block[1].col = down_col;
                down_block[2].row = -2;
                down_block[2].col = down_col;
                down_block[3].row = -3;
                down_block[3].col = down_col+1;
                bottom_block_num = 2;
            }
        }
        else if(c[0] == 'I'){
            down_col = c[3] - '0' -1;
            if(c[1] == '1'){
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -2;
                down_block[1].col = down_col;
                down_block[2].row = -3;
                down_block[2].col = down_col;
                down_block[3].row = -4;
                down_block[3].col = down_col;
                bottom_block_num = 1;
            }
            else if(c[1] == '2'){
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -1;
                down_block[2].col = down_col+2;
                down_block[3].row = -1;
                down_block[3].col = down_col+3;
                bottom_block_num = 4;
            }
        }
        else if(c[0] == 'O'){
                down_col = c[3] - '0' -1;
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -2;
                down_block[2].col = down_col;
                down_block[3].row = -2;
                down_block[3].col = down_col+1;
                bottom_block_num = 2;
        }
        else if(c[0] == 'E'){
            break;
        }
        //READ over
        //block down
        Listnode* now_check_ptr = head->next->next->next;
        int now_check_row = -1;
        bool collision = 0;
        while(!collision){
            bool all_pass = 1;
            for(int i = 0; i<bottom_block_num; i++){
                Listnode* temp = now_check_ptr;
                if(down_block[i].row != now_check_row){
                    for(int j = now_check_row; j!=down_block[i].row; j--)
                        temp = temp->prev;
                }
                if(now_check_ptr->next->data[down_block[i].col] == 1){
                    all_pass = 0;
                    break;
                }
            }
            if(!all_pass){
                collision = 1;
            }
            else{
                for(int i = 0; i<4; i++)
                    down_block[i].row++;
                now_check_ptr = now_check_ptr->next;
                now_check_row++;
            }
        }

        for(int i = 0; i<4; i++){
            Listnode* temp = now_check_ptr;
            if(down_block[i].row != now_check_row){
                for(int j = now_check_row; j!=down_block[i].row; j--)
                    temp = temp->prev;
            }
            temp->data[down_block[i].col] = 1;
        }
        //block down over
        //delete row

    }


    return 0;
}
