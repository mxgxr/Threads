#include <iostream>
#include <fstream>
#include <thread>
#include <list>
#include <iterator>
#include <vector>

using namespace std;

void factorial(int numero);

int main()
{
    int num=0;
    vector<int>numeros;
    list<thread>hilos;
    cout << "Ingrese el numero a calcular su factorial" << endl;
    cout << "Ingrese -1 para finalizar" << endl;

    while(true){
        cin>>num;
        if(num!=-1 and num>=0){
            numeros.push_back(num);
            //hilos.push_back(thread (factorial,(num)));
        }
        else{
            break;
        }
    }

    vector<int>::iterator it;

    for(it=numeros.begin(); it!=numeros.end(); it++){
        hilos.push_back(thread (factorial,(*it)));
    }

    list<thread>::iterator iter;
    for(iter=hilos.begin(); iter!=hilos.end(); iter++){
        (*iter).join();
    }

    return 0;
}

void factorial(int numero){
    double fact=1;
    for(int i=numero; i>0; i--){
        fact=fact*numero;
    }
    cout << "El factorial de " << numero << " es: " << fact << endl;
}
