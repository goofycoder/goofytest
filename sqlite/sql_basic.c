/*
    SQLite3 C interface:
        sqlite3_open();
        sqlite3_exec(db, sql_cmd, ...);
        sqlite3_close();
        sqlite3_errmsg(db);
        sqlite3_free();
 */
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main(int argc, char* argv[])
{
    sqlite3 *db;
    char *errMsg = 0;
    int  rc;
    char *sql_cmd;

    /* Open database */
    rc = sqlite3_open("test.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else {
        fprintf(stdout, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sql_cmd = "CREATE TABLE COMPANY("  \
              "ID INT PRIMARY KEY     NOT NULL," \
              "NAME           TEXT    NOT NULL," \
              "AGE            INT     NOT NULL," \
              "ADDRESS        CHAR(50)," \
              "SALARY         REAL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql_cmd, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }

    /* Create SQL statement */
    sql_cmd = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
                "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
              "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
                "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); " \
              "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
                "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
              "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
                "VALUES (4, 'Mark', 25, 'Richmond ', 65000.00 );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql_cmd, callback, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Records created successfully\n");
    }

    sqlite3_close(db);
   
    return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;

   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }

   printf("\n");
   return 0;
}
