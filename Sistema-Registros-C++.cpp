/*
 *  SISTEMA DE GESTIÓN DE EMPLEADOS
 */

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;



// CLASE Empleado: Contiene los datos de un empleado y sus propios metodos

class Empleado {

private:
    // Atributos privados: solo se acceden desde dentro de la clase
    int id;
    string nombre;
    string departamento;
    string cargo;
    double salario;
    int experiencia;
    string estado;

public:
    // --- Constructor ---
    // Permite crear un empleado pasando todos sus datos de una vez
    Empleado(int id, string nombre, string departamento, string cargo,
             double salario, int experiencia, string estado) {
        this->id           = id;
        this->nombre       = nombre;
        this->departamento = departamento;
        this->cargo        = cargo;
        this->salario      = salario;
        this->experiencia  = experiencia;
        this->estado       = estado;
    }

    // --- Getters ---
    // Métodos para leer los atributos desde fuera de la clase
    int    getId()           { return id; }
    string getNombre()       { return nombre; }
    string getDepartamento() { return departamento; }
    string getCargo()        { return cargo; }
    double getSalario()      { return salario; }
    int    getExperiencia()  { return experiencia; }
    string getEstado()       { return estado; }

    // --- Setters ---
    // Métodos para modificar los atributos desde fuera de la clase
    void setNombre(string n)       { nombre = n; }
    void setDepartamento(string d) { departamento = d; }
    void setCargo(string c)        { cargo = c; }
    void setSalario(double s)      { salario = s; }
    void setExperiencia(int e)     { experiencia = e; }
    void setEstado(string e)       { estado = e; }

    // --- mostrarDatos() ---
    // Imprime una fila con los datos del empleado en formato tabla
    void mostrarDatos() {
        cout << fixed << setprecision(2);
        cout << left
             << setw(5)  << id
             << setw(25) << nombre
             << setw(18) << departamento
             << setw(22) << cargo
             << "$" << setw(9) << salario
             << setw(5)  << experiencia
             << estado << endl;
    }

    // --- modificarDatos() ---
    // Pregunta qué campo cambiar y aplica el cambio
    void modificarDatos() {
        cout << "Empleado: " << nombre << endl;
        cout << "Que campo quiere modificar?" << endl;
        cout << "1. Nombre   2. Departamento   3. Cargo   4. Salario   5. Experiencia   6. Estado" << endl;
        cout << "Opcion: ";
        int campo;
        cin >> campo;
        cin.ignore();

        if (campo == 1) {
            cout << "Nuevo nombre: ";
            getline(cin, nombre);
        } else if (campo == 2) {
            cout << "Nuevo departamento: ";
            getline(cin, departamento);
        } else if (campo == 3) {
            cout << "Nuevo cargo: ";
            getline(cin, cargo);
        } else if (campo == 4) {
            cout << "Nuevo salario: ";
            cin >> salario;
            cin.ignore();
        } else if (campo == 5) {
            cout << "Nuevos anos de experiencia: ";
            cin >> experiencia;
            cin.ignore();
        } else if (campo == 6) {
            cout << "Nuevo estado (Activo/Inactivo): ";
            getline(cin, estado);
        } else {
            cout << "Campo invalido." << endl;
        }
    }
};


// CLASE GestionEmpleados: Contiene el vector de empleados y todas las operaciones

class GestionEmpleados {

private:
    // El vector que guarda todos los empleados
    vector<Empleado> lista;

    // Busca un empleado por ID y devuelve su posición en el vector
    // Devuelve -1 si no lo encuentra
    int buscarPorId(int id) {
        for (int i = 0; i < lista.size(); i++) {
            if (lista[i].getId() == id)
                return i;
        }
        return -1;
    }

