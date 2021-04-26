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
void printvector(vector<long long> vec);

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
int arc()
{
    counter = 0;
    long long aux;
    int check;
    int lastcol = h;
    vector<long long> somaup = vector<long long>(ceiling + 1, 1);
    vector<long long> newsomaup = vector<long long>(ceiling + 1, 0);
    vector<long long> somadown = vector<long long>(ceiling + 1, 0);
    vector<long long> newsomadown = vector<long long>(ceiling + 1, 0);
    table[1][h] = 1;
    for (int i = 0; i < h; i++)
    {
        somaup[i] = 0;
    }

    for (int row = 2; row < n + 1; row++)
    {
        //printvector(somaup);
        newsomaup = vector<long long>(ceiling + 1, 0);
        newsomadown = vector<long long>(ceiling + 1, 0);
        check = 0;
        for (int col = lastcol; col < ceiling + 1; col++)
        {
            if (row == 1 && col == h)
            {
                continue;
            }
            aux = 0;
            aux = mod_sub(somaup[col - 1], somaup[col - h], 1000000007);
            if (row != 1 || col != h)
            {
                table[row][col] = aux;
                newsomaup[col] = mod_add(newsomaup[col - 1], aux, 1000000007);
            }

            if (aux)
            {
                if (check == 0)
                {
                    lastcol = col;
                }
                check = 1;
            }
        }
        //cout << "vetor up anterior: ";
        //printvector(somaup);
        //cout << "vetor down anterior: ";
        //printvector(somadown);
        for (int col = 0; col < ceiling + 1; col++)
        {
            //cout << "col: " << col << "\n";

            aux = 0;
            if (col + h - 1 > ceiling)
            {
                aux = mod_add(aux, mod_sub(somaup[ceiling], somaup[col], 1000000007), 1000000007);
                //cout << "somaup1: " << somaup[col + 1] << " somaup2: " << somaup[col + h] << "\n";

                aux = mod_add(aux, mod_sub(somadown[ceiling], somadown[col], 1000000007), 1000000007);
            }
            else
            {
                aux = mod_add(aux, mod_sub(somaup[col + h - 1], somaup[col], 1000000007), 1000000007);
                //cout << "somaup1: " << somaup[col + 1] << " somaup2: " << somaup[col + h] << "\n";

                aux = mod_add(aux, mod_sub(somadown[col + h - 1], somadown[col], 1000000007), 1000000007);
            }

            //cout << "somadown1: " << somadown[col + 1] << " somadown2: " << somadown[col + h] << "\n\n";
            //cout << aux << "\n";
            tableDown[row][col] = mod_abs(aux, 1000000007);
            if (col != 0)
            {
                newsomadown[col] = mod_add(newsomadown[col - 1], aux, 1000000007);
            }
            else
            {
                newsomadown[col] = mod_abs(aux, 1000000007);
            }

            //cout << col << "\n";
            //printvector(table[row]);
            //printvector(tableDown[row]);
            if (col == h)
            {
                counter = mod_add(counter, tableDown[row][col], 1000000007);
            }
        }
        //cout << "linha que gerou: ";
        //printvector(tableDown[row]);

        /*
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
        */
        somadown = newsomadown;
        somaup = newsomaup;
        lastcol++;
    }

    return counter;
}

void printvector(vector<long long> vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
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
        // printMatrix();
        //printMatrixDown();
    }
    return 0;
}