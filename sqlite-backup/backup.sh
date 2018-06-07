#!/bin/bash

#
# sqlite3_backup.sh
# Script for backing up and compress a sqlite3 database, using the .backup command
# Intended for use with cron for regular automated backups
#
# @author @felubra https://github.com/felubra
# based on the original sqlite3_backup.sh script by shaune@princeton.edu
# (https://gist.github.com/sdellis/3835123)
#

# check to see if $DB_PATH exists
if [ ! -f $DB_PATH ]
then
    echo ERROR: cannot find the database at the following path: $DB_PATH
    exit 1
fi

# check to make sure $BACKUP_PATH exists and is writable
if [ ! -d $BACKUP_PATH ]
then
	# BACKUP_PATH does not exist or is not a directory
    echo ERROR: cannot find backup path: $BACKUP_PATH
    exit 1
else
	# check to make sure it's writable
	if [ ! -w $DB_PATH ]
	then
		echo ERROR: backup path is not writable: $BACKUP_PATH
		exit 1
	fi
fi

# attempt to make a backup
backup_file=$BACKUP_PATH/${DB_PATH##*/}.$(date +%s)
sqlite3 $DB_PATH ".backup '$backup_file'"
did_backup=$?

if [ $did_backup -ne 0 ]
then
  #failed to backup
  echo ERROR: failed trying to backup $DB_PATH to $backup_file
  exit 1
fi

# compress the backup file
tar cJf $backup_file.xz $backup_file &> /dev/null
backup_did_compress=$?

if [ $backup_did_compress -ne 0 ]
then
  #failed to compress the backup
  echo ERROR: failed to compress the backup file $backup_file
  exit 1
else
  echo SUCCESS: created the compressed backup file $backup_file.xz
  rm $backup_file
  backup_file=$backup_file.xz
fi

# create a checksum file of the backup
md5sum $backup_file > $BACKUP_PATH/${backup_file##*/}.md5
calc_md5sum=$?
if [ $calc_md5sum -ne 0 ]
then
  # failed create the checksum
  echo ERROR: failed to calc the MD5 hash of $backup_file
  exit 1
else
  echo INFO: Wrote MD5Sum to $BACKUP_PATH
fi