    // Imprime la cabecera de la tabla
    void imprimirCabecera() {
        cout << left << setw(5) << "ID"
             << setw(25) << "Nombre"
             << setw(18) << "Departamento"
             << setw(22) << "Cargo"
             << setw(10) << "Salario"
             << setw(5)  << "Exp"
             << "Estado" << endl;
        cout << string(90, '-') << endl;
    }

public:
    // cargarDatos()
    // Agrega los 10 empleados de prueba al iniciar el programa
    void cargarDatos() {
        lista.push_back(Empleado(1,  "Ana Torres",     "Recursos Humanos", "Gerente de RRHH",    2800, 8,  "Activo"));
        lista.push_back(Empleado(2,  "Carlos Mendoza",  "Tecnologia",       "Desarrollador",      3200, 6,  "Activo"));
        lista.push_back(Empleado(3,  "Lucia Fernandez", "Contabilidad",     "Contadora",          2500, 5,  "Activo"));
        lista.push_back(Empleado(4,  "Andres Salas",    "Ventas",           "Ejecutivo de Ventas",1900, 3,  "Activo"));
        lista.push_back(Empleado(5,  "Valeria Quispe",  "Tecnologia",       "Analista",           2600, 4,  "Activo"));
        lista.push_back(Empleado(6,  "Diego Paredes",   "Logistica",        "Coordinador",        2100, 7,  "Activo"));
        lista.push_back(Empleado(7,  "Sofia Herrera",   "Marketing",        "Disenadora",         1800, 2,  "Activo"));
        lista.push_back(Empleado(8,  "Mateo Villacis",  "Gerencia",         "Director General",   5000, 15, "Activo"));
        lista.push_back(Empleado(9,  "Camila Rojas",    "Ventas",           "Supervisora",        2300, 6,  "Activo"));
        lista.push_back(Empleado(10, "Javier Molina",   "Contabilidad",     "Auxiliar Contable",  1600, 1,  "Inactivo"));
    }

    // agregarEmpleado()
    // Opción 1: pide los datos al usuario y agrega un nuevo empleado
    void agregarEmpleado() {
        // el ID se calcula automáticamente segun el mayor existente
        int maxId = 0;
        for (int i = 0; i < lista.size(); i++) {
            if (lista[i].getId() > maxId)
                maxId = lista[i].getId();
        }
        int nuevoId = maxId + 1;

        cout << "\n-- Registrar nuevo empleado (ID: " << nuevoId << ") --" << endl;

        string nombre, departamento, cargo, estado;
        double salario;
        int experiencia;

        cout << "Nombre: ";
        getline(cin, nombre);
        cout << "Departamento: ";
        getline(cin, departamento);
        cout << "Cargo: ";
        getline(cin, cargo);
        cout << "Salario: ";
        cin >> salario;
        cin.ignore();
        cout << "Anos de experiencia: ";
        cin >> experiencia;
        cin.ignore();
        estado = "Activo";

        // se crea el objeto y se agrega al vector
        lista.push_back(Empleado(nuevoId, nombre, departamento, cargo, salario, experiencia, estado));
        cout << "Empleado agregado correctamente." << endl;
    }

    // mostrarEmpleados())
    // Opción 2: muestra todos los empleados en una tabla
    void mostrarEmpleados() {
        if (lista.size() == 0) {
            cout << "No hay empleados registrados." << endl;
            return;
        }

        cout << "\n-- Lista de empleados --" << endl;
        imprimirCabecera();

        for (int i = 0; i < lista.size(); i++) {
            lista[i].mostrarDatos();
        }
    }

    // buscarEmpleado()
    // Opción 3: busca por ID, nombre o departamento
    void buscarEmpleado() {
        cout << "\nBuscar por: 1) ID   2) Nombre   3) Departamento" << endl;
        cout << "Opcion: ";
        int op;
        cin >> op;
        cin.ignore();

        bool encontrado = false;

        if (op == 1) {
            cout << "Ingrese el ID: ";
            int id;
            cin >> id;
            cin.ignore();
            int pos = buscarPorId(id);
            if (pos != -1) {
                imprimirCabecera();
                lista[pos].mostrarDatos();
                encontrado = true;
            }

        } else if (op == 2) {
            cout << "Ingrese el nombre: ";
            string nombre;
            getline(cin, nombre);
            imprimirCabecera();
            for (int i = 0; i < lista.size(); i++) {
                // busca si el nombre contiene el texto ingresado
                if (lista[i].getNombre().find(nombre) != string::npos) {
                    lista[i].mostrarDatos();
                    encontrado = true;
                }
            }

        } else if (op == 3) {
            cout << "Ingrese el departamento: ";
            string depto;
            getline(cin, depto);
            imprimirCabecera();
            for (int i = 0; i < lista.size(); i++) {
                if (lista[i].getDepartamento() == depto) {
                    lista[i].mostrarDatos();
                    encontrado = true;
                }
            }

        } else {
            cout << "Opcion invalida." << endl;
            return;
        }

        if (!encontrado)
            cout << "No se encontraron resultados." << endl;
    }

    // modificarEmpleado() 
    // Opción 4: busca por ID y llama al método modificarDatos() del empleado
    void modificarEmpleado() {
        cout << "\nIngrese el ID del empleado a modificar: ";
        int id;
        cin >> id;
        cin.ignore();

        int pos = buscarPorId(id);
        if (pos == -1) {
            cout << "Empleado no encontrado." << endl;
            return;
        }

        // se delega la modificación al propio objeto Empleado
        lista[pos].modificarDatos();
        cout << "Registro modificado." << endl;
    }

