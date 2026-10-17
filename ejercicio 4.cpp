/*
 * Nombre del proyecto: Punto de venta «Cafetería PSM»
 * Modelo: C
 * Integrantes: Rafael Cabello - Sebastian Hernandez
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// Prototipos de funciones
void mostrarCatalogo();
double precioProducto(int codigo);
int leerEnteroEnRango(int min, int max);
double leerRealPositivo();
double calcularDescuento(double subtotal);
double calcularIVA(double base);
double aBolivares(double dolares, double tasa);
double calcularVuelto(double total, double recibido);

int main() {
    // Configuración de formato para mostrar siempre 2 decimales
    cout << fixed << setprecision(2);

    // Variable para la tasa del día
    double tasaDia = 0.0;
    
    // Estadísticas para el cierre de caja (sin variables globales)
    int totalVentas = 0;
    int unidadesCafe = 0;
    int unidadesEmpanada = 0;
    int unidadesJugo = 0;
    int unidadesPastelito = 0;
    int unidadesCombo = 0;
    double totalVendidoUSD = 0.0;
    double totalVendidoBs = 0.0;
    double ventaMasAlta = 0.0;
    double totalEfectivoUSD = 0.0;

    cout << "=== BIENVENIDO AL SISTEMA DE PUNTO DE VENTA «CAFETERÍA PSM» ===\n";
    cout << "Por favor, ingrese la tasa del dia (Bolivares por Dolar):\n> ";
    tasaDia = leerRealPositivo();

    int opcionMenu = 0;
    do {
        cout << "\n=========================================\n";
        cout << "           MENU PRINCIPAL               \n";
        cout << "=========================================\n";
        cout << "1. Registrar nueva venta\n";
        cout << "2. Cambiar la tasa del dia (Actual: " << tasaDia << " Bs/$)\n";
        cout << "3. Ver cierre de caja\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion (1-4): ";
        opcionMenu = leerEnteroEnRango(1, 4);

        switch (opcionMenu) {
            case 1: {
                cout << "\n--- NUEVA VENTA ---\n";
                mostrarCatalogo();
                
                double subtotalVenta = 0.0;
                int prodCafe = 0;
                int prodEmpanada = 0;
                int prodJugo = 0;
                int prodPastelito = 0;
                int prodCombo = 0;
                int productosAgregados = 0;

                while (true) {
                    cout << "\nIngrese codigo del producto (1-5) o 0 para terminar la venta: ";
                    int codigo = leerEnteroEnRango(0, 5);

                    if (codigo == 0) {
                        if (productosAgregados == 0) {
                            cout << "Error: No se puede cerrar una venta sin productos. Agregue al menos uno.\n";
                            continue;
                        } else {
                            break;
                        }
                    }

                    cout << "Ingrese cantidad (1-50): ";
                    int cantidad = leerEnteroEnRango(1, 50);

                    double precioU = precioProducto(codigo);
                    double subtotalItem = precioU * cantidad;
                    subtotalVenta += subtotalItem;
                    productosAgregados += cantidad;

                    // Acumular unidades temporales para esta venta
                    if (codigo == 1) prodCafe += cantidad;
                    else if (codigo == 2) prodEmpanada += cantidad;
                    else if (codigo == 3) prodJugo += cantidad;
                    else if (codigo == 4) prodPastelito += cantidad;
                    else if (codigo == 5) prodCombo += cantidad;

                    cout << "-> Subtotal parcial de la venta: $" << subtotalVenta << "\n";
                }

                // Cálculos de descuento, IVA y totales
                double descuento = calcularDescuento(subtotalVenta);
                double baseImponible = subtotalVenta - descuento;
                double iva = calcularIVA(baseImponible);
                double totalUSD = baseImponible + iva;
                double totalBs = aBolivares(totalUSD, tasaDia);

                cout << "\n-----------------------------------------\n";
                cout << "RESUMEN DE LA VENTA:\n";
                cout << "Subtotal bruto: $" << subtotalVenta << "\n";
                if (descuento > 0) {
                    cout << "Descuento del 10%: -$" << descuento << "\n";
                }
                cout << "Base imponible: $" << baseImponible << "\n";
                cout << "IVA (16%): $" << iva << "\n";
                cout << "TOTAL A PAGAR ($): $" << totalUSD << "\n";
                cout << "TOTAL A PAGAR (Bs): Bs. " << totalBs << " (Tasa: " << tasaDia << ")\n";
                cout << "-----------------------------------------\n";

                cout << "Seleccione forma de pago:\n";
                cout << "1. Efectivo en dolares ($)\n";
                cout << "2. Pago movil en bolivares (Bs)\n";
                cout << "Seleccione opcion (1-2): ";
                int formaPago = leerEnteroEnRango(1, 2);

                if (formaPago == 1) {
                    double recibido = 0.0;
                    while (true) {
                        cout << "Ingrese monto recibido en dolares ($): ";
                        recibido = leerRealPositivo();
                        if (recibido >= totalUSD) {
                            break;
                        }
                        cout << "Error: El monto recibido no puede ser menor que el total a pagar ($" << totalUSD << ").\n";
                    }
                    double vueltoUSD = calcularVuelto(totalUSD, recibido);
                    double vueltoBs = aBolivares(vueltoUSD, tasaDia);
                    cout << "Vuelto a entregar: $" << vueltoUSD << " (Bs. " << vueltoBs << ")\n";
                    
                    totalEfectivoUSD += totalUSD;
                } else {
                    cout << "Pago movil procesado exitosamente por Bs. " << totalBs << "\n";
                }

                // Actualizar estadísticas del cierre de caja del turno
                totalVentas++;
                unidadesCafe += prodCafe;
                unidadesEmpanada += prodEmpanada;
                unidadesJugo += prodJugo;
                unidadesPastelito += prodPastelito;
                unidadesCombo += prodCombo;
                totalVendidoUSD += totalUSD;
                totalVendidoBs += totalBs;

                if (totalUSD > ventaMasAlta) {
                    ventaMasAlta = totalUSD;
                }

                cout << "\n¡Venta registrada con exito!\n";
                break;
            }
            case 2: {
                cout << "\n--- CAMBIAR TASA DEL DÍA ---\n";
                cout << "Tasa actual: " << tasaDia << " Bs/$\n";
                cout << "Ingrese la nueva tasa del día: ";
                tasaDia = leerRealPositivo();
                cout << "¡Tasa actualizada con éxito!\n";
                break;
            }
            case 3: {
                cout << "\n=========================================\n";
                cout << "           CIERRE DE CAJA PARCIAL        \n";
                cout << "=========================================\n";
                cout << "Número total de ventas: " << totalVentas << "\n";
                cout << "Unidades vendidas por producto:\n";
                cout << " - Café: " << unidadesCafe << "\n";
                cout << " - Empanada: " << unidadesEmpanada << "\n";
                cout << " - Jugo natural: " << unidadesJugo << "\n";
                cout << " - Pastelito: " << unidadesPastelito << "\n";
                cout << " - Combo empanada y jugo: " << unidadesCombo << "\n";
                cout << "Total vendido en USD: $" << totalVendidoUSD << "\n";
                cout << "Total vendido en Bs: Bs. " << totalVendidoBs << "\n";
                cout << "Venta más alta: $" << ventaMasAlta << "\n";
                cout << "Total cobrado en efectivo ($): $" << totalEfectivoUSD << "\n";
                cout << "=========================================\n";
                break;
            }
            case 4: {
                cout << "\n=========================================\n";
                cout << "           CIERRE DE CAJA FINAL          \n";
                cout << "=========================================\n";
                cout << "Número total de ventas: " << totalVentas << "\n";
                cout << "Unidades vendidas por producto:\n";
                cout << " - Café: " << unidadesCafe << "\n";
                cout << " - Empanada: " << unidadesEmpanada << "\n";
                cout << " - Jugo natural: " << unidadesJugo << "\n";
                cout << " - Pastelito: " << unidadesPastelito << "\n";
                cout << " - Combo empanada y jugo: " << unidadesCombo << "\n";
                cout << "Total vendido en USD: $" << totalVendidoUSD << "\n";
                cout << "Total vendido en Bs: Bs. " << totalVendidoBs << "\n";
                cout << "Venta más alta: $" << ventaMasAlta << "\n";
                cout << "Total cobrado en efectivo ($): $" << totalEfectivoUSD << "\n";
                cout << "=========================================\n";
                cout << "Saliendo del sistema. ¡Buen trabajo!\n";
                break;
            }
        }
    } while (opcionMenu != 4);

    return 0;
}

/**
 * Función: mostrarCatalogo
 * Descripción: Imprime en pantalla la lista de productos disponibles con su código y precio en dólares.
 * Parámetros: Ninguno
 * Retorno: void
 */
