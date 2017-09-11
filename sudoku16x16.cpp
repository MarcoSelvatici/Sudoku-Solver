#include <iostream>
#include <vector>

using namespace std;

int griglia[16][16]={ {0, 0, 5, 0,   4, 8, 0, 0,    0, 0, 13, 12,    0, 2, 0, 0},
                      {0, 0, 0, 0,   3, 5, 15, 14,    11, 2, 10, 1,    0, 0, 0, 0},
                      {1, 0, 4, 6,   0, 0, 0, 0,    0, 0, 0, 0,    8, 7, 0, 10},
                      {0, 0, 2, 3,   0, 10, 0, 0,    0, 0, 5, 0,    11, 15, 0, 0},

                      {2, 12, 0, 0,   0, 0, 6, 11,    10, 15, 0, 0,    0, 0, 4, 16},
                      {6, 3, 0, 14,   0, 0, 0, 0,    0, 0, 0, 0,    9, 0, 10, 7},
                      {0, 10, 0, 0,   9, 0, 2, 8,    3, 1, 0, 7,    0, 0, 12, 0},
                      {0, 4, 0, 0,   10, 0, 3, 0,    0, 16, 0, 6,    0, 0, 8, 0},

                      {0, 5, 0, 0,   6, 0, 1, 0,    0, 11, 0, 15,    0, 0, 16, 0},
                      {0, 6, 0, 0,   12, 0, 8, 16,    5, 4, 0, 9,    0, 0, 2, 0},
                      {16, 9, 0, 2,   0, 0, 0, 0,    0, 0, 0, 0,    13, 0, 11, 14},
                      {10, 15, 0, 0,   0, 0, 14, 3,    16, 13, 0, 0,    0, 0, 1, 6},

                      {0, 0, 6, 7,   0, 3, 0, 0,    0, 0, 11, 0,    14, 8, 0, 0},
                      {12, 0, 3, 16,   0, 0, 0, 0,    0, 0, 0, 0,    2, 4, 0, 5},
                      {0, 0, 0, 0,   14, 15, 13, 12,    8, 7, 9, 3,    0, 0, 0, 0},
                      {0, 0, 10, 0,   8, 6, 0, 0,    0, 0, 1, 4,    0, 13, 0, 0},
                    };

struct dominio
{
    // vero se è disponibile
    bool d[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int dimesioni_dom = 17;
};

// sensata solo per le caselle vuote
dominio CalcolaDominio(int rig, int col)
{
    dominio dom;
    // controllo la riga
    for(int i = 0; i < 16; i++)
        if(griglia[rig][i] != 0)
            dom.d[ griglia[rig][i] - 1 ] = false;

    // controllo la colonna
    for(int i = 0; i < 16; i++)
        if(griglia[i][col] != 0)
            dom.d[ griglia[i][col] - 1 ] = false;

    // controllo il "quadrato"
    int start_pos_x = rig / 4;
    start_pos_x *= 4;
    int start_pos_y = col / 4;
    start_pos_y *= 4;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(griglia[start_pos_x + i][start_pos_y + j] != 0)
                dom.d[ griglia[start_pos_x + i][start_pos_y + j] - 1 ] = false;

    int cont = 0;
    for (int i=0; i<16; i++)
        if(dom.d[i])
            cont++;
    dom.dimesioni_dom = cont;

    return dom;
}

void visualizzaGriglia()
{
    cout << "\n ";
    for(int i = 0; i < 16; i++){
        if (i == 4 || i == 8 || i == 12)
            cout << "-----------------------------------------------------\n ";
        for(int j = 0; j < 16; j++){
            if (j == 4 || j == 8 || j == 12)
                cout << "| ";
            cout << griglia[i][j] << " ";
            if(griglia[i][j] < 10) cout << " ";
        }
        cout << "\n ";
    }
}

bool vittoria()
{
    for(int i = 0; i < 16; i++)
        for(int j = 0; j < 16; j++)
            if(griglia[i][j] == 0)
                return false;

    visualizzaGriglia();
    return true;
}

int conta_chiamate = 0;
int risolvi()
{
    conta_chiamate++;
    int best = 17;
    int best_row;
    int best_col;
    vector< pair< int, int > > sicuri;
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            if (griglia[i][j] == 0){
                dominio dom = CalcolaDominio(i,j);
                if(dom.dimesioni_dom == 1){
                    sicuri.push_back(make_pair(i,j));
                    for(int k=0; k<16; k++)
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
    for(int i = 0; i < 16; i++){
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
