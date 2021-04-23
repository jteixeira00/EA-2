//g++ -std=c++17 -Wall -Wextra -O2 "Trabalho2.cpp" -lm

#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;
int n;       //numero de blocos;
int h;       //tamanho do bloco;
int ceiling; //altura do teto -> H no enunciado;
int narcs;
vector<vector<long long>> table;
vector<vector<long long>> tableDown;
long long counter = 0;

long long mod_abs(long long a, int mod)
{
    return ((a % mod) + mod) % mod;
}
long long mod_add(long long a, int b, int mod)
{
    return (mod_abs(a, mod) + mod_abs(b, mod)) % mod;
}
long long mod_sub(long long a, int b, int mod)
{
    return (mod_abs(a, mod) - mod_abs(b, mod)) % mod;
}
int arc()
{
    counter = 0;
    long long aux;
    int check;
    int lastcol = h;

    table[1][h] = 1;

    for (int row = 1; row < n + 1; row++)
    {
        check = 0;
        for (int col = lastcol; col < ceiling + 1; col++)
        {

            aux = 0;

            for (int k = col - h + 1; k < col; k++)
            {
                //aux += table[k][col - 1];
                aux = mod_add(aux, table[row - 1][k], 1000000007);
            }

            //aux = mod_add(mod_sub(table[row - 1][col], table[row - h][col - 1], 1000000007), table[row - 1][col - 1], 1000000007);

            //aux = mod_sub(mod_add(table[row - 1][col], table[row - 1][col - 1], 1000000007), table[row - h][col - 1], 1000000007);
            //6 = 4-1+3

            if (row != 1 || col != h)
            {
                table[row][col] = aux;
            }
            if (aux)
            {
                if (check == 0)
                {
                    lastcol = col;
                }
                check = 1;
            }
            if (check)
            {
                if (aux == 0)
                {
                    break;
                }
            }
        }

        for (int col = 0; col <= ceiling; col++)
        {

            aux = 0;
            for (int j = col + 1; j < col + h; j++)
            {
                if (j <= ceiling)
                {
                    aux = mod_add(aux, tableDown[row - 1][j], 1000000007);
                    aux = mod_add(aux, table[row - 1][j], 1000000007);
                }
            }
            tableDown[row][col] = aux;

            if (col == h)
            {
                counter = mod_add(counter, tableDown[row][col], 1000000007);
            }
        }
        lastcol++;
    }

    return counter;
}
void printMatrix()
{
    cout << "\n";
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < ceiling + 1; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}
void printMatrixDown()
{
    cout << "\n";
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < ceiling + 1; j++)
        {
            cout << tableDown[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ncases;

    cin >> ncases;
    for (int i = 0; i < ncases; i++)
    {

        cin >> n >> h;
        cin >> ceiling;
        table = vector<vector<long long>>(n + 1, vector<long long>(ceiling + 1, 0));
        tableDown = vector<vector<long long>>(n + 1, vector<long long>(ceiling + 1, 0));
        cout << arc() << "\n";
        //printMatrix();
        // printMatrixDown();
    }
    return 0;
}