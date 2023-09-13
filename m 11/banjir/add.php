<?php
   include("inc.inc");
   	
   //$link=Connection();
   date_default_timezone_set("Asia/Kuala_Lumpur");
   $height=$_GET["dist"];
	$locate=$_GET["loc"];
   
   //Location
   if ($locate == 1)
   {
      $location = "SG PUSU, GOMBAK";
   }
   echo "<br>Height: ".$height. "cm & Location: ". $location; //flag to check data send form sensor
   


   //THE FORMULA @ CONDITIONS
   if ($height < 5) //if the height between sensor & water surface is less then 5cm -- status = DANGER
   {
      $status = "DANGER";
   } else {
      $status = "SAFE";
   }
   echo "<br>".$status;
	$query = "INSERT INTO riverdetail (location, height, status) VALUES ('$location','$height', '$status')"; 
   	
   if  ((is_null($height) or is_null($location)))
   {
      echo "Empty data"; //flag
   }
   else
   {
      mysqli_query($conn, $query) or die('Failed to update site table. Mysql returned the following:'.mysqli_error());
      echo "<br>Added to DB"; //flag
      
   }
   //header("Location: index.php");
?>