void mostrarCatalogo() {
    cout << "\n--- CATALOGO DE PRODUCTOS ---\n";
    cout << "1. Cafe .................... $1.50\n";
    cout << "2. Empanada ................ $2.00\n";
    cout << "3. Jugo natural ............ $2.50\n";
    cout << "4. Pastelito ............... $1.00\n";
    cout << "5. Combo empanada y jugo ... $4.00\n";
}

/**
 * Función: precioProducto
 * Descripción: Retorna el precio unitario en dólares de un producto según su código utilizando un switch.
 * Parámetros: int codigo (código del producto entre 1 y 5)
 * Retorno: double (precio del producto)
 */
double precioProducto(int codigo) {
    double precio = 0.0;
    switch (codigo) {
        case 1:
            precio = 1.50;
            break;
        case 2:
            precio = 2.00;
            break;
        case 3:
            precio = 2.50;
            break;
        case 4:
            precio = 1.00;
            break;
        case 5:
            precio = 4.00;
            break;
        default:
            precio = 0.0;
            break;
    }
    return precio;
}

/**
 * Función: leerEnteroEnRango
 * Descripción: Lee un valor entero desde la consola asegurándose de que sea numérico y que se encuentre dentro de un rango específico.
 * Parámetros: int min (límite inferior), int max (límite superior)
 * Retorno: int (el número entero validado)
 */
int leerEnteroEnRango(int min, int max) {
    int valor;
    while (true) {
        if (cin >> valor) {
            if (valor >= min && valor <= max) {
                return valor;
            } else {
                cout << "Error: El valor debe estar entre " << min << " y " << max << ". Intente de nuevo: ";
            }
        } else {
            cout << "Error: Entrada inválida (se esperaba un número entero). Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/**
 * Función: leerRealPositivo
 * Descripción: Lee un número real (double) desde la consola, validando que sea numérico y estrictamente mayor que cero.
 * Parámetros: Ninguno
 * Retorno: double (el número real positivo validado)
 */
double leerRealPositivo() {
    double valor;
    while (true) {
        if (cin >> valor) {
            if (valor > 0) {
                return valor;
            } else {
                cout << "Error: El valor debe ser mayor que 0. Intente de nuevo: ";
            }
        } else {
            cout << "Error: Entrada inválida (se esperaba un número real). Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

/**
 * Función: calcularDescuento
 * Descripción: Calcula el descuento del 10% si el subtotal es mayor o igual a $20.00; de lo contrario, retorna 0.
 * Parámetros: double subtotal (subtotal de la venta en dólares)
 * Retorno: double (monto del descuento)
 */
double calcularDescuento(double subtotal) {
    if (subtotal >= 20.00) {
        return subtotal * 0.10;
    }
    return 0.0;
}

/**
 * Función: calcularIVA
 * Descripción: Calcula el 16% de IVA sobre la base imponible.
 * Parámetros: double base (monto base imponible)
 * Retorno: double (monto correspondiente al IVA)
 */
double calcularIVA(double base) {
    return base * 0.16;
}

/**
 * Función: aBolivares
 * Descripción: Convierte un monto en dólares a bolívares multiplicándolo por la tasa del día.
 * Parámetros: double dolares (monto en USD), double tasa (tasa de cambio Bs/$ )
 * Retorno: double (monto convertido en bolívares)
 */
double aBolivares(double dolares, double tasa) {
    return dolares * tasa;
}

/**
 * Función: calcularVuelto
 * Descripción: Calcula el monto de cambio o vuelto a entregar al cliente.
 * Parámetros: double total (monto total a pagar), double recibido (monto entregado por el cliente)
 * Retorno: double (vuelto en dólares)
 */
double calcularVuelto(double total, double recibido) {
    return recibido - total;
}
