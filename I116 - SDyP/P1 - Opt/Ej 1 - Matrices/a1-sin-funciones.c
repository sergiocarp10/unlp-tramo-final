#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> // Esto ya muestra que debe correrse en Linux

#define ORDENXFILAS 0
#define ORDENXCOLUMNAS 1

// Dimension por defecto de las matrices
int N = 100;

// Retorna el valor de la matriz en la posicion fila y columna segun el orden que este ordenada
double getValor(double *matriz, int fila, int columna, int orden)
{
  if (orden == ORDENXFILAS) return (matriz[fila * N + columna]);
  else return (matriz[fila + columna * N]);
}

// Establece el valor de la matriz en la posicion fila y columna segun el orden que este ordenada
void setValor(double *matriz, int fila, int columna, int orden, double valor)
{
  if (orden == ORDENXFILAS) matriz[fila * N + columna] = valor;
  else matriz[fila + columna * N] = valor;
}

// Para calcular tiempo
double dwalltime()
{
  double sec;
  struct timeval tv;

  gettimeofday(&tv, NULL);
  sec = tv.tv_sec + tv.tv_usec / 1000000.0;
  return sec;
}

int main(int argc, char *argv[])
{
  double *A, *B, *C;
  int i, j, k;
  int check = 1;
  double timetick;

  // Controla los argumentos al programa
  if ((argc != 2) || ((N = atoi(argv[1])) <= 0))
  {
    printf("\nUsar: %s n\n  n: Dimension de la matriz (nxn X nxn)\n", argv[0]);
    exit(1);
  }

  // Aloca memoria para las matrices
  A = (double *)malloc(sizeof(double) * N * N);
  B = (double *)malloc(sizeof(double) * N * N);
  C = (double *)malloc(sizeof(double) * N * N);

  // Inicializa las matrices A y B en 1, el resultado sera una matriz con todos sus valores en N
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      setValor(A, i, j, ORDENXFILAS, 1);
      setValor(B, i, j, ORDENXFILAS, 1);
    }
  }

  // =========================== LA PARTE QUE NOS INTERESA ============================= //

  // Realiza la multiplicacion

  timetick = dwalltime();

  // Funciones reemplazadas:
  // setValor(double *matriz, int fila, int columna, int orden, double valor)
    // ORDEN POR FILAS: matriz[fila * N + columna] = valor;
  // getValor(double *matriz, int fila, int columna, int orden)
    // ORDEN POR FILAS: return (matriz[fila * N + columna])

  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      // Inicializa la posición C[i,j] en cero (posteriormente se sumará a partir de este valor)
      // setValor(C, i, j, ORDENXFILAS, 0);
      C[i*N+j] = 0;
      
      for (k = 0; k < N; k++) {
        // Realiza C[i,j] += A[i,k] * B[k,j]
        // setValor(C, i, j, ORDENXFILAS, getValor(C, i, j, ORDENXFILAS) + getValor(A, i, k, ORDENXFILAS) * getValor(B, k, j, ORDENXFILAS));
        C[i*N+j] = C[i*N+j] + A[i*N+k] * B[k*N+j];
      }
    }
  }

  printf("Tiempo en segundos %f\n", dwalltime() - timetick);

  // ============================== FIN DE PARTE DE INTERÉS =============================== //

  // Verifica el resultado
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < N; j++)
    {
      check = check && (getValor(C, i, j, ORDENXFILAS) == N);
    }
  }

  if (check)
  {
    printf("Multiplicacion de matrices resultado correcto\n");
  }
  else
  {
    printf("Multiplicacion de matrices resultado erroneo\n");
  }

  free(A);
  free(B);
  free(C);
  return (0);
}