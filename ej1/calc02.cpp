#include <iostream>
#include <sstream>
#include <vector>
#include <memory> // Para manejar punteros inteligentes
using namespace std;

class OperacionBase
{
public:
    virtual int realizar(int a, int b) = 0; // Método virtual puro
    virtual int precedencia() const = 0;    // Precedencia de la operación
};

class Suma : public OperacionBase
{
public:
    int realizar(int a, int b) override
    {
        return a + b;
    }
    int precedencia() const override
    {
        return 1; // Precedencia baja
    }
};

class Resta : public OperacionBase
{
public:
    int realizar(int a, int b) override
    {
        return a - b;
    }
    int precedencia() const override
    {
        return 1; // Precedencia baja
    }
};

class Multiplicacion : public OperacionBase
{
public:
    int realizar(int a, int b) override
    {
        return a * b;
    }
    int precedencia() const override
    {
        return 2; // Precedencia alta
    }
};

class Division : public OperacionBase
{
public:
    int realizar(int a, int b) override
    {
        return (b != 0) ? a / b : 0;
    }
    int precedencia() const override
    {
        return 2; // Precedencia alta
    }
};

class Analizador
{
public:
    bool analizarOperacion(const string &operacion, vector<int> &numeros, vector<shared_ptr<OperacionBase>> &operaciones)
    {
        istringstream iss(operacion);
        string token;
        size_t pos = 0;

        while (pos < operacion.length())
        {
            // Leer números
            while (isdigit(operacion[pos]))
            {
                token += operacion[pos++];
            }
            if (!token.empty())
            {
                if (numeros.size() >= 6)
                { // Verificar si ya se alcanzaron los 6 números
                    cout << "Error: No se permiten más de 6 números en la operación." << endl;
                    return false; // Indicar que hubo un error
                }
                numeros.push_back(stoi(token)); // Convierte y guarda el número
                token.clear();
            }
            // Leer operadores y crear objetos de operaciones correspondientes
            if (pos < operacion.length())
            {
                switch (operacion[pos])
                {
                case '+':
                    operaciones.push_back(make_shared<Suma>());
                    break;
                case '-':
                    operaciones.push_back(make_shared<Resta>());
                    break;
                case '*':
                    operaciones.push_back(make_shared<Multiplicacion>());
                    break;
                case '/':
                    operaciones.push_back(make_shared<Division>());
                    break;
                default:
                    break;
                }
                pos++;
            }
        }
        return true; // Indicar que todo salió bien
    }
};

class Calculadora
{
private:
    Analizador analizador;

public:
    void procesarOperacion(const string &operacion)
    {
        vector<int> numeros;
        vector<shared_ptr<OperacionBase>> operaciones;

        // Si analizarOperacion devuelve false, se detiene el procesamiento
        if (!analizador.analizarOperacion(operacion, numeros, operaciones))
        {
            return; // Salir si se excedió el límite de números
        }

        // Primero resolver multiplicaciones y divisiones
        for (size_t i = 0; i < operaciones.size(); ++i)
        {
            if (operaciones[i]->precedencia() == 2)
            { // Precedencia alta: *, /
                numeros[i] = operaciones[i]->realizar(numeros[i], numeros[i + 1]);
                numeros.erase(numeros.begin() + i + 1);     // Eliminar el segundo número
                operaciones.erase(operaciones.begin() + i); // Eliminar la operación realizada
                --i;                                        // Retroceder el índice para evitar saltar una operación
            }
        }

        // Luego resolver sumas y restas
        int resultado = numeros[0];
        for (size_t i = 0; i < operaciones.size(); ++i)
        {
            resultado = operaciones[i]->realizar(resultado, numeros[i + 1]);
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
