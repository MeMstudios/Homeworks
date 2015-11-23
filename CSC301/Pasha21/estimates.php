<?php 

$page_title = 'Pasha the Painter Estimates';
include('includes/header.inc.php');
	

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
 if (!empty($_POST['myName'])) {
	$name = strip_tags($_POST['myName']);
 }
 else {
	$name = NULL;
	echo '<p class="error"> You forgot to enter your name!</p>';
 }
 if (filter_var($_POST['myEmail'], FILTER_VALIDATE_EMAIL)) {
 	$email = $_POST['myEmail'];	
 }
 else {
	$email = NULL;
	echo '<p class="error"> Please enter a valid email address!</p>';
 }
 if (!empty($_POST['myJob'])) {
 	$job = strip_tags($_POST['myJob']);	
 }
 else {
	$job = NULL;
	echo '<p class="error"> You forgot to enter your job!</p>';
 }
 if (!empty($_POST['myCity'])) {
    $city = strip_tags($_POST['myCity']);
    $cityPattern = '/^[A-Z][A-Za-z.\s]+$/';
 	if(!preg_match ($cityPattern, $city)) {
        echo'<p class="error"> Invalid city name! </p>';
        $city = NULL;
    }
 }
 else {
	$city = NULL;
	echo '<p class="error"> You forgot to enter your city!</p>';
 }
 if (!empty($_POST['myZip'])) {
 	$zip = $_POST['myZip'];	
    $zipPattern = '/^\d{5}(-\d{4})?$/';
 	if(!preg_match ($zipPattern, $zip)) {
        echo'<p class="error"> Invalid zip code! </p>';
        $zip = NULL;
    }
 }
 else {
	$zip = NULL;
	echo '<p class="error"> Please enter a valid zip code!</p>';	
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
	 echo '<p class="error"> Please try again.</p>';
 }
}
?>

<div id="rightcolumn">
  <p>Request a Free Estimate.</p>
  <form method="post" action="estimates.php">
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
	</div>
    <div>
      <label class="labelCol" for="myJob">Type of Job: </label>
      <textarea name="myJob" id="myJob" rows="2" cols="20">
		<?php if(isset($_POST['myJob']))echo $_POST['myJob'];?>
	  </textarea>
    </div>
    <div class="mySubmit">
      <input type="submit" value="Free Estimate" />
    </div>
  </form>
<?php include('includes/footer.inc.php'); ?>
