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

int arc()
{
    counter = 0;
    long long aux;
    int check;
<<<<<<< Updated upstream
    int lastcol = 1;
    long long varaux;
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
=======
    int lastcol = h;

    table[1][h] = 1;

    for (int row = 1; row < n + 1; row++)
>>>>>>> Stashed changes
    {
        check = 0;
        for (int col = lastcol; col < ceiling + 1; col++)
        {

            aux = 0;
<<<<<<< Updated upstream
            for (int k = row - h + 1; k < row; k++)
=======

            for (int k = col - h + 1; k < col; k++)
>>>>>>> Stashed changes
            {
                //aux += table[k][col - 1];
                aux = mod_add(aux, table[row - 1][k], 1000000007);
            }
<<<<<<< Updated upstream
            if (row != h || col != 1)
=======

            //aux = mod_add(mod_sub(table[row - 1][col], table[row - h][col - 1], 1000000007), table[row - 1][col - 1], 1000000007);

            //aux = mod_sub(mod_add(table[row - 1][col], table[row - 1][col - 1], 1000000007), table[row - h][col - 1], 1000000007);
            //6 = 4-1+3

            if (row != 1 || col != h)
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream

            for (int aux = row - h + 1; aux < row; aux++)
            {
                for (int auxcol = 1; auxcol <= n - col; auxcol++)
                {
                    //counter += table[row][col] * table[aux][auxcol];
                    varaux = (long long)(table[row][col] * table[aux][auxcol]) % 1000000007;
                    counter = mod_add(counter, varaux, 1000000007);
                }
            }
            if (varaux == 0)
            {
                break;
            }
        }
    }
    /*
    for (int row = h + 1; row <= ceiling; row++)
    {
        for (int col = 2; col < n; col++)
        {
            for (int aux = row - h + 1; aux < row; aux++)
            {
                for (int auxcol = 1; auxcol <= n - col; auxcol++)
                {
                    //counter += table[row][col] * table[aux][auxcol];
                    long long varaux = (long long)(table[row][col] * table[aux][auxcol]) % 1000000007;
                    counter = mod_add(counter, varaux, 1000000007);
                }
=======
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
>>>>>>> Stashed changes
            }
        }
        lastcol++;
    }
    */
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
