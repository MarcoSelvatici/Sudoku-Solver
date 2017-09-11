/*

120 chiamate
int griglia[9][9]={ {0, 0, 5,    3, 0, 0,    0, 0, 0},
                    {8, 0, 0,    0, 0, 0,    0, 2, 0},
                    {0, 7, 0,    0, 1, 0,    5, 0, 0},

                    {4, 0, 0,    0, 0, 5,    3, 0, 0},
                    {0, 1, 0,    0, 7, 0,    0, 0, 6},
                    {0, 0, 3,    2, 0, 0,    0, 8, 0},

                    {0, 6, 0,    5, 0, 0,    0, 0, 9},
                    {0, 0, 4,    0, 0, 0,    0, 3, 0},
                    {0, 0, 0,    0, 0, 9,    7, 0, 0},
                    };

44 chiamate
int griglia[9][9]={ {0, 0, 0,    0, 0, 0,    0, 0, 0},
                    {0, 0, 3,    5, 0, 1,    7, 0, 0},
                    {0, 5, 0,    7, 9, 2,    0, 1, 0},

                    {3, 0, 8,    0, 0, 0,    6, 0, 4},
                    {0, 0, 0,    8, 0, 9,    0, 0, 0},
                    {5, 0, 7,    0, 0, 0,    2, 0, 1},

                    {0, 4, 0,    6, 1, 8,    0, 3, 0},
                    {0, 0, 6,    2, 0, 7,    4, 0, 0},
                    {0, 0, 0,    0, 0, 0,    0, 0, 0},
                    };

427 chiamate
int griglia[9][9]={ {0, 0, 0,    0, 0, 0,    8, 0, 6},
                    {0, 0, 9,    0, 0, 0,    0, 0, 0},
                    {0, 0, 6,    0, 4, 2,    0, 0, 0},

                    {0, 8, 0,    1, 0, 0,    0, 0, 0},
                    {0, 1, 0,    0, 0, 0,    0, 2, 0},
                    {0, 0, 0,    0, 0, 9,    0, 4, 0},

                    {0, 0, 0,    8, 3, 0,    1, 0, 0},
                    {0, 0, 0,    0, 0, 0,    9, 0, 0},
                    {2, 0, 5,    0, 0, 0,    0, 0, 0},
                    };

int griglia[9][9]={ {8, 0, 0,    0, 0, 0,    0, 0, 0},
                    {0, 0, 3,    6, 0, 0,    0, 0, 0},
                    {0, 7, 0,    0, 9, 0,    2, 0, 0},

                    {0, 5, 0,    0, 0, 7,    0, 0, 0},
                    {0, 0, 0,    0, 4, 5,    7, 0, 0},
                    {0, 0, 0,    1, 0, 0,    0, 3, 0},

                    {0, 0, 1,    0, 0, 0,    0, 6, 8},
                    {0, 0, 8,    5, 0, 0,    0, 1, 0},
                    {0, 9, 0,    0, 0, 0,    4, 0, 0},
                    };

int griglia[9][9]={ {0, 0, 0,    0, 0, 0,    8, 0, 6},
                    {0, 0, 9,    0, 0, 0,    0, 0, 0},
                    {0, 0, 6,    0, 4, 2,    0, 0, 0},

                    {0, 8, 0,    1, 0, 0,    0, 0, 0},
                    {0, 1, 0,    0, 0, 0,    0, 2, 0},
                    {0, 0, 0,    0, 0, 9,    0, 4, 0},

                    {0, 0, 0,    8, 3, 0,    1, 0, 0},
                    {0, 0, 0,    0, 0, 0,    9, 0, 0},
                    {2, 0, 5,    0, 0, 0,    0, 0, 0},
                    };

Grid created to challenge computer algorithms
int griglia[9][9]={ {0, 0, 0,    0, 0, 0,    0, 0, 0},
                    {0, 0, 0,    0, 0, 3,    0, 8, 5},
                    {0, 0, 1,    0, 2, 0,    0, 0, 0},

                    {0, 0, 0,    5, 0, 7,    0, 0, 0},
                    {0, 0, 4,    0, 0, 0,    1, 0, 0},
                    {0, 9, 0,    0, 0, 0,    0, 0, 0},

                    {5, 0, 0,    0, 0, 0,    0, 7, 3},
                    {0, 0, 2,    0, 1, 0,    0, 0, 0},
                    {0, 0, 0,    0, 4, 0,    0, 0, 9},
                    };

*/

#include <iostream>
#include <vector>

using namespace std;

int griglia[9][9]={ {0, 0, 0,    0, 0, 0,    8, 0, 6},
                    {0, 0, 9,    0, 0, 0,    0, 0, 0},
                    {0, 0, 6,    0, 4, 2,    0, 0, 0},

                    {0, 8, 0,    1, 0, 0,    0, 0, 0},
                    {0, 1, 0,    0, 0, 0,    0, 2, 0},
                    {0, 0, 0,    0, 0, 9,    0, 4, 0},

                    {0, 0, 0,    8, 3, 0,    1, 0, 0},
                    {0, 0, 0,    0, 0, 0,    9, 0, 0},
                    {2, 0, 5,    0, 0, 0,    0, 0, 0},
                    };


struct dominio
{
    // vero se è disponibile
    bool d[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int dimesioni_dom = 10;
};

dominio CalcolaDominio(int rig, int col)
{
    // NOTA se una casella è gia piena non viene contata come non nel dominio il numero all'interno
    // sensata solo per le caselle vuote
    dominio dom;
    // controllo la riga
    for(int i = 0; i<9; i++)
    {
        if(griglia[rig][i] != 0)
        {
            dom.d[ griglia[rig][i] - 1 ] = false;
        }
    }

    // controllo la colonna
    for(int i = 0; i<9; i++)
    {
        if(griglia[i][col] != 0)
        {
            dom.d[ griglia[i][col] - 1 ] = false;
        }
    }

    // controllo il quadrato
    int start_pos_x = rig / 3;
    start_pos_x *= 3;
    int start_pos_y = col / 3;
    start_pos_y *= 3;

    for(int i = 0; i< 3; i++){
        for(int j = 0; j< 3; j++){
            if(griglia[start_pos_x + i][start_pos_y + j] != 0)
            {
                dom.d[ griglia[start_pos_x + i][start_pos_y + j] - 1 ] = false;
            }
        }
    }

    int cont = 0;
    for (int i=0; i<9; i++)
    {
        if(dom.d[i])
            cont++;
    }
    dom.dimesioni_dom = cont;
    return dom;
}

void visualizzaGriglia()
{
    cout << "\n ";
    for(int i=0; i<9; i++){
        if (i == 3 || i == 6)
            cout << "---------------------\n ";
        for(int j=0; j<9; j++){
            if (j == 3 || j == 6)
                cout << "| ";
            cout << griglia[i][j] << " ";
        }
        cout << "\n ";
    }
}

bool vittoria()
{
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(griglia[i][j] == 0)
                return false;
        }
    }
    visualizzaGriglia();
    return true;
}

int conta_chiamate = 0;
int risolvi()
{
    conta_chiamate++;
    int best = 10;
    int best_row;
    int best_col;
    vector< pair< int, int > > sicuri;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if (griglia[i][j] == 0){
                dominio dom = CalcolaDominio(i,j);
                if(dom.dimesioni_dom == 1){
                    sicuri.push_back(make_pair(i,j));
                    for(int k=0; k<9; k++)
                        if(dom.d[k])
                            { griglia[i][j] = k + 1; break; }

                }
                else if(dom.dimesioni_dom < best){
                    best_row = i;
                    best_col = j;
                    best = dom.dimesioni_dom;
                }
            }
        }
    }
    if(vittoria())
        return 1;
    dominio dom = CalcolaDominio(best_row,best_col);

    // scorro i possibili domini
    for(int i = 0; i < 9; i++){
        if(dom.d[i]){ // se disponibile
            griglia[best_row][best_col] = i + 1;
            int temp = risolvi();
            if(temp == 1)
                return temp;
        }
    }
    if(vittoria())
        return 1;

    for(int i=0; i<sicuri.size(); i++)
        griglia[ sicuri[i].first ][ sicuri[i].second ] = 0;
    griglia[best_row][best_col] = 0;
    return 0;
}

int main()
{
    risolvi();
    cout << "\n\n Recursive calls: " << conta_chiamate << endl;
    return 0;
}
