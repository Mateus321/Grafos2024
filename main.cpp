#include "listaadj/Grafo.h" 
#include <fstream>
using namespace std;

int main (int argc, char **argv) 
{
    ifstream in ("input.txt");
    Grafo *grafo = new Grafo (in);
    grafo->imprime ();  

    cout << endl; 

    //Ex1: criar e imprimir grafo transposto.

    //Grafo *grafoT = grafo->grafoTransposto();
    //grafoT->imprime();

    //Ex2: Criar e imprimir um grafo não orientado.


    //Grafo *grafoND = grafo->grafoNaoDirecionado();
    //grafoND->imprime();
    
    //Ex3: Ler e inserir nova aresta, verificando se ela já existe.
    int i, j;  
    /*cin >> i >> j;
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
    }*/
    
    cout << endl;
    //grafo->imprime();
   
    //Ex4: Ler e remover uma aresta, verificando se ela já existe.
    
    /*cin >> i >> j;
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
    cout << endl;*/
    

    //Ex5: Imprimir uma lista adjacente de um determinado vértices.

    /*vector<int> lista = grafo->listaAdj(0);

    for (int i=0; i < lista.size(); i++)
        cout << lista.at(i) << " ";
    
    cout << endl;*/

    //Verificando se existe caminho de euler
    /*if (grafo->existeCaminhoEuler())
        cout << "Existe caminho de Euler" << endl;
    
    else
        cout << "Não existe caminho de Euler" << endl;
    
    
    //Verificando se existe ciclo euleriano
    if (grafo->existeCicloEuler())
        cout << "Existe ciclo de Euler" << endl;
    
    else
        cout << "Não existe ciclo de Euler" << endl;

*/
    //Verificar se é direcionado
/*
    if (grafo->direcionado())
        cout << "Grafo direcionado" << endl;
    
    else
        cout << "Grafo não direcionado" << endl;
*/
    //Verificar se existe autoloop
/*
    if (grafo->autoloop())
        cout << "Existe autoloop" << endl;
    
    else
        cout << "Não existe autoloop" << endl;
*/
    //Verificar se é completo

    if (grafo->completo())
        cout << "Grafo completo" << endl;
    
    else
        cout << "Grafo não completo" << endl;

    

}
