-- phpMyAdmin SQL Dump
-- version 4.2.11
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: May 24, 2015 at 04:41 PM
-- Server version: 5.6.21
-- PHP Version: 5.6.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `trains_system`
--

-- --------------------------------------------------------

--
-- Table structure for table `sites`
--

CREATE TABLE IF NOT EXISTS `sites` (
`site_id` int(11) NOT NULL,
  `site_name` varchar(50) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=46 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `sites`
--

INSERT INTO `sites` (`site_id`, `site_name`) VALUES
(3, '上海虹桥'),
(7, '临湘'),
(28, '乌鲁木齐'),
(18, '兖州'),
(29, '包头'),
(42, '北京'),
(1, '北京南'),
(2, '南京南'),
(24, '南昌'),
(9, '咸宁'),
(14, '商丘南'),
(6, '岳阳'),
(25, '常德'),
(43, '广州'),
(40, '怀化南'),
(23, '成都'),
(15, '曹县'),
(10, '武昌'),
(22, '武汉'),
(45, '永州'),
(5, '汨罗'),
(19, '泰山'),
(20, '济南'),
(17, '济宁'),
(12, '潢川'),
(26, '益阳'),
(16, '菏泽'),
(8, '赤壁'),
(44, '郴州'),
(4, '长沙'),
(41, '长沙南'),
(13, '阜阳'),
(11, '麻城');

-- --------------------------------------------------------

--
-- Table structure for table `timetable`
--

CREATE TABLE IF NOT EXISTS `timetable` (
`no` int(11) NOT NULL,
  `site_id` int(11) NOT NULL,
  `train_no` int(11) NOT NULL,
  `in_time` time NOT NULL,
  `out_time` time NOT NULL,
  `next_day` tinyint(4) NOT NULL,
  `zhanci` tinyint(4) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=42 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `timetable`
--

INSERT INTO `timetable` (`no`, `site_id`, `train_no`, `in_time`, `out_time`, `next_day`, `zhanci`) VALUES
(4, 4, 5, '15:45:00', '15:45:00', 0, 1),
(6, 6, 5, '17:17:00', '17:22:00', 0, 3),
(7, 7, 5, '17:47:00', '17:49:00', 0, 4),
(8, 8, 5, '18:43:00', '18:45:00', 0, 5),
(9, 9, 5, '19:12:00', '19:35:00', 0, 6),
(10, 10, 5, '20:27:00', '20:47:00', 0, 7),
(11, 11, 5, '22:22:00', '22:28:00', 0, 8),
(12, 12, 5, '23:38:00', '23:40:00', 0, 9),
(13, 13, 5, '01:41:00', '02:02:00', 1, 10),
(14, 14, 5, '04:17:00', '04:22:00', 1, 11),
(15, 15, 5, '04:58:00', '05:00:00', 1, 12),
(16, 16, 5, '05:30:00', '05:37:00', 1, 13),
(17, 17, 5, '06:54:00', '06:56:00', 1, 14),
(18, 18, 5, '07:26:00', '07:49:00', 1, 15),
(19, 19, 5, '08:46:00', '08:50:00', 1, 16),
(20, 20, 5, '09:47:00', '09:47:00', 1, 17),
(23, 25, 8, '08:58:00', '08:58:00', 0, 1),
(24, 4, 8, '11:40:00', '11:40:00', 0, 3),
(28, 5, 5, '16:33:00', '16:34:00', 0, 2),
(29, 26, 8, '10:01:00', '10:03:00', 0, 2),
(34, 40, 11, '22:41:00', '22:41:00', 0, 1),
(35, 41, 11, '23:59:00', '23:59:00', 0, 2),
(36, 4, 12, '19:37:00', '19:37:00', 0, 1),
(37, 42, 12, '09:42:00', '09:42:00', 1, 4),
(38, 6, 12, '20:54:00', '20:57:00', 0, 2),
(39, 10, 12, '23:05:00', '23:11:00', 0, 3),
(40, 41, 13, '11:02:00', '11:02:00', 0, 1),
(41, 43, 13, '17:59:00', '17:59:00', 0, 2);

-- --------------------------------------------------------

--
-- Table structure for table `trains`
--

CREATE TABLE IF NOT EXISTS `trains` (
`no` int(11) NOT NULL,
  `train_name` varchar(10) NOT NULL,
  `depart_time` time NOT NULL,
  `arrival_time` time NOT NULL,
  `count_day` tinyint(4) NOT NULL,
  `departation` varchar(50) NOT NULL,
  `destination` varchar(50) NOT NULL
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;

--
-- Dumping data for table `trains`
--

INSERT INTO `trains` (`no`, `train_name`, `depart_time`, `arrival_time`, `count_day`, `departation`, `destination`) VALUES
(5, 'K1074', '15:46:00', '09:47:00', 2, '4', '20'),
(8, 'K9091', '08:58:00', '11:40:00', 1, '25', '4'),
(11, 'G6414', '22:41:00', '22:41:00', 1, '40', '41'),
(12, 'Z18', '19:37:00', '09:42:00', 2, '4', '42'),
(13, 'D666', '12:02:00', '17:59:00', 1, '41', '43');

-- --------------------------------------------------------

--
-- Table structure for table `usr`
--

CREATE TABLE IF NOT EXISTS `usr` (
  `name` varchar(50) NOT NULL,
  `password` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `usr`
--

INSERT INTO `usr` (`name`, `password`) VALUES
('233', '233'),
('666', '666'),
('886', '886'),
('999', '999');

-- --------------------------------------------------------

--
-- Stand-in structure for view `view_timetable`
--
CREATE TABLE IF NOT EXISTS `view_timetable` (
`site_name` varchar(50)
,`train_name` varchar(10)
,`in_time` time
,`out_time` time
,`next_day` tinyint(4)
,`zhanci` tinyint(4)
);
-- --------------------------------------------------------

--
-- Stand-in structure for view `view_trains`
--
CREATE TABLE IF NOT EXISTS `view_trains` (
`no` int(11)
,`train_name` varchar(10)
,`depart_time` time
,`arrival_time` time
,`count_day` tinyint(4)
,`site_name_1` varchar(50)
,`site_name_2` varchar(50)
);
-- --------------------------------------------------------

--
-- Structure for view `view_timetable`
--
DROP TABLE IF EXISTS `view_timetable`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `view_timetable` AS select `sites`.`site_name` AS `site_name`,`trains`.`train_name` AS `train_name`,`timetable`.`in_time` AS `in_time`,`timetable`.`out_time` AS `out_time`,`timetable`.`next_day` AS `next_day`,`timetable`.`zhanci` AS `zhanci` from ((`sites` join `trains`) join `timetable`) where ((`sites`.`site_id` = `timetable`.`site_id`) and (`trains`.`no` = `timetable`.`train_no`));

-- --------------------------------------------------------

--
-- Structure for view `view_trains`
--
DROP TABLE IF EXISTS `view_trains`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `view_trains` AS select `trains`.`no` AS `no`,`trains`.`train_name` AS `train_name`,`trains`.`depart_time` AS `depart_time`,`trains`.`arrival_time` AS `arrival_time`,`trains`.`count_day` AS `count_day`,`sites_1`.`site_name` AS `site_name_1`,`sites_2`.`site_name` AS `site_name_2` from ((`trains` join `sites` `sites_1`) join `sites` `sites_2`) where ((`trains`.`departation` = `sites_1`.`site_id`) and (`trains`.`destination` = `sites_2`.`site_id`));

--
-- Indexes for dumped tables
--

--
-- Indexes for table `sites`
--
ALTER TABLE `sites`
 ADD PRIMARY KEY (`site_id`), ADD UNIQUE KEY `site_name` (`site_name`), ADD UNIQUE KEY `site_id` (`site_id`), ADD UNIQUE KEY `site_id_2` (`site_id`,`site_name`);

--
-- Indexes for table `timetable`
--
ALTER TABLE `timetable`
 ADD PRIMARY KEY (`no`);

--
-- Indexes for table `trains`
--
ALTER TABLE `trains`
 ADD PRIMARY KEY (`no`), ADD UNIQUE KEY `train_no` (`train_name`);

--
-- Indexes for table `usr`
--
ALTER TABLE `usr`
 ADD PRIMARY KEY (`name`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `sites`
--
ALTER TABLE `sites`
MODIFY `site_id` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=46;
--
-- AUTO_INCREMENT for table `timetable`
--
ALTER TABLE `timetable`
MODIFY `no` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=42;
--
-- AUTO_INCREMENT for table `trains`
--
ALTER TABLE `trains`
MODIFY `no` int(11) NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=14;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
