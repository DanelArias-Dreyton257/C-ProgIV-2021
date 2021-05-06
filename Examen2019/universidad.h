#ifndef UNIVERSIDAD_H_
#define UNIVERSIDAD_H_

typedef struct {
	char dni[10];
	char *nombre;
} Alumno;

typedef struct {
	float nota;
	char dni[10];
} Nota;

typedef struct {
	int numPlazas;
	int numAlumnos;
	char *nombre;
	Alumno *alumnos;
	Nota *notas;
} Asignatura;

void imprimirAlumno(Alumno);

void setNumeroPlazas(Asignatura *asig, int numAlumn);

void matricularAlumno(Asignatura *asig, Alumno *al);

void imprimirMatriculados(Asignatura asig);

Alumno* buscarAlumnoPorDNI(Asignatura *asig, char *dni);

void anyadirNota(Asignatura *asig, char *dni, float valor);

void imprimirNotas(Asignatura asig);

float calcularNotaMedia(Asignatura asig);

void liberarAsignatura(Asignatura *asig);

void pedirNotasPorTeclado(Asignatura *asig);

#endif /* UNIVERSIDAD_H_ */
