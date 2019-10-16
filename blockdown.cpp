#include "p1.h"

Listnode* blockdown(int bottom_block_num, block* down_block, Listnode* head, int col_out)
{
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
    //delete part
    Listnode* del_row[4]; //用來記錄要刪除哪些row
        for(int i = 0; i<4; i++)
            del_row[i] = nullptr;
        //which row to delete
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
        for(int j = 0; j<4; j++){
            for(int i = 0; i<4; i++){
                if(del_row[i] != nullptr){
                    if(del_row[i]->prev != nullptr)
                        if(del_row[i]->prev->prev != nullptr)
                            if(del_row[i]->prev->prev->prev != nullptr)
                                if(del_row[i]->prev->prev->prev->prev != nullptr){
                                    del_row[i]->prev->next = del_row[i]->next;
                                    if(del_row[i]->next != nullptr)
                                        del_row[i]->next->prev = del_row[i]->prev;
                                    for(int j = 0; j<col_out; j++)
                                        del_row[i]->data[j] = 0;
                                    head->prev = del_row[i];
                                    del_row[i]->next = head;
                                    del_row[i]->prev = nullptr;
                                    head = del_row[i];
                                    del_row[i] = nullptr;
                                }
                }
            }
        }
        return head;
}
