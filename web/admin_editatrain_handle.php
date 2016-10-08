<?php
$con = mysql_connect("localhost","trainsAdmin","nwGXxXjTJzVJLuS4");
if (!$con)
  {
  die('请检查: ' . mysql_error());
  }
mysql_select_db("trains_system", $con);


if ($_SERVER["REQUEST_METHOD"] == "POST") {
	if ($_POST['myQuestType'] == "updateRow") {
		$sql = "UPDATE timetable SET in_time = '".$_POST['intime']."', out_time = '".$_POST['outtime']."' WHERE no = ".$_POST['timetableid'].";";
		$result = mysql_query($sql);
		if ($result) {
			echo "Update Information Successfully!";
		}else {
			echo "Error occurred!";
		}
	}
	if ($_POST['myQuestType'] == "addSiteALine") {
		$sql1 = "UPDATE timetable SET zhanci=zhanci+1 WHERE train_no=".$_POST['timetabletrainid']." AND zhanci > ".$_POST['zhanciid'].";";
		$result1 = mysql_query($sql1);

		$sql2 = "INSERT INTO timetable(site_id, train_no, in_time, out_time, next_day, zhanci) VALUES (".$_POST['asite'].", ".$_POST['timetabletrainid'].",'".$_POST['intime']."','".$_POST['outtime']."',".$_POST['nextday'].",".($_POST['zhanciid']+1).");";
		$result2 = mysql_query($sql2);
		if ($result1 && $result2) {
			echo "Add Information Successfully!";
		}else {
			echo "Error occurred!";
		}
	}
	if ($_POST['myQuestType'] == "deleteSiteALine") {
		$sql1 = "DELETE FROM timetable WHERE no = ".$_POST['ttrowid'].";";
		$result1 = mysql_query($sql1);

		$sql2 = "UPDATE timetable SET zhanci=zhanci-1 WHERE train_no=".$_POST['trainid']." AND zhanci > ".$_POST['zhancihao'].";";
		$result2 = mysql_query($sql2);
		if ($result1 && $result2) {
			echo "Delete Successfully!";
		}else {
			echo "Error occurred!";
		}
	}
}


mysql_close($con);
?>