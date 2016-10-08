<?php

$con = mysql_connect("localhost","trainsAdmin","nwGXxXjTJzVJLuS4");
if (!$con)
  {
  die('请检查: ' . mysql_error());
  }
mysql_select_db("trains_system", $con);

$confirm_btn = "";
$site_name = $site_info = "";
$train_id = $start_time = $end_time = $days = $start_point = $end_point = "";

if ($_SERVER["REQUEST_METHOD"] == "GET") {
	$confirm_btn = $_REQUEST["confirm_btn"];

    if ($confirm_btn == "add_site_confirm") {
    	$site_name = test_input($_REQUEST["site_name"]);
      // $site_info = test_input($_REQUEST["site_info"]);
      $sql = "INSERT INTO sites(site_name) VALUES ('".$site_name."');";
      // echo $sql;
      $result = mysql_query($sql);
      if ($result) {
        echo "<br>success<br>";
      }else{
        echo "<br>error occurred in inserting<br>";  
        if (mysql_errno() == 1062) {
          echo "该条目已经存在！";
        };
      }
      echo '3s后跳转……
<script type="text/javascript">
  window.setTimeout("location.href=document.referrer",3000);
</script>';
      


    }elseif ($confirm_btn == "add_train_confirm") {
    	$train_id = test_input($_REQUEST["train_id"]);
      $start_time = $_REQUEST["start_time"];
      $end_time = $_REQUEST["end_time"];
      $days = test_input($_REQUEST["days"]);
      $start_point = test_input($_REQUEST["start_point"]);
      $end_point = test_input($_REQUEST["end_point"]);


      $little_sql = "SELECT * FROM sites WHERE site_name LIKE '".$start_point."';";
      $result = mysql_query($little_sql);
      $row = mysql_fetch_row($result);
      $get_ssite_no = $row[0];

      $little_sql = "SELECT * FROM sites WHERE site_name LIKE '".$end_point."';";
      $result = mysql_query($little_sql);
      $row = mysql_fetch_row($result);
      $get_dsite_no = $row[0];

      $sql = "INSERT INTO trains(train_name, depart_time, arrival_time, count_day, departation, destination) VALUES ('".$train_id."', '".$start_time."', '".$end_time."', ".$days.", ".$get_ssite_no.", ".$get_dsite_no.");";
      // echo $sql;
      $result1 = mysql_query($sql);

      $sql =" SELECT * FROM trains WHERE train_name LIKE '".$train_id."';";
      $result = mysql_query($sql);
      $row = mysql_fetch_row($result);
      $get_train_no = $row[0];

      $sql = "INSERT INTO timetable(site_id, train_no, in_time, out_time, next_day, zhanci) VALUES (".$get_ssite_no.", ".$get_train_no.", '".$start_time."', '".$start_time."', 0, 1)";
      $result2 = mysql_query($sql);
      $sql = "INSERT INTO timetable(site_id, train_no, in_time, out_time, next_day, zhanci) VALUES (".$get_dsite_no.", ".$get_train_no.", '".$end_time."', '".$end_time."', ".($days-1).", 2)";
      $result3 = mysql_query($sql);


      if ($result1 && $result2 && $result3) {
        echo "<br>成功！<br>";
      }else{
        echo "<br>error occurred in inserting<br>";  
        if (mysql_errno() == 1062) {
          echo "该条目已经存在！";
        };
      }
      echo '3s后跳转……
<script type="text/javascript">
  window.setTimeout("location.href=document.referrer",3000);
</script>';


    }elseif ($confirm_btn == "end2endsearch") {
    	



    }
	
	
}elseif ($_SERVER["REQUEST_METHOD"] == "POST") {
  if ($_POST['myQuestType'] == "deleterow") {
    $getId = $_POST['trainid'];
    $sql1 = "DELETE FROM timetable WHERE train_no = ".$getId.";";
    $result1 = mysql_query($sql1);
    $sql2 = "DELETE FROM trains WHERE no = ".$getId.";";
    $result2 = mysql_query($sql2);
    if ($result1 && $result2) {
      echo "删除成功";
    }
  }
  if ($_POST['myQuestType'] == "registeruser") {
    $sql = "INSERT INTO usr(name, password) VALUES ('".$_POST['modalusername']."', '".$_POST['modalpassword']."');";
    $result = mysql_query($sql);
    if ($result) {
      echo "Registered";
    } else {
      echo "Error occurred";

    }
    
  }
}

mysql_close($con);

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}


?>
