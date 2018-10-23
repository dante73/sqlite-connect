#include <iostream>
#include <sqlite3.h>
//
class DbAdmin{
    private:
        sqlite3 *db;
    public:
        //
        void open(const char *filename);
        void close();
        void finish(sqlite3_stmt *stmt);
        //
        sqlite3_stmt& query(const char *sqlcmd);
};
