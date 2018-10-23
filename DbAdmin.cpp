#include <iostream>
#include <string>
#include <sqlite3.h>
#include "DbAdmin.h"
//
void DbAdmin::open(const char *filename){
    if (sqlite3_open_v2(filename, &db, SQLITE_OPEN_READWRITE, NULL) != SQLITE_OK){
        close();
        throw "Erro ao abrir base de dados";
    }
}
void DbAdmin::close(){
    sqlite3_close(db);
}
sqlite3_stmt& DbAdmin::query(const char *sqlcmd){
    int rc;
    sqlite3_stmt *stmt;
    rc=sqlite3_prepare_v2(db, sqlcmd, strlen(sqlcmd), &stmt, NULL);
    if (rc != SQLITE_OK){
        finish(stmt);
        close();
        throw "Erro ao preparar comando";
    }
    return *stmt;
}
void DbAdmin::finish(sqlite3_stmt *stmt){
    int rc;
    rc=sqlite3_finalize(stmt);
    if (rc){
        close();
        throw "Erro finalizando o comando";
    }
}
