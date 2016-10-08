<?php
$con = mysql_connect("localhost","trainsAdmin","nwGXxXjTJzVJLuS4");
if (!$con)
  {
  die('请检查: ' . mysql_error());
  }
mysql_select_db("trains_system", $con);

$sql = "SELECT site_id, site_name FROM sites;";
$result = mysql_query($sql);

echo '<div class="box-content">
						<table class="table">
							  <tbody>';

$column_count=0;
while($row = mysql_fetch_array($result))
{
  if (($column_count%4) == 0) {
  		echo "<tr>";
  	}
  echo '<td><a onclick="clickonsite(this.innerHTML)" data-dismiss="modal">' . $row['site_name'] . '</a></td>';
  $column_count++;
  if (($column_count%4) == 0) {
  		echo "</tr>";
  	} 
}

echo '</tbody>
						 </table>  
						      
					</div>';

mysql_close($con);
?>
