#include <iostream>

using namespace std;

class Martix
{
    public:
        Martix(int temp_row,int temp_col);
        Martix();
        ~Martix();
        void Cre_Martix();
        void Inp_Martix();
        void Pri_Martix();
        void Sor_Martix();
    private:
        int row,col;
        int **data;
};

Martix::Martix(int temp_row,int temp_col):row(temp_row),col(temp_col){}

Martix::Martix():row(1),col(1){}

Martix::~Martix()
{
    for(int i = 0; i < row; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

void Martix::Cre_Martix()
{
    int **data = new int*[col];
    for(int i = 0;i < col;i ++)
    {
        data[i] = new int[row];
    }
}

void Martix::Inp_Martix()
{
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            cin >> data[i][j];
        }
    }
}

void Martix::Pri_Martix()
{
    if(col == 1 && row == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        //cout << 1 << endl;
        for(int i = 0; i < col; i++)
        {
            for(int j = 0; j < row; j++)
            {
                cout << data[i][j] << ' ';
            }
            cout << endl;
        }
    }
}

void Martix::Sor_Martix()
{
    if(col == 1 && row == 1){}
    else
    {
        if(col == 1)
        {
            int temp = data[0][0];
            for(int i = 1;i < row;i ++)
            {
                data[0][i - 1] = data[0][i];
            }
            data[0][row - 1] = temp;
        }
        else
        {
            int *temp = data[0];
            for(int i = 1;i < col;i ++)
            {
                data[i - 1] = data[i];
            }
            data[col - 1] = temp;
        }
    }
}

int main()
{
    int rows,cols,num;
    cin >> num;
    Martix *martix = new Martix[num];
    for(int i = 0;i < num;i ++)
    {
        cin >> rows >> cols; 
        new (&martix[i]) Martix(cols,rows);
        martix[i].Cre_Martix();
        martix[i].Inp_Martix();
        martix[i].Sor_Martix();
    }
    for(int i = 0;i < num;i ++)
    {
        martix[i].Pri_Martix();
    }
}

