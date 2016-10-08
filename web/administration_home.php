<?php
session_start();

// 定义变量并设置为空值
$username = $password ="";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $username = test_input($_POST["username"]);
  $password = test_input($_POST["password"]);

  $_SESSION['temp_user'] = $username;
}

function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

//get user state

$meta_tag2jump = "";

if(isset($_SESSION['temp_user']))
  {

  }
else
  {
	// header("location:login.php");
	$meta_tag2jump = '<meta http-equiv="refresh" content="0;login.php">';
  }


$con = mysql_connect("localhost","trainsAdmin","nwGXxXjTJzVJLuS4");
if (!$con)
  {
  die('请检查: ' . mysql_error());
  }

mysql_select_db("trains_system", $con);

// setcookie("username", $username, time()+500);
// setcookie("password", $password, time()+500);



mysql_close($con);
?>



<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Home: Trains Schedule Searching System</title>
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<meta name="description" content="Database project, by Simon Cao.">
	<meta name="author" content="Simon Cao">

	<?php echo $meta_tag2jump;?>

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

<script type="text/javascript">
function validate_required(formid)
{
	var x=document.getElementById(formid).getElementsByTagName("input");
	for (var i = 0; i < x.length; i++) {
		if (x[i].value==null||x[i].value==""){
			alert("字段不能为空！");
			return false;
		}
		else {
			continue;
		}
	};
	return true;
}

	</script>

<!-- get search result by ajax-->
<script type="text/javascript">
function showsearchresult()
{
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

    document.getElementById("to-set-table").innerHTML=xmlhttp.responseText;
    }
  }
xmlhttp.open("GET","ajax_seachresult.php",true);
xmlhttp.send();
}
</script>

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
						<li><a class="ajax-link" href="administration_add.php"><i class="icon-eye-open"></i><span class="hidden-tablet"> Add Info</span></a></li>
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
						<a href="index.html">Home</a> <span class="divider">/</span>
					</li>
					<li>
						<a href="#">Search</a>
					</li>
				</ul>
			</div>


			<!-- 20150418 -->
			<?php

		echo "<h1>Welcome, ".$_SESSION['temp_user']."!</h1>";

			?>


					<div class="box-content">
						<ul class="nav nav-tabs" id="myTab">
							<li class="active"><a href="#site2site"><h3>站站查询</h3></a></li>
							<li class=""><a href="#searchtrain"><h3>车次查询</h3></a></li>
							<li class=""><a href="#searchsite"><h3>车站查询</h3></a></li>
						</ul>
						 
						<div id="myTabContent" class="tab-content">
							<div class="tab-pane active" id="site2site">
								<form class="form-horizontal" action="admin_searchresult.php" method="get" onsubmit="return validate_required(this.id)" id="site2siteform">
									<fieldset>
									<div class="control-group">
										<span class="add-on">出发地</span>
										<input id="prependedInput" size="16" type="text" name="depart_point">
									</div>
									<div class="control-group">
										<span class="add-on">目的地</span>
										<input id="prependedInput" size="16" type="text" name="dest_point">
									</div>
									<div class="form-actions">
										<button type="submit" class="btn btn-primary" name="searchbtn" value="end2endsearch">搜索</button>
									</div>
									</fieldset>
								</form>

							</div>
							<div class="tab-pane" id="searchtrain">
								<form class="form-horizontal" action="admin_searchresult.php" method="get" onsubmit="return validate_required(this.id)" id="searchtrainform">
									<fieldset>
									<span class="add-on">车次</span>
									<input id="prependedInput" size="16" type="text" name="trainname">
									<div class="form-actions">
									<button type="submit" class="btn btn-primary" name="searchbtn" value="trainsearch">搜索</button>
									</div>
									</fieldset>
								</form>

							</div>
							<div class="tab-pane" id="searchsite">
								<form class="form-horizontal" action="admin_searchresult.php" method="get" onsubmit="return validate_required(this.id)" id="searchsiteform">
									<fieldset>
									<span class="add-on">车站</span>
									<input id="prependedInput" size="16" type="text" name="sitename">
									<div class="form-actions">
									<button type="submit" class="btn btn-primary" name="searchbtn" value="sitesearch">搜索</button>
									</div>
									</fieldset>
								</form>
							</div>
						</div>
					</div>

			<div id="to-set-table">No1017</div>



				
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