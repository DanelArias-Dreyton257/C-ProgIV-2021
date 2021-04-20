/*
 * main.c
 *
 *  Created on: 19 abr. 2021
 *      Author: danel
 */
#include <stdio.h>
#include "sqlite3.h"
#include <string.h>
#define DB_FILENAME "futbol.sqlite"

int insertEquipos(sqlite3 *db);
int insertCampeonatos(sqlite3 *db);
int insertCampeon(sqlite3 *db, char *nomCampeonato, char *nomEquipo);
int showCampeonatos(sqlite3 *db, char *nomEquipo);

sqlite3 *db;

int main(int argc, char **argv) {

	//Abrir la base de datos
	int res = sqlite3_open(DB_FILENAME, &db);
	if (res != SQLITE_OK) {
		//Error al establecer la conexion
		printf("Error opening database\n");
		return res;
	}

	printf("Database opened");

//	insertar datos

//	res = insertEquipos(db);
//	if (res != SQLITE_OK) {
//		printf("Error inserting equipos\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return res;
//	}
//
//	res = insertCampeonatos(db);
//	if (res != SQLITE_OK) {
//		printf("Error inserting campeonatos\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return res;
//	}

//	res = insertCampeon(db, "Copa 2020-21", "F.C. Barcelona");
//	if (res != SQLITE_OK) {
//		printf("Error inserting campeonatos\n");
//		printf("%s\n", sqlite3_errmsg(db));
//		return res;
//	}

	res = showCampeonatos(db, "F.C. Barcelona");
	if (res != SQLITE_OK) {
		printf("Error inserting campeonatos\n");
		printf("%s\n", sqlite3_errmsg(db));
		return res;
	}

}

int showCampeonatos(sqlite3 *db, char *nomEquipo) {//FIXME

	sqlite3_stmt *stmt;

	char *sql = "SELECT ID,NOMBRE FROM CAMPEONATOS WHERE CAMPEON IN (SELECT ID FROM EQUIPOS WHERE NOMBRE = ?)";

	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("SQL query prepared (SELECT)\n");

	result = sqlite3_bind_text(stmt, 1, nomEquipo, strlen(nomEquipo),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	printf("SQL query prepared (SELECT)\n");

	int id;
	char name[100];

	printf("\n");
	printf("Mostrando los campeonatos de %s:\n", nomEquipo);
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			id = sqlite3_column_int(stmt, 0);
			strcpy(name, (char*) sqlite3_column_text(stmt, 1));
			printf("ID: %d Nombre: %s\n", id, name);
		}
	} while (result == SQLITE_ROW);

	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	return SQLITE_OK;

}

/**
 * El campeonato no existe en la BD y el equipo ya existe en la DB
 */
int insertCampeon(sqlite3 *db, char *nomCampeonato, char *nomEquipo) {
	sqlite3_stmt *stmt1;

	char *sql1 = "SELECT ID FROM EQUIPOS WHERE NOMBRE=?";

	int result = sqlite3_prepare_v2(db, sql1, strlen(sql1) + 1, &stmt1, NULL);
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	printf("SQL query prepared (SELECT)\n");

	result = sqlite3_bind_text(stmt1, 1, nomEquipo, strlen(nomEquipo),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int id;

	result = sqlite3_step(stmt1);
	if (result == SQLITE_ROW) {
		id = sqlite3_column_int(stmt1, 0);
	}

	result = sqlite3_finalize(stmt1);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (SELECT)\n");

	sqlite3_stmt *stmt2;

	char *sql2 = "INSERT INTO CAMPEONATOS(ID, NOMBRE, CAMPEON) VALUES(NULL,?,?)";
	result = sqlite3_prepare_v2(db, sql2, strlen(sql2) + 1, &stmt2, NULL);

	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	printf("SQL query prepared (INSERT)\n");

	result = sqlite3_bind_text(stmt2, 1, nomCampeonato, strlen(nomCampeonato),
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	char idc = id + '0';
	result = sqlite3_bind_text(stmt2, 2, &idc, 1,
	SQLITE_STATIC);
	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt2);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data into country table\n");
		return result;
	}

	result = sqlite3_finalize(stmt2);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	printf("Prepared statement finalized (INSERT)\n");

	return SQLITE_OK;

}

int insertEquipos(sqlite3 *db) {

	char *nombresEquipos[] = { "Athletic Club", "Real Sociedad",
			"F.C. Barcelona", "Real Madrid F.C.", "Valencia F.C." };

	for (int i = 0; i < 5; i++) {

		sqlite3_stmt *stmt;

		char *sql = "INSERT INTO EQUIPOS(ID, NOMBRE) VALUES(NULL,?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_text(stmt, 1, nombresEquipos[i],
				strlen(nombresEquipos[i]), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");
	}

	return SQLITE_OK;

}

int insertCampeonatos(sqlite3 *db) {
	char *nombresLigas[] = { "Liga 2017-18", "Liga 2018-19", "Liga 2019-20",
			"Copa 2017-18", "Copa 2018-19", "Copa 2019-20" };
	char campeonesLigas[] = { '3', '3', '4', '3', '5', '2' };

	int result = 0;

	for (int i = 0; i < 6; i++) {

		sqlite3_stmt *stmt;

		char *sql =
				"INSERT INTO CAMPEONATOS(ID, NOMBRE, CAMPEON) VALUES(NULL,?,?)";
		result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
		printf("SQL query prepared (INSERT)\n");

		result = sqlite3_bind_text(stmt, 1, nombresLigas[i],
				strlen(nombresLigas[i]), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_bind_text(stmt, 2, &campeonesLigas[i], 1,
		SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into country table\n");
			return result;
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}

		printf("Prepared statement finalized (INSERT)\n");
	}

	return SQLITE_OK;

}

