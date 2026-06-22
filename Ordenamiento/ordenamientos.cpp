#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

const int ENSAYOS = 1000; 

struct DatosRendimiento {
    string nombre;
    long long iteraciones;
    double tiempo_ns;
};

void ordenBurbuja(vector<int>& v, long long& c) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            c++;
            if (v[j] > v[j+1]) swap(v[j], v[j+1]);
        }
    }
}

void ordenSeleccion(vector<int>& v, long long& c) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            c++;
            if (v[j] < v[m]) m = j;
        }
        swap(v[i], v[m]);
    }
}

void ordenInsercion(vector<int>& v, long long& c) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int aux = v[i], j = i - 1;
        while (j >= 0 && v[j] > aux) {
            c++; v[j + 1] = v[j]; j--;
        }
        v[j + 1] = aux;
    }
}

void mezcla(vector<int>& v, int l, int m, int r, long long& c) {
    int n1 = m - l + 1, n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = v[l + i];
    for (int j = 0; j < n2; j++) R[j] = v[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        c++;
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

void ordenMezcla(vector<int>& v, int l, int r, long long& c) {
    if (l < r) {
        int m = l + (r - l) / 2;
        ordenMezcla(v, l, m, c);
        ordenMezcla(v, m + 1, r, c);
        mezcla(v, l, m, r, c);
    }
}

int particion(vector<int>& v, int b, int a, long long& c) {
    int e = v[a], i = b - 1;
    for (int j = b; j < a; j++) {
        c++;
        if (v[j] < e) { i++; swap(v[i], v[j]); }
    }
    swap(v[i + 1], v[a]);
    return i + 1;
}

void ordenRapido(vector<int>& v, int b, int a, long long& c) {
    if (b < a) {
        int p = particion(v, b, a, c);
        ordenRapido(v, b, p - 1, c);
        ordenRapido(v, p + 1, a, c);
    }
}

template<typename T>
DatosRendimiento evaluar(string n, vector<int> b, T f) {
    long long it_total = 0;
    vector<int> w = b;
    long long d = 0;
    f(w, d);

    auto t1 = steady_clock::now();
    for(int i = 0; i < ENSAYOS; i++) {
        vector<int> c = b;
        long long p = 0;
        f(c, p);
        it_total += p;
    }
    auto t2 = steady_clock::now();
    double diff = duration_cast<nanoseconds>(t2 - t1).count();
    return {n, it_total / ENSAYOS, diff / ENSAYOS};
}

int main() {
    srand(time(0));
    int tam, mi, ma;

    cout << "****************************************************" << endl;
    cout << "      LABORATORIO DE ANALISIS DE ALGORITMOS        " << endl;
    cout << "****************************************************" << endl;
    cout << ">> Tamaño del arreglo: "; cin >> tam;
    cout << ">> Valor minimo: "; cin >> mi;
    cout << ">> Valor maximo: "; cin >> ma;

    vector<int> base(tam);
    for(int &x : base) x = mi + rand() % (ma - mi + 1);

    vector<DatosRendimiento> lista;
    
    lista.push_back(evaluar("Burbuja", base, [](vector<int>& v, long long& c){ ordenBurbuja(v, c); }));
    lista.push_back(evaluar("Seleccion", base, [](vector<int>& v, long long& c){ ordenSeleccion(v, c); }));
    lista.push_back(evaluar("Insercion", base, [](vector<int>& v, long long& c){ ordenInsercion(v, c); }));
    lista.push_back(evaluar("Merge Sort", base, [&](vector<int>& v, long long& c){ ordenMezcla(v, 0, v.size()-1, c); }));
    lista.push_back(evaluar("Quick Sort", base, [&](vector<int>& v, long long& c){ ordenRapido(v, 0, v.size()-1, c); }));

    sort(lista.begin(), lista.end(), [](const DatosRendimiento& a, const DatosRendimiento& b){
        return a.tiempo_ns < b.tiempo_ns;
    });

    cout << "\n" << left << setw(5) << "RANK" << setw(18) << "METODO" 
         << setw(18) << "PASOS (PROM)" << "TIEMPO (NS)" << endl;
    cout << string(60, '-') << endl;

    for(int i = 0; i < (int)lista.size(); i++) {
        cout << left << setw(5) << (i+1) 
             << setw(18) << lista[i].nombre 
             << setw(18) << lista[i].iteraciones 
             << fixed << setprecision(2) << lista[i].tiempo_ns << " ns" << endl;
    }

    cout << "\n[RESULTADO] Algoritmo mas optimo: " << lista[0].nombre << endl;
    cout << "****************************************************" << endl;

    return 0;
}