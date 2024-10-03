#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

class Analizador
{
public:
    void analizarOperacion(const string &operacion, vector<int> &numeros, vector<char> &operadores)
    {
        istringstream iss(operacion);
        string token;
        size_t pos = 0;
        while (pos < operacion.length())
        {
            while (isdigit(operacion[pos]))
            {
                token += operacion[pos++];
            }
            if (!token.empty())
            {
                numeros.push_back(stoi(token));
                token.clear();
            }
            if (pos < operacion.length() && (operacion[pos] == '+' || operacion[pos] == '-' || operacion[pos] == '*' || operacion[pos] == '/'))
            {
                operadores.push_back(operacion[pos++]);
            }
        }
    }
};
class Operaciones
{
public:
    int realizarOperacion(int a, int b, char op)
    {
        switch (op)
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return (b != 0) ? a / b : 0;
        default:
            return 0;
        }
    }
};
class Calculadora
{
private:
    Analizador analizador;
    Operaciones operaciones;

public:
    void procesarOperacion(const string &operacion)
    {
        vector<int> numeros;
        vector<char> operadores;
        analizador.analizarOperacion(operacion, numeros, operadores);
        int resultado = numeros[0];
        for (size_t i = 0; i < operadores.size(); ++i)
        {
            resultado = operaciones.realizarOperacion(resultado, numeros[i + 1], operadores[i]);
        }
        cout << "El resultado de la operación '" << operacion << "' es: " << resultado << endl;
    }
};
int main()
{
    Calculadora calc;
    string operacion;

    cout << "Ingrese una operación (hasta 6 números): ";
    getline(cin, operacion);

    calc.procesarOperacion(operacion);

    return 0;
}
