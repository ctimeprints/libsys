<?php
session_start();

$username = $password ="";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $username = test_input($_POST["username"]);
  $password = test_input($_POST["password"]);
}
function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

$con = mysql_connect("localhost","trainsAdmin","nwGXxXjTJzVJLuS4");
if (!$con)
  {
  die('请检查: ' . mysql_error());
  }

mysql_select_db("trains_system", $con);

$sql = "SELECT * FROM usr WHERE name=".$username.";";
$result = mysql_query($sql);

if (mysql_num_rows($result)) {
	$row = mysql_fetch_array($result);
	if ($password == $row[1]) {
		$_SESSION['temp_user'] = $username;
		header("Location: administration_home.php");
	}else {
  header("Location: login.php");
}
} else {
	header("Location: login.php");
}
mysql_close($con);
?>