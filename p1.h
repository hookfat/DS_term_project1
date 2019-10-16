
using namespace std;

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

int Readblock(char*c, block* down_block);
void print_output(Listnode*,int);
Listnode* blockdown(int bottom_block_num, block* down_block, Listnode* head, int col_out);

