#include "listaadj/Grafo.h" 
#include <fstream>
using namespace std;

void transposto (Grafo *grafo)
{
    Grafo *grafoT = grafo->grafoTransposto();
    grafoT->imprime();
}


void insereAresta (Grafo *grafo, int i, int j, int peso)
{
    if (grafo->existeAresta(i, j))
    {
        cout << "Aresta já existe" << endl;
    }
    else
    {
        cout << "Digite o peso da aresta: ";
        int peso;
        cin >> peso;
        grafo->insereAresta(i, j, peso);
        grafo->imprime();
    }
}

void removerAresta (Grafo *grafo, int i, int j)
{
    if (grafo->existeAresta(i, j))
    {
        grafo->retiraAresta(i, j);
        cout << "Aresta removida" << endl;
        grafo->imprime();
    }
    else
    {
        cout << "Aresta não existe" << endl;
    }
}

void listaAdjacente (Grafo *grafo, int i)
{
    vector<int> lista = grafo->listaAdj(i);
    for (int i=0; i < lista.size(); i++)
        cout << lista.at(i) << " ";
    cout << endl;
}

void caminhoEuler (Grafo *grafo)
{
    if (grafo->existeCaminhoEuler())
        cout << "Existe caminho de Euler" << endl;
    else
        cout << "Não existe caminho de Euler" << endl;
}

void cicloEuleriano (Grafo *grafo)
{
    if (grafo->existeCicloEuler())
        cout << "Existe ciclo de Euler" << endl;
    else
        cout << "Não existe ciclo de Euler" << endl;
}

void direcionado (Grafo *grafo)
{
    if (grafo->direcionado())
        cout << "Grafo direcionado" << endl;
    else
        cout << "Grafo não direcionado" << endl;
}

void autoloop (Grafo *grafo)
{
    if (grafo->autoloop())
        cout << "Existe autoloop" << endl;
    else
        cout << "Não existe autoloop" << endl;
}

void completo (Grafo *grafo)
{
    if (grafo->completo())
        cout << "Grafo completo" << endl;
    else
        cout << "Grafo não completo" << endl;
}

int main (int argc, char **argv) 
{
    ifstream in ("input.txt");
    Grafo *grafo = new Grafo (in);
    grafo->imprime();  

    cout << endl; 

    cout << "Dijkstra" << endl;
    grafo->dijkstra(0, 1);
    cout << endl;
    cout<<"Algoritmo Floyd Warshall"<< endl;
    grafo->floyd_warshall(0, 1);
    /*
    Grafo *grafoND = grafo->grafoNaoDirecionado();

    cicloEuleriano(grafoND);
    cout << " Numero de componentes: "<< grafo->numComponentes() << endl;
    cout << endl;
    cout << grafo->ordTopologica() << endl;
    cout << endl;
    grafoND->dijkstra(0,2);
    cout << endl;


    
    cout << "Busca em largura" << endl;
    grafoND->buscaemlargura();

    Grafo *GrafoKruskal = grafoND->kruskal();
    cout << "Grafo Kruskal" << endl;
    GrafoKruskal->imprime();

    Grafo *GrafoPrim = grafoND->prim(0);
    cout << "Grafo Prim" << endl;
    GrafoPrim->imprime();*/

}
