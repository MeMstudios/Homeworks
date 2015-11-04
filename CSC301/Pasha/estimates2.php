<?php 
define('LIVE', FALSE);	
// Create the error handler:

function my_error_handler ($e_number, $e_message, $e_file, $e_line, $e_vars) {	//Build the error message: 
	$message = "An error occurred in script '$e_file' on line $e_line: $e_message\n";

	//Append $e_vars to $message:
	$message .= print_r ($e_vars, 1);
	if (!LIVE) { // Development (print the error).
		echo '<pre>' . $message . "\n";
		debug_print_backtrace();
		echo '</pre><br />';
	} 
	else { // Don't show the error.
		echo '<div class="error">A system error occurred. We apologize for the inconvenience.</div><br />';
	}
} // End of my_error_handler() definition.
set_error_handler ('my_error_handler');
$page_title = 'Pasha the Painter Estimates';
include('includes/header.inc.php');
//Flag variable for  site status:


function create_type_radio($value) {
	echo '<input type="radio" name="paintType" id="paintType" value="' . $value . '"';
	if (isset($_POST['paintType']) && ($_POST['paintType'] == $value)) {
		echo ' checked="checked"';
	} 
	echo " /> $value ";
}
function  calculate($length, $width, $paint){
	$h = 8;
	if ($paint == "High quality") $m = 2.5;
	else $m = 1.75;
	$estimate = (($length*$h*2) + ($width*$h*2) + ($length*$width))*$m;
	return $estimate;
}
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
	
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

 if (!empty($_POST['myCity'])) {
 	$city = $_POST['myCity'];	
 }
 else {
	$city = NULL;
	echo '<p class="error"> You forgot to enter your city!</p>';
 }
 if (is_numeric($_POST['myZip'])) {
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
 if (is_numeric($_POST['width'])) {
 	$width = $_POST['width'];	
 }
 else {
	$width = NULL;
	echo '<p class="error"> You forgot to enter a room width!</p>';	
 }
 if (is_numeric($_POST['length'])) {
 	$length = $_POST['length'];	
 }
 else {
	$length = NULL;
	echo '<p class="error"> You forgot to enter a room length!</p>';	
 }
  if (!empty($_POST['paintType'])) {
 	$type = $_POST['paintType'];	
 }
 else {
	$type = NULL;
	echo '<p class="error"> You forgot to enter a type of paint!</p>';
 }
if ($length && $width && $type) {
	$cost = calculate($length, $width, $type);
	echo '<p> The estimated cost of the job is: $' . number_format($cost, 2) . '</p>     <h3>Thank you for your interest in the Painter!</h3>';
 }

 else {
	 echo '<p class="error"> Please try again.</p>';
 }
}

?>

<div id="rightcolumn">
  <p>Request a Free Estimate.</p>
  <form method="post" action="estimates2.php">
    <div class="myRow">
      <label class="labelCol" for="myName">Name: </label>
      <input type="text" name="myName" id="myName" value="<?php 
		if(isset($_POST['myName'])) echo($_POST['myName']); 
		?>"/>	 
    </div>
    <div class="myRow">
      <label class="labelCol" for="myEmail">E-mail: </label>
      <input type="text" name="myEmail" id="myEmail" value="<?php 
		if(isset($_POST['myEmail'])) echo($_POST['myEmail']); 
		?>"/>
    </div>
	<div class="myRow">
      <label class="labelCol" for="myCity">City: </label>
      <input type="text" name="myCity" id="myCity"value="<?php 
		if(isset($_POST['myCity'])) echo($_POST['myCity']); 
		?>"/>
    </div>
	<div class="myRow">
      <label class="labelCol" for="myZip">Zip Code: </label>
      <input type="text" name="myZip" id="myZip"value="<?php 
		if(isset($_POST['myZip'])) echo($_POST['myZip']); 
		?>"/>
    </div>	
	<div class="myRow">
	<?php
	$states = array ('KY', 'OH', 'IN');
	echo '<label class="labelCol" for="myState">State: </label>
		  <select name="myState" id="myState">';
		  foreach ($states as $value) {
			  echo "<option value=\"$value\"";
			  if(isset($_POST['myState']) && ($_POST['myState'] == $value)) 
				echo 'selected="selected"';
			  echo ">$value</option>\n";
		  }
		echo '</select>';	
	?> 
	<div class="myRow">
      <label class="labelCol" for="length">Room length</label>
      <input type="text" name="length" id="length"value="<?php 
		if(isset($_POST['length'])) echo($_POST['length']); 
		?>"/>
    </div>
	<div class="myRow">
      <label class="labelCol" for="width">Room width</label>
      <input type="text" name="width" id="width"value="<?php 
		if(isset($_POST['width'])) echo($_POST['width']); 
		?>"/>
    </div>
	<div class="myRow">
      <label class="labelCol" for="paintType">Paint Type: </label>
      <?php
		create_type_radio('High quality');
		create_type_radio('Regular');
	  ?>
    </div>
		
	
	</div>
    <div>
      
    </div>
    <div class="mySubmit">
      <input type="submit" value="Free Estimate" />
    </div>
  </form>
<?php include('includes/footer.inc.php'); ?>
