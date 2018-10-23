#include <iostream>
#include "DbAdmin.h"
//
using namespace std;
//
int main(int argc, char **argv){
    try{
        (void)argc;
        (void)argv;
        sqlite3_stmt *result;
        //
        int rc;
        const unsigned char *data;
        DbAdmin dbh;
        dbh.open("test.db");
        result=&(dbh.query("SELECT * FROM contatos"));
        //
        while (SQLITE_ROW == (rc = sqlite3_step(result))) {
            // we'll only get here if we fetched a new row of data
            for(int i = 0; i < sqlite3_column_count(result); i++) {
                // this will process all of the returned columns
                data = sqlite3_column_text(result, i); // text in ith column
                cout << "\t|\t" << data;
            }
            cout << "\n";
        }
        cout << "-Fim-\n";
        //
        dbh.finish(result);
        dbh.close();
    }
    catch (const char *str_with_error){
        cout << str_with_error << "\n";
    }
    return 0;
}
