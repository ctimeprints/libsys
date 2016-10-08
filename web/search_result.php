<?php
$depart_point = $dest_point= "";
$trainname = "";
$sitename = "";
$searchbtn = "";

if ($_SERVER["REQUEST_METHOD"] == "GET") {
	$searchbtn = $_REQUEST["searchbtn"];
    if ($searchbtn == "trainsearch") {
    	$trainname = test_input($_REQUEST["trainname"]);
    }elseif ($searchbtn == "sitesearch") {
    	$sitename = test_input($_REQUEST["sitename"]);
    }elseif ($searchbtn == "end2endsearch") {
    	$depart_point = test_input($_REQUEST["depart_point"]);
    	$dest_point = test_input($_REQUEST["dest_point"]);
    }
	
	
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}


?>




<!DOCTYPE html>
<html>
<head>
	<!--
		Charisma v1.0.0

		Copyright 2012 Muhammad Usman
		Licensed under the Apache License v2.0
		http://www.apache.org/licenses/LICENSE-2.0

		http://usman.it
		http://twitter.com/halalit_usman
	-->
	<meta charset="utf-8">
	<title>Free HTML5 Bootstrap Admin Template</title>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta name="description" content="Charisma, a fully featured, responsive, HTML5, Bootstrap admin template.">
	<meta name="author" content="Muhammad Usman">

	<!-- The styles -->
	<link id="bs-css" href="css/bootstrap-cerulean.css" rel="stylesheet">
	<style type="text/css">
	  body {
		padding-bottom: 40px;
	  }
	  .sidebar-nav {
		padding: 9px 0;
	  }
	</style>
	<link href="css/bootstrap-responsive.css" rel="stylesheet">
	<link href="css/charisma-app.css" rel="stylesheet">
	<link href="css/jquery-ui-1.8.21.custom.css" rel="stylesheet">
	<link href='css/fullcalendar.css' rel='stylesheet'>
	<link href='css/fullcalendar.print.css' rel='stylesheet'  media='print'>
	<link href='css/chosen.css' rel='stylesheet'>
	<link href='css/uniform.default.css' rel='stylesheet'>
	<link href='css/colorbox.css' rel='stylesheet'>
	<link href='css/jquery.cleditor.css' rel='stylesheet'>
	<link href='css/jquery.noty.css' rel='stylesheet'>
	<link href='css/noty_theme_default.css' rel='stylesheet'>
	<link href='css/elfinder.min.css' rel='stylesheet'>
	<link href='css/elfinder.theme.css' rel='stylesheet'>
	<link href='css/jquery.iphone.toggle.css' rel='stylesheet'>
	<link href='css/opa-icons.css' rel='stylesheet'>
	<link href='css/uploadify.css' rel='stylesheet'>

	<!-- The HTML5 shim, for IE6-8 support of HTML5 elements -->
	<!--[if lt IE 9]>
	  <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
	<![endif]-->

	<!-- The fav icon -->
	<link rel="shortcut icon" href="img/favicon.ico">
		
</head>

<body>
				<!-- topbar starts -->
	<div class="navbar">
		<div class="navbar-inner">
			<div class="container-fluid">
				<a class="btn btn-navbar" data-toggle="collapse" data-target=".top-nav.nav-collapse,.sidebar-nav.nav-collapse">
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
				</a>
				<a class="brand" href="index.html"><img alt="Charisma Logo" src="img/logo20.png" /><span>Trains Schedule Searching System</span></a>
				
				<!-- theme selector starts -->
				<div class="btn-group pull-right theme-container" >
					<a class="btn dropdown-toggle" data-toggle="dropdown" href="#">
						<i class="icon-tint"></i><span class="hidden-phone"> Change Theme / Skin</span>
						<span class="caret"></span>
					</a>
					<ul class="dropdown-menu" id="themes">
						<li><a data-value="classic" href="#"><i class="icon-blank"></i> Classic</a></li>
						<li><a data-value="cerulean" href="#"><i class="icon-blank"></i> Cerulean</a></li>
						<li><a data-value="cyborg" href="#"><i class="icon-blank"></i> Cyborg</a></li>
						<li><a data-value="redy" href="#"><i class="icon-blank"></i> Redy</a></li>
						<li><a data-value="journal" href="#"><i class="icon-blank"></i> Journal</a></li>
						<li><a data-value="simplex" href="#"><i class="icon-blank"></i> Simplex</a></li>
						<li><a data-value="slate" href="#"><i class="icon-blank"></i> Slate</a></li>
						<li><a data-value="spacelab" href="#"><i class="icon-blank"></i> Spacelab</a></li>
						<li><a data-value="united" href="#"><i class="icon-blank"></i> United</a></li>
					</ul>
				</div>
				<!-- theme selector ends -->
				
				<!-- user dropdown starts -->
				
				<!-- user dropdown ends -->
				
			</div>
		</div>
	</div>
	<!-- topbar ends -->


		<div class="container-fluid">
		<div class="row-fluid">
				
			<!-- left menu starts -->
			<div class="span2 main-menu-span">
				<div class="well nav-collapse sidebar-nav">
					<ul class="nav nav-tabs nav-stacked main-menu">
						<li class="nav-header hidden-tablet">Main</li>
						<li><a class="ajax-link" href="index.html"><i class="icon-home"></i><span class="hidden-tablet"> Dashboard</span></a></li>
						<li><a class="ajax-link" href="search.html"><i class="icon-eye-open"></i><span class="hidden-tablet"> Search</span></a></li>
						</ul>
					</div><!--/.well -->
			</div><!--/span-->
			<!-- left menu ends -->
			
			<noscript>
				<div class="alert alert-block span10">
					<h4 class="alert-heading">Warning!</h4>
					<p>You need to have <a href="http://en.wikipedia.org/wiki/JavaScript" target="_blank">JavaScript</a> enabled to use this site.</p>
				</div>
			</noscript>
			

			<!-- content starts -->
			<div id="content" class="span10">
			
			

			
			<div class="row-fluid">		
				<div class="box span12">
					<div class="box-header well" data-original-title>
						<h2><i class="icon-user"></i> 结果</h2>
						<div class="box-icon">
							<a href="#" class="btn btn-setting btn-round"><i class="icon-cog"></i></a>
							<a href="#" class="btn btn-minimize btn-round"><i class="icon-chevron-up"></i></a>
							<a href="#" class="btn btn-close btn-round"><i class="icon-remove"></i></a>
						</div>
					</div>


<?php
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
  							echo '<td><a href="search_result.php?trainname='.$get_train_name.'&searchbtn=trainsearch">' . $get_train_name . '</a></td>';
  							echo '<td><a href="search_result.php?sitename='.$row['site_name'].'&searchbtn=sitesearch">' . $row['site_name'] . '</a></td>';
  							if ($row['next_day'] == 0) {
  								echo "<td>当天</td>";
  							}else {
  								echo "<td>第" . ($row['next_day']+1) . "天</td>";
  							}
  							echo "<td>" . $row['in_time'] . "</td>";
  							echo "<td>" . $row['out_time'] . "</td>";
  							//calculate the stopping time
  							$seconds = strtotime($row['out_time'])-strtotime($row['in_time']);
  							$minutes = $seconds/60;
  							echo "<td>" . ($minutes) . " min</td>";
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
  							echo '<td><a href="search_result.php?sitename='.$row['site_name'].'&searchbtn=sitesearch">' . $row['site_name'] . '</a></td>';
  							echo '<td><a href="search_result.php?trainname='.$row['train_name'].'&searchbtn=trainsearch">' . $row['train_name'] . '</a></td>';
  							echo "<td>" . $row['in_time'] . "</td>";
  							echo "<td>" . $row['out_time'] . "</td>";

	$little_sql = "SELECT site_name FROM sites WHERE site_id = ".$row['departation'].";";
	$little_result = mysql_query($little_sql, $con);
	$trainname_row = mysql_fetch_array($little_result);
	$get_site_name = $trainname_row['site_name'];
  							echo '<td><a href="search_result.php?sitename='.$get_site_name.'&searchbtn=sitesearch">' . $get_site_name . '</a></td>';

  	$little_sql = "SELECT site_name FROM sites WHERE site_id = ".$row['destination'].";";
	$little_result = mysql_query($little_sql, $con);
	$trainname_row = mysql_fetch_array($little_result);
	$get_site_name = $trainname_row['site_name'];
  							echo '<td><a href="search_result.php?sitename='.$get_site_name.'&searchbtn=sitesearch">' . $get_site_name . '</a></td>';

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
	AND SECOND.site_name='".$dest_point."'
	AND FIRST.zhanci<=SECOND.zhanci";
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
  							echo '<td><a href="search_result.php?trainname='.$row['train_name'].'&searchbtn=trainsearch">' . $row['train_name'] . "</a></td>";

  							echo '<td><a href="search_result.php?sitename='.$row['site_name_1'].'&searchbtn=sitesearch">' . $row['site_name_1'].'</a><br><a href="search_result.php?sitename='.$row['site_name_2'].'&searchbtn=sitesearch">'.$row['site_name_2']. '</a></td>';

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
							//calculate the stopping time
							$intimesec = strtotime($row['in_time']) + $row['next_day_2']*24*3600;
							$outtimesec = strtotime($row['out_time']) + $row['next_day_1']*24*3600;
  							$seconds = $intimesec-$outtimesec;
  							$minutes = $seconds/60;
  							$hours = (int)($minutes/60);
  							$modminutes = $minutes%60;
  							echo "<td>" .$hours. "h " . $modminutes . "min</td>";
  							echo "</tr>";
  							}
  						echo '</tbody>
					  </table>            
					</div>';
}

?>


							
						  
				</div><!--box span 12 end-->
			
			</div><!--/row fluid sortable end--> 
					<!-- content ends -->




			</div><!--/#content.span10-end-->
				</div><!--/fluid-row end -->
				
		<hr>

		<div class="modal hide fade" id="myModal">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal">×</button>
				<h3>Settings</h3>
			</div>
			<div class="modal-body">
				<p>Here settings can be configured...</p>
			</div>
			<div class="modal-footer">
				<a href="#" class="btn" data-dismiss="modal">Close</a>
				<a href="#" class="btn btn-primary">Save changes</a>
			</div>
		</div>

		<footer>
			<p class="pull-left">&copy; <a href="http://ctimeprints.github.io" target="_blank">Simon Cao</a> 2015</p>
			<p class="pull-right">Powered by: <a href="index.html">Trains Schedule Searching System</a></p>
		</footer>
		
	</div><!--/.fluid-container-->
<!---  end the php script
==================== -->
<?php
mysql_close($con);
?>
<!--- ========= -->
	<!-- external javascript
	================================================== -->
	<!-- Placed at the end of the document so the pages load faster -->

	<!-- jQuery -->
	<script src="js/jquery-1.7.2.min.js"></script>
	<!-- jQuery UI -->
	<script src="js/jquery-ui-1.8.21.custom.min.js"></script>
	<!-- transition / effect library -->
	<script src="js/bootstrap-transition.js"></script>
	<!-- alert enhancer library -->
	<script src="js/bootstrap-alert.js"></script>
	<!-- modal / dialog library -->
	<script src="js/bootstrap-modal.js"></script>
	<!-- custom dropdown library -->
	<script src="js/bootstrap-dropdown.js"></script>
	<!-- scrolspy library -->
	<script src="js/bootstrap-scrollspy.js"></script>
	<!-- library for creating tabs -->
	<script src="js/bootstrap-tab.js"></script>
	<!-- library for advanced tooltip -->
	<script src="js/bootstrap-tooltip.js"></script>
	<!-- popover effect library -->
	<script src="js/bootstrap-popover.js"></script>
	<!-- button enhancer library -->
	<script src="js/bootstrap-button.js"></script>
	<!-- accordion library (optional, not used in demo) -->
	<script src="js/bootstrap-collapse.js"></script>
	<!-- carousel slideshow library (optional, not used in demo) -->
	<script src="js/bootstrap-carousel.js"></script>
	<!-- autocomplete library -->
	<script src="js/bootstrap-typeahead.js"></script>
	<!-- tour library -->
	<script src="js/bootstrap-tour.js"></script>
	<!-- library for cookie management -->
	<script src="js/jquery.cookie.js"></script>
	<!-- calander plugin -->
	<script src='js/fullcalendar.min.js'></script>
	<!-- data table plugin -->
	<script src='js/jquery.dataTables.min.js'></script>

	<!-- chart libraries start -->
	<script src="js/excanvas.js"></script>
	<script src="js/jquery.flot.min.js"></script>
	<script src="js/jquery.flot.pie.min.js"></script>
	<script src="js/jquery.flot.stack.js"></script>
	<script src="js/jquery.flot.resize.min.js"></script>
	<!-- chart libraries end -->

	<!-- select or dropdown enhancer -->
	<script src="js/jquery.chosen.min.js"></script>
	<!-- checkbox, radio, and file input styler -->
	<script src="js/jquery.uniform.min.js"></script>
	<!-- plugin for gallery image view -->
	<script src="js/jquery.colorbox.min.js"></script>
	<!-- rich text editor library -->
	<script src="js/jquery.cleditor.min.js"></script>
	<!-- notification plugin -->
	<script src="js/jquery.noty.js"></script>
	<!-- file manager library -->
	<script src="js/jquery.elfinder.min.js"></script>
	<!-- star rating plugin -->
	<script src="js/jquery.raty.min.js"></script>
	<!-- for iOS style toggle switch -->
	<script src="js/jquery.iphone.toggle.js"></script>
	<!-- autogrowing textarea plugin -->
	<script src="js/jquery.autogrow-textarea.js"></script>
	<!-- multiple file upload plugin -->
	<script src="js/jquery.uploadify-3.1.min.js"></script>
	<!-- history.js for cross-browser state change on ajax -->
	<script src="js/jquery.history.js"></script>
	<!-- application script for Charisma demo -->
	<script src="js/charisma.js"></script>
	
		
</body>
</html>
