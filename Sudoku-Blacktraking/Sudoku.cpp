#include <iostream>



#define MAX 9



using namespace std;
// es valido poner este numero aki? 
bool esSeguro(int tablero[9][9], int fila, int col, int num)
{
    // revisar fila
    for(int i = 0; i < 9; i++)
        if(tablero[fila][i] == num)
            return false;

    // revisar columna
    for(int i = 0; i < 9; i++)
        if(tablero[i][col] == num)
            return false;

    // revisar bloque 3x3
    int inicioFila = fila - (fila % 3);
    int inicioCol  = col - (col % 3);

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(tablero[inicioFila + i][inicioCol + j] == num)
                return false;

    return true;
}
//backtraking

bool SolucionarSudoku(int tablero[9][9])
{
    // Recorrer el tablero para encontrar una celda vacía
    for(int fila = 0; fila < 9; fila++)
    {
    for(int col = 0; col < 9; col++)
    {
        if(tablero[fila][col] == 0)
        {
            //Probamos números del 1 al 9
            for(int num = 1; num <= 9; num++)
            {
                // Verificar si es seguro colocar el número en la celda  "Es seguro"
                if(esSeguro(tablero, fila, col, num))
                {
                        // 1. probar temporalmente
                        tablero[fila][col] = num;

                        //cout << "Pongo " << num << " en (" << fila << "," << col << ")\n";
                        

                        // 2. recursion
                        if(SolucionarSudoku(tablero))
                            return true;
                        //cout << "Backtrack en ("<< fila << "," << col << ") borro " << num << "\n";
                        
                        

                        // 3. si falla → deshacer (BACKTRACK)
                        tablero[fila][col] = 0;
                }
            }
             // si ningún número funciona aquí
                return false;
        }
    }
    }
    return true; // Si no hay celdas vacías, el Sudoku está resuelto
}


void Imprimir(int tablero[9][9]) {

    for (int fila = 0; fila < 9; fila++) {

        if (fila % 3 == 0 && fila != 0) {

            cout << "------+-------+------" << endl;

        }

        for (int col = 0; col < 9; col++) {

            if (col % 3 == 0 && col != 0) {

                cout << "| ";

            }



            cout << tablero[fila][col] << " ";

        }



        cout << endl;

    }

}

int main()
{
    freopen("in.txt","r",stdin);

    int tablero[9][9]={};
    int pos_x,pos_y,valor;

    while(cin>>pos_x>>pos_y>>valor)
        tablero[pos_x-1][pos_y-1]=valor;

    Imprimir(tablero);

    cout << "\nResolviendo...\n";

    if(SolucionarSudoku(tablero))
    {
        cout << "\nSudoku resuelto:\n";
        Imprimir(tablero);
    }
    else
    {
        cout << "No tiene solucion" << endl;
    }

    return 0;
}

