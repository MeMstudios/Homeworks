<?php #Script9.2-mysqli_connect.php	
//this file contains database access information.
//This file also establishes a connection to mysql 
//Set the database access information as constants: 
DEFINE('DB_USER','murphym2');
DEFINE('DB_PASSWORD','3athurUc');
DEFINE('DB_HOST','csweb.hh.nku.edu');
DEFINE('DB_NAME','db_fall15_murphym2');
//Maketheconnection:
$dbc = @mysqli_connect(DB_HOST,DB_USER,DB_PASSWORD,DB_NAME) OR die ('Could not connect to MySQL:' .mysqli_connect_error());	
//Set the encoding...
mysqli_set_charset($dbc,'utf8');