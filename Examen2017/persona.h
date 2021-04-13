#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct
{
	char* nombre;
	int edad;
} Persona;

void imprimirPersona(Persona p);
char* personaString(Persona p);

#endif /* PERSONA_H_ */
