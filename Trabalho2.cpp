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
    int lastcol = 2;

    /*
    for (int i = 0; i < ceiling + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            table[i][j] = 0;
        }
    }
    */
    table[h][1] = 1;
    for (int row = h; row < ceiling + 1; row++)
    {
        check = 0;
        for (int col = lastcol; col < n + 1; col++)
        {

            aux = 0;

            /*for (int k = row - h + 1; k < row; k++)
            {
                //aux += table[k][col - 1];
                aux = mod_add(aux, table[k][col - 1], 1000000007);
            }
*/
            //aux = mod_add(mod_sub(table[row - 1][col], table[row - h][col - 1], 1000000007), table[row - 1][col - 1], 1000000007);
            aux = mod_sub(mod_add(table[row - 1][col], table[row - 1][col - 1], 1000000007), table[row - h][col - 1], 1000000007);
            //6 = 4-1+3

            if (row != h || col != 1)
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
            /*
            for (int aux = row - h + 1; aux < row; aux++)
            {
                for (int auxcol = 1; auxcol <= n - col; auxcol++)
                {
                    //counter += table[row][col] * table[aux][auxcol];
                    varaux = (long long)(table[row][col] * table[aux][auxcol]) % 1000000007;
                    counter = mod_add(counter, varaux, 1000000007);
                }
            }
            */
            long long auxcounter = 0;

            if (col < (n) / 2)
            {
                //cout << "primeiro caso na posicao " << row << " " << col << "\n";
                for (int auxcol = 1; auxcol <= col; auxcol++)
                {
                    auxcounter = mod_add(auxcounter, table[row][auxcol], 1000000007);
                }
                counter = mod_add(counter, auxcounter * table[row][col] * 2, 1000000007);
            }

            else if ((col == (int)(n + 1) / 2))
            {
                //cout << "segundo caso na posicao " << row << " " << col << "\n";
                for (int auxcol = 1; auxcol < col; auxcol++)
                {
                    auxcounter = mod_add(auxcounter, table[row][auxcol], 1000000007);
                    //  cout << auxcounter << "\n";
                }
                counter = mod_add(counter, auxcounter * table[row][col] * 2, 1000000007);
                counter = mod_add(counter, table[row][col] * table[row][col], 1000000007);
                //cout << "counter: " << counter << "\n";
            }
            else
            {
                //cout << "terceiro caso na posicao " << row << " " << col << "\n";
                for (int auxcol = 1; auxcol <= n - col + 1; auxcol++)
                {
                    auxcounter = mod_add(auxcounter, table[row][auxcol], 1000000007);
                    //cout << auxcounter << "\n";
                }
                counter = mod_add(counter, auxcounter * table[row][col] * 2, 1000000007);
                //cout << "counter: " << counter << "\n";
            }
        }
    }

    return counter;
}
void printMatrix()
{
    cout << "\n";
    for (int i = 0; i < ceiling + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << table[i][j] << " ";
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
        table = vector<vector<long long>>(ceiling + 1, vector<long long>(n + 1, 0));
        cout << arc() << "\n";
        //printMatrix();
    }
    return 0;
}
