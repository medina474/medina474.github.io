#!/bin/bash

SCHEMA_ONLY_QUERY="SELECT datname from pg_database where datname !~'postgres|template' order by datname;"
SCHEMA_ONLY_DB_LIST=`psql -At -c "$SCHEMA_ONLY_QUERY"`

for DATABASE in $SCHEMA_ONLY_DB_LIST
do
    echo $DATABASE
    DUMPDIR=/home/$DATABASE/backups
    mkdir -p $DUMPDIR

    if [ "`date +%d`" = "17" ]
    then
    echo "`date` : vacuum full analyze"
    psql -d $DATABASE -c "VACUUM full analyze;"
    else
    echo "`date` : vacuum"
    psql -d $DATABASE -c "VACUUM;"
    fi

    date=`date '+%Y.%m.%d'`
    file=${DUMPDIR}/$DATABASE_$date.sql.gz
    pg_dump $DATABASE -C | gzip > $file

    find ${DUMPDIR}/ -name '*.sql.gz' -mtime +14 -exec rm -f {} \; -print

done

if [ "`date +%u`" = "7" ]
then
    echo "reindex";
    /usr/bin/reindexdb -a
fi
