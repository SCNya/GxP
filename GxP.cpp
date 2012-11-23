#include "GxP.h"

void step()
{
    while(rend());
}

void create(ifstream &in)
{
    int i(0);
    string s;
    getline(in, s);
    n = new int (s.size());
    m = new int (1);
    while (getline(in, s)) (*m)++;
    mass = new bool*[(*m)];
    for (; i < (*m); i++)
        mass[i] = new bool[(*n)];
    cout << "m= " << *m << endl;
    cout << "n= " << *n << endl;
    *m = 0;
    in.clear();
    in.seekg(0, ios::beg);
    while (getline(in, s))
        {
            for (i = 0; i<(*n); i++)
                if (s[i] == '+') mass[(*m)][i] = true;
                else
                    mass[(*m)][i] = false;
            (*m)++;
        }
}

bool rend()
{
    int point(0);
    int mat[((*m)*(*n)*2)];
    int *p = &mat[0];
        for (int i(0); i < (*m); i++)
            for (int j(0); j < (*n); j++)
                if (mass[i][j] == false)
                {
                    point++;
                    *p = i;
                    p++;
                    *p = j;
                    p++;
                }
        *p = (-1);
        if (point != 0)
        {
        calc(mat);
        }
        if (count() != false)
        return false;
    else
    return true;
}

void calc(int i, int j)
{
    view(i, j);
    for (int x(0); x<*m; x++)
        for (int y(0); y<*n; y++)
        {
            if ((i == x) || (j == y))
            {
            if (mass[x][y] == true)
            mass[x][y] = false;
            else
            mass[x][y] = true;
            }
        }
}

void view(int i, int j)
{
    for (int x(0); x<*m; x++)
    {
        cout << endl;
        for (int y(0); y<*n; y++)
            if ((i == x) && (j == y))
                cout << "\t(" << mass[x][y] << ')';
                else
            cout << "\t " << mass[x][y];
    }
    cout << endl;
}

void view()
{
    for (int x(0); x<*m; x++)
    {
        cout << endl;
        for (int y(0); y<*n; y++)
            cout << "\t " << mass[x][y];
    }
    cout << endl;
}


void calc(int *mat)
{
    for (int i(0); i < ((*m)*(*n)*2); i = i+2)
    {
        if (mat[i] == (-1))
            break;
        calc(mat[i], mat[(i+1)]);
    }
}

bool count()
{
    bool res(false);
    int soc(0);
    for (int x(0); x<*m; x++)
        for (int y(0); y<*n; y++)
            if (mass[x][y] == true) soc++;
    if (soc == ((*m)*(*n))) res = true;
    return res;
}
