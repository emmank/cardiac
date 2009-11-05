-- MySQL dump 10.11
--
-- Host: localhost    Database: mycms
-- ------------------------------------------------------
-- Server version	5.0.84

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `groups`
--

DROP TABLE IF EXISTS `groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `groups` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `useradd` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `groups`
--

LOCK TABLES `groups` WRITE;
/*!40000 ALTER TABLE `groups` DISABLE KEYS */;
INSERT INTO `groups` VALUES (1,'admin',NULL),(2,'users',NULL),(3,'vascular',NULL),(4,'echocardiography',NULL),(5,'patient','1'),(6,'kardio dewasa',NULL),(7,'reference',NULL),(8,'kardio anak',NULL);
/*!40000 ALTER TABLE `groups` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `modules`
--

DROP TABLE IF EXISTS `modules`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `modules` (
  `id` int(11) NOT NULL,
  `module` varchar(255) NOT NULL,
  `description` varchar(255) default NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `module` (`module`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `modules`
--

LOCK TABLES `modules` WRITE;
/*!40000 ALTER TABLE `modules` DISABLE KEYS */;
INSERT INTO `modules` VALUES (1,'auth',NULL),(2,'user',NULL),(4,'echocardiography',NULL),(3,'vascular',NULL),(5,'group',NULL),(6,'patient',NULL),(7,'cardio',NULL),(8,'presentStatus',NULL),(9,'vitalSign',NULL),(10,'headface',NULL),(11,'eye',NULL),(12,'ear',NULL),(13,'nose',NULL),(14,'mouth',NULL),(15,'neck',NULL),(16,'thorax',NULL),(17,'paru',NULL),(18,'hearth',NULL),(19,'abdomen',NULL),(20,'anusrectum',NULL),(21,'punggung',NULL),(22,'extermitas',NULL);
/*!40000 ALTER TABLE `modules` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `navigations`
--

DROP TABLE IF EXISTS `navigations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `navigations` (
  `id` int(11) NOT NULL,
  `menus` varchar(100) NOT NULL,
  `parent` int(11) default NULL,
  `weight` int(11) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `menus` (`menus`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `navigations`
--

LOCK TABLES `navigations` WRITE;
/*!40000 ALTER TABLE `navigations` DISABLE KEYS */;
INSERT INTO `navigations` VALUES (1,'node',NULL,0),(2,'user',NULL,1),(3,'admin',NULL,3),(4,'user_view',3,0),(6,'vascular_form',2,5),(5,'user_settings',2,0),(7,'echocardiography_form',2,0),(8,'group_view',3,1),(9,'patient_lists',1,0),(10,'patient_register',2,2),(11,'reference',NULL,2),(12,'ref_present_nutrient',11,0),(13,'ref_present_soreness',11,1),(14,'ref_present_risk_factor',11,2),(15,'ref_present_illness_history',11,3),(16,'ref_vitalsign_type',11,4),(17,'ref_vitalsign_pulse_rythm',11,5),(18,'ref_vitalsign_kesadaran',11,6),(19,'ref_headface_inspections',11,7),(20,'ref_headface_expression',11,8),(21,'ref_headface_hair',11,9),(22,'ref_eye_inspections',11,10),(23,'ref_eye_tekanan_bola_mata',11,11),(24,'ref_eye_kelopak_mata',11,12),(25,'ref_eye_konjunctifa',11,13),(26,'ref_eye_cornea',11,14),(27,'ref_eye_pupil',11,15),(28,'ref_ear_inspections',11,16),(29,'ref_nose_inspections',11,17),(30,'ref_mouth_inspections',11,18),(31,'ref_mouth_lips',11,19),(32,'ref_mouth_gums',11,20),(33,'ref_mouth_tongue',11,21),(34,'ref_neck_inspections',11,22),(35,'ref_thorax_inspections',11,23),(36,'ref_thorax_relief',11,24),(37,'ref_paru_fremitus_raba',11,25),(38,'ref_paru_kiri',11,26),(39,'ref_paru_kanan',11,27),(40,'ref_paru_belakang_kiri',11,28),(41,'ref_paru_belakang_kanan',11,29),(42,'ref_paru_hepar',11,30),(43,'ref_paru_bunyi_pernafasan',11,31),(44,'ref_paru_bunyi_tambahan',11,32),(45,'ref_hearth_inspection',11,33),(46,'ref_hearth_palpation',11,34),(47,'ref_hearth_percussion_top',11,35),(48,'ref_hearth_percussion_bottom',11,36),(49,'ref_hearth_percussion_right',11,37),(50,'ref_hearth_percussion_left',11,38),(51,'ref_hearth_auscultation_sound',11,39),(52,'ref_hearth_localization',11,40),(53,'ref_hearth_intencity',11,41),(54,'ref_hearth_penjalaran',11,42),(55,'ref_hearth_auscultation_kind',11,43),(56,'ref_hearth_auscultation_quality',11,44),(57,'ref_abdomen_relief',11,45),(58,'ref_abdomen_center',11,46),(59,'ref_abdomen_skin',11,47),(60,'ref_abdomen_gerakan_dinding_perut',11,48),(61,'ref_abdomen_hepar',11,49),(62,'ref_abdomen_liver',11,50),(63,'ref_abdomen_ginjal',11,51),(64,'ref_abdomen_perkusi',11,52),(65,'ref_abdomen_auscultation',11,53),(66,'ref_abdomen_peristaltik_usus',11,54),(67,'ref_anusrectum_inspections',11,55),(68,'ref_anusrectum_rectal_touche',11,56),(69,'ref_punggung_inspections',11,57),(70,'ref_punggung_palpations',11,58),(71,'ref_punggung_bunyi_pernafasan',11,59),(72,'ref_punggung_bunyi_tambahan',11,60),(73,'ref_punggung_others',11,61),(74,'ref_extermitas_inspections',11,62),(75,'cardio_dewasa_form',2,3);
/*!40000 ALTER TABLE `navigations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `primary_links`
--

DROP TABLE IF EXISTS `primary_links`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `primary_links` (
  `id` int(11) NOT NULL,
  `menus` varchar(100) NOT NULL,
  `weight` int(11) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `menus` (`menus`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `primary_links`
--

LOCK TABLES `primary_links` WRITE;
/*!40000 ALTER TABLE `primary_links` DISABLE KEYS */;
INSERT INTO `primary_links` VALUES (1,'login',50),(2,'logout',50);
/*!40000 ALTER TABLE `primary_links` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `secondary_links`
--

DROP TABLE IF EXISTS `secondary_links`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `secondary_links` (
  `id` int(11) NOT NULL,
  `menus` varchar(100) NOT NULL,
  `weight` int(11) NOT NULL default '0',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `menus` (`menus`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `secondary_links`
--

LOCK TABLES `secondary_links` WRITE;
/*!40000 ALTER TABLE `secondary_links` DISABLE KEYS */;
/*!40000 ALTER TABLE `secondary_links` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `translations`
--

DROP TABLE IF EXISTS `translations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `translations` (
  `strkey` varchar(255) NOT NULL,
  `indonesia` varchar(255) NOT NULL,
  PRIMARY KEY  (`strkey`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `translations`
--

LOCK TABLES `translations` WRITE;
/*!40000 ALTER TABLE `translations` DISABLE KEYS */;
INSERT INTO `translations` VALUES ('login','masuk'),('logout','keluar');
/*!40000 ALTER TABLE `translations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `userid` varchar(100) NOT NULL,
  `sandi` varchar(255) default NULL,
  `groups` int(11) NOT NULL default '2',
  `theme` varchar(100) NOT NULL default 'default',
  `bahasa` varchar(100) NOT NULL default 'indonesia',
  `sesi` varchar(255) default NULL,
  `timelog` varchar(100) default NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `userid` (`userid`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (0,'admin','de551978f5fe6b7a8bab5591e5a6588fdcad0cb6114ea5',1,'default','indonesia','k5tivo378a9kf4bjl3qu6qgct1','2009-10-18 13:03:24'),(1,'denic','de551978f5fe6b7a8bab5591e5a6588fdcad0cb6114ea5',2,'default','indonesia',NULL,NULL);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-10-18 14:48:08
