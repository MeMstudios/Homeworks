
<?php
if($_SERVER['REQUEST_METHOD']=='POST') {
  require('mysqli_connect.php');
  $errors = array();
  if (empty($_POST['searchtype'])) {
    $errors[ ] = 'You forgot to choose a search type.';
  } 
  else {
	$searchtype = mysqli_real_escape_string($dbc, trim($_POST['searchtype']));
  }
  if (empty($_POST['searchterm'])) {
    $errors[ ] = 'You forgot to enter a search term.';
  } 
  else {
	$searchterm = mysqli_real_escape_string($dbc, trim($_POST['searchterm']));
  }

if(empty($errors)){  

  $query = "select * from customers where ".$searchtype." like '%".$searchterm."%'";
  $result = @mysqli_query($dbc,$query);

  $num_results = mysqli_num_rows($result);

  echo "<p>Number of books found: ".$num_results."</p>";

  for ($i=0; $i <$num_results; $i++) {
     $row = $result->fetch_assoc();
     echo "<p><strong>".($i+1).". Name ";
     echo htmlspecialchars(stripslashes($row['name']));
     echo "</strong><br />Address: ";
     echo stripslashes($row['address']);
     echo "<br />City: ";
     echo stripslashes($row['city']);
     
     echo "</p>";
  }

  mysqli_free_result($result);
  mysqli_close($dbc);
}
else {
	echo '<h1>Error!</h1>
	<p class="error">The following error(s) occurred:<br />';
	foreach ($errors as $msg) { // Print each error.
		echo " - $msg<br />\n";
   }
  echo '</p><p>Please try again.</p><p><br /></p>';
}
}
?>

<html>
<head>
  <title>Book-O-Rama Customer Search</title>
</head>

<body>
  <h1>Book-O-Rama Customer Search</h1>

  <form action="results.php" method="post">
    Choose Search Type:<br />
    <select name="searchtype">
      <option value="name">Name
      <option value="city">City
     
    </select>
    <br />
    Enter Search Term:<br />
    <input name="searchterm" type="text" size="40">
    <br />
    <input type="submit" name="submit" value="Search">
  </form>

</body>
</html>
