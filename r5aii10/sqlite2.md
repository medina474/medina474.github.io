sqlite3* db;
int rc;

rc = sqlite3_open("users.db", &db);
if(rc != SQLITE_OK) {
   fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
   sqlite3_close(db);
   return 1;
}

if(!table_exists(db, "camion")) {
  if(!create_camion_table(db)) {
    sqlite3_close(db);
    return 1;
  }
}

bool table_exists(sqlite3* db, const char* table_name)
{
    sqlite3_stmt* statement;
    int rc;

    const char* sql_table_list = "SELECT name FROM sqlite_master WHERE type='table'";

    rc = sqlite3_prepare_v2(db, sql_table_list, strlen(sql_table_list), &statement, NULL);
    if(rc == SQLITE_OK) {
        // Lister toutes les tables
        while(sqlite3_step(statement) == SQLITE_ROW) {
            if(!strcmp((const char*) sqlite3_column_text(statement, 0), table_name))
                return true;
        }
    }

    return false;
}

bool create_table(sqlite3* db)
{
    sqlite3_stmt* statement;
    int rc;

    const char* sql_create_table = "CREATE TABLE ... ";

    rc = sqlite3_prepare_v2(db, sql_create_table, strlen(sql_create_table), &statement, NULL);
    if(rc == SQLITE_OK) {
        rc = sqlite3_step(statement);
        sqlite3_finalize(statement);
    } else {
        fprintf(stderr, "Impossible de créer la table: %s\n", sqlite3_errmsg(db));
        return false;
    }

    return true;
}

void display_users(sqlite3* db)
{
    sqlite3_stmt* statement;
    int rc;

    const char* sql_display = "SELECT  FROM table";

    // Execute the previous query to select all user in the 'user' table
    rc = sqlite3_prepare_v2(db, sql_display, strlen(sql_display), &statement, NULL);
    if(rc == SQLITE_OK) {

        // Afficher l'entête
        printf("%10s | %10s | %10s\n", "col1", "col2", "col3");
        printf("------------------------------------\n");

        while(sqlite3_step(statement) == SQLITE_ROW) {

            User user = {0};

            // Loop through all the selected columns : first_name (i=0), last_name (i=1), birthday (i=3)
            for(int i = 0; i < sqlite3_column_count(statement); ++i) {

                    switch(i) {
                    case 0: // text
                        strcpy(colonne1, (const char*) sqlite3_column_text(statement, i));
                        break;

                    case 1: // text
                        strcpy(colonne2, (const char*) sqlite3_column_text(statement, i));
                        break;

                    case 2: // int
                        colonne3 = sqlite3_column_int(statement, i);
                        break;
                    }
                }
            }

            // Afficher la ligne
            printf("%10s | %10s | %02d/%02d/%04d\n",
                   colonne1, colonne2,colonne3);
        }
    }

    sqlite3_finalize(statement);
}

bool insert_user(sqlite3* db, Structure* data)
{
    sqlite3_stmt* statement;
    int rc;

    char sql_insert_user[USER_INSER_QUERY_SIZE];
    sprintf(sql_insert_user,
            "INSERT INTO user (colonne1, colonne2, colonne3) VALUES ('%s', '%s', %lu)",
            data->colonne1,
            data->colonne2,
            (int) data->colonne3);

    rc = sqlite3_prepare_v2(db, sql_insert_user, strlen(sql_insert_user), &statement, NULL);
    if(rc == SQLITE_OK) {
        rc = sqlite3_step(statement);

    } else {
        fprintf(stderr, "Impossible d'insérer les données %s", sqlite3_errmsg(db));
        return false;
    }

    sqlite3_finalize(statement);

    return true;
}
