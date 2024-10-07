#include <iostream>
#include <ctype.h>
#include <cstring>

using namespace std;

void menu_inicio(int&);
void validar_numero(string&, bool&);
double sumar(string&, bool&, char&);
char regresar_menu();

int main()
{
    //Muestra los acentos en español
    setlocale(LC_ALL, "Spanish");

    int opc_menu{0};
    double resultado;//Resultado
    string numero{""};//Numero para validar que no sea letra
    bool sin_letras{true};
    char opc_sn;

    do
    {
        menu_inicio(opc_menu);//LLamamos a mostrar el menu de inicio

        switch(opc_menu)
        {
        case 1: //Sumar
            resultado = 0.0;
            resultado = sumar(numero, sin_letras, opc_sn);
            cout << "El resultado de la suma es: " << resultado << endl;
            system("PAUSE");//Se pause el programa para leer el mensaje
            system("CLS");//Borra pantalla
            break;
        case 2: //Restar
            break;
        case 3: //Multiplicacion
            break;
        case 4: //Division
            break;
        case 5: //Salir del programa
            break;
        default: //Dato fuera de rango
            cout << "Opción fuera de rango, intente de nuevo" << endl;
            system("PAUSE");//Se pause el programa para leer el mensaje
            system("CLS");//Borra pantalla
            break;
        }
    }//fin del do/while
    while(opc_menu != 5);

    return 0;
}

void menu_inicio(int& opc_menu_char)
{
    cout << "Calculadora Básica" << endl;

    cout << "\nMenú de inicio" << endl;

    cout << "\n1. Suma" << endl;
    cout << "2. Resta" << endl;
    cout << "3. Multiplicación" << endl;
    cout << "4. División" << endl;
    cout << "5. Salir del programa" << endl;

    cout << "\nR/: ";
    cin >> opc_menu_char;//Se recibe la opcion del menu
    cin.clear();//Borra el bufer
    cin.ignore();//ignora algun espacio inecesario

    system("CLS");
}

void validar_numero(string& numero_str, bool& sin_letras_bool)
{
    //Validad cada caracter dentro del numero brindado
    for(char c : numero_str)
    {
        //Si c contiene una letra ingresa en el if
        if(!isdigit(c))
        {
            //Si c lleva una letra, sin_letra es falso
            sin_letras_bool = false;
        }//Fin del if
        //Si c es numero ingresa en este else if
        else if(isdigit(c))
        {
            //Si c es un digito, sin letras es true
            sin_letras_bool = true;
        }//Fin del else if
    }//Fin del for
}

double sumar(string& numero_str, bool& sin_letras_bool, char& opc_sn_char)
{
    double resultado{0.0};
    int mostrar_salida{0};
    int num;//numero

    do
    {
        if(mostrar_salida >= 2)
        {
            cout << "Si desea regresar al menú principal digite una letra" << endl;
            system("PAUSE");//Se pause el programa para leer el mensaje
            system("CLS");//Borra pantalla
        }

        cout << "Digite el número " << mostrar_salida + 1 << " a sumar" << endl;
        cin >> numero_str;
        cin.clear();//Borra el bufer
        cin.ignore();//ignora algun espacio inecesario
        system("CLS");//Borra pantalla

        mostrar_salida++;

        validar_numero(numero_str, sin_letras_bool);

        if(sin_letras_bool == false && mostrar_salida >= 2)
        {
            opc_sn_char = regresar_menu();

            sin_letras_bool = true;
            mostrar_salida --;

            //Restablecemos el valor de numero int en 0
            numero_str = "0";
        }
        else if(sin_letras_bool == false)
        {
            cout << "Ingrese solo números, intente de nuevo";
            system("PAUSE");//Se pause el programa para leer el mensaje
            system("CLS");//Borra pantalla

            //Restablecemos el valor de numero int en 0
            numero_str = "0";
        }//Fin del if
        //Sumamos el numero ingresado en caso de ser un numero y no una letra
        //num = std::stoi(numero_str)
        resultado = resultado + stoi(numero_str);
    }
    while(sin_letras_bool == false || opc_sn_char != 'S');
    return resultado;
}

char regresar_menu()
{
    char opc_sino;
    do
    {
        cout << "¿Desea regresar al menú principal? (S/N)" << endl;
        cout << "R/: ";
        cin >> opc_sino;//Se toma la desicion del usuario de regresar o no al menu principal.
        cin.clear();//Borra el bufer
        cin.ignore();//ignora algun espacio inecesario

        system("CLS");//Borra pantalla

        opc_sino = toupper(opc_sino);

        //Si es un digito o alguna respuesta diferente a N o S entra
        if(isdigit(opc_sino) == true || (opc_sino != 'N' && opc_sino != 'S'))
        {
            cout << "Valor incorrecto, intente de nuevo";
            system("PAUSE");//Se pause el programa para leer el mensaje
            system("CLS");//Borra pantalla
        }
    }
    while(isdigit(opc_sino) == true || (opc_sino != 'N' && opc_sino != 'S'));

    return opc_sino;
}
