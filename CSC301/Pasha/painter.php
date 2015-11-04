<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="en" xml:lang="en">

<head>
<title>The Painter</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<style type="text/css">
body {background-color:#FFFFFF;
      font-family:Arial;
      }
td {color:#000000;
    font-family:Arial;
     }
.heading {color:#ffffff;
          font-size:larger;
          font-weight:bold;
   background-color:#336600;
         }
div {text-align:center; }
.error {
	font-weight: bold;
	color: #C00;
}
</style>      
</head>
<body>
<div>
<img src="painterlogo.gif" width="620" height="120" alt="The Painter" /><br />
 <h2>Free Estimate</h2>
 <h3>We will contact you to arrange your free estimate</h3>
 <h3>Here is the information you entered:</h3>
 <?php
 if (!empty($_POST['myName'])) {
 	$name = $_POST['myName'];	
 }
 else {
	$name = NULL;
	echo '<p class="error"> You forgot to enter your name!</p>';
 }
 if (!empty($_POST['myEmail'])) {
 	$email = $_POST['myEmail'];	
 }
 else {
	$email = NULL;
	echo '<p class="error"> You forgot to enter your email!</p>';
 }
 if (!empty($_POST['myJob'])) {
 	$job = $_POST['myJob'];	
 }
 else {
	$job = NULL;
	echo '<p class="error"> You forgot to enter your job!</p>';
 }
 if (!empty($_POST['myCity'])) {
 	$city = $_POST['myCity'];	
 }
 else {
	$city = NULL;
	echo '<p class="error"> You forgot to enter your city!</p>';
 }
 if (!empty($_POST['myZip'])) {
 	$zip = $_POST['myZip'];	
 }
 else {
	$zip = NULL;
	echo '<p class="error"> You forgot to enter your zip code!</p>';	
 }
 if (!empty($_POST['myState'])) {
 	$state = $_POST['myState'];	
 }
 else {
	$state = NULL;	
 }
if ($name && $email && $job && $city && $zip) {
	echo "<p>Your Name: $name <br> Email: $email <br> Job: $job <br> City: $city <br> State: $state <br> Zip: $zip <br> </p>     <h3>Thank you for your interest in the Painter!</h3>";
 }

 else {
	 echo '<p class="error"> please go back and try again.</p>';
 }
?>
<form action="#">
<input type="button" value = "Back" onclick="javascript:history.go(-1)" />
</form>
</div>
</body>
</html>