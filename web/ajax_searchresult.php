<?php
echo '<div class="row-fluid">		
				<div class="box span12">
					<div class="box-header well" data-original-title>
						<h2><i class="icon-user"></i> 结果</h2>
						<div class="box-icon">
							<a href="#" class="btn btn-setting btn-round"><i class="icon-cog"></i></a>
							<a href="#" class="btn btn-minimize btn-round"><i class="icon-chevron-up"></i></a>
							<a href="#" class="btn btn-close btn-round"><i class="icon-remove"></i></a>
						</div>
					</div>';





$con = mysql_connect("localhost","trainsAdmin","nwGXxXjTJzVJLuS4");
if (!$con)
  {
  die('请检查: ' . mysql_error());
  }
mysql_select_db("trains_system", $con);

if ($searchbtn == "trainsearch") {
	# code...
	$sql = "SELECT train_name FROM trains WHERE train_name like '".$trainname."';";
	$train_number_result = mysql_query($sql, $con);
	$trainname_row = mysql_fetch_array($train_number_result);
	$get_train_name = $trainname_row['train_name'];

	$sql = "SELECT site_name, next_day, in_time, out_time, zhanci FROM timetable, sites 
	WHERE timetable.site_id = sites.site_id 
	AND timetable.train_no IN (SELECT no FROM trains WHERE train_name like '".$trainname."') ORDER BY zhanci;";
	$result = mysql_query($sql,$con);

	$table_header = "<th>车次</th><th>站名</th><th>日期</th><th>到达时间</th><th>开车时间</th><th>停车时间</th><th>站次</th>";

echo '<!--table!!!!, start from here -->
					<div class="box-content">
						<table class="table table-striped table-bordered bootstrap-datatable datatable">
						  <thead>
							  <tr>';
							  echo $table_header;
						echo '</tr>
						  </thead>   
						  <tbody>';

						  while($row = mysql_fetch_array($result))
  							{
  							echo "<tr>";
  							echo "<td>" . $get_train_name . "</td>";
  							echo "<td>" . $row['site_name'] . "</td>";
  							if ($row['next_day'] == 0) {
  								echo "<td>当天</td>";
  							}else {
  								echo "<td>第" . ($row['next_day']+1) . "天</td>";
  							}
  							echo "<td>" . $row['in_time'] . "</td>";
  							echo "<td>" . $row['out_time'] . "</td>";
  							echo "<td>" . "计算时间" . "</td>";
  							echo "<td>" . $row['zhanci'] . "</td>";
  							echo "</tr>";
  							}
  						echo '</tbody>
					  </table>            
					</div>';

}elseif ($searchbtn == "sitesearch") {
	$sql = "SELECT site_name, train_name, in_time, out_time, departation, destination 
	FROM timetable, sites, trains WHERE timetable.site_id = sites.site_id AND timetable.train_no = trains.no 
	AND timetable.site_id IN (SELECT site_id FROM sites WHERE site_name LIKE '".$sitename."')";
	$result = mysql_query($sql,$con);

	$table_header = "<th>站名</th><th>车次</th><th>到站时间</th><th>出站时间</th><th>起始站</th><th>终点站</th>";
	echo '<!--table!!!!, start from here -->
					<div class="box-content">
						<table class="table table-striped table-bordered bootstrap-datatable datatable">
						  <thead>
							  <tr>';
							  echo $table_header;
						echo '</tr>
						  </thead>   
						  <tbody>';
						  while($row = mysql_fetch_array($result))
  							{
  							echo "<tr>";
  							echo "<td>" . $row['site_name'] . "</td>";
  							echo "<td>" . $row['train_name'] . "</td>";
  							echo "<td>" . $row['in_time'] . "</td>";
  							echo "<td>" . $row['out_time'] . "</td>";

	$little_sql = "SELECT site_name FROM sites WHERE site_id = ".$row['departation'].";";
	$little_result = mysql_query($little_sql, $con);
	$trainname_row = mysql_fetch_array($little_result);
	$get_site_name = $trainname_row['site_name'];
  							echo "<td>" . $get_site_name . "</td>";

  	$little_sql = "SELECT site_name FROM sites WHERE site_id = ".$row['destination'].";";
	$little_result = mysql_query($little_sql, $con);
	$trainname_row = mysql_fetch_array($little_result);
	$get_site_name = $trainname_row['site_name'];
  							echo "<td>" . $get_site_name . "</td>";

  							echo "</tr>";
  							}
  						echo '</tbody>
					  </table>            
					</div>';




}elseif ($searchbtn == "end2endsearch") {
	$sql = "SELECT FIRST.train_name, FIRST.site_name site_name_1, SECOND.site_name site_name_2, 
	FIRST.out_time, SECOND.in_time, FIRST.next_day next_day_1, SECOND.next_day next_day_2
	FROM view_timetable FIRST, view_timetable SECOND 
	WHERE FIRST.train_name=SECOND.train_name 
	AND FIRST.site_name='".$depart_point."' 
	AND SECOND.site_name='".$dest_point."'";
	$result = mysql_query($sql,$con);

	$table_header = "<th>车次</th><th>发站/到站</th><th>发/到时间</th><th>运行时间</th>";
	echo '<!--table!!!!, start from here -->
					<div class="box-content">
						<table class="table table-striped table-bordered bootstrap-datatable datatable">
						  <thead>
							  <tr>';
							  echo $table_header;
						echo '</tr>
						  </thead>   
						  <tbody>';
						  while($row = mysql_fetch_array($result))
  							{
  							echo "<tr>";
  							echo "<td>" . $row['train_name'] . "</td>";

  							echo "<td>" . $row['site_name_1']."<br>".$row['site_name_2']. "</td>";

  							echo "<td>" . $row['out_time'];
								if ($row['next_day_1'] == 0) {
  									echo "(当天)";
  								}else {
  									echo "(第" . ($row['next_day_1']+1) . "天)";
  								}
  								echo "<br>";
  								echo $row['in_time'];
  								if ($row['next_day_2'] == 0) {
  									echo "(当天)";
  								}else {
  									echo "(第" . ($row['next_day_2']+1) . "天)";
  								}
  							echo "</td>";

  							echo "<td>" . "计算时间" . "</td>";
  							echo "</tr>";
  							}
  						echo '</tbody>
					  </table>            
					</div>';
}

mysql_close($con);


echo '				</div><!--box span 12 end-->
			
			</div><!--/row fluid sortable end--> 
					<!-- content ends -->';


?>


							
						  
