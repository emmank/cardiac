-- MySQL dump 10.11
--
-- Host: localhost    Database: layanan_kesehatan
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
-- Table structure for table `abdomen`
--

DROP TABLE IF EXISTS `abdomen`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `abdomen` (
  `id` int(11) NOT NULL,
  `relief` int(11) default NULL,
  `center` int(11) default NULL,
  `inspeksi_kulit` varchar(255) default NULL,
  `gerakan_dinding_perut` int(11) default NULL,
  `palpasi_hepar` int(11) default NULL,
  `palpasi_hepar_derajat_pembesaran` varchar(255) default NULL,
  `palpasi_hepar_konsistensi` varchar(255) default NULL,
  `palpasi_hepar_permukaan` varchar(255) default NULL,
  `palpasi_hepar_tepi` varchar(255) default NULL,
  `palpasi_hepar_nyeri_tekan` tinyint(1) default NULL,
  `palpasi_liver` int(11) default NULL,
  `palpasi_liver_derajat_pembesaran` varchar(255) default NULL,
  `palpasi_liver_konsistensi` varchar(255) default NULL,
  `palpasi_liver_permukaan` varchar(255) default NULL,
  `palpasi_liver_tepi` varchar(255) default NULL,
  `palpasi_liver_nyeri_tekan` tinyint(1) default NULL,
  `palpasi_ginjal` int(11) default NULL,
  `ballottement` tinyint(1) default NULL,
  `perkusi` varchar(255) default NULL,
  `auscultation` varchar(255) default NULL,
  `peristaltik_usus` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `abdomen`
--

LOCK TABLES `abdomen` WRITE;
/*!40000 ALTER TABLE `abdomen` DISABLE KEYS */;
/*!40000 ALTER TABLE `abdomen` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `anus_rectum`
--

DROP TABLE IF EXISTS `anus_rectum`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `anus_rectum` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  `rectal_touche` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `anus_rectum`
--

LOCK TABLES `anus_rectum` WRITE;
/*!40000 ALTER TABLE `anus_rectum` DISABLE KEYS */;
/*!40000 ALTER TABLE `anus_rectum` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bagian`
--

DROP TABLE IF EXISTS `bagian`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bagian` (
  `id` int(11) NOT NULL,
  `bagian` varchar(100) NOT NULL,
  `tableuse` varchar(100) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bagian`
--

LOCK TABLES `bagian` WRITE;
/*!40000 ALTER TABLE `bagian` DISABLE KEYS */;
INSERT INTO `bagian` VALUES (1,'vascular','vascular'),(2,'echocardiography','echocardiography'),(3,'cardio_dewasa','cardio'),(4,'cardio_anak','cardio');
/*!40000 ALTER TABLE `bagian` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `cardio`
--

DROP TABLE IF EXISTS `cardio`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `cardio` (
  `id` int(11) NOT NULL,
  `teens` tinyint(1) NOT NULL default '0',
  `tgl` date NOT NULL,
  `patients` int(11) NOT NULL,
  `nomor` varchar(100) default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` varchar(100) NOT NULL,
  `updated` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cardio`
--

LOCK TABLES `cardio` WRITE;
/*!40000 ALTER TABLE `cardio` DISABLE KEYS */;
/*!40000 ALTER TABLE `cardio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ear`
--

DROP TABLE IF EXISTS `ear`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ear` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ear`
--

LOCK TABLES `ear` WRITE;
/*!40000 ALTER TABLE `ear` DISABLE KEYS */;
/*!40000 ALTER TABLE `ear` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `echocardiography`
--

DROP TABLE IF EXISTS `echocardiography`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `echocardiography` (
  `id` int(11) NOT NULL,
  `patients` int(11) NOT NULL,
  `tgl_periksa` date NOT NULL,
  `description` varchar(255) default NULL,
  `conclusion` varchar(255) default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(100) default NULL,
  `cd` varchar(255) default NULL,
  `aortie_root_dimension` varchar(100) default NULL,
  `aortie_valve_excursion` varchar(100) default NULL,
  `left_atrium` varchar(100) default NULL,
  `ivs_thickness` varchar(100) default NULL,
  `mitral_valve_excursion` varchar(100) default NULL,
  `left_ventricular_posterior_wall_thickness` varchar(100) default NULL,
  `right_ventricular_internal_dimension` varchar(100) default NULL,
  `left_ventricular_end_diastolic_dimension` varchar(100) default NULL,
  `left_ventricular_end_systolic_dimension` varchar(100) default NULL,
  `left_ventricular_end_diastolic_volume` varchar(100) default NULL,
  `left_ventricular_end_systolic_volume` varchar(100) default NULL,
  `ejection_fraction` varchar(100) default NULL,
  `velocity_circumfrential_shortening` varchar(100) default NULL,
  `shortening_fraction` varchar(100) default NULL,
  `velocity` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `echocardiography`
--

LOCK TABLES `echocardiography` WRITE;
/*!40000 ALTER TABLE `echocardiography` DISABLE KEYS */;
/*!40000 ALTER TABLE `echocardiography` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `extermitas`
--

DROP TABLE IF EXISTS `extermitas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `extermitas` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `extermitas`
--

LOCK TABLES `extermitas` WRITE;
/*!40000 ALTER TABLE `extermitas` DISABLE KEYS */;
/*!40000 ALTER TABLE `extermitas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `eye`
--

DROP TABLE IF EXISTS `eye`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `eye` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  `tekanan_bola_mata` int(11) default NULL,
  `kelopak_mata` int(11) default NULL,
  `konjuctifa` int(11) default NULL,
  `cornea` int(11) default NULL,
  `pupil` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `eye`
--

LOCK TABLES `eye` WRITE;
/*!40000 ALTER TABLE `eye` DISABLE KEYS */;
/*!40000 ALTER TABLE `eye` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `head_n_face`
--

DROP TABLE IF EXISTS `head_n_face`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `head_n_face` (
  `id` int(11) NOT NULL,
  `expression` int(11) default NULL,
  `hair` int(11) default NULL,
  `inspections` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `head_n_face`
--

LOCK TABLES `head_n_face` WRITE;
/*!40000 ALTER TABLE `head_n_face` DISABLE KEYS */;
/*!40000 ALTER TABLE `head_n_face` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `hearth`
--

DROP TABLE IF EXISTS `hearth`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `hearth` (
  `id` int(11) NOT NULL,
  `inspection` varchar(255) default NULL,
  `palpation` varchar(255) default NULL,
  `percussion_top` int(11) default NULL,
  `percussion_bottom` int(11) default NULL,
  `percussion_left` int(11) default NULL,
  `percussion_right` int(11) default NULL,
  `bunyi_jantung` varchar(255) default NULL,
  `auscultation_sound` varchar(255) default NULL,
  `localization` int(11) default NULL,
  `intencity` int(11) default NULL,
  `penjalaran` int(11) default NULL,
  `kind` int(11) default NULL,
  `quality` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `hearth`
--

LOCK TABLES `hearth` WRITE;
/*!40000 ALTER TABLE `hearth` DISABLE KEYS */;
/*!40000 ALTER TABLE `hearth` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kunjungan`
--

DROP TABLE IF EXISTS `kunjungan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `kunjungan` (
  `id` int(11) NOT NULL,
  `pukul` datetime NOT NULL,
  `patients` int(11) NOT NULL,
  `bagian` varchar(255) NOT NULL,
  `nourut` int(11) NOT NULL,
  `doneby` int(11) default NULL,
  `keluhan` varchar(255) default NULL,
  `inputer` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kunjungan`
--

LOCK TABLES `kunjungan` WRITE;
/*!40000 ALTER TABLE `kunjungan` DISABLE KEYS */;
INSERT INTO `kunjungan` VALUES (1,'2009-10-17 16:09:39',1,'vascular',1,NULL,'Nyeri Punggung','1'),(2,'2009-10-17 16:09:47',2,'echocardiography',1,NULL,'Sakit kepala puyeng','0'),(3,'2009-10-03 21:26:59',3,'echocardiography',1,0,'sdljlk','0'),(4,'2009-10-17 16:09:54',4,'cardio_dewasa',1,NULL,'Sakit perut... sudah 2 hari belum makan kasihanilah pak...','0'),(5,'2009-10-17 16:09:57',5,'cardio_dewasa',2,NULL,'Batuk-batuk berdahak','0'),(6,'2009-10-17 16:10:01',6,'cardio_anak',1,NULL,'Berak-berak terus nggak mau berhenti','0');
/*!40000 ALTER TABLE `kunjungan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mouth`
--

DROP TABLE IF EXISTS `mouth`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `mouth` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  `lips` int(11) default NULL,
  `gums` int(11) default NULL,
  `tongue` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mouth`
--

LOCK TABLES `mouth` WRITE;
/*!40000 ALTER TABLE `mouth` DISABLE KEYS */;
/*!40000 ALTER TABLE `mouth` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `neck`
--

DROP TABLE IF EXISTS `neck`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `neck` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `neck`
--

LOCK TABLES `neck` WRITE;
/*!40000 ALTER TABLE `neck` DISABLE KEYS */;
/*!40000 ALTER TABLE `neck` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `nose`
--

DROP TABLE IF EXISTS `nose`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `nose` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `nose`
--

LOCK TABLES `nose` WRITE;
/*!40000 ALTER TABLE `nose` DISABLE KEYS */;
/*!40000 ALTER TABLE `nose` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `paru`
--

DROP TABLE IF EXISTS `paru`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `paru` (
  `id` int(11) NOT NULL,
  `fremitus_raba` int(11) default NULL,
  `nyeri_tekan` tinyint(1) default NULL,
  `paru_kiri` int(11) default NULL,
  `paru_kanan` int(11) default NULL,
  `batas_paru_belakang_kiri` int(11) default NULL,
  `batas_paru_belakang_kanan` int(11) default NULL,
  `batas_paru_hepar` int(11) default NULL,
  `bunyi_pernafasan` int(11) default NULL,
  `bunyi_tambahan` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `paru`
--

LOCK TABLES `paru` WRITE;
/*!40000 ALTER TABLE `paru` DISABLE KEYS */;
/*!40000 ALTER TABLE `paru` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `patients`
--

DROP TABLE IF EXISTS `patients`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `patients` (
  `id` int(11) NOT NULL,
  `nomor` int(11) default NULL,
  `nama` varchar(255) NOT NULL,
  `kelamin` smallint(1) NOT NULL,
  `tp_lahir` varchar(255) default NULL,
  `tgl_lahir` date default NULL,
  `gol_darah` char(2) default NULL,
  `alamat` varchar(255) default NULL,
  `kota` varchar(100) default NULL,
  `propinsi` varchar(100) default NULL,
  `no_identitas` varchar(255) default NULL,
  `sandi` varchar(255) default NULL,
  `inputtime` varchar(100) default NULL,
  `sesi` varchar(255) default NULL,
  `timelog` datetime default NULL,
  `strnum` varchar(100) default NULL,
  `groups` int(11) default NULL,
  `inputer` varchar(100) NOT NULL,
  `updated` varchar(255) default NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `nomor` (`nomor`),
  UNIQUE KEY `strnum` (`strnum`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `patients`
--

LOCK TABLES `patients` WRITE;
/*!40000 ALTER TABLE `patients` DISABLE KEYS */;
INSERT INTO `patients` VALUES (1,1,'Sutiyem',0,'Blitar','1971-09-13','O','Jl. Raya Keras Km 21','Blitar','Jawa Timur','dlkfjlkkdfnl',NULL,'2009-09-29 10:07:07',NULL,NULL,'00001',NULL,'1',NULL),(2,2,'Karjo',1,'Sinjai','1982-08-15','B','Jl. Rusa No. 15','Makassar','Sulawesi Selatan','kdjfnkjdg',NULL,'2009-09-29 10:54:57',NULL,NULL,'00002',NULL,'0',NULL),(3,3,'Alkflk',0,'kdjgl','1970-01-01','A','lkfjglkdjgk','kjdlkjl','kldsjldsk','ldkjglk',NULL,'2009-10-03 21:26:59',NULL,NULL,'00003',NULL,'0',NULL),(4,4,'Kurtep',0,'Mbanyakan','1970-04-02','O','Jl. Meranti No.33','Makassar','Sulawesi Selatan','ldjfgildjfgijrig',NULL,'2009-10-16 15:05:50',NULL,NULL,'00004',NULL,'0',NULL),(5,5,'Agung Baskoro',1,'Jakarta','1977-06-05','AB','Jl. Tanjung No 9','Makassar','Sulawesi Selatan','lkjdglkjdlfsg',NULL,'2009-10-16 15:09:57',NULL,NULL,'00005',NULL,'0',NULL),(6,6,'Robert Rambalangi',1,'Toraja','2000-05-10','B','Perumahan Budi Daya Permai Blok B No. 21','Makassar','Sulawesi Selatan','kdgjljdg',NULL,'2009-10-16 16:14:23',NULL,NULL,'00006',NULL,'0',NULL);
/*!40000 ALTER TABLE `patients` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `present_status`
--

DROP TABLE IF EXISTS `present_status`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `present_status` (
  `id` int(11) NOT NULL,
  `tall` varchar(100) default NULL,
  `weight` varchar(100) default NULL,
  `tension` varchar(100) default NULL,
  `catched` datetime default NULL,
  `nutrient` int(11) default NULL,
  `main_soreness` int(11) default NULL,
  `risk_factor` varchar(255) default NULL,
  `ilness_history` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `present_status`
--

LOCK TABLES `present_status` WRITE;
/*!40000 ALTER TABLE `present_status` DISABLE KEYS */;
/*!40000 ALTER TABLE `present_status` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `punggung`
--

DROP TABLE IF EXISTS `punggung`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `punggung` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  `palpations` varchar(255) default NULL,
  `bunyi_pernafasan` int(11) default NULL,
  `bunyi_tambahan` int(11) default NULL,
  `others` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `punggung`
--

LOCK TABLES `punggung` WRITE;
/*!40000 ALTER TABLE `punggung` DISABLE KEYS */;
/*!40000 ALTER TABLE `punggung` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_auscultation`
--

DROP TABLE IF EXISTS `ref_abdomen_auscultation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_auscultation` (
  `id` int(11) NOT NULL,
  `auscultation` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_auscultation`
--

LOCK TABLES `ref_abdomen_auscultation` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_auscultation` DISABLE KEYS */;
INSERT INTO `ref_abdomen_auscultation` VALUES (1,'gerakan cairan'),(2,'bising pembuluh darah');
/*!40000 ALTER TABLE `ref_abdomen_auscultation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_center`
--

DROP TABLE IF EXISTS `ref_abdomen_center`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_center` (
  `id` int(11) NOT NULL,
  `center` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_center`
--

LOCK TABLES `ref_abdomen_center` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_center` DISABLE KEYS */;
INSERT INTO `ref_abdomen_center` VALUES (1,'Normal'),(2,'Menonjol kecil'),(3,'Menonjol besar disertai konsistensi keras');
/*!40000 ALTER TABLE `ref_abdomen_center` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_gerakan_dinding_perut`
--

DROP TABLE IF EXISTS `ref_abdomen_gerakan_dinding_perut`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_gerakan_dinding_perut` (
  `id` int(11) NOT NULL,
  `gerakan_dinding_perut` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_gerakan_dinding_perut`
--

LOCK TABLES `ref_abdomen_gerakan_dinding_perut` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_gerakan_dinding_perut` DISABLE KEYS */;
INSERT INTO `ref_abdomen_gerakan_dinding_perut` VALUES (1,'Teratur dan bebas bergerak'),(2,'Terlambat sebagian'),(3,'Seluruh tampak tertinggal'),(4,'Gerakan didaerah epigastrium sesuai pulsasi jantung'),(5,'Tampak pulsasi aorta abdominalis'),(6,'Tampak gerakan usus');
/*!40000 ALTER TABLE `ref_abdomen_gerakan_dinding_perut` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_ginjal`
--

DROP TABLE IF EXISTS `ref_abdomen_ginjal`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_ginjal` (
  `id` int(11) NOT NULL,
  `ginjal` varchar(255) NOT NULL,
  `type` varchar(50) NOT NULL default 'text',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_ginjal`
--

LOCK TABLES `ref_abdomen_ginjal` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_ginjal` DISABLE KEYS */;
INSERT INTO `ref_abdomen_ginjal` VALUES (1,'teraba/tidak','radio'),(2,'ballottement','checkbox');
/*!40000 ALTER TABLE `ref_abdomen_ginjal` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_hepar`
--

DROP TABLE IF EXISTS `ref_abdomen_hepar`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_hepar` (
  `id` int(11) NOT NULL,
  `hepar` varchar(255) NOT NULL,
  `type` varchar(50) NOT NULL default 'text',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_hepar`
--

LOCK TABLES `ref_abdomen_hepar` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_hepar` DISABLE KEYS */;
INSERT INTO `ref_abdomen_hepar` VALUES (1,'teraba/tidak','radio'),(2,'derajat pembesaran','text'),(3,'konsistensi','text'),(4,'permukaan','text'),(5,'tepi','text'),(6,'nyeri tekan','checkbox');
/*!40000 ALTER TABLE `ref_abdomen_hepar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_liver`
--

DROP TABLE IF EXISTS `ref_abdomen_liver`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_liver` (
  `id` int(11) NOT NULL,
  `liver` varchar(255) NOT NULL,
  `type` varchar(50) NOT NULL default 'text',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_liver`
--

LOCK TABLES `ref_abdomen_liver` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_liver` DISABLE KEYS */;
INSERT INTO `ref_abdomen_liver` VALUES (1,'teraba/tidak','radio'),(2,'derajat pembesaran','text'),(3,'konsistensi','text'),(4,'permukaan','text'),(5,'tepi','text'),(6,'nyeri tekan','checkbox');
/*!40000 ALTER TABLE `ref_abdomen_liver` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_peristaltik_usus`
--

DROP TABLE IF EXISTS `ref_abdomen_peristaltik_usus`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_peristaltik_usus` (
  `id` int(11) NOT NULL,
  `peristaltik_usus` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_peristaltik_usus`
--

LOCK TABLES `ref_abdomen_peristaltik_usus` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_peristaltik_usus` DISABLE KEYS */;
INSERT INTO `ref_abdomen_peristaltik_usus` VALUES (1,'Ada kesan normal'),(2,'Ada kesan meningkat'),(3,'Ada kesan menurun'),(4,'Tidak ada');
/*!40000 ALTER TABLE `ref_abdomen_peristaltik_usus` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_perkusi`
--

DROP TABLE IF EXISTS `ref_abdomen_perkusi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_perkusi` (
  `id` int(11) NOT NULL,
  `perkusi` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_perkusi`
--

LOCK TABLES `ref_abdomen_perkusi` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_perkusi` DISABLE KEYS */;
INSERT INTO `ref_abdomen_perkusi` VALUES (1,'timpani'),(2,'pekak');
/*!40000 ALTER TABLE `ref_abdomen_perkusi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_relief`
--

DROP TABLE IF EXISTS `ref_abdomen_relief`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_relief` (
  `id` int(11) NOT NULL,
  `relief` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_relief`
--

LOCK TABLES `ref_abdomen_relief` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_relief` DISABLE KEYS */;
INSERT INTO `ref_abdomen_relief` VALUES (1,'Simetris'),(2,'Simetris dan membesar'),(3,'Simetris dan cekung'),(4,'Asimetris'),(5,'Pembesaran setempat');
/*!40000 ALTER TABLE `ref_abdomen_relief` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_skin`
--

DROP TABLE IF EXISTS `ref_abdomen_skin`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_skin` (
  `id` int(11) NOT NULL,
  `skin` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_skin`
--

LOCK TABLES `ref_abdomen_skin` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_skin` DISABLE KEYS */;
INSERT INTO `ref_abdomen_skin` VALUES (1,'petichian'),(2,'icterus'),(3,'striae'),(4,'caput medusa'),(5,'rose spots');
/*!40000 ALTER TABLE `ref_abdomen_skin` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_anusrectum_inspections`
--

DROP TABLE IF EXISTS `ref_anusrectum_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_anusrectum_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_anusrectum_inspections`
--

LOCK TABLES `ref_anusrectum_inspections` WRITE;
/*!40000 ALTER TABLE `ref_anusrectum_inspections` DISABLE KEYS */;
INSERT INTO `ref_anusrectum_inspections` VALUES (1,'hemorroid'),(2,'fistula'),(3,'fissure');
/*!40000 ALTER TABLE `ref_anusrectum_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_anusrectum_rectal_touche`
--

DROP TABLE IF EXISTS `ref_anusrectum_rectal_touche`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_anusrectum_rectal_touche` (
  `id` int(11) NOT NULL,
  `rectal_touche` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_anusrectum_rectal_touche`
--

LOCK TABLES `ref_anusrectum_rectal_touche` WRITE;
/*!40000 ALTER TABLE `ref_anusrectum_rectal_touche` DISABLE KEYS */;
INSERT INTO `ref_anusrectum_rectal_touche` VALUES (1,'mukosa'),(2,'tumor-tumor'),(3,'feses'),(4,'stricture'),(5,'nyeri tekan');
/*!40000 ALTER TABLE `ref_anusrectum_rectal_touche` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ear_inspections`
--

DROP TABLE IF EXISTS `ref_ear_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ear_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ear_inspections`
--

LOCK TABLES `ref_ear_inspections` WRITE;
/*!40000 ALTER TABLE `ref_ear_inspections` DISABLE KEYS */;
INSERT INTO `ref_ear_inspections` VALUES (1,'tophil'),(2,'lubang kanan'),(3,'lubang kiri'),(4,'Nyeri tekan di prosesus mastoideus'),(5,'otorhoe kanan'),(6,'otorhoe kiri'),(7,'pendengaran');
/*!40000 ALTER TABLE `ref_ear_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_extermitas_inspections`
--

DROP TABLE IF EXISTS `ref_extermitas_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_extermitas_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_extermitas_inspections`
--

LOCK TABLES `ref_extermitas_inspections` WRITE;
/*!40000 ALTER TABLE `ref_extermitas_inspections` DISABLE KEYS */;
INSERT INTO `ref_extermitas_inspections` VALUES (1,'udema'),(2,'ikterus'),(3,'sianosis'),(4,'petichian');
/*!40000 ALTER TABLE `ref_extermitas_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_eye_cornea`
--

DROP TABLE IF EXISTS `ref_eye_cornea`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_eye_cornea` (
  `id` int(11) NOT NULL,
  `cornea` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_eye_cornea`
--

LOCK TABLES `ref_eye_cornea` WRITE;
/*!40000 ALTER TABLE `ref_eye_cornea` DISABLE KEYS */;
INSERT INTO `ref_eye_cornea` VALUES (1,'jernih'),(2,'keruh');
/*!40000 ALTER TABLE `ref_eye_cornea` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_eye_inspections`
--

DROP TABLE IF EXISTS `ref_eye_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_eye_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_eye_inspections`
--

LOCK TABLES `ref_eye_inspections` WRITE;
/*!40000 ALTER TABLE `ref_eye_inspections` DISABLE KEYS */;
INSERT INTO `ref_eye_inspections` VALUES (1,'eksopthalmus'),(2,'enopthalmus'),(3,'gerakan nistagmus'),(4,'sklera ikterus'),(5,'sklera hemorragik');
/*!40000 ALTER TABLE `ref_eye_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_eye_kelopak_mata`
--

DROP TABLE IF EXISTS `ref_eye_kelopak_mata`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_eye_kelopak_mata` (
  `id` int(11) NOT NULL,
  `kelopak_mata` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_eye_kelopak_mata`
--

LOCK TABLES `ref_eye_kelopak_mata` WRITE;
/*!40000 ALTER TABLE `ref_eye_kelopak_mata` DISABLE KEYS */;
INSERT INTO `ref_eye_kelopak_mata` VALUES (1,'normal'),(2,'ptosis'),(3,'xanthelasma'),(4,'edema'),(5,'perdarahan pleparitis');
/*!40000 ALTER TABLE `ref_eye_kelopak_mata` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_eye_konjunctifa`
--

DROP TABLE IF EXISTS `ref_eye_konjunctifa`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_eye_konjunctifa` (
  `id` int(11) NOT NULL,
  `konjunctifa` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_eye_konjunctifa`
--

LOCK TABLES `ref_eye_konjunctifa` WRITE;
/*!40000 ALTER TABLE `ref_eye_konjunctifa` DISABLE KEYS */;
INSERT INTO `ref_eye_konjunctifa` VALUES (1,'anemis'),(2,'sianosis');
/*!40000 ALTER TABLE `ref_eye_konjunctifa` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_eye_pupil`
--

DROP TABLE IF EXISTS `ref_eye_pupil`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_eye_pupil` (
  `id` int(11) NOT NULL,
  `pupil` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_eye_pupil`
--

LOCK TABLES `ref_eye_pupil` WRITE;
/*!40000 ALTER TABLE `ref_eye_pupil` DISABLE KEYS */;
INSERT INTO `ref_eye_pupil` VALUES (1,'isokor'),(2,'anisokor');
/*!40000 ALTER TABLE `ref_eye_pupil` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_eye_tekanan_bola_mata`
--

DROP TABLE IF EXISTS `ref_eye_tekanan_bola_mata`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_eye_tekanan_bola_mata` (
  `id` int(11) NOT NULL,
  `tekanan_bola_mata` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_eye_tekanan_bola_mata`
--

LOCK TABLES `ref_eye_tekanan_bola_mata` WRITE;
/*!40000 ALTER TABLE `ref_eye_tekanan_bola_mata` DISABLE KEYS */;
INSERT INTO `ref_eye_tekanan_bola_mata` VALUES (1,'normal'),(2,'meningkat'),(3,'menurun');
/*!40000 ALTER TABLE `ref_eye_tekanan_bola_mata` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_headface_expression`
--

DROP TABLE IF EXISTS `ref_headface_expression`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_headface_expression` (
  `id` int(11) NOT NULL,
  `expression` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_headface_expression`
--

LOCK TABLES `ref_headface_expression` WRITE;
/*!40000 ALTER TABLE `ref_headface_expression` DISABLE KEYS */;
/*!40000 ALTER TABLE `ref_headface_expression` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_headface_hair`
--

DROP TABLE IF EXISTS `ref_headface_hair`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_headface_hair` (
  `id` int(11) NOT NULL,
  `hair` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_headface_hair`
--

LOCK TABLES `ref_headface_hair` WRITE;
/*!40000 ALTER TABLE `ref_headface_hair` DISABLE KEYS */;
/*!40000 ALTER TABLE `ref_headface_hair` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_headface_inspections`
--

DROP TABLE IF EXISTS `ref_headface_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_headface_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_headface_inspections`
--

LOCK TABLES `ref_headface_inspections` WRITE;
/*!40000 ALTER TABLE `ref_headface_inspections` DISABLE KEYS */;
INSERT INTO `ref_headface_inspections` VALUES (1,'simetris'),(2,'deformitas'),(3,'gerakan');
/*!40000 ALTER TABLE `ref_headface_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_auscultation_kind`
--

DROP TABLE IF EXISTS `ref_hearth_auscultation_kind`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_auscultation_kind` (
  `id` int(11) NOT NULL,
  `auscultation_kind` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_auscultation_kind`
--

LOCK TABLES `ref_hearth_auscultation_kind` WRITE;
/*!40000 ALTER TABLE `ref_hearth_auscultation_kind` DISABLE KEYS */;
INSERT INTO `ref_hearth_auscultation_kind` VALUES (1,'tipe injection'),(2,'tipe pansystole');
/*!40000 ALTER TABLE `ref_hearth_auscultation_kind` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_auscultation_quality`
--

DROP TABLE IF EXISTS `ref_hearth_auscultation_quality`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_auscultation_quality` (
  `id` int(11) NOT NULL,
  `auscultation_quality` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_auscultation_quality`
--

LOCK TABLES `ref_hearth_auscultation_quality` WRITE;
/*!40000 ALTER TABLE `ref_hearth_auscultation_quality` DISABLE KEYS */;
INSERT INTO `ref_hearth_auscultation_quality` VALUES (1,'crescendo'),(2,'decrescendo'),(3,'blowing'),(4,'rumbling'),(5,'astamatic');
/*!40000 ALTER TABLE `ref_hearth_auscultation_quality` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_auscultation_sound`
--

DROP TABLE IF EXISTS `ref_hearth_auscultation_sound`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_auscultation_sound` (
  `id` int(11) NOT NULL,
  `auscultation_sound` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_auscultation_sound`
--

LOCK TABLES `ref_hearth_auscultation_sound` WRITE;
/*!40000 ALTER TABLE `ref_hearth_auscultation_sound` DISABLE KEYS */;
INSERT INTO `ref_hearth_auscultation_sound` VALUES (1,'bising'),(2,'gesekan pericard');
/*!40000 ALTER TABLE `ref_hearth_auscultation_sound` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_inspection`
--

DROP TABLE IF EXISTS `ref_hearth_inspection`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_inspection` (
  `id` int(11) NOT NULL,
  `inspection` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_inspection`
--

LOCK TABLES `ref_hearth_inspection` WRITE;
/*!40000 ALTER TABLE `ref_hearth_inspection` DISABLE KEYS */;
INSERT INTO `ref_hearth_inspection` VALUES (1,'voussure cardioque'),(2,'ictus cordis');
/*!40000 ALTER TABLE `ref_hearth_inspection` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_intencity`
--

DROP TABLE IF EXISTS `ref_hearth_intencity`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_intencity` (
  `id` int(11) NOT NULL,
  `intencity` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_intencity`
--

LOCK TABLES `ref_hearth_intencity` WRITE;
/*!40000 ALTER TABLE `ref_hearth_intencity` DISABLE KEYS */;
INSERT INTO `ref_hearth_intencity` VALUES (1,'tingkat I'),(2,'tingkat II'),(3,'tingkat III'),(4,'tingkat IV'),(5,'tingkat V'),(6,'tingkat VI');
/*!40000 ALTER TABLE `ref_hearth_intencity` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_localization`
--

DROP TABLE IF EXISTS `ref_hearth_localization`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_localization` (
  `id` int(11) NOT NULL,
  `localization` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_localization`
--

LOCK TABLES `ref_hearth_localization` WRITE;
/*!40000 ALTER TABLE `ref_hearth_localization` DISABLE KEYS */;
INSERT INTO `ref_hearth_localization` VALUES (1,'katub mitral'),(2,'katub pulmoral'),(3,'katub aorta'),(4,'ASD/VSD');
/*!40000 ALTER TABLE `ref_hearth_localization` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_palpation`
--

DROP TABLE IF EXISTS `ref_hearth_palpation`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_palpation` (
  `id` int(11) NOT NULL,
  `palpation` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_palpation`
--

LOCK TABLES `ref_hearth_palpation` WRITE;
/*!40000 ALTER TABLE `ref_hearth_palpation` DISABLE KEYS */;
INSERT INTO `ref_hearth_palpation` VALUES (1,'voussure cardioque'),(2,'ictus cordis');
/*!40000 ALTER TABLE `ref_hearth_palpation` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_penjalaran`
--

DROP TABLE IF EXISTS `ref_hearth_penjalaran`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_penjalaran` (
  `id` int(11) NOT NULL,
  `penjalaran` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_penjalaran`
--

LOCK TABLES `ref_hearth_penjalaran` WRITE;
/*!40000 ALTER TABLE `ref_hearth_penjalaran` DISABLE KEYS */;
INSERT INTO `ref_hearth_penjalaran` VALUES (1,'tidak menjalar/daerah sekitarnya'),(2,'ke daerah karotis'),(3,'batas sternum kiri'),(4,'keaksila'),(5,'puggung dan seluruh precordium');
/*!40000 ALTER TABLE `ref_hearth_penjalaran` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_percussion_bottom`
--

DROP TABLE IF EXISTS `ref_hearth_percussion_bottom`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_percussion_bottom` (
  `id` int(11) NOT NULL,
  `percussion_bottom` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_percussion_bottom`
--

LOCK TABLES `ref_hearth_percussion_bottom` WRITE;
/*!40000 ALTER TABLE `ref_hearth_percussion_bottom` DISABLE KEYS */;
INSERT INTO `ref_hearth_percussion_bottom` VALUES (1,'thorocal 10'),(2,'thorocal 11'),(3,'thorocal 12');
/*!40000 ALTER TABLE `ref_hearth_percussion_bottom` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_percussion_left`
--

DROP TABLE IF EXISTS `ref_hearth_percussion_left`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_percussion_left` (
  `id` int(11) NOT NULL,
  `percussion_left` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_percussion_left`
--

LOCK TABLES `ref_hearth_percussion_left` WRITE;
/*!40000 ALTER TABLE `ref_hearth_percussion_left` DISABLE KEYS */;
INSERT INTO `ref_hearth_percussion_left` VALUES (1,'thorocal 10'),(2,'thorocal 11'),(3,'thorocal 12');
/*!40000 ALTER TABLE `ref_hearth_percussion_left` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_percussion_right`
--

DROP TABLE IF EXISTS `ref_hearth_percussion_right`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_percussion_right` (
  `id` int(11) NOT NULL,
  `percussion_right` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_percussion_right`
--

LOCK TABLES `ref_hearth_percussion_right` WRITE;
/*!40000 ALTER TABLE `ref_hearth_percussion_right` DISABLE KEYS */;
INSERT INTO `ref_hearth_percussion_right` VALUES (1,'sonor'),(2,'hipersonor'),(3,'pekak'),(4,'timpani');
/*!40000 ALTER TABLE `ref_hearth_percussion_right` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_percussion_top`
--

DROP TABLE IF EXISTS `ref_hearth_percussion_top`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_percussion_top` (
  `id` int(11) NOT NULL,
  `percussion_top` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_hearth_percussion_top`
--

LOCK TABLES `ref_hearth_percussion_top` WRITE;
/*!40000 ALTER TABLE `ref_hearth_percussion_top` DISABLE KEYS */;
INSERT INTO `ref_hearth_percussion_top` VALUES (1,'sonor'),(2,'hipersonor'),(3,'pekak'),(4,'timpani');
/*!40000 ALTER TABLE `ref_hearth_percussion_top` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_mouth_gums`
--

DROP TABLE IF EXISTS `ref_mouth_gums`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_mouth_gums` (
  `id` int(11) NOT NULL,
  `gums` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_mouth_gums`
--

LOCK TABLES `ref_mouth_gums` WRITE;
/*!40000 ALTER TABLE `ref_mouth_gums` DISABLE KEYS */;
INSERT INTO `ref_mouth_gums` VALUES (1,'perdarahan'),(2,'ginggivitis');
/*!40000 ALTER TABLE `ref_mouth_gums` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_mouth_inspections`
--

DROP TABLE IF EXISTS `ref_mouth_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_mouth_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_mouth_inspections`
--

LOCK TABLES `ref_mouth_inspections` WRITE;
/*!40000 ALTER TABLE `ref_mouth_inspections` DISABLE KEYS */;
INSERT INTO `ref_mouth_inspections` VALUES (1,'gigi geligi caries'),(2,'tonsil'),(3,'faring hiperemis');
/*!40000 ALTER TABLE `ref_mouth_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_mouth_lips`
--

DROP TABLE IF EXISTS `ref_mouth_lips`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_mouth_lips` (
  `id` int(11) NOT NULL,
  `lips` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_mouth_lips`
--

LOCK TABLES `ref_mouth_lips` WRITE;
/*!40000 ALTER TABLE `ref_mouth_lips` DISABLE KEYS */;
INSERT INTO `ref_mouth_lips` VALUES (1,'sianosis'),(2,'pecah-pecah'),(3,'dll');
/*!40000 ALTER TABLE `ref_mouth_lips` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_mouth_tongue`
--

DROP TABLE IF EXISTS `ref_mouth_tongue`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_mouth_tongue` (
  `id` int(11) NOT NULL,
  `tongue` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_mouth_tongue`
--

LOCK TABLES `ref_mouth_tongue` WRITE;
/*!40000 ALTER TABLE `ref_mouth_tongue` DISABLE KEYS */;
INSERT INTO `ref_mouth_tongue` VALUES (1,'kotor'),(2,'hiperemis'),(3,'tremor');
/*!40000 ALTER TABLE `ref_mouth_tongue` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_neck_inspections`
--

DROP TABLE IF EXISTS `ref_neck_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_neck_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_neck_inspections`
--

LOCK TABLES `ref_neck_inspections` WRITE;
/*!40000 ALTER TABLE `ref_neck_inspections` DISABLE KEYS */;
INSERT INTO `ref_neck_inspections` VALUES (1,'kelenjar gondok'),(2,'kelenjar getah bening'),(3,'pembuluh darah'),(4,'tumor'),(5,'trakea'),(6,'dvs'),(7,'kaku kuduk');
/*!40000 ALTER TABLE `ref_neck_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_nose_inspections`
--

DROP TABLE IF EXISTS `ref_nose_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_nose_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_nose_inspections`
--

LOCK TABLES `ref_nose_inspections` WRITE;
/*!40000 ALTER TABLE `ref_nose_inspections` DISABLE KEYS */;
INSERT INTO `ref_nose_inspections` VALUES (1,'perdarahan'),(2,'sekret');
/*!40000 ALTER TABLE `ref_nose_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_paru_belakang_kanan`
--

DROP TABLE IF EXISTS `ref_paru_belakang_kanan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_paru_belakang_kanan` (
  `id` int(11) NOT NULL,
  `belakang_kanan` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_paru_belakang_kanan`
--

LOCK TABLES `ref_paru_belakang_kanan` WRITE;
/*!40000 ALTER TABLE `ref_paru_belakang_kanan` DISABLE KEYS */;
INSERT INTO `ref_paru_belakang_kanan` VALUES (1,'thorocal 10'),(2,'thorocal 11'),(3,'thorocal 12');
/*!40000 ALTER TABLE `ref_paru_belakang_kanan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_paru_belakang_kiri`
--

DROP TABLE IF EXISTS `ref_paru_belakang_kiri`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_paru_belakang_kiri` (
  `id` int(11) NOT NULL,
  `belakang_kiri` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_paru_belakang_kiri`
--

LOCK TABLES `ref_paru_belakang_kiri` WRITE;
/*!40000 ALTER TABLE `ref_paru_belakang_kiri` DISABLE KEYS */;
INSERT INTO `ref_paru_belakang_kiri` VALUES (1,'thorocal 10'),(2,'thorocal 11'),(3,'thorocal 12');
/*!40000 ALTER TABLE `ref_paru_belakang_kiri` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_paru_bunyi_pernafasan`
--

DROP TABLE IF EXISTS `ref_paru_bunyi_pernafasan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_paru_bunyi_pernafasan` (
  `id` int(11) NOT NULL,
  `bunyi_pernafasan` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_paru_bunyi_pernafasan`
--

LOCK TABLES `ref_paru_bunyi_pernafasan` WRITE;
/*!40000 ALTER TABLE `ref_paru_bunyi_pernafasan` DISABLE KEYS */;
INSERT INTO `ref_paru_bunyi_pernafasan` VALUES (1,'vesicular'),(2,'bronchovesiculer'),(3,'bronchial'),(4,'amphoric'),(5,'astamatic');
/*!40000 ALTER TABLE `ref_paru_bunyi_pernafasan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_paru_bunyi_tambahan`
--

DROP TABLE IF EXISTS `ref_paru_bunyi_tambahan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_paru_bunyi_tambahan` (
  `id` int(11) NOT NULL,
  `bunyi_tambahan` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_paru_bunyi_tambahan`
--

LOCK TABLES `ref_paru_bunyi_tambahan` WRITE;
/*!40000 ALTER TABLE `ref_paru_bunyi_tambahan` DISABLE KEYS */;
INSERT INTO `ref_paru_bunyi_tambahan` VALUES (1,'tidak ada'),(2,'ronchi'),(3,'wheezing'),(4,'repitasi'),(5,'gesekan pleura'),(6,'succtio hypocrates'),(7,'falling drop sound'),(8,'coin sign');
/*!40000 ALTER TABLE `ref_paru_bunyi_tambahan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_paru_fremitus_raba`
--

DROP TABLE IF EXISTS `ref_paru_fremitus_raba`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_paru_fremitus_raba` (
  `id` int(11) NOT NULL,
  `fremitus_raba` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_paru_fremitus_raba`
--

LOCK TABLES `ref_paru_fremitus_raba` WRITE;
/*!40000 ALTER TABLE `ref_paru_fremitus_raba` DISABLE KEYS */;
INSERT INTO `ref_paru_fremitus_raba` VALUES (1,'kiri = kanan normal'),(2,'kiri = kanan meningkat'),(3,'kiri = kanan menurun'),(4,'kanan meningkat kiri menurun'),(5,'kiri meningkat kanan menurun');
/*!40000 ALTER TABLE `ref_paru_fremitus_raba` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_paru_hepar`
--

DROP TABLE IF EXISTS `ref_paru_hepar`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_paru_hepar` (
  `id` int(11) NOT NULL,
  `hepar` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_paru_hepar`
--

LOCK TABLES `ref_paru_hepar` WRITE;
/*!40000 ALTER TABLE `ref_paru_hepar` DISABLE KEYS */;
INSERT INTO `ref_paru_hepar` VALUES (1,'ICS 4'),(2,'ICS 5'),(3,'ICS 6');
/*!40000 ALTER TABLE `ref_paru_hepar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_paru_kanan`
--

DROP TABLE IF EXISTS `ref_paru_kanan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_paru_kanan` (
  `id` int(11) NOT NULL,
  `kanan` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_paru_kanan`
--

LOCK TABLES `ref_paru_kanan` WRITE;
/*!40000 ALTER TABLE `ref_paru_kanan` DISABLE KEYS */;
INSERT INTO `ref_paru_kanan` VALUES (1,'sonor'),(2,'hipersonor'),(3,'pekak'),(4,'timpani');
/*!40000 ALTER TABLE `ref_paru_kanan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_paru_kiri`
--

DROP TABLE IF EXISTS `ref_paru_kiri`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_paru_kiri` (
  `id` int(11) NOT NULL,
  `kiri` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_paru_kiri`
--

LOCK TABLES `ref_paru_kiri` WRITE;
/*!40000 ALTER TABLE `ref_paru_kiri` DISABLE KEYS */;
INSERT INTO `ref_paru_kiri` VALUES (1,'sonor'),(2,'hipersonor'),(3,'pekak'),(4,'timpani');
/*!40000 ALTER TABLE `ref_paru_kiri` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_present_illness_history`
--

DROP TABLE IF EXISTS `ref_present_illness_history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_present_illness_history` (
  `id` int(11) NOT NULL,
  `illness_history` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_present_illness_history`
--

LOCK TABLES `ref_present_illness_history` WRITE;
/*!40000 ALTER TABLE `ref_present_illness_history` DISABLE KEYS */;
INSERT INTO `ref_present_illness_history` VALUES (1,'cacar air'),(2,'cacar'),(3,'batuk rejan'),(4,'tampek');
/*!40000 ALTER TABLE `ref_present_illness_history` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_present_nutrient`
--

DROP TABLE IF EXISTS `ref_present_nutrient`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_present_nutrient` (
  `id` int(11) NOT NULL,
  `nutrient` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_present_nutrient`
--

LOCK TABLES `ref_present_nutrient` WRITE;
/*!40000 ALTER TABLE `ref_present_nutrient` DISABLE KEYS */;
INSERT INTO `ref_present_nutrient` VALUES (1,'kurang'),(2,'cukup'),(3,'lebih');
/*!40000 ALTER TABLE `ref_present_nutrient` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_present_risk_factor`
--

DROP TABLE IF EXISTS `ref_present_risk_factor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_present_risk_factor` (
  `id` int(11) NOT NULL,
  `risk_factor` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_present_risk_factor`
--

LOCK TABLES `ref_present_risk_factor` WRITE;
/*!40000 ALTER TABLE `ref_present_risk_factor` DISABLE KEYS */;
INSERT INTO `ref_present_risk_factor` VALUES (1,'hypertensi'),(2,'Diabetes Melitus'),(3,'Kegemukan');
/*!40000 ALTER TABLE `ref_present_risk_factor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_present_soreness`
--

DROP TABLE IF EXISTS `ref_present_soreness`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_present_soreness` (
  `id` int(11) NOT NULL,
  `soreness` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_present_soreness`
--

LOCK TABLES `ref_present_soreness` WRITE;
/*!40000 ALTER TABLE `ref_present_soreness` DISABLE KEYS */;
/*!40000 ALTER TABLE `ref_present_soreness` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_punggung_bunyi_pernafasan`
--

DROP TABLE IF EXISTS `ref_punggung_bunyi_pernafasan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_punggung_bunyi_pernafasan` (
  `id` int(11) NOT NULL,
  `bunyi_pernafasan` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_punggung_bunyi_pernafasan`
--

LOCK TABLES `ref_punggung_bunyi_pernafasan` WRITE;
/*!40000 ALTER TABLE `ref_punggung_bunyi_pernafasan` DISABLE KEYS */;
INSERT INTO `ref_punggung_bunyi_pernafasan` VALUES (1,'vesicular'),(2,'bronchovesiculer'),(3,'bronchial'),(4,'amphoric'),(5,'astamatic');
/*!40000 ALTER TABLE `ref_punggung_bunyi_pernafasan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_punggung_bunyi_tambahan`
--

DROP TABLE IF EXISTS `ref_punggung_bunyi_tambahan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_punggung_bunyi_tambahan` (
  `id` int(11) NOT NULL,
  `bunyi_tambahan` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_punggung_bunyi_tambahan`
--

LOCK TABLES `ref_punggung_bunyi_tambahan` WRITE;
/*!40000 ALTER TABLE `ref_punggung_bunyi_tambahan` DISABLE KEYS */;
INSERT INTO `ref_punggung_bunyi_tambahan` VALUES (1,'tidak ada'),(2,'ronchi'),(3,'wheezing'),(4,'repitasi'),(5,'gesekan pleura'),(6,'succtio hypocrates'),(7,'falling drop sound'),(8,'coin sign');
/*!40000 ALTER TABLE `ref_punggung_bunyi_tambahan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_punggung_inspections`
--

DROP TABLE IF EXISTS `ref_punggung_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_punggung_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_punggung_inspections`
--

LOCK TABLES `ref_punggung_inspections` WRITE;
/*!40000 ALTER TABLE `ref_punggung_inspections` DISABLE KEYS */;
INSERT INTO `ref_punggung_inspections` VALUES (1,'kyposis'),(2,'lordosis'),(3,'skoliosis');
/*!40000 ALTER TABLE `ref_punggung_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_punggung_others`
--

DROP TABLE IF EXISTS `ref_punggung_others`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_punggung_others` (
  `id` int(11) NOT NULL,
  `others` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_punggung_others`
--

LOCK TABLES `ref_punggung_others` WRITE;
/*!40000 ALTER TABLE `ref_punggung_others` DISABLE KEYS */;
INSERT INTO `ref_punggung_others` VALUES (1,'nyeri ketok'),(2,'gerakan');
/*!40000 ALTER TABLE `ref_punggung_others` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_punggung_palpations`
--

DROP TABLE IF EXISTS `ref_punggung_palpations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_punggung_palpations` (
  `id` int(11) NOT NULL,
  `palpations` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_punggung_palpations`
--

LOCK TABLES `ref_punggung_palpations` WRITE;
/*!40000 ALTER TABLE `ref_punggung_palpations` DISABLE KEYS */;
INSERT INTO `ref_punggung_palpations` VALUES (1,'massa tumor'),(2,'nyeri tekan');
/*!40000 ALTER TABLE `ref_punggung_palpations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_thorax_inspections`
--

DROP TABLE IF EXISTS `ref_thorax_inspections`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_thorax_inspections` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_thorax_inspections`
--

LOCK TABLES `ref_thorax_inspections` WRITE;
/*!40000 ALTER TABLE `ref_thorax_inspections` DISABLE KEYS */;
INSERT INTO `ref_thorax_inspections` VALUES (1,'simetris'),(2,'eksantem'),(3,'pethichian'),(4,'perdarahan di bawah kulit'),(5,'spider nervi'),(6,'pembuluh darah'),(7,'sela iga melebar'),(8,'Buah dada ginekomastis');
/*!40000 ALTER TABLE `ref_thorax_inspections` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_thorax_relief`
--

DROP TABLE IF EXISTS `ref_thorax_relief`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_thorax_relief` (
  `id` int(11) NOT NULL,
  `relief` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_thorax_relief`
--

LOCK TABLES `ref_thorax_relief` WRITE;
/*!40000 ALTER TABLE `ref_thorax_relief` DISABLE KEYS */;
INSERT INTO `ref_thorax_relief` VALUES (1,'normochest'),(2,'emphysematicus'),(3,'paralyticus'),(4,'pyramidalis'),(5,'pectus carinatum'),(6,'pectus excavatum'),(7,'rachitis rosary');
/*!40000 ALTER TABLE `ref_thorax_relief` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_vitalsign_kesadaran`
--

DROP TABLE IF EXISTS `ref_vitalsign_kesadaran`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_vitalsign_kesadaran` (
  `id` int(11) NOT NULL,
  `kesadaran` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_vitalsign_kesadaran`
--

LOCK TABLES `ref_vitalsign_kesadaran` WRITE;
/*!40000 ALTER TABLE `ref_vitalsign_kesadaran` DISABLE KEYS */;
INSERT INTO `ref_vitalsign_kesadaran` VALUES (1,'composmentis'),(2,'incomposmentis');
/*!40000 ALTER TABLE `ref_vitalsign_kesadaran` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_vitalsign_pulse_rythm`
--

DROP TABLE IF EXISTS `ref_vitalsign_pulse_rythm`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_vitalsign_pulse_rythm` (
  `id` int(11) NOT NULL,
  `pulse_rythm` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_vitalsign_pulse_rythm`
--

LOCK TABLES `ref_vitalsign_pulse_rythm` WRITE;
/*!40000 ALTER TABLE `ref_vitalsign_pulse_rythm` DISABLE KEYS */;
INSERT INTO `ref_vitalsign_pulse_rythm` VALUES (1,'reguler'),(2,'irreguler');
/*!40000 ALTER TABLE `ref_vitalsign_pulse_rythm` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_vitalsign_type`
--

DROP TABLE IF EXISTS `ref_vitalsign_type`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_vitalsign_type` (
  `id` int(11) NOT NULL,
  `type` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_vitalsign_type`
--

LOCK TABLES `ref_vitalsign_type` WRITE;
/*!40000 ALTER TABLE `ref_vitalsign_type` DISABLE KEYS */;
INSERT INTO `ref_vitalsign_type` VALUES (1,'thorakal'),(2,'abnormal'),(3,'thorakoabdominal');
/*!40000 ALTER TABLE `ref_vitalsign_type` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `stafs`
--

DROP TABLE IF EXISTS `stafs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `stafs` (
  `id` int(11) NOT NULL,
  `nomor` varchar(100) default NULL,
  `nama` varchar(255) NOT NULL,
  `kelamin` tinyint(4) default NULL,
  `tp_lahir` varchar(255) default NULL,
  `tgl_lahir` date default NULL,
  `alamat` varchar(255) default NULL,
  `kota` varchar(255) default NULL,
  `propinsi` varchar(255) default NULL,
  `negara` varchar(255) default NULL,
  `no_ktp` varchar(255) default NULL,
  `agama` smallint(6) default NULL,
  `email` varchar(255) default NULL,
  `sandi` varchar(255) default NULL,
  `inputtime` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stafs`
--

LOCK TABLES `stafs` WRITE;
/*!40000 ALTER TABLE `stafs` DISABLE KEYS */;
INSERT INTO `stafs` VALUES (0,'1234567890','admin',1,NULL,'1975-04-10',NULL,'Makassar','Sulawesi Selatan','Indonesia',NULL,0,'denicwibowo@gmail.com','de551978f5feecb2ae07f69b8152bb5ff9c434297777d9',NULL),(1,'12345678','Denic Wibowo',1,'Kediri','1975-04-10','Jl. RSI Faisal XI No. 42','Makassar','Sulawesi Selatan','Indonesia','1234567890',0,'denicwibowo@gmail.com','de551978f5feecb2ae07f69b8152bb5ff9c434297777d9',NULL);
/*!40000 ALTER TABLE `stafs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `thorax`
--

DROP TABLE IF EXISTS `thorax`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `thorax` (
  `id` int(11) NOT NULL,
  `inspections` varchar(255) default NULL,
  `relief` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `thorax`
--

LOCK TABLES `thorax` WRITE;
/*!40000 ALTER TABLE `thorax` DISABLE KEYS */;
/*!40000 ALTER TABLE `thorax` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vascular`
--

DROP TABLE IF EXISTS `vascular`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `vascular` (
  `id` int(11) NOT NULL,
  `patients` int(11) NOT NULL,
  `tgl_periksa` date default NULL,
  `klinis` varchar(255) default NULL,
  `right_cca_imc` varchar(100) default NULL,
  `right_cca_plaqthr` varchar(100) default NULL,
  `left_cca_imc` varchar(100) default NULL,
  `left_cca_plaqthr` varchar(100) default NULL,
  `right_ica_psv_imc` varchar(100) default NULL,
  `left_ica_psv_imc` varchar(100) default NULL,
  `right_ica_psv_plaqthr` varchar(100) default NULL,
  `left_ica_psv_plaqthr` varchar(100) default NULL,
  `right_ica_edv_imc` varchar(100) default NULL,
  `left_ica_edv_imc` varchar(100) default NULL,
  `right_ica_edv_plaqthr` varchar(100) default NULL,
  `left_ica_edv_plaqthr` varchar(100) default NULL,
  `right_psvratio_imc` varchar(100) default NULL,
  `left_psvratio_imc` varchar(100) default NULL,
  `right_psvratio_plaqthr` varchar(100) default NULL,
  `left_psvratio_plaqthr` varchar(100) default NULL,
  `right_averteb_d_imc` varchar(100) default NULL,
  `left_averteb_d_imc` varchar(100) default NULL,
  `right_averteb_d_plaqthr` varchar(100) default NULL,
  `left_averteb_d_plaqthr` varchar(100) default NULL,
  `right_averteb_psv_imc` varchar(100) default NULL,
  `left_averteb_psv_imc` varchar(100) default NULL,
  `right_averteb_psv_plaqthr` varchar(100) default NULL,
  `left_averteb_psv_plaqthr` varchar(100) default NULL,
  `interpretasi` varchar(255) default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vascular`
--

LOCK TABLES `vascular` WRITE;
/*!40000 ALTER TABLE `vascular` DISABLE KEYS */;
INSERT INTO `vascular` VALUES (1,1,'2009-09-16','kjdflkjk','12','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','Oh... sehat-sehat aja kok... cuman perlu istirahat mi saja...\r\nOk ?!',1,'2009-09-16 03:38:43',NULL);
/*!40000 ALTER TABLE `vascular` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vital_sign`
--

DROP TABLE IF EXISTS `vital_sign`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `vital_sign` (
  `id` int(11) NOT NULL,
  `tensi_systole` varchar(100) default NULL,
  `tensi_diastole` varchar(100) default NULL,
  `denyut_nadi` int(11) default NULL,
  `pulse_rythm` int(11) default NULL,
  `pernafasan` int(11) default NULL,
  `type` int(11) default NULL,
  `suhu_axilla` varchar(20) default NULL,
  `suhu_oral` varchar(20) default NULL,
  `suhu_rectal` varchar(20) default NULL,
  `kesadaran` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vital_sign`
--

LOCK TABLES `vital_sign` WRITE;
/*!40000 ALTER TABLE `vital_sign` DISABLE KEYS */;
/*!40000 ALTER TABLE `vital_sign` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-10-18 14:48:19
