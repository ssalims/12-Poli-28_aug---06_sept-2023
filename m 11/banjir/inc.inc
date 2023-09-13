<?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "riverserver";
    // Create connection
     $conn	=	mysqli_connect($servername, $username,$password, $dbname );
   //  $connection = mysqli_select_db($conn,$dbname);

     // Check connection
	if (!$conn) {
    	die("Connection failed. " . mysqli_connect_error());
        
	}else{
        //echo "Connected to DB";
    }
?>