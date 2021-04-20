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
vector<vector<int>> table;

int arc()
{
    int aux;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            table[i][j] = 0;
        }
    }
    table[h][1] = 1;
    for (int row = h; row < n + 1; row++)
    {
        for (int col = 1; col < n + 1; col++)
        {

            aux = 0;
            for (int k = row - h + 1; k < row; k++)
            {
                aux += table[k][col - 1];
            }
            if (row != h || col != 1)
            {
                table[row][col] = aux;
            }
        }
    }

    return narcs;
}
void printMatrix()
{
    cout << "\n";
    for (int i = 0; i < n + 1; i++)
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
        table = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        arc();
        printMatrix();
    }
    return 0;
}
