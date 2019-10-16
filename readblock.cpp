#include "p1.h"

using namespace std;
int Readblock(char*c, block* down_block)
{
    //block down_block[4]; //用來記錄讀入的block的 row,col
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


    return bottom_block_num;

}