    // eliminarEmpleado()
    // Opción 5: pide confirmación y elimina el empleado del vector
    void eliminarEmpleado() {
        cout << "\nIngrese el ID del empleado a eliminar: ";
        int id;
        cin >> id;
        cin.ignore();

        int pos = buscarPorId(id);
        if (pos == -1) {
            cout << "Empleado no encontrado." << endl;
            return;
        }

        cout << "Seguro que desea eliminar a " << lista[pos].getNombre() << "? (s/n): ";
        char conf;
        cin >> conf;
        cin.ignore();

        if (conf == 's' || conf == 'S') {
            lista.erase(lista.begin() + pos);
            cout << "Empleado eliminado." << endl;
        } else {
            cout << "Operacion cancelada." << endl;
        }
    }

    // generarReporte()
    // Opción 6: muestra estadísticas generales del sistema
    void generarReporte() {
        if (lista.size() == 0) {
            cout << "No hay datos." << endl;
            return;
        }

        double total       = 0;
        double mayor       = lista[0].getSalario();
        double menor       = lista[0].getSalario();
        string nombreMayor = lista[0].getNombre();
        int activos = 0, inactivos = 0;

        for (int i = 0; i < lista.size(); i++) {
            total += lista[i].getSalario();

            if (lista[i].getSalario() > mayor) {
                mayor       = lista[i].getSalario();
                nombreMayor = lista[i].getNombre();
            }
            if (lista[i].getSalario() < menor)
                menor = lista[i].getSalario();

            if (lista[i].getEstado() == "Activo")
                activos++;
            else
                inactivos++;
        }

        cout << fixed << setprecision(2);
        cout << "\n--- REPORTE FINAL ---" << endl;
        cout << "Total empleados    : " << lista.size() << endl;
        cout << "Activos            : " << activos << endl;
        cout << "Inactivos          : " << inactivos << endl;
        cout << "Total en planilla  : $" << total << endl;
        cout << "Salario promedio   : $" << total / lista.size() << endl;
        cout << "Salario mas alto   : $" << mayor << " (" << nombreMayor << ")" << endl;
        cout << "Salario mas bajo   : $" << menor << endl;

        // contar cuántos empleados hay por departamento
        cout << "\nEmpleados por departamento:" << endl;
        vector<string> deptos;
        for (int i = 0; i < lista.size(); i++) {
            bool yaEsta = false;
            for (int j = 0; j < (int)deptos.size(); j++) {
                if (deptos[j] == lista[i].getDepartamento())
                    yaEsta = true;
            }
            if (!yaEsta)
                deptos.push_back(lista[i].getDepartamento());
        }
        for (int i = 0; i < (int)deptos.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < (int)lista.size(); j++) {
                if (lista[j].getDepartamento() == deptos[i])
                    cnt++;
            }
            cout << "  " << left << setw(20) << deptos[i] << ": " << cnt << endl;
        }
    }

    // mostrarMenu()
    // Imprime las opciones del menú principal
    void mostrarMenu() {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Registrar empleado" << endl;
        cout << "2. Mostrar empleados" << endl;
        cout << "3. Buscar empleado" << endl;
        cout << "4. Modificar empleado" << endl;
        cout << "5. Eliminar empleado" << endl;
        cout << "6. Reporte final" << endl;
        cout << "7. Salir" << endl;
    }
};


// FUNCIÓN PRINCIPAL: Solo crea el objeto GestionEmpleados y maneja el menú

int main() {
    GestionEmpleados sistema;
    sistema.cargarDatos(); // carga los 10 empleados de prueba

    int op;
    cout << "Bienvenido al sistema de empleados" << endl;

    do {
        sistema.mostrarMenu();
        cout << "Ingrese una opcion: ";
        cin >> op;
        cin.ignore();

        if      (op == 1) sistema.agregarEmpleado();
        else if (op == 2) sistema.mostrarEmpleados();
        else if (op == 3) sistema.buscarEmpleado();
        else if (op == 4) sistema.modificarEmpleado();
        else if (op == 5) sistema.eliminarEmpleado();
        else if (op == 6) sistema.generarReporte();
        else if (op == 7) cout << "Saliendo..." << endl;
        else              cout << "Opcion no valida" << endl;

    } while (op != 7);

    return 0;
}
