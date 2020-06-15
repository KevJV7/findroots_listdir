// LIST DIR
#include <iostream>
#include <fstream>
#include <sstream>
#include <dirent.h> //DIR para manejo de directorios a través de la funcion list_dir

using namespace std;

void list_dir(string dir)//dir es el argumento donde se incluyen las rutas del directorio
{
    DIR* directorio;//puntero directorio que Apunta a un objeto DIR para manejar directorios
    struct dirent* elemento; //Estructura de datos dirent nos permite acceder a la informacion de elementos
    string elem;
    string todo;


    if (directorio = opendir(dir.c_str()))//si podemos abrir el directorio
    {
        ofstream fp("archivo.json");
        fp << "{ \"files\": [\n";

        while (elemento = readdir(directorio))//con readdir podemos leer uno a uno los elementos del directorio que tenemos abierto
        {

            elem = elemento->d_name;//asignamos el nombre accediendo al objeto elemento de la estructura de datos dirent y al miembreo de d_name 
            todo = dir + "\\" + elem;
            ifstream ifs(todo);

            ifs.seekg(0, ios::end); //recorre la posicion del stream al final
            int x;
            x = ifs.tellg();//se usa para saber la posicion del stream

            stringstream ss;//convertir int a string
            ss << x << endl;
            string newString = ss.str();


            if (elem != "." && elem != "..") fp << "\t{\"name\":\"" << elem << "\", \"size\":" << newString << "}, \n";



        }
        fp << "]}\n";
    }
    closedir(directorio);
}

void init()
{
    string dir;
    cout << "Ruta del directorio a listar: "; cin >> dir;//introducir ruta y la guardamos en dir # tambien podriamos asignar su valor a través de una entrada de datos getine(cin,dir);

    list_dir(dir);



}

int main()
{
    // ofstream fp("hola.json");


    init();



    return 0;
}