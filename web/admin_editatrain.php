<?php
session_start();
$meta_tag2jump = "";

if(isset($_SESSION['temp_user']))
  {

  }
else
  {
	// header("location:login.php");
	$meta_tag2jump = '<meta http-equiv="refresh" content="0;login.php">';
  }

?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Home: Trains Schedule Searching System</title>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta name="description" content="Database project, by Simon Cao.">
	<meta name="author" content="Simon Cao">

<?php
	echo $meta_tag2jump;
?>

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
	<link href='css/mymymy.css' rel='stylesheet'>
	<link rel="stylesheet" type="text/css" href="css/mymymy.css">
	<!-- The HTML5 shim, for IE6-8 support of HTML5 elements -->
	<!--[if lt IE 9]>
	  <script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
	<![endif]-->

<!-- get sites from databse-->
<script type="text/javascript">
var timetabletrainid=null;
var zhanciid=null;
function setid(trainid, zhanci){
	timetabletrainid = trainid;
	zhanciid = zhanci;
}
function ajaxsubmit(timetableRowId){
	if (timetableRowId != null) {

		//todo: delete the tuple in database
var xmlhttp;
if (window.XMLHttpRequest)
  {// code for IE7+, Firefox, Chrome, Opera, Safari
  xmlhttp=new XMLHttpRequest();
  }
else
  {// code for IE6, IE5
  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
xmlhttp.onreadystatechange=function()
  {
  if (xmlhttp.readyState==4 && xmlhttp.status==200)
    {
    alert(xmlhttp.responseText);
    location.reload();
    }
  }

xmlhttp.open("POST","admin_editatrain_handle.php",true);
xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
//TO-DO: to update info, posting the info in input first, needing to get the info in input
var aIntime = document.getElementById("input1"+timetableRowId).value;
var aOuttime = document.getElementById("input2"+timetableRowId).value;

xmlhttp.send("timetableid="+timetableRowId+"&intime="+aIntime+"&outtime="+aOuttime+"&myQuestType=updateRow");

	}
}

function submitAddttrow(){
var xmlhttp;
if (window.XMLHttpRequest)
  {// code for IE7+, Firefox, Chrome, Opera, Safari
  xmlhttp=new XMLHttpRequest();
  }
else
  {// code for IE6, IE5
  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
xmlhttp.onreadystatechange=function()
  {
  if (xmlhttp.readyState==4 && xmlhttp.status==200)
    {
    alert(xmlhttp.responseText);
    location.reload();
    }
  }

xmlhttp.open("POST","admin_editatrain_handle.php",true);
xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
var aSite = document.getElementById("siteoptionid").value;
var aIntime = document.getElementById("modaltime1").value;
var aOuttime = document.getElementById("modaltime2").value;
var aNextday = document.getElementById("nextday").value;

xmlhttp.send("zhanciid="+zhanciid+"&timetabletrainid="+timetabletrainid+"&asite="+aSite+"&intime="+aIntime+"&outtime="+aOuttime+"&nextday="+aNextday+"&myQuestType=addSiteALine");

}

function ajaxdelete(ttrowid, trainid, zhancihao){
	var xmlhttp;
if (window.XMLHttpRequest)
  {// code for IE7+, Firefox, Chrome, Opera, Safari
  xmlhttp=new XMLHttpRequest();
  }
else
  {// code for IE6, IE5
  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }
xmlhttp.onreadystatechange=function()
  {
  if (xmlhttp.readyState==4 && xmlhttp.status==200)
    {
    	alert(xmlhttp.responseText);
    	location.reload();
    }
  }

xmlhttp.open("POST","admin_editatrain_handle.php",true);
xmlhttp.setRequestHeader("Content-type","application/x-www-form-urlencoded");
xmlhttp.send("ttrowid="+ttrowid+"&trainid="+trainid+"&zhancihao="+zhancihao+"&myQuestType=deleteSiteALine");
}
</script>


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
				<div class="btn-group pull-right" >
					<a class="btn dropdown-toggle" data-toggle="dropdown" href="#">
						<i class="icon-user"></i><span class="hidden-phone"> admin</span>
						<span class="caret"></span>
					</a>
					<ul class="dropdown-menu">
						<li><a href="login.php">Logout</a></li>
					</ul>
				</div>

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
						<li><a class="ajax-link" href="administration_home.php"><i class="icon-home"></i><span class="hidden-tablet"> Admin Home</span></a></li>
						<li><a class="ajax-link" href="administration_add.php"><i class="icon-plus"></i><span class="hidden-tablet"> Add Info</span></a></li>
						<li><a class="ajax-link" href="administration_modify.php"><i class="icon-pencil"></i><span class="hidden-tablet"> Modify</span></a></li>
						
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
			
			<div id="content" class="span10">
			<!-- content starts -->
			

			<div>
				<ul class="breadcrumb">
					<li>
						<a href="administration_home.php">Admin Home</a> <span class="divider">/</span>
					</li>
					<li>
						<a href="administration_modify.php">Modify</a>
					</li>
				</ul>
			</div>

<!--mymymy-->


<?php

$con = mysql_connect("localhost","trainsAdmin","nwGXxXjTJzVJLuS4");
if (!$con)
  {
  die('请检查: ' . mysql_error());
  }
mysql_select_db("trains_system", $con);



if ($_SERVER["REQUEST_METHOD"] == "GET") {
	$trainid=$_GET['trainid'];

	$sql = "SELECT train_name FROM trains WHERE no = ".$trainid.";";
	$train_number_result = mysql_query($sql, $con);
	$trainname_row = mysql_fetch_array($train_number_result);
	$get_train_name = $trainname_row['train_name'];

	$sql = "SELECT timetable.no ttNo, site_name, next_day, in_time, out_time, zhanci FROM timetable, sites 
	WHERE timetable.site_id = sites.site_id 
	AND timetable.train_no = ".$trainid." ORDER BY zhanci;";
	$result = mysql_query($sql,$con);

	$table_header = "<th>车次</th><th>站名</th><th>日期</th><th>到达时间</th><th>开车时间</th><th>站次</th><th>操作</th>";

echo '<!--table!!!!, start from here -->
					<div class="box-content">
						<table class="table table-striped table-bordered bootstrap-datatable datatable">
						  <thead>
							  <tr>';
							  echo $table_header;
						echo '</tr>
						  </thead>   
						  <tbody>';
						  $rowcount=1;
						  $numrows = mysql_num_rows($result);
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
  							echo '<td><input id="input1'.$row['ttNo'].'" class="my-time-input" type="time" value="' . $row['in_time'] . '"></td>';
  							echo '<td><input id="input2'.$row['ttNo'].'" class="my-time-input" type="time" value="' . $row['out_time'] . '"></td>';
  							echo "<td>" . $row['zhanci'] . "</td>";
  							echo '<td>';
  							echo '<a onclick="ajaxsubmit('.$row['ttNo'].');" href="#" title="点击此处提交更改." data-rel="tooltip" class="btn btn-primary">提交</a>&nbsp;';
  							if ($rowcount== $numrows) {
  								echo '<a  href="#" title="终点站后不可添加车站." data-rel="tooltip" class="btn btn-success">添加</a>&nbsp;';
  							} else {
  								echo '<a onclick="setid('.$trainid.','.$row['zhanci'].');" href="#" title="在此站后添加车站." data-rel="tooltip" class="btn btn-success btn-setting">添加</a>&nbsp;';
  							}
  							
  							if ($rowcount==1 || $rowcount== $numrows) {
  								echo '<a onclick="" href="#" title="起始站和终点站不可删除" class="btn btn-warning" data-rel="tooltip">删除</a>';
  							}else {
  								echo '<a onclick="ajaxdelete('.$row['ttNo'].', '.$trainid.', '.$row['zhanci'].');" href="#" title="在此线路中删除该车站" class="btn btn-warning" data-rel="tooltip">删除</a>';
  							}
  							echo '</td>';
  							echo "</tr>";
  							$rowcount++;
  							}
  						echo '</tbody>
					  </table>            
					</div>';


}

?>


<!--mymymy-->
		<hr>

		<div class="modal hide fade" id="myModal">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal">×</button>
				<h3>Add site for the train!</h3>
			</div>
			<!--modal-body-->
			<div class="modal-body" id="my-modal-body">
				<form class="form-horizontal">
							<fieldset>
							  <div class="control-group">
								<label class="control-label" for="focusedInput">选择车站</label>
								<div class="controls">
								  <select name="sitesoption" id="siteoptionid">
								  <?php
								  	$sql = "SELECT * FROM sites";
								  	$result = mysql_query($sql);
								  	while($row = mysql_fetch_array($result)){
								  		echo '<option value='.$row[0].'>'.$row[1].'</option>';
								  	}
								  ?>
								  </select>
								</div>
							  </div>
							  <div class="control-group">
								<label class="control-label" for="focusedInput">到达时间</label>
								<div class="controls">
								  <input class="input-xlarge focused" type="time" name="start_time" id="modaltime1">
								</div>
							  </div>
							  <div class="control-group">
								<label class="control-label" for="focusedInput">距出发日天数</label>
								<div class="controls">
								  <input class="input-xlarge focused" type="text" name="next_day" id="nextday">
								</div>
							  </div>
							  <div class="control-group">
								<label class="control-label" for="focusedInput">开车时间</label>
								<div class="controls">
								  <input class="input-xlarge focused" type="time" name="end_time" id="modaltime2">
								</div>
							  </div>
							  
							  
							  
							</fieldset>
						  </form>
			</div>
			<!--modal-body-end-->
			<div class="modal-footer">
				<button class="btn btn-primary" onclick="submitAddttrow();">Confirm</button>
				<a href="#" class="btn" data-dismiss="modal">Cancel</a>
			</div>
		</div>

		<footer>
			<p class="pull-left">&copy; <a href="http://ctimeprints.github.io" target="_blank">Simon Cao</a> 2015</p>
			<p class="pull-right">Powered by: <a href="index.html">Trains Schedule Searching System</a></p>
		</footer>
		
	</div><!--/.fluid-container-->

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