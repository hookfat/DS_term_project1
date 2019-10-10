#include <iostream>
#include <fstream>
using namespace std;
int col_out;
class Listnode{
public:
    Listnode* next;
    Listnode* prev;
    bool* data;
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
            data[i] = 0;
    }
    ~Listnode(){
        delete[] data;
    }
};
typedef struct{
    int row;
    int col;
}block;

void print_output(Listnode*,int);

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
        block down_block[4]; //用來記錄讀入的block的 row,col
        int bottom_block_num;  //用來記錄有幾個block在底部
        int down_col; //紀錄輸入的方格的col
        if(c[0] == 'T'){
            if(c[4] != '\0'){
                down_col = (c[3] - '0') * 10;
                down_col += c[4] - '0' -1;
            }
            else
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
            if(c[4] != '\0'){
                down_col = (c[3] - '0') * 10;
                down_col += c[4] - '0' -1;
            }
            else
                down_col = c[3] - '0' -1;
            if(c[1] == '1'){
                down_block[0].row = -1;
                down_block[0].col = down_col;
                down_block[1].row = -1;
                down_block[1].col = down_col+1;
                down_block[2].row = -2;
                down_block[2].col = down_col;
                down_block[3].row = -3;
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
            if(c[4] != '\0'){
                down_col = (c[3] - '0') * 10;
                down_col += c[4] - '0' -1;
            }
            else
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
            if(c[4] != '\0'){
                down_col = (c[3] - '0') * 10;
                down_col += c[4] - '0' -1;
            }
            else
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
            if(c[4] != '\0'){
                down_col = (c[3] - '0') * 10;
                down_col += c[4] - '0' -1;
            }
            else
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
            if(c[4] != '\0'){
                down_col = (c[3] - '0') * 10;
                down_col += c[4] - '0' -1;
            }
            else
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
                if(c[3] != '\0'){
                    down_col = (c[2] - '0') * 10;
                    down_col += c[3] - '0' -1;
                }
                else
                    down_col = c[2] - '0' -1;
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
        while(!collision && now_check_row < row){
            bool all_pass = 1;
            for(int i = 0; i<bottom_block_num; i++){
                Listnode* temp = now_check_ptr;
                if(down_block[i].row != now_check_row){
                    for(int j = now_check_row; j!=down_block[i].row; j--)
                        temp = temp->prev;
                }
                if(now_check_ptr->next == nullptr){
                    all_pass = 0;
                    break;
                }
                else if(temp->next->data[down_block[i].col] == 1){
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
        Listnode* del_row[4]; //用來記錄要刪除哪些row
        for(int i = 0; i<4; i++)
            del_row[i] = nullptr;

        for(int i = 0; i<4; i++){
            Listnode* temp = now_check_ptr;
            bool flag1 = 0;
            for(int j = 0; j<i; j++){
                if(down_block[j].row == down_block[i].row){
                    flag1 = 1;
                    break;
                }
            }

            if(flag1)
                continue;


            if(down_block[i].row != now_check_row){
                for(int j = now_check_row; j!=down_block[i].row; j--)
                    temp = temp->prev;
            }
            bool flag = 0;
            for(int j = 0; j<col_out; j++){
                if(temp->data[j] != 1){
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                del_row[i] = temp;
        }

        for(int i = 0; i<4; i++){
            if(del_row[i] != nullptr){
                if(del_row[i]->prev != nullptr)
                    del_row[i]->prev->next = del_row[i]->next;
                if(del_row[i]->next != nullptr)
                    del_row[i]->next->prev = del_row[i]->prev;
                for(int j = 0; j<col_out; j++)
                        del_row[i]->data[j] = 0;
                head->prev = del_row[i];
                del_row[i]->next = head;
                del_row[i]->prev = nullptr;
                head = del_row[i];
            }
        }
        //delete row over
        //check lose
        bool lose = 0;
        for(int i = 0; i<4; i++){
            if(down_block[i].row < 0){
                lose = 1;
                break;
            }
        }
        if(lose)
            break;
        //check lose over
    }
    //print output

    print_output(head->next->next->next->next, col);

    //free memory
    Listnode* temp1 = head->next;
    while(temp1!=nullptr){
        temp1->prev->~Listnode();
        delete temp1->prev;
        temp1 = temp1->next;
    }


    return 0;
}
/*
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
*/
void print_output(Listnode* head, int num)
{
    ofstream out;
    out.open("Tetris.output");
    Listnode* temp = head;
    while(temp != nullptr){
        for(int i = 0; i<col_out; i++)
            out << temp->data[i];
        out << endl;
        temp = temp->next;
    }

}
