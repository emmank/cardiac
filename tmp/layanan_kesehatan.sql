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
  `inspeksi_ginjal` varchar(255) default NULL,
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
INSERT INTO `abdomen` VALUES (1,1,1,NULL,1,NULL,'','','','',NULL,NULL,'','','','',NULL,NULL,NULL,NULL,NULL,NULL),(2,1,1,NULL,1,NULL,'','','','',NULL,NULL,'','','','',NULL,NULL,NULL,NULL,NULL,NULL),(3,1,1,NULL,1,NULL,'','','','',NULL,NULL,'','','','',NULL,NULL,NULL,NULL,NULL,NULL),(4,1,1,NULL,1,NULL,'','','','',NULL,NULL,'','','','',NULL,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `abdomen` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `alergi`
--

DROP TABLE IF EXISTS `alergi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `alergi` (
  `id` int(11) NOT NULL,
  `perawatan` int(11) NOT NULL,
  `tgl` datetime NOT NULL,
  `nama_alergi` varchar(255) default NULL,
  `jenis_alergi` varchar(255) default NULL,
  `keterangan` varchar(255) default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `alergi`
--

LOCK TABLES `alergi` WRITE;
/*!40000 ALTER TABLE `alergi` DISABLE KEYS */;
INSERT INTO `alergi` VALUES (1,1,'2009-12-18 15:08:32','kacang','','',0,'2009-12-18 15:08:37','0|2009-12-18 18:13:58');
/*!40000 ALTER TABLE `alergi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `antrian`
--

DROP TABLE IF EXISTS `antrian`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `antrian` (
  `id` int(11) NOT NULL,
  `nama` varchar(255) default NULL,
  `kelamin` tinyint(1) NOT NULL default '1',
  `tp_lahir` varchar(255) default NULL,
  `tgl_lahir` date default NULL,
  `gol_darah` char(2) default NULL,
  `alamat` varchar(255) default NULL,
  `kota` varchar(100) default NULL,
  `propinsi` varchar(100) default NULL,
  `no_identitas` varchar(255) default NULL,
  `sandi` varchar(255) default NULL,
  `status` varchar(20) default NULL,
  `nama_suami_istri` varchar(35) default NULL,
  `pekerjaan_suami_istri` varchar(35) default NULL,
  `foto` varchar(255) default NULL,
  `pekerjaan` varchar(20) default NULL,
  `pendidikan` varchar(50) default NULL,
  `kode_pos` varchar(10) default NULL,
  `no_tlp` varchar(100) default NULL,
  `no_hp` varchar(100) default NULL,
  `agama` varchar(15) default NULL,
  `suku` varchar(20) default NULL,
  `nama_ayah` varchar(50) default NULL,
  `pekerjaan_ayah` varchar(50) default NULL,
  `nama_ibu` varchar(50) default NULL,
  `pekerjaan_ibu` varchar(50) default NULL,
  `pukul` varchar(100) default NULL,
  `strnum` varchar(100) default NULL,
  `bagian` varchar(255) default NULL,
  `nourut` int(11) default NULL,
  `keluhan` varchar(255) default NULL,
  `cara_berkunjung` varchar(200) default NULL,
  `pilihan_cara_berkunjung` varchar(255) default NULL,
  `cara_bayar` varchar(200) default NULL,
  `pilihan_cara_bayar` varchar(255) default NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `strnum` (`strnum`),
  UNIQUE KEY `pukul` (`pukul`),
  UNIQUE KEY `strnum_2` (`strnum`),
  UNIQUE KEY `pukul_2` (`pukul`),
  UNIQUE KEY `strnum_3` (`strnum`),
  UNIQUE KEY `pukul_3` (`pukul`),
  UNIQUE KEY `strnum_4` (`strnum`),
  UNIQUE KEY `pukul_4` (`pukul`),
  UNIQUE KEY `strnum_5` (`strnum`),
  UNIQUE KEY `pukul_5` (`pukul`),
  UNIQUE KEY `strnum_6` (`strnum`),
  UNIQUE KEY `pukul_6` (`pukul`),
  UNIQUE KEY `strnum_7` (`strnum`),
  UNIQUE KEY `pukul_7` (`pukul`),
  UNIQUE KEY `strnum_8` (`strnum`),
  UNIQUE KEY `pukul_8` (`pukul`),
  UNIQUE KEY `strnum_9` (`strnum`),
  UNIQUE KEY `pukul_9` (`pukul`),
  UNIQUE KEY `strnum_10` (`strnum`),
  UNIQUE KEY `pukul_10` (`pukul`),
  UNIQUE KEY `strnum_11` (`strnum`),
  UNIQUE KEY `pukul_11` (`pukul`),
  UNIQUE KEY `strnum_12` (`strnum`),
  UNIQUE KEY `pukul_12` (`pukul`),
  UNIQUE KEY `strnum_13` (`strnum`),
  UNIQUE KEY `pukul_13` (`pukul`),
  UNIQUE KEY `strnum_14` (`strnum`),
  UNIQUE KEY `pukul_14` (`pukul`),
  UNIQUE KEY `strnum_15` (`strnum`),
  UNIQUE KEY `pukul_15` (`pukul`),
  UNIQUE KEY `strnum_16` (`strnum`),
  UNIQUE KEY `pukul_16` (`pukul`),
  UNIQUE KEY `strnum_17` (`strnum`),
  UNIQUE KEY `pukul_17` (`pukul`),
  UNIQUE KEY `strnum_18` (`strnum`),
  UNIQUE KEY `pukul_18` (`pukul`),
  UNIQUE KEY `strnum_19` (`strnum`),
  UNIQUE KEY `pukul_19` (`pukul`),
  UNIQUE KEY `strnum_20` (`strnum`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `antrian`
--

LOCK TABLES `antrian` WRITE;
/*!40000 ALTER TABLE `antrian` DISABLE KEYS */;
/*!40000 ALTER TABLE `antrian` ENABLE KEYS */;
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
INSERT INTO `anus_rectum` VALUES (1,NULL,NULL),(2,NULL,NULL),(3,NULL,NULL),(4,NULL,NULL);
/*!40000 ALTER TABLE `anus_rectum` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asuransi`
--

DROP TABLE IF EXISTS `asuransi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `asuransi` (
  `id_asuransi` int(11) NOT NULL,
  `nama_asuransi` varchar(100) NOT NULL,
  `nama_singkat` varchar(100) default NULL,
  `alamat` varchar(255) default NULL,
  `alamat_tagihan` varchar(255) default NULL,
  `email` varchar(100) default NULL,
  `no_tlp` varchar(100) default NULL,
  `no_fax` varchar(100) default NULL,
  `contact_person` varchar(100) default NULL,
  `alamat_cp` varchar(255) default NULL,
  `email_cp` varchar(100) default NULL,
  `no_tlp_cp` varchar(100) default NULL,
  `no_fax_cp` varchar(100) default NULL,
  PRIMARY KEY  (`id_asuransi`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asuransi`
--

LOCK TABLES `asuransi` WRITE;
/*!40000 ALTER TABLE `asuransi` DISABLE KEYS */;
INSERT INTO `asuransi` VALUES (0,'Umum','Umum','-','-','-','-','-','-','-','-','-','-'),(1,'PT. ASKES INDONESIA,Tbk','ASKES','Jl.','Jl',NULL,'0411 - ',NULL,'dr.','Jl',NULL,'0811',NULL),(2,'PT. ASKES INDONESIA,Tbk','ASKES Sukarela','Jl.','Jl','-','0411-','-','dr.','Jl','-','0811','-'),(3,'PT.ASTEK','ASTEK','Jl.','Jl','-','0411-','-','dr.','Jl',NULL,'',NULL),(4,'JPS','JPS','','',NULL,'',NULL,'','',NULL,'',NULL),(5,'Kartu Sehat','Kartu Sehat','','',NULL,'',NULL,'','',NULL,'',NULL),(6,'Kartu Miskin','Kartu Miskin','','',NULL,'',NULL,'','',NULL,'',NULL),(7,'SKTM','SKTM','','',NULL,'',NULL,'','',NULL,'',NULL),(8,'IKS','IKS','','',NULL,'',NULL,'','',NULL,'',NULL);
/*!40000 ALTER TABLE `asuransi` ENABLE KEYS */;
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
INSERT INTO `bagian` VALUES (1,'vascular','vascular'),(2,'echocardiography','echocardiography'),(3,'cardio_dewasa','cardio'),(4,'cardio_anak','cardio'),(5,'EKG','ekg'),(6,'Holter','holter'),(7,'Treadmill','treadmill'),(8,'perawatan','perawatan');
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
  `kunjungan` int(11) NOT NULL,
  `teens` tinyint(1) NOT NULL default '0',
  `tgl` date NOT NULL,
  `patients` int(11) NOT NULL,
  `nomor` varchar(100) default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(50) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `cardio`
--

LOCK TABLES `cardio` WRITE;
/*!40000 ALTER TABLE `cardio` DISABLE KEYS */;
INSERT INTO `cardio` VALUES (4,18,0,'2009-12-08',11,NULL,0,'2009-12-08 10:49:48','');
/*!40000 ALTER TABLE `cardio` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `carotis`
--

DROP TABLE IF EXISTS `carotis`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `carotis` (
  `id` int(11) NOT NULL,
  `artery_carotis_communis` varchar(150) default NULL,
  `artery_carotis_interna` varchar(150) default NULL,
  `artery_carotis_eksterna` varchar(150) default NULL,
  `vena_jugularis_interna` varchar(150) default NULL,
  `vena_jugularis_superficial` varchar(150) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `carotis`
--

LOCK TABLES `carotis` WRITE;
/*!40000 ALTER TABLE `carotis` DISABLE KEYS */;
/*!40000 ALTER TABLE `carotis` ENABLE KEYS */;
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
INSERT INTO `ear` VALUES (1,NULL),(2,NULL),(3,NULL),(4,NULL);
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
-- Table structure for table `ekg`
--

DROP TABLE IF EXISTS `ekg`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ekg` (
  `id` int(11) NOT NULL,
  `patients` int(11) NOT NULL,
  `kunjungan` int(11) NOT NULL,
  `tgl` date NOT NULL,
  `irama_dasar` int(11) NOT NULL default '0',
  `denyut_jantung` int(11) default NULL,
  `gelombang_p` int(11) default NULL,
  `interval_pr` int(11) default NULL,
  `qrs_axis` int(11) default NULL,
  `qrs_durasi` int(11) default NULL,
  `qrs_konfigurasi_patologi` int(11) default NULL,
  `qrs_konfigurasi_r_s` int(11) default NULL,
  `segmen_st_depresi` varchar(150) default NULL,
  `segmen_st_elevasi` varchar(150) default NULL,
  `gelombang_t` varchar(150) default NULL,
  `q_interval` int(11) default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(50) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ekg`
--

LOCK TABLES `ekg` WRITE;
/*!40000 ALTER TABLE `ekg` DISABLE KEYS */;
INSERT INTO `ekg` VALUES (1,12,0,'2009-11-18',1,1,1,1,1,1,4,1,'1','1','',1,0,'2009-11-18 13:53:27',''),(2,10,0,'2009-11-21',4,4,2,2,2,2,3,1,'1','1','3',1,0,'2009-11-21 16:09:59',''),(3,9,0,'2009-11-22',4,2,1,2,3,2,4,2,'1mm - 2mm|1','1|>2mm - 3mm','Inverted|6',1,0,'2009-11-22 21:08:59',''),(4,11,24,'2009-12-13',3,3,3,2,2,2,0,2,'> 2mm - 3mm|5','> 3mm|5','Normal|5',2,0,'2009-12-13 01:04:55','');
/*!40000 ALTER TABLE `ekg` ENABLE KEYS */;
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
INSERT INTO `extermitas` VALUES (1,NULL),(2,NULL),(3,NULL),(4,NULL);
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
  `pupil` int(11) default '0',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `eye`
--

LOCK TABLES `eye` WRITE;
/*!40000 ALTER TABLE `eye` DISABLE KEYS */;
INSERT INTO `eye` VALUES (1,NULL,1,1,1,1,1),(2,NULL,1,1,1,1,1),(3,NULL,1,1,1,1,1),(4,NULL,1,1,1,1,1);
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
INSERT INTO `head_n_face` VALUES (1,1,1,NULL),(2,1,1,NULL),(3,1,1,NULL),(4,1,1,NULL);
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
INSERT INTO `hearth` VALUES (2,NULL,NULL,1,1,1,1,'',NULL,1,1,1,1,1),(3,NULL,NULL,1,1,1,1,'',NULL,1,1,1,1,1),(4,NULL,NULL,1,1,1,1,'',NULL,1,1,1,1,1);
/*!40000 ALTER TABLE `hearth` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `holter`
--

DROP TABLE IF EXISTS `holter`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `holter` (
  `id` int(11) NOT NULL,
  `kunjungan` int(11) NOT NULL,
  `patients` int(11) NOT NULL,
  `tgl` date NOT NULL,
  `the_average_HR` varchar(255) NOT NULL default '0',
  `the_minimum_HR` varchar(255) default NULL,
  `the_maximum_HR` varchar(255) default NULL,
  `segment_st_depresi` varchar(150) default NULL,
  `segment_st_elevasi` varchar(150) default NULL,
  `gelombang_t` varchar(150) default NULL,
  `pause` varchar(255) default NULL,
  `VES` varchar(255) default NULL,
  `AES` varchar(255) default NULL,
  `SVT` varchar(255) default NULL,
  `VT` varchar(255) default NULL,
  `AF` varchar(255) default NULL,
  `heart_block_1_degree` varchar(255) default NULL,
  `heart_block_2_degree` varchar(255) default NULL,
  `heart_block_3_degree` varchar(255) default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(50) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `holter`
--

LOCK TABLES `holter` WRITE;
/*!40000 ALTER TABLE `holter` DISABLE KEYS */;
INSERT INTO `holter` VALUES (1,23,11,'2009-12-13','100|10:10','100|10:10','100|10:20','> 2mm - 3mm|5','> 3mm|3','Normal','100|100|100','3|100|100','2|100|100','2|100|100','100|100|100','3|100|100','100|100|100','2|100|100','100|100|100',0,'2009-12-13 00:56:12','');
/*!40000 ALTER TABLE `holter` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `inferior`
--

DROP TABLE IF EXISTS `inferior`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `inferior` (
  `id` int(11) NOT NULL,
  `artery_fermoralis_communis` varchar(150) default NULL,
  `artery_fermoralis_profunde` varchar(150) default NULL,
  `artery_fermoralis_superficial` varchar(150) default NULL,
  `artery_paplitca` varchar(150) default NULL,
  `artery_tibalin_arterior` varchar(150) default NULL,
  `artery_tibalin_rasterior` varchar(150) default NULL,
  `artery_aorsalin_pedia` varchar(150) default NULL,
  `vena` varchar(150) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `inferior`
--

LOCK TABLES `inferior` WRITE;
/*!40000 ALTER TABLE `inferior` DISABLE KEYS */;
/*!40000 ALTER TABLE `inferior` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `isearch_patients`
--

DROP TABLE IF EXISTS `isearch_patients`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `isearch_patients` (
  `id` int(11) NOT NULL,
  `phrase` text,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `isearch_patients`
--

LOCK TABLES `isearch_patients` WRITE;
/*!40000 ALTER TABLE `isearch_patients` DISABLE KEYS */;
INSERT INTO `isearch_patients` VALUES (1,'1 1 Sutiyem 0 Blitar 1971-09-13 O Jl. Raya Keras Km 21 Kabupaten Asmat Jawa Timur dlkfjlkkdfnl  kawin         islam      2009-09-29 10:07:07   00001  1 0|2009-11-23 09:39:01'),(2,'2 2 Karjo 1 Sinjai 1982-08-15 B Jl. Rusa No. 15 Kabupaten Asmat Sulawesi Selatan kdjfnkjdg  kawin         islam      2009-09-29 10:54:57   00002  0 0|2009-11-23 15:08:52'),(3,'3 3 Amir 1 Makassar 1970-01-01 O Jl.Sungai saddang Kabupaten Asmat Bali 12  kawin         islam      2009-10-28 16:03:46   00003  0 0|2009-11-23 15:09:01'),(4,'4 4 Ma\'ruf 1 Makassar 1981-01-01 O Jl.Urip Sumoharjo Kabupaten Asmat Bali   kawin         islam      2009-10-29 11:02:53   00004  0 0|2009-11-23 15:09:36'),(5,'5 5 Anis 1 Maros 1970-01-01 AB Jl.Nipa-nipa Kabupaten Asmat Bali   kawin         islam      2009-11-09 14:58:42   00005  0 0|2009-11-23 15:09:25'),(6,'6 6 Santi 0 Malang 1986-04-02 AB Jl. Lamadukeleng No. 12 Makassar Sulawesi Selatan dksjhfglkjdlg                 2009-11-09 15:29:17   00006  0 '),(7,'7 7 Accing 1 Makassar 1990-02-04 B Jl. RSI Faisal XI No. 42 Makassar Sulawesi Selatan jdlgdnfkn                 2009-11-11 05:55:44   00007  0 '),(8,'8 8 Alif 1 Makassar 1989-02-17 A Jl. Kijang No. 14 Makassar Sulawesi Selatan jfdl.df.kgdlg                 2009-11-11 05:55:58   00008  0 '),(9,'9 9 Anas 1 Makassar 1970-01-01 O Jl. Borong Raya No.111 Kabupaten Asmat Bali   kawin Tia Ibu Rumah Tangga  PNS S1 90000 444444 08131000000 islam Bugis Beddu Petani Sri PNS 2009-11-17 16:03:49   00009  0 0|2009-11-22 18:14:13'),(10,'10 10 Anas 1 Makassar 1970-01-01 O Jl. Borong Raya No.111 Kabupaten Asmat Bali   kawin Tia Ibu Rumah Tangga  PNS S1 90000 444444 08131000000 islam Bugis Beddu Petani Sri PNS 2009-11-17 16:04:20   00010  0 0|2009-11-20 16:26:36'),(11,'11 11 Basri 1 Makassar 1975-01-01 O Jl.Dg.Baji Kabupaten Asmat Bali 737101017505  kawin Becce PNS  PNS S1 90000 445566 08134455778899 islam Bugis Dg.Ambo Pensiun Hj.Hasrah IRT 2009-11-18 11:51:59   00011  0 0|2009-11-20 14:22:45'),(12,'12 12 Adi 1 Malang 1971-01-01 O Jl.Maccini Raya No.111 Kabupaten Asmat Bali 737101017102  kawin    PNS S2 90000 432345 081310000001 islam Makassar Basuki Petani Becce IRT 2009-11-18 12:10:07   00012  0 0|2009-11-20 14:24:02'),(13,'Rahmat 1 Makassar 1984-4-01 O Jl.Pandang Raya No.80 Makassar Kota Makassar Sulawesi Selatan  tidak kawin   Pegawai swasta SMA  4775432 081310000123 islam      00013 13 13 0 2009-11-25 10:43:56'),(14,'Andi Rahmat 1 Makassar 1973-1-01 O Jl.dr.Leimena Kota Makassar Sulawesi Selatan  tidak kawin        islam      00014 14 14 0 2009-11-25 11:39:39'),(15,'Ida 0 Bone 1970-1-01 O BTN Antara Kota Makassar Sulawesi Selatan  kawin        islam      00015 15 15 0 2009-12-01 19:08:25'),(16,'16 00016 Bejo Kesupen 1 Palopo 1972-3-12  islam Jawa     Petani SLTP 934795830 Jl. Wirajaya V 73 23 9803940 984580985 459845350909 Kemis Petani Supratin Ibu Rumah Tangga kawin Jumarah Ibu Rumah Tangga 16 0 2009-12-19 15:22:28'),(17,'17 00543 Poniyem 0 Malili 1976-7-18  islam Jawa     Buruh Tani SD 0956804865094 Jl. Kejayaan 2  73 10 9856094 9486094068409 09485094065889879 Karsan Petani Waginah Ibu Rumah Tangga kawin Baso Lahamuddin PNS 17 0 2009-12-19 15:49:05');
/*!40000 ALTER TABLE `isearch_patients` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `istirahat`
--

DROP TABLE IF EXISTS `istirahat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `istirahat` (
  `id` int(11) NOT NULL,
  `tensi_sistolik` varchar(100) default NULL,
  `tensi_diastolik` varchar(100) default NULL,
  `denyut_jantung` int(11) default NULL,
  `irama_dasar` int(11) default NULL,
  `gelombang_p` int(11) default NULL,
  `interval_pr` int(11) default NULL,
  `qrs_axis` int(11) default NULL,
  `qrs_durasi` int(11) default NULL,
  `qrs_konfigurasi_patologi` int(11) default NULL,
  `gelombang_t` varchar(150) default NULL,
  `q_interval` int(11) default NULL,
  `qrs_konfigurasi_r_s` int(11) default NULL,
  `segmen_st_depresi` varchar(150) default NULL,
  `segmen_st_elevasi` varchar(150) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `istirahat`
--

LOCK TABLES `istirahat` WRITE;
/*!40000 ALTER TABLE `istirahat` DISABLE KEYS */;
INSERT INTO `istirahat` VALUES (1,'100','100',4,2,3,3,3,3,0,'Inverted',2,3,'> 3mm|2','> 2mm - 3mm|4');
/*!40000 ALTER TABLE `istirahat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `istirahatberdiri`
--

DROP TABLE IF EXISTS `istirahatberdiri`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `istirahatberdiri` (
  `id` int(11) NOT NULL,
  `tensi_sistolik` varchar(100) default NULL,
  `tensi_diastolik` varchar(100) default NULL,
  `denyut_jantung` int(11) default NULL,
  `irama_dasar` int(11) default NULL,
  `gelombang_p` int(11) default NULL,
  `interval_pr` int(11) default NULL,
  `qrs_axis` int(11) default NULL,
  `qrs_durasi` int(11) default NULL,
  `qrs_konfigurasi_patologi` int(11) default NULL,
  `gelombang_t` varchar(150) default NULL,
  `q_interval` int(11) default NULL,
  `qrs_konfigurasi_r_s` int(11) default NULL,
  `segmen_st_depresi` varchar(150) default NULL,
  `segmen_st_elevasi` varchar(150) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `istirahatberdiri`
--

LOCK TABLES `istirahatberdiri` WRITE;
/*!40000 ALTER TABLE `istirahatberdiri` DISABLE KEYS */;
INSERT INTO `istirahatberdiri` VALUES (1,'','',0,0,0,0,0,0,0,'',0,0,'|','|');
/*!40000 ALTER TABLE `istirahatberdiri` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `istirahathiperventilasi`
--

DROP TABLE IF EXISTS `istirahathiperventilasi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `istirahathiperventilasi` (
  `id` int(11) NOT NULL,
  `tensi_sistolik` varchar(100) default NULL,
  `tensi_diastolik` varchar(100) default NULL,
  `irama_dasar` int(11) default NULL,
  `denyut_jantung` int(11) default NULL,
  `gelombang_p` int(11) default NULL,
  `interval_pr` int(11) default NULL,
  `qrs_axis` int(11) default NULL,
  `qrs_durasi` int(11) default NULL,
  `qrs_konfigurasi_patologi` int(11) default NULL,
  `qrs_konfigurasi_r_s` int(11) default NULL,
  `segmen_st_depresi` varchar(150) default NULL,
  `segmen_st_elevasi` varchar(150) default NULL,
  `gelombang_t` varchar(150) default NULL,
  `q_interval` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `istirahathiperventilasi`
--

LOCK TABLES `istirahathiperventilasi` WRITE;
/*!40000 ALTER TABLE `istirahathiperventilasi` DISABLE KEYS */;
INSERT INTO `istirahathiperventilasi` VALUES (1,'','',0,0,0,0,0,0,0,0,'|','|','',0);
/*!40000 ALTER TABLE `istirahathiperventilasi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kabupaten`
--

DROP TABLE IF EXISTS `kabupaten`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `kabupaten` (
  `id_kab` varchar(3) NOT NULL,
  `kabupaten` varchar(30) NOT NULL,
  `ibukota` varchar(30) NOT NULL,
  `kode_bps` varchar(2) NOT NULL,
  PRIMARY KEY  (`id_kab`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kabupaten`
--

LOCK TABLES `kabupaten` WRITE;
/*!40000 ALTER TABLE `kabupaten` DISABLE KEYS */;
INSERT INTO `kabupaten` VALUES ('1','Kabupaten Bantaeng','Bantaeng','73'),('2','Kabupaten Barru','Barru','73'),('3','Kabupaten Bone','Watampone','73'),('4','Kabupaten Bulukumba','Bulukumba','73'),('5','Kabupaten Enrekang','Enrekang','73'),('6','Kabupaten Gowa','Sunggu Minasa','73'),('7','Kabupaten Jeneponto','Jeneponto','73'),('8','Kabupaten Kepulauan Selayar','Benteng','73'),('9','Kabupaten Luwu','Palopo','73'),('10','Kabupaten Luwu Timur','Malili','73'),('11','Kabupaten Luwu Utara','Masamba','73'),('12','Kabupaten Maros','Maros','73'),('13','Kabupaten Pangkajene dan Kepul','Pangkajene','73'),('14','Kabupaten Pinrang','Pinrang','73'),('15','Kabupaten Sidenreng Rappang','Sidenreng','73'),('16','Kabupaten Sinjai','Sinjai','73'),('17','Kabupaten Soppeng','Watan Soppeng','73'),('18','Kabupaten Takalar','Takalar','73'),('19','Kabupaten Tana Toraja','Makale','73'),('20','Kabupaten Toraja Utara','Rantepao','73'),('21','Kabupaten Wajo','Sengkang','73'),('22','Kota Makassar','Makassar','73'),('23','Kota Palopo','Palopo','73'),('24','Kota Parepare','Pare-pare','73'),('25','Kabupaten Banggai','Luwuk','72'),('26','Kabupaten Banggai Kepulauan','Banggai','72'),('27','Kabupaten Buol','Buol','72'),('28','Kabupaten Donggala','Donggala','72'),('29','Kabupaten Morowali','Bungku','72'),('30','Kabupaten Parigi Moutong','Parigi','72'),('31','Kabupaten Poso','Poso','72'),('32','Kabupaten Tojo Una-Una','Ampana','72'),('33','Kabupaten Toli-Toli','Toli-Toli','72'),('34','Kabupaten Sigi','Sigi Biromaru','72'),('35','Kota Palu','Palu','72'),('36','Kabupaten Bolaang Mongondow','Kotamobagu','71'),('37','Kabupaten Bolaang Mongondow Se','Bolaang Uki','71'),('38','Kabupaten Bolaang Mongondow Ti','Tutuyan','71'),('39','Kabupaten Bolaang Mongondow Ut','Boroko','71'),('40','Kabupaten Kepulauan Sangihe','Tahuna','71'),('41','Kabupaten Kepulauan Siau Tagul','Ondong Siau','71'),('42','Kabupaten Kepulauan Talaud','Melonguane','71'),('43','Kabupaten Minahasa','Tondano','71'),('44','Kabupaten Minahasa Selatan','Amurang','71'),('45','Kabupaten Minahasa Tenggara','Ratahan','71'),('46','Kabupaten Minahasa Utara','Airmadidi','71'),('47','Kota Bitung','Bitung','71'),('48','Kota Kotamobagu','Kotamobagu','71'),('49','Kota Manado','Manado','71'),('50','Kota Tomohon','Tomohon','71'),('51','Kabupaten Bombana','Rumbia','74'),('52','Kabupaten Buton','Bau-Bau','74'),('53','Kabupaten Buton Utara','Buranga','74'),('54','Kabupaten Kolaka','Kolaka','74'),('55','Kabupaten Kolaka Utara','Lasusua','74'),('56','Kabupaten Konawe','Unaaha','74'),('57','Kabupaten Konawe Selatan','Andolo','74'),('58','Kabupaten Konawe Utara','Wanggudu','74'),('59','Kabupaten Muna','Raha','74'),('60','Kabupaten Wakatobi','Wangi-Wangi','74'),('61','Kota Bau-Bau','Bau-Bau','74'),('62','Kota Kendari','Kendari','74'),('63','Kabupaten Boalemo','Marisa/Tilamuta','75'),('64','Kabupaten Bone Bolango','Suwawa','75'),('65','Kabupaten Gorontalo','Gorontalo','75'),('66','Kabupaten Gorontalo Utara','Kwandang','75'),('67','Kabupaten Pohuwato','Marisa','75'),('68','Kota Gorontalo','Gorontalo','75'),('69','Kabupaten Majene','Majene','76'),('70','Kabupaten Mamasa','Mamasa','76'),('71','Kabupaten Mamuju','Mamuju','76'),('72','Kabupaten Mamuju Utara','Pasangkayu','76'),('73','Kabupaten Polewali Mandar','Polewali','76'),('74','Kabupaten Buru','Namlea','81'),('75','Kabupaten Buru Selatan','Namrole','81'),('76','Kabupaten Kepulauan Aru','Oobo','81'),('77','Kabupaten Maluku Barat Daya','Tiakur','81'),('78','Kabupaten Maluku Tengah','Masohi','81'),('79','Kabupaten Maluku Tenggara','Tual','81'),('80','Kabupaten Maluku Tenggara Bara','Saumlaki','81'),('81','Kabupaten Seram Bagian Barat','Dataran Hunipopu','81'),('82','Kabupaten Seram Bagian Timur','Dataran Hunimoa','81'),('83','Kota Ambon','Ambon','81'),('84','Kota Tual','Tual','81'),('85','Kabupaten Halmahera Barat','Jailolo','82'),('86','Kabupaten Halmahera Tengah','Weda','82'),('87','Kabupaten Halmahera Utara','Tobelo','82'),('88','Kabupaten Halmahera Selatan','Labuha','82'),('89','Kabupaten Kepulauan Sula','Sanana','82'),('90','Kabupaten Halmahera Timur','Maba','82'),('91','Kabupaten Pulau Morotai','Morotai Selatan','82'),('92','Kota Ternate','Ternate','82'),('93','Kota Tidore Kepulauan','Tidore','82'),('94','Kabupaten Fakfak','Fakfak','91'),('95','Kabupaten Kaimana','Kaimana','91'),('96','Kabupaten Manokwari','Manokwari','91'),('97','Kabupaten Maybrat','Kumurkek','91'),('98','Kabupaten Raja Ampat','Waisai','91'),('99','Kabupaten Sorong','Sorong','91'),('100','Kabupaten Sorong Selatan','Teminabuan','91'),('101','Kabupaten Tambrauw','Fef','91'),('102','Kabupaten Teluk Bintuni','Bintuni','91'),('103','Kabupaten Teluk Wondama','Rasiei','91'),('104','Kota Sorong','-','91'),('105','Kabupaten Asmat','Agats','92'),('106','Kabupaten Biak Numfor','Biak','92'),('107','Kabupaten Boven Digoel','Tanah Merah','92'),('108','Kabupaten Deiyai','Tigi','92'),('109','Kabupaten Dogiyai','Kigamani','92'),('110','Kabupaten Intan Jaya','Sugapa','92'),('111','Kabupaten Jayapura','Sentani','92'),('112','Kabupaten Jayawijaya','Wamena','92'),('113','Kabupaten Keerom','Waris','92'),('114','Kabupaten Kepulauan Yapen','Serui','92'),('115','Kabupaten Lanny Jaya','Tiom','92'),('116','Kabupaten Mamberamo Raya','Burmeso','92'),('117','Kabupaten Mamberamo Tengah','Kobakma','92'),('118','Kabupaten Mappi','Kepi','92'),('119','Kabupaten Merauke','Merauke','92'),('120','Kabupaten Mimika','Timika','92'),('121','Kabupaten Nabire','Nabire','92'),('122','Kabupaten Nduga','Kenyam','92'),('123','Kabupaten Paniai','Enarotali','92'),('124','Kabupaten Pegunungan Bintang','Oksibil','92'),('125','Kabupaten Puncak','Ilaga','92'),('126','Kabupaten Puncak Jaya','Kotamulia','92'),('127','Kabupaten Sarmi','Sarmi','92'),('128','Kabupaten Supiori','Sorendiweri','92'),('129','Kabupaten Tolikara','Karubaga','92'),('130','Kabupaten Waropen','Botawa','92'),('131','Kabupaten Yahukimo','Sumohai','92'),('132','Kabupaten Yalimo','Elelim','92'),('133','Kota Jayapura','-','92');
/*!40000 ALTER TABLE `kabupaten` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kecamatan`
--

DROP TABLE IF EXISTS `kecamatan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `kecamatan` (
  `id_kec` varchar(3) NOT NULL,
  `nama_kecamatan` varchar(30) NOT NULL,
  `id_kab` varchar(3) NOT NULL,
  PRIMARY KEY  (`id_kec`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kecamatan`
--

LOCK TABLES `kecamatan` WRITE;
/*!40000 ALTER TABLE `kecamatan` DISABLE KEYS */;
INSERT INTO `kecamatan` VALUES ('1','Biring Kanayya','22'),('2','Bontoala','22'),('3','Makassar','22'),('4','Mamajang','22'),('5','Manggala','22'),('6','Mariso','22'),('7','Panakkukang','22'),('8','Rappocini','22'),('9','Tallo','22'),('10','Tamalanrea','22'),('11','Tamalate','22'),('12','Ujung Pandang','22'),('13','Ujung Tanah','22'),('14','Wajo','22'),('15','Bantaeng','1'),('16','Bissapu','1'),('17','eremerase','1'),('18','gantarangkeke','1'),('19','pajukukang','1'),('20','sinoa','1'),('21','tompobulu','1'),('22','uluere','1'),('23','balusu','2'),('24','barru','2'),('25','mallusetasi','2'),('26','pujananting','2'),('27','soppeng riaja','2'),('28','tanete riaja','2'),('29','tanete rilau','2'),('30','Ajangale','3'),('31','Amali ','3'),('32','Awangpone','3'),('33','Barebbo ','3'),('34','Bengo','3'),('35','cerana','3'),('36','cina','3'),('37','dua boccoe','3'),('38','kahu','3'),('39','kajuara','3'),('40','lamuru','3'),('41','lappariaja','3'),('42','libureng','3'),('43','mare','3'),('44','palakka','3'),('45','patimpeng','3'),('46','ponre','3'),('47','salomekko','3'),('48','sibule','3'),('49','tanete riattang','3'),('50','tanete riattang barat','3'),('51','tanete riattang timur','3'),('52','tellu limpoe','3'),('53','tellu siattinge','3'),('54','tonra','3'),('55','ulaweng','3'),('56','bontocani','3'),('57','Bonto Bahari','4'),('58','Bontotiro','4'),('59','Bulukumpa','4'),('60','Gantarangkeke','4'),('61','Hero Lange-Lange','4'),('62','Kajang','4'),('63','Kindang','4'),('64','Tiau Ale','4'),('65','Ujung Bulu','4'),('66','Ujung Loe','4'),('67','alla','5'),('68','alla timur','5'),('69','anggeraja','5'),('70','anggeraja timur','5'),('71','baraka','5'),('72','enrekang','5'),('73','enrekang selatan','5'),('74','maiwa','5'),('75','maiwa atas','5'),('76','bajeng','6'),('77','barombong','6'),('78','biringbulu','6'),('79','bontomarannu','6'),('80','bontonompo','6'),('81','bungaya','6'),('82','palangga','6'),('83','parangloe','6'),('84','somba opu','6'),('85','tinggimoncong','6'),('86','tombolo pao','6'),('87','tompobulu','6'),('88','arungkeke','7'),('89','bangkala','7'),('90','bangkala barat','7'),('91','batang','7'),('92','binamu','7'),('93','bontoramba','7'),('94','kelara','7'),('95','tamalatea','7'),('96','turatea','7'),('97','Benteng','8'),('98','Bontoharu','8'),('99','Bontomanai','8'),('100','Bontomatene','8'),('101','Bontosikuyu','8'),('102','Pasilambena','8'),('103','Pasimarannu','8'),('104','Pasimassunggu','8'),('105','Takabonerate','8'),('106','Bajo','9'),('107','Bassesangtempe','9'),('108','Belopa','9'),('109','Bua','9'),('110','Bua Ponrang','9'),('111','Kamanre','9'),('112','Lamasi','9'),('113','larompong','9'),('114','Larompong Selatan','9'),('115','Latimojong','9'),('116','Poncang','9'),('117','Suli','9'),('118','Walerang','9'),('119','Angkona','10'),('120','burau','10'),('121','malili','10'),('122','mangkutana','10'),('123','nuha','10'),('124','tomoni','10'),('125','towuti','10'),('126','wotu','10'),('127','Baebunta ','11'),('128','Bone-bone','11'),('129','limboang','11'),('130','malangke','11'),('131','malangke barat','11'),('132','mappedeceng','11'),('133','masamba','11'),('134','rampi','11'),('135','sabbang','11'),('136','seko','11'),('137','sukamaju','12'),('138','Bantimurung','12'),('139','camba','12'),('140','cenrana','12'),('141','lau','12'),('142','mallawa','12'),('143','mandai','12'),('144','maros baru','12'),('145','maros utara','12'),('146','marusu','12'),('147','moncongloe','12'),('148','simbang','12'),('149','tanralili','12'),('150','tompobulu','12'),('151','balocci','12'),('152','bungoro','13'),('153','kalukuang masalima','13'),('154','labakkang','13'),('155','liukang tangngaayya','13'),('156','liukang tupabbiring','13'),('157','mandalle','13'),('158','ma\'rang','13'),('159','minasa te\'ne','13'),('160','pangkajene','13'),('161','segeri','13'),('162','tondong talasa','13'),('163','Batulappa','14'),('164','cempa','14'),('165','duampanua','14'),('166','lansirang','14'),('167','lembang','14'),('168','mattiro bulu','14'),('169','mattirosompe','14'),('170','paleteang','14'),('171','patampanua','14'),('172','suppa','14'),('173','tiroang','14'),('174','watang sawitto','14'),('175','baranti','15'),('176','duapitue','15'),('177','kulo','15'),('178','maritengngae','15'),('179','panca lautang','15'),('180','panca rijang','15'),('181','pitu riase','15'),('182','pitu riawa','15'),('183','sidenreng','15'),('184','tellulimpo e','15'),('185','watang pulu','15'),('186','Bulupoddo','16'),('187','Pulau Sembilan','16'),('188','Sinjai Barat','16'),('189','Sinjai Borong','16'),('190','Sinjai Selatan','16'),('191','Sinjai Tengah','16'),('192','Sinjai Timur','16'),('193','Sinjai Utara','16'),('194','tellu limpoe','16'),('195','Donri-Donri','17'),('196','ganra','17'),('197','Labatang','17'),('198','Lili Riaja','17'),('199','Lili rilau','17'),('200','Mario Riawa','17'),('201','Mario Riwawo','17'),('202','Galesong selatan','18'),('203','galesong utara','18'),('204','mangara bombang','18'),('205','mappakasunggu','18'),('206','Patalassang','18'),('207','Polobangkeng selatan','18'),('208','polobangkeng utara','19'),('209','Bituang','19'),('210','Bonggakaradeng','19'),('211','Buntao Rantebua','19'),('212','Makale','19'),('213','Mengkendek','19'),('214','Rantetayo','19'),('215','Saluputti','19'),('216','sanggala','19'),('217','simbuang','19'),('218','Awan Rante karua','20'),('219','balusu','20'),('220','bangkelekila','20'),('221','baruppu','20'),('222','buntao Rantebua','20'),('223','buntu pepasan','20'),('224','dende\' piongan napo','20'),('225','kapala pitu','20'),('226','kesu','20'),('227','nanggala','20'),('228','rantebua','20'),('229','rantepao','20'),('230','rindingallo','20'),('231','sa\'dan','20'),('232','sanggalangi','20'),('233','sesean','20'),('234','sesean suloara','20'),('235','sopai','20'),('236','tikala','20'),('237','tallunglipu','20'),('238','tondong talasa','20'),('239','Belawa','21'),('240','bola','21'),('241','gilireng','21'),('242','keera','21'),('243','majauleng','21'),('244','maniang pajo','21'),('245','penrang','21'),('246','pitumpanua','21'),('247','sabbang paru','21'),('248','sajonging','21'),('249','takkalalla','21'),('250','tana sitolo','21'),('251','tempe','23'),('252','tellu wanua','23'),('253','wara','23'),('254','wara selatan','23'),('255','wara utara','23'),('256','bacukiki','24'),('257','soreang','24'),('258','ujung Bulu','24'),('259','bacukiki barat','24');
/*!40000 ALTER TABLE `kecamatan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kesimpulan`
--

DROP TABLE IF EXISTS `kesimpulan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `kesimpulan` (
  `id` int(11) NOT NULL,
  `tingkat_kesegaran_jasmani` int(11) default NULL,
  `klasifikasi_fungsional` int(11) default NULL,
  `kapasitas_aerobik` varchar(255) default NULL,
  `uljb_jantung_koroner` int(11) default NULL,
  `respons_tekanan_darah` int(11) default NULL,
  `kesimpulan_lainlain` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kesimpulan`
--

LOCK TABLES `kesimpulan` WRITE;
/*!40000 ALTER TABLE `kesimpulan` DISABLE KEYS */;
INSERT INTO `kesimpulan` VALUES (1,0,0,'',0,0,'');
/*!40000 ALTER TABLE `kesimpulan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `konsul`
--

DROP TABLE IF EXISTS `konsul`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `konsul` (
  `id_konsul` int(11) NOT NULL,
  `nama_konsul` varchar(100) NOT NULL,
  PRIMARY KEY  (`id_konsul`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `konsul`
--

LOCK TABLES `konsul` WRITE;
/*!40000 ALTER TABLE `konsul` DISABLE KEYS */;
INSERT INTO `konsul` VALUES (101,'Paviliun Sawit'),(102,'Palm Atas'),(103,'Palm Bawah'),(104,'Lontara 1 Interna Atas'),(105,'Lontara 1 Interna Bawah'),(106,'Lontara 1 Kardiologi'),(107,'Lontara 2 Atas'),(108,'Lontara 2 Bawah'),(109,'Lontara 3 Atas'),(110,'Lontara 3 Bawah'),(111,'Lontara 4 Atas'),(112,'Lontara 4 Bawah'),(201,'Poliklinik Interna'),(202,'Poliklinik Anak'),(203,'Poliklinik Anestesi'),(204,'Poliklinik Bedah Anak'),(205,'Poliklinik Bedah Digestive'),(206,'Poliklinik Bedah Orthoped'),(207,'Poliklinik Bedah Plastik'),(208,'Poliklinik Bedah Syaraf'),(209,'Poliklinik Bedah Tumor'),(210,'Poliklinik Bedah Urologi'),(211,'Poliklinik Endokrin'),(212,'Poliklinik Gastrologi'),(213,'Poliklinik Gigi dan Mulut'),(214,'Poliklinik Gizi'),(215,'Poliklinik Hipertensi'),(216,'Poliklinik Jantung'),(217,'Poliklinik Jiwa'),(218,'Poliklinik Kulit Kelamin'),(219,'Poliklinik Mata'),(220,'Poliklinik Neurologi'),(221,'Poliklinik Obgyn'),(222,'Poliklinik Paru'),(223,'Poliklinik Rehabilitasi Medik'),(224,'Poliklinik Rhematologi'),(225,'Poliklinik Syaraf'),(226,'Poliklinik THT'),(227,'Poliklinik Tropis Menular');
/*!40000 ALTER TABLE `konsul` ENABLE KEYS */;
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
  `cara_berkunjung` varchar(100) default NULL,
  `pilihan_cara_berkunjung` varchar(255) default NULL,
  `cara_bayar` varchar(255) default NULL,
  `pilihan_cara_bayar` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kunjungan`
--

LOCK TABLES `kunjungan` WRITE;
/*!40000 ALTER TABLE `kunjungan` DISABLE KEYS */;
INSERT INTO `kunjungan` VALUES (2,'2009-12-01 12:35:06',12,'Holter',1,NULL,'','0',NULL,NULL,NULL,NULL),(1,'2009-11-22 10:36:27',11,'cardio_dewasa',1,NULL,'Sakit dada','0',NULL,NULL,NULL,NULL),(3,'2009-11-22 19:09:20',10,'EKG',1,1,'','0',NULL,NULL,NULL,NULL),(4,'2009-11-22 18:14:13',9,'EKG',2,1,'','0',NULL,NULL,NULL,NULL),(5,'2009-12-01 12:35:06',1,'EKG',1,NULL,'','0',NULL,NULL,NULL,NULL),(6,'2009-11-23 15:08:52',2,'cardio_dewasa',1,NULL,'','0',NULL,NULL,NULL,NULL),(7,'2009-12-01 12:35:06',3,'cardio_dewasa',2,NULL,'','0',NULL,NULL,NULL,NULL),(8,'2009-12-01 12:35:06',5,'cardio_dewasa',3,NULL,'','0',NULL,NULL,NULL,NULL),(9,'2009-11-23 15:09:36',4,'cardio_dewasa',4,NULL,'','0',NULL,NULL,NULL,NULL),(10,'2009-12-01 12:35:06',13,'EKG',2,NULL,'Nyeri dada kanan','0',NULL,NULL,NULL,NULL),(11,'2009-12-01 12:35:06',14,'cardio_dewasa',4,NULL,'Sesak','0',NULL,NULL,NULL,NULL),(13,'2009-12-01 19:08:25',15,'Treadmill',2,NULL,'','0',NULL,NULL,NULL,NULL),(12,'2009-12-01 23:28:51',11,'vascular',1,NULL,'','0',NULL,NULL,NULL,NULL),(14,'2009-12-01 23:33:19',11,'echocardiography',1,NULL,'','0',NULL,NULL,NULL,NULL),(15,'2009-12-02 08:39:15',11,'Treadmill',1,NULL,'','0',NULL,NULL,NULL,NULL),(16,'2009-12-05 18:01:56',11,'Treadmill',1,NULL,'','0',NULL,NULL,NULL,NULL),(17,'2009-12-06 05:48:03',11,'Treadmill',1,NULL,'','0',NULL,NULL,NULL,NULL),(18,'2009-12-08 05:41:08',11,'cardio_dewasa',1,0,'','0',NULL,NULL,NULL,NULL),(19,'2009-12-10 06:18:44',11,'Treadmill',1,NULL,'','0',NULL,NULL,NULL,NULL),(20,'2009-12-10 21:13:16',11,'Treadmill',2,NULL,NULL,'0',NULL,NULL,NULL,NULL),(21,'2009-12-10 21:14:05',2,'EKG',1,NULL,NULL,'0',NULL,NULL,NULL,NULL),(22,'2009-12-10 21:20:16',9,'Holter',1,NULL,NULL,'0',NULL,NULL,NULL,NULL),(23,'2009-12-13 00:52:12',11,'Holter',1,0,NULL,'0',NULL,NULL,NULL,NULL),(24,'2009-12-13 00:59:53',11,'EKG',1,0,NULL,'0',NULL,NULL,NULL,NULL),(25,'2009-12-13 01:07:31',11,'Treadmill',1,0,NULL,'0',NULL,NULL,NULL,NULL),(26,'2009-12-13 14:27:21',11,'perawatan',1,0,NULL,'0',NULL,NULL,NULL,NULL),(27,'2009-12-15 23:47:17',11,'Treadmill',1,NULL,NULL,'0',NULL,NULL,NULL,NULL),(28,'2009-12-17 13:06:01',11,'vascular',1,NULL,NULL,'0',NULL,NULL,NULL,NULL),(29,'2009-12-18 20:31:06',11,'perawatan',1,0,NULL,'0',NULL,NULL,NULL,NULL),(30,'2009-12-18 22:47:34',11,'EKG',1,NULL,NULL,'0',NULL,NULL,NULL,NULL),(31,'2009-12-19 15:22:28',16,'perawatan',1,NULL,'Batuk-batuk','0','konsul','Poliklinik Jantung','asuransi','JPS'),(32,'2009-12-19 15:49:05',17,'perawatan',2,NULL,'Pusing tujuh keliling','0','konsul','Poliklinik Neurologi','asuransi','Umum'),(33,'2009-12-19 22:24:21',11,'vascular',1,NULL,NULL,'0',NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `kunjungan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `latihan`
--

DROP TABLE IF EXISTS `latihan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `latihan` (
  `id` int(11) NOT NULL,
  `protokol` varchar(100) default NULL,
  `irama_dasar` varchar(100) default NULL,
  `perubahan_gelombang_r` int(11) default NULL,
  `dihentikan_karena` int(11) default NULL,
  `respon_denyut_jantung` int(11) default NULL,
  `puncak_denyut_jantung` varchar(100) default NULL,
  `tekanan_darah` varchar(100) default NULL,
  `tekanan_darah_puncak` varchar(20) default NULL,
  `segmen_st_depresi` varchar(100) default NULL,
  `segmen_st_elevasi` varchar(100) default NULL,
  `segmen_st_konfigurasi` varchar(100) default NULL,
  `denyut_jantung_lainlain` varchar(100) default NULL,
  `rekaman_ekg_lainlain` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `latihan`
--

LOCK TABLES `latihan` WRITE;
/*!40000 ALTER TABLE `latihan` DISABLE KEYS */;
INSERT INTO `latihan` VALUES (1,'|','1|',1,1,0,'< 60 X/menit','','','|','|','','','');
/*!40000 ALTER TABLE `latihan` ENABLE KEYS */;
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
INSERT INTO `mouth` VALUES (1,NULL,1,1,1),(2,NULL,1,1,1),(3,NULL,1,1,1),(4,NULL,1,1,1);
/*!40000 ALTER TABLE `mouth` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `nadi_latihan`
--

DROP TABLE IF EXISTS `nadi_latihan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `nadi_latihan` (
  `no` int(11) NOT NULL auto_increment,
  `umur` varchar(3) NOT NULL,
  `nadi` varchar(3) NOT NULL,
  PRIMARY KEY  (`no`)
) ENGINE=MyISAM AUTO_INCREMENT=53 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `nadi_latihan`
--

LOCK TABLES `nadi_latihan` WRITE;
/*!40000 ALTER TABLE `nadi_latihan` DISABLE KEYS */;
INSERT INTO `nadi_latihan` VALUES (1,'20','197'),(2,'21','196'),(3,'22','196'),(4,'23','196'),(5,'24','194'),(6,'25','194'),(7,'26','193'),(8,'27','192'),(9,'28','192'),(10,'29','191'),(11,'30','191'),(12,'31','190'),(13,'32','190'),(14,'33','188'),(15,'34','188'),(16,'35','187'),(17,'36','187'),(18,'37','186'),(19,'38','186'),(20,'39','186'),(21,'40','184'),(22,'41','183'),(23,'42','183'),(24,'43','182'),(25,'44','182'),(26,'45','181'),(27,'46','181'),(28,'47','179'),(29,'48','179'),(30,'49','178'),(31,'50','178'),(32,'51','177'),(33,'52','177'),(34,'53','175'),(35,'54','175'),(36,'55','175'),(37,'56','175'),(38,'57','174'),(39,'58','174'),(40,'59','173'),(41,'60','171'),(42,'61','171'),(43,'62','170'),(44,'63','170'),(45,'64','169'),(46,'65','169'),(47,'66','168'),(48,'67','167'),(49,'68','166'),(50,'69','165'),(51,'70','165'),(52,'71','155');
/*!40000 ALTER TABLE `nadi_latihan` ENABLE KEYS */;
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
INSERT INTO `neck` VALUES (1,NULL),(2,NULL),(3,NULL),(4,NULL);
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
INSERT INTO `nose` VALUES (1,NULL),(2,NULL),(3,NULL),(4,NULL);
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
INSERT INTO `paru` VALUES (1,1,NULL,1,1,1,1,1,1,1),(2,1,NULL,1,1,1,1,1,1,1),(3,1,NULL,1,1,1,1,1,1,1),(4,1,NULL,1,1,1,1,1,1,1);
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
  `kelamin` tinyint(1) NOT NULL default '1',
  `tp_lahir` varchar(255) default NULL,
  `tgl_lahir` date default NULL,
  `gol_darah` char(2) default NULL,
  `alamat` varchar(255) default NULL,
  `kota` varchar(100) default NULL,
  `propinsi` varchar(100) default NULL,
  `no_identitas` varchar(255) default NULL,
  `sandi` varchar(255) default NULL,
  `status` varchar(20) default NULL,
  `nama_suami_istri` varchar(35) default NULL,
  `pekerjaan_suami_istri` varchar(35) default NULL,
  `foto` varchar(255) default NULL,
  `pekerjaan` varchar(20) default NULL,
  `pendidikan` varchar(50) default NULL,
  `kode_pos` varchar(10) default NULL,
  `no_tlp` varchar(100) default NULL,
  `no_hp` varchar(100) default NULL,
  `agama` varchar(15) default NULL,
  `suku` varchar(20) default NULL,
  `nama_ayah` varchar(50) default NULL,
  `pekerjaan_ayah` varchar(50) default NULL,
  `nama_ibu` varchar(50) default NULL,
  `pekerjaan_ibu` varchar(50) default NULL,
  `inputtime` datetime default NULL,
  `sesi` varchar(255) default NULL,
  `timelog` datetime default NULL,
  `strnum` varchar(100) default NULL,
  `groups` int(11) default NULL,
  `inputer` varchar(100) default NULL,
  `updated` varchar(255) default NULL,
  `tinggi` varchar(20) default NULL,
  `berat` varchar(20) default NULL,
  `tekanan_darah` varchar(20) default NULL,
  `indikasi` varchar(255) default NULL,
  PRIMARY KEY  (`id`),
  UNIQUE KEY `nomor` (`nomor`),
  UNIQUE KEY `strnum` (`strnum`),
  UNIQUE KEY `strnum_2` (`strnum`),
  UNIQUE KEY `strnum_3` (`strnum`),
  UNIQUE KEY `strnum_4` (`strnum`),
  UNIQUE KEY `strnum_5` (`strnum`),
  UNIQUE KEY `strnum_6` (`strnum`),
  UNIQUE KEY `strnum_7` (`strnum`),
  UNIQUE KEY `strnum_8` (`strnum`),
  UNIQUE KEY `strnum_9` (`strnum`),
  UNIQUE KEY `strnum_10` (`strnum`),
  UNIQUE KEY `strnum_11` (`strnum`),
  UNIQUE KEY `strnum_12` (`strnum`),
  UNIQUE KEY `strnum_13` (`strnum`),
  UNIQUE KEY `strnum_14` (`strnum`),
  UNIQUE KEY `strnum_15` (`strnum`),
  UNIQUE KEY `strnum_16` (`strnum`),
  UNIQUE KEY `strnum_17` (`strnum`),
  UNIQUE KEY `strnum_18` (`strnum`),
  UNIQUE KEY `strnum_19` (`strnum`),
  UNIQUE KEY `strnum_20` (`strnum`),
  UNIQUE KEY `strnum_21` (`strnum`),
  UNIQUE KEY `strnum_22` (`strnum`),
  UNIQUE KEY `strnum_23` (`strnum`),
  UNIQUE KEY `strnum_24` (`strnum`),
  UNIQUE KEY `strnum_25` (`strnum`),
  UNIQUE KEY `strnum_26` (`strnum`),
  UNIQUE KEY `strnum_27` (`strnum`),
  UNIQUE KEY `strnum_28` (`strnum`),
  UNIQUE KEY `strnum_29` (`strnum`),
  UNIQUE KEY `strnum_30` (`strnum`),
  UNIQUE KEY `strnum_31` (`strnum`),
  UNIQUE KEY `strnum_32` (`strnum`),
  UNIQUE KEY `strnum_33` (`strnum`),
  UNIQUE KEY `strnum_34` (`strnum`),
  UNIQUE KEY `strnum_35` (`strnum`),
  UNIQUE KEY `strnum_36` (`strnum`),
  UNIQUE KEY `strnum_37` (`strnum`),
  UNIQUE KEY `strnum_38` (`strnum`),
  UNIQUE KEY `strnum_39` (`strnum`),
  UNIQUE KEY `strnum_40` (`strnum`),
  UNIQUE KEY `strnum_41` (`strnum`),
  UNIQUE KEY `strnum_42` (`strnum`),
  UNIQUE KEY `strnum_43` (`strnum`),
  UNIQUE KEY `strnum_44` (`strnum`),
  UNIQUE KEY `strnum_45` (`strnum`),
  UNIQUE KEY `strnum_46` (`strnum`),
  UNIQUE KEY `strnum_47` (`strnum`),
  UNIQUE KEY `strnum_48` (`strnum`),
  UNIQUE KEY `strnum_49` (`strnum`),
  UNIQUE KEY `strnum_50` (`strnum`),
  UNIQUE KEY `strnum_51` (`strnum`),
  UNIQUE KEY `strnum_52` (`strnum`),
  UNIQUE KEY `strnum_53` (`strnum`),
  UNIQUE KEY `strnum_54` (`strnum`),
  UNIQUE KEY `strnum_55` (`strnum`),
  UNIQUE KEY `strnum_56` (`strnum`),
  UNIQUE KEY `strnum_57` (`strnum`),
  UNIQUE KEY `strnum_58` (`strnum`),
  UNIQUE KEY `strnum_59` (`strnum`),
  UNIQUE KEY `strnum_60` (`strnum`),
  UNIQUE KEY `strnum_61` (`strnum`),
  UNIQUE KEY `strnum_62` (`strnum`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `patients`
--

LOCK TABLES `patients` WRITE;
/*!40000 ALTER TABLE `patients` DISABLE KEYS */;
INSERT INTO `patients` VALUES (1,1,'Sutiyem',0,'Blitar','1971-09-13','O','Jl. Raya Keras Km 21','Kabupaten Asmat','Jawa Timur','dlkfjlkkdfnl',NULL,'kawin','','','','','','','','','islam','','','','','','2009-09-29 10:07:07',NULL,NULL,'00001',NULL,'1','0|2009-11-23 09:39:01',NULL,NULL,NULL,NULL),(2,2,'Karjo',1,'Sinjai','1982-08-15','B','Jl. Rusa No. 15','Kabupaten Asmat','Sulawesi Selatan','kdjfnkjdg',NULL,'kawin','','','','','','','','','islam','','','','','','2009-09-29 10:54:57',NULL,NULL,'00002',NULL,'0','0|2009-11-23 15:08:52',NULL,NULL,NULL,NULL),(3,3,'Amir',1,'Makassar','1970-01-01','O','Jl.Sungai saddang','Kabupaten Asmat','Bali','12',NULL,'kawin','','','','','','','','','islam','','','','','','2009-10-28 16:03:46',NULL,NULL,'00003',NULL,'0','0|2009-11-23 15:09:01',NULL,NULL,NULL,NULL),(4,4,'Ma\'ruf',1,'Makassar','1981-01-01','O','Jl.Urip Sumoharjo','Kabupaten Asmat','Bali','',NULL,'kawin','','','','','','','','','islam','','','','','','2009-10-29 11:02:53',NULL,NULL,'00004',NULL,'0','0|2009-11-23 15:09:36',NULL,NULL,NULL,NULL),(5,5,'Anis',1,'Maros','1970-01-01','AB','Jl.Nipa-nipa','Kabupaten Asmat','Bali','',NULL,'kawin','','','','','','','','','islam','','','','','','2009-11-09 14:58:42',NULL,NULL,'00005',NULL,'0','0|2009-11-23 15:09:25',NULL,NULL,NULL,NULL),(6,6,'Santi',0,'Malang','1986-04-02','AB','Jl. Lamadukeleng No. 12','Makassar','Sulawesi Selatan','dksjhfglkjdlg',NULL,'','','','','','','','','','','','','','','','2009-11-09 15:29:17',NULL,NULL,'00006',NULL,'0',NULL,NULL,NULL,NULL,NULL),(7,7,'Accing',1,'Makassar','1990-02-04','B','Jl. RSI Faisal XI No. 42','Makassar','Sulawesi Selatan','jdlgdnfkn',NULL,'','','','','','','','','','','','','','','','2009-11-11 05:55:44',NULL,NULL,'00007',NULL,'0',NULL,NULL,NULL,NULL,NULL),(8,8,'Alif',1,'Makassar','1989-02-17','A','Jl. Kijang No. 14','Makassar','Sulawesi Selatan','jfdl.df.kgdlg',NULL,'','','','','','','','','','','','','','','','2009-11-11 05:55:58',NULL,NULL,'00008',NULL,'0',NULL,NULL,NULL,NULL,NULL),(9,9,'Anas',1,'Makassar','1970-01-01','O','Jl. Borong Raya No.111','Kabupaten Asmat','Bali','',NULL,'kawin','Tia','Ibu Rumah Tangga','','PNS','S1','90000','444444','08131000000','islam','Bugis','Beddu','Petani','Sri','PNS','2009-11-17 16:03:49',NULL,NULL,'00009',NULL,'0','0|2009-11-22 18:14:13',NULL,NULL,NULL,NULL),(10,10,'Anas',1,'Makassar','1970-01-01','O','Jl. Borong Raya No.111','Kabupaten Asmat','Bali','',NULL,'kawin','Tia','Ibu Rumah Tangga','','PNS','S1','90000','444444','08131000000','islam','Bugis','Beddu','Petani','Sri','PNS','2009-11-17 16:04:20',NULL,NULL,'00010',NULL,'0','0|2009-11-20 16:26:36',NULL,NULL,NULL,NULL),(11,11,'Basri',1,'Makassar','1975-01-01','O','Jl.Dg.Baji','7','73','737101017505',NULL,'kawin','Becce','PNS','','PNS','S1','90000','445566','08134455778899','islam','Bugis','Dg.Ambo','Pensiun','Hj.Hasrah','IRT','2009-11-18 11:51:59',NULL,NULL,'00011',NULL,'0','0|2009-12-19 22:24:21','100','60','45',''),(12,12,'Adi',1,'Malang','1971-01-01','O','Jl.Maccini Raya No.111','Kabupaten Asmat','Bali','737101017102',NULL,'kawin','','','','PNS','S2','90000','432345','081310000001','islam','Makassar','Basuki','Petani','Becce','IRT','2009-11-18 12:10:07',NULL,NULL,'00012',NULL,'0','0|2009-11-20 14:24:02',NULL,NULL,NULL,NULL),(13,13,'Rahmat',1,'Makassar','1984-04-01','O','Jl.Pandang Raya No.80 Makassar','Kota Makassar','Sulawesi Selatan','',NULL,'tidak kawin','','','','Pegawai swasta','SMA','','4775432','081310000123','islam','','','','','','2009-11-25 10:43:56',NULL,NULL,'00013',NULL,'0',NULL,NULL,NULL,NULL,NULL),(14,14,'Andi Rahmat',1,'Makassar','1973-01-01','O','Jl.dr.Leimena','Kota Makassar','Sulawesi Selatan','',NULL,'tidak kawin','','','','','','','','','islam','','','','','','2009-11-25 11:39:39',NULL,NULL,'00014',NULL,'0',NULL,NULL,NULL,NULL,NULL),(15,15,'Ida',0,'Bone','1970-01-01','O','BTN Antara','Kota Makassar','Sulawesi Selatan','',NULL,'kawin','','','','','','','','','islam','','','','','','2009-12-01 19:08:25',NULL,NULL,'00015',NULL,'0',NULL,NULL,NULL,NULL,NULL),(16,16,'Bejo Kesupen',1,'Palopo','1972-03-12','','Jl. Wirajaya V','23','73','934795830',NULL,'kawin','Jumarah','Ibu Rumah Tangga',NULL,'Petani','SLTP','9803940','984580985','459845350909','islam','Jawa','Kemis','Petani','Supratin','Ibu Rumah Tangga','2009-12-19 15:22:28',NULL,NULL,'00016',NULL,'0',NULL,'','','',''),(17,17,'Poniyem',0,'Malili','1976-07-18','','Jl. Kejayaan 2 ','10','73','0956804865094',NULL,'kawin','Baso Lahamuddin','PNS',NULL,'Buruh Tani','SD','9856094','9486094068409','09485094065889879','islam','Jawa','Karsan','Petani','Waginah','Ibu Rumah Tangga','2009-12-19 15:49:05',NULL,NULL,'00543',NULL,'0',NULL,'','','','');
/*!40000 ALTER TABLE `patients` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pemberian`
--

DROP TABLE IF EXISTS `pemberian`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pemberian` (
  `id` int(11) NOT NULL,
  `tgl_pemberian_cairan` datetime NOT NULL,
  `jenis_cairan` varchar(100) NOT NULL,
  `pemberi_instruksi_cairan` varchar(100) NOT NULL,
  `instruksi_pemberian_cairan` varchar(100) NOT NULL,
  `pelaksana_instruksi_cairan` varchar(100) NOT NULL,
  `tgl_pemberian_obat` datetime NOT NULL,
  `jenis_obat` varchar(100) NOT NULL,
  `pemberi_instruksi_obat` varchar(100) NOT NULL,
  `instruksi_pemberian_obat` varchar(100) NOT NULL,
  `pelaksana_instruksi_obat` varchar(100) NOT NULL,
  `catatan` varchar(100) NOT NULL,
  `tgl_pemberian_diet` datetime NOT NULL,
  `nama_diet` varchar(100) NOT NULL,
  `catatan_diet` varchar(100) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pemberian`
--

LOCK TABLES `pemberian` WRITE;
/*!40000 ALTER TABLE `pemberian` DISABLE KEYS */;
/*!40000 ALTER TABLE `pemberian` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pemeriksaan`
--

DROP TABLE IF EXISTS `pemeriksaan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pemeriksaan` (
  `id` int(11) NOT NULL,
  `tgl_periksa` datetime NOT NULL,
  `tensi_sistolik` varchar(4) NOT NULL,
  `tensi_diastolik` varchar(4) NOT NULL,
  `nps` varchar(100) NOT NULL,
  `kesadaran` varchar(100) NOT NULL,
  `penivien` varchar(100) NOT NULL,
  `pemasukan` varchar(100) NOT NULL,
  `pengeluaran` varchar(100) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pemeriksaan`
--

LOCK TABLES `pemeriksaan` WRITE;
/*!40000 ALTER TABLE `pemeriksaan` DISABLE KEYS */;
INSERT INTO `pemeriksaan` VALUES (1,'2009-12-05 21:00:14','60','100','nps','sys','peni','oral','muntah');
/*!40000 ALTER TABLE `pemeriksaan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pengkajian`
--

DROP TABLE IF EXISTS `pengkajian`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pengkajian` (
  `id` int(11) NOT NULL,
  `items` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pengkajian`
--

LOCK TABLES `pengkajian` WRITE;
/*!40000 ALTER TABLE `pengkajian` DISABLE KEYS */;
/*!40000 ALTER TABLE `pengkajian` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pengkajian_items`
--

DROP TABLE IF EXISTS `pengkajian_items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pengkajian_items` (
  `id` int(11) NOT NULL,
  `items` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pengkajian_items`
--

LOCK TABLES `pengkajian_items` WRITE;
/*!40000 ALTER TABLE `pengkajian_items` DISABLE KEYS */;
INSERT INTO `pengkajian_items` VALUES (1,'riwayat_kesehatan'),(2,'alergi'),(3,'kondisi'),(4,'nutrisi_kesehatan'),(5,'aktivitas'),(6,'eliminasi'),(7,'pola_tidur'),(8,'psiko_sosial'),(9,'alergi');
/*!40000 ALTER TABLE `pengkajian_items` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `perawatan`
--

DROP TABLE IF EXISTS `perawatan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `perawatan` (
  `id` int(11) NOT NULL,
  `patients` int(11) NOT NULL,
  `kunjungan` int(11) NOT NULL,
  `pukul_masuk` datetime NOT NULL,
  `ruang` int(11) NOT NULL,
  `pukul_keluar` datetime default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `perawatan`
--

LOCK TABLES `perawatan` WRITE;
/*!40000 ALTER TABLE `perawatan` DISABLE KEYS */;
INSERT INTO `perawatan` VALUES (1,11,26,'2009-12-13 22:13:45',3,NULL,0,'2009-12-13 22:14:41','0|2009-12-14 13:44:35');
/*!40000 ALTER TABLE `perawatan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `perawatan_items`
--

DROP TABLE IF EXISTS `perawatan_items`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `perawatan_items` (
  `id` int(11) NOT NULL,
  `items` varchar(100) NOT NULL,
  `module` varchar(100) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `perawatan_items`
--

LOCK TABLES `perawatan_items` WRITE;
/*!40000 ALTER TABLE `perawatan_items` DISABLE KEYS */;
INSERT INTO `perawatan_items` VALUES (1,'pengkajian','pengkajian'),(2,'catatan_pemberian_cairan','pemberianCairan'),(3,'catatan_pemberian_obat','pemberianObat'),(4,'diet','diet'),(5,'pemeriksaan','pemeriksaan'),(6,'tindakan','tindakan'),(7,'catatan_perkembangan','perkembangan'),(8,'rencana','rencana');
/*!40000 ALTER TABLE `perawatan_items` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `perkembangan`
--

DROP TABLE IF EXISTS `perkembangan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `perkembangan` (
  `id` int(11) NOT NULL,
  `tgl_subyektif` int(11) NOT NULL,
  `subyektif` int(11) NOT NULL,
  `tgl_obyektif` int(11) NOT NULL,
  `obyektif` int(11) NOT NULL,
  `tgl_analisa` int(11) NOT NULL,
  `analisa` int(11) NOT NULL,
  `tgl_planning` int(11) NOT NULL,
  `planning` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `perkembangan`
--

LOCK TABLES `perkembangan` WRITE;
/*!40000 ALTER TABLE `perkembangan` DISABLE KEYS */;
/*!40000 ALTER TABLE `perkembangan` ENABLE KEYS */;
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
  `main_soreness` int(11) default '0',
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
INSERT INTO `present_status` VALUES (1,'175','','','2009-11-18 11:52:04',0,0,NULL,NULL),(2,'175','','100/70','2009-11-20 14:22:55',0,0,'1','1'),(3,'165','65','','2009-11-23 15:17:13',0,0,NULL,NULL),(4,'100','60','45','2009-12-08 10:49:15',0,0,'1','3');
/*!40000 ALTER TABLE `present_status` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `propinsi`
--

DROP TABLE IF EXISTS `propinsi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `propinsi` (
  `kode_bps` varchar(2) NOT NULL,
  `nama_propinsi` varchar(30) NOT NULL,
  `kode_iso` varchar(6) NOT NULL,
  `Ibukota_propinsi` varchar(30) NOT NULL,
  `populasi` varchar(10) default NULL,
  `luas` varchar(10) default NULL,
  `status_khusus` varchar(25) default NULL,
  `pulau` varchar(25) NOT NULL,
  PRIMARY KEY  (`kode_bps`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `propinsi`
--

LOCK TABLES `propinsi` WRITE;
/*!40000 ALTER TABLE `propinsi` DISABLE KEYS */;
INSERT INTO `propinsi` VALUES ('11','Nanggroe Aceh Darussalam','ID-AC','Banda Aceh','5.201.002','56.500,51','Daerah Khusus','Sumatera'),('12','Sumatera Utara','ID-SU','Medan','12.450.911','72.427,81','','Sumatera'),('13','Sumatera Barat','ID-SB','Padang','4.566.126','42.224,65','','Sumatera'),('14','Riau','ID-RI','Pekanbaru','4.579.219','87.844,23','','Sumatera'),('15','Jambi','ID-JA','Jambi','2.635.968','45.348,49','','Sumatera'),('16','Sumatera Selatan','ID-SS','Palembang','6.782.339','60.302,54','','Sumatera'),('17','Bengkulu','ID-BE','Bengkulu','1.549.273','19.795,15','','Sumatera'),('18','Lampung','ID-LA','Bandar Lampung','7.116.177','37.735,15','','Sumatera'),('19','Kepulauan Bangka Belitung','ID-BB','Pangkal Pinang','1.043.456','16.424,14','','Sumatera'),('21','Kepulauan Riau','ID-KR','Tanjung Pinang','1.274.848','8.084,01','','Sumatera'),('31','Daerah Khusus Ibukota Jakarta','ID-JK','Jakarta','8.860.381','740,29','Daerah Khusus Ibukota','Jawa'),('32','Jawa Barat','ID-JB','Bandung','38.965.440','36.925,05','','Jawa'),('33','Jawa Tengah','ID-JT','Semarang','31.977.968','32.799,71','','Jawa'),('34','Daerah Istimewa Yogyakarta','ID-YO','Yogyakarta','3.343.651','3.133,15','Daerah Istimewa','Jawa'),('35','Jawa Timur','ID-JI','Surabaya','36.294.280','46.689,64','','Jawa'),('36','Banten','ID-BT','Serang','9.028.816','9.018,64','','Jawa'),('51','Bali','ID-BA','Denpasar','3.383.572','5.449,37','','Nusa Tenggara'),('52','Nusa Tenggara Barat','ID-NB','Mataram','4.184.411','19.708,79','','Nusa Tenggara'),('53','Nusa Tenggara Timur','ID-NT','Kupang','4.260.294','46.137,87','','Nusa Tenggara'),('61','Kalimantan Barat','ID-KB','Pontianak','4.052.345','120.114,32','','Kalimantan'),('62','Kalimantan Tengah','ID-KT','Palangkaraya','1.914.900','153.564,50','','Kalimantan'),('63','Kalimantan Selatan','ID-KS','Banjarmasin','3.281.993','38.884,28','','Kalimantan'),('64','Kalimantan Timur','ID-KI','Samarinda','2.848.798','194.849,08','','Kalimantan'),('71','Sulawesi Utara','ID-SA','Manado','2.128.780','13.930,73','','Sulawesi'),('72','Sulawesi Tengah','ID-ST','Palu','2.294.841','68.089,83','','Sulawesi'),('73','Sulawesi Selatan','ID-SN','Makassar','7.509.704','46.116,45','','Sulawesi'),('74','Sulawesi Tenggara','ID-SG','Kendari','1.963.025','36.757,45','','Sulawesi'),('75','Gorontalo','ID-GO','Gorontalo','922.18','12.165,44','','Sulawesi'),('76','Sulawesi Barat','ID-SR','Mamuju','969.43','16.787,19','','Sulawesi'),('81','Maluku','ID-MA','Ambon','1.251.539','47.350,42','','Maluku'),('82','Maluku Utara','ID-MU','Ternate','884.14','39.959,99','','Maluku'),('91','Papua Barat','[4]','Manokwari','643.01','114.566,40','Daerah Khusus','Papua'),('92','Papua','ID-PA','Jayapura','1.875.388','309.934,40','Daerah Khusus','Papua');
/*!40000 ALTER TABLE `propinsi` ENABLE KEYS */;
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
INSERT INTO `punggung` VALUES (1,NULL,NULL,1,1,NULL),(2,NULL,NULL,1,1,NULL),(3,NULL,NULL,1,1,NULL),(4,NULL,NULL,1,1,NULL);
/*!40000 ALTER TABLE `punggung` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `recovery`
--

DROP TABLE IF EXISTS `recovery`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `recovery` (
  `id` int(11) NOT NULL,
  `irama_dasar` int(11) default NULL,
  `denyut_jantung` int(11) default NULL,
  `gelombang_p` int(11) default NULL,
  `interval_pr` int(11) default NULL,
  `qrs_axis` int(11) default NULL,
  `qrs_durasi` int(11) default NULL,
  `qrs_konfigurasi_patologi` int(11) default NULL,
  `qrs_konfigurasi_r_s` int(11) default NULL,
  `segmen_st_depresi` varchar(150) default NULL,
  `segmen_st_elevasi` varchar(150) default NULL,
  `gelombang_t` varchar(150) default NULL,
  `q_interval` int(11) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `recovery`
--

LOCK TABLES `recovery` WRITE;
/*!40000 ALTER TABLE `recovery` DISABLE KEYS */;
INSERT INTO `recovery` VALUES (1,0,0,0,0,0,0,0,0,'|','|','',0);
/*!40000 ALTER TABLE `recovery` ENABLE KEYS */;
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
INSERT INTO `ref_abdomen_gerakan_dinding_perut` VALUES (1,'Teratur dan bebas bergerak'),(2,'Terlambat sebagian'),(3,'Seluruh nampak tertinggal'),(4,'Gerakan didaerah epigastrium sesuai pulsasi jantung'),(5,'Tampak pulsasi aorta abdominalis'),(6,'Tampak gerakan usus');
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
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_ginjal`
--

LOCK TABLES `ref_abdomen_ginjal` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_ginjal` DISABLE KEYS */;
INSERT INTO `ref_abdomen_ginjal` VALUES (1,'Ginjal teraba'),(2,'Ginjal tidak teraba');
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
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_hepar`
--

LOCK TABLES `ref_abdomen_hepar` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_hepar` DISABLE KEYS */;
INSERT INTO `ref_abdomen_hepar` VALUES (1,'Hati teraba'),(2,'Hati tidak teraba');
/*!40000 ALTER TABLE `ref_abdomen_hepar` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_abdomen_inspeksi_ginjal`
--

DROP TABLE IF EXISTS `ref_abdomen_inspeksi_ginjal`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_abdomen_inspeksi_ginjal` (
  `id` int(11) NOT NULL auto_increment,
  `inspeksi_ginjal` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_inspeksi_ginjal`
--

LOCK TABLES `ref_abdomen_inspeksi_ginjal` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_inspeksi_ginjal` DISABLE KEYS */;
INSERT INTO `ref_abdomen_inspeksi_ginjal` VALUES (1,'ballottement');
/*!40000 ALTER TABLE `ref_abdomen_inspeksi_ginjal` ENABLE KEYS */;
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
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_abdomen_liver`
--

LOCK TABLES `ref_abdomen_liver` WRITE;
/*!40000 ALTER TABLE `ref_abdomen_liver` DISABLE KEYS */;
INSERT INTO `ref_abdomen_liver` VALUES (1,'Limpa teraba'),(2,'Limpa tidak teraba');
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
INSERT INTO `ref_abdomen_perkusi` VALUES (1,'Timpani'),(2,'Pekak');
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
INSERT INTO `ref_abdomen_skin` VALUES (1,'Petichian'),(2,'Icterus'),(3,'Striae'),(4,'Caput medusa'),(5,'Rose spot');
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
INSERT INTO `ref_anusrectum_inspections` VALUES (1,'Hemorroid'),(2,'Fistula'),(3,'Fissure');
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
INSERT INTO `ref_anusrectum_rectal_touche` VALUES (1,'Mukosa'),(2,'Tumor'),(3,'Feses'),(4,'Stricture'),(5,'Nyeri tekan');
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
-- Table structure for table `ref_ekgQrs_Qpatologi`
--

DROP TABLE IF EXISTS `ref_ekgQrs_Qpatologi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekgQrs_Qpatologi` (
  `id` int(11) NOT NULL auto_increment,
  `Qpatologi` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekgQrs_Qpatologi`
--

LOCK TABLES `ref_ekgQrs_Qpatologi` WRITE;
/*!40000 ALTER TABLE `ref_ekgQrs_Qpatologi` DISABLE KEYS */;
INSERT INTO `ref_ekgQrs_Qpatologi` VALUES (1,'I, AVL'),(2,'II,III, AVF'),(3,'V1,V2'),(4,'V1,V2,V3'),(5,'V1,V2,V3,V4'),(6,'V5,V6'),(7,'V1,V2,V3,V4,V5,V6');
/*!40000 ALTER TABLE `ref_ekgQrs_Qpatologi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekgQrs_RlbS`
--

DROP TABLE IF EXISTS `ref_ekgQrs_RlbS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekgQrs_RlbS` (
  `id` int(11) NOT NULL auto_increment,
  `RlbS` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekgQrs_RlbS`
--

LOCK TABLES `ref_ekgQrs_RlbS` WRITE;
/*!40000 ALTER TABLE `ref_ekgQrs_RlbS` DISABLE KEYS */;
INSERT INTO `ref_ekgQrs_RlbS` VALUES (1,'S yang dalam pada V5 - V6'),(2,'S V1 + R V6 >= 7mm'),(3,'Rr\' di V1,V2'),(4,'Rr\' di V5,V6'),(5,'Low voltage');
/*!40000 ALTER TABLE `ref_ekgQrs_RlbS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekgQrs_axis`
--

DROP TABLE IF EXISTS `ref_ekgQrs_axis`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekgQrs_axis` (
  `id` int(11) NOT NULL auto_increment,
  `axis` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekgQrs_axis`
--

LOCK TABLES `ref_ekgQrs_axis` WRITE;
/*!40000 ALTER TABLE `ref_ekgQrs_axis` DISABLE KEYS */;
INSERT INTO `ref_ekgQrs_axis` VALUES (1,'Normal'),(2,'LAD'),(3,'RAD'),(4,'Exthreme RAD');
/*!40000 ALTER TABLE `ref_ekgQrs_axis` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekgQrs_durasi`
--

DROP TABLE IF EXISTS `ref_ekgQrs_durasi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekgQrs_durasi` (
  `id` int(11) NOT NULL auto_increment,
  `durasi` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekgQrs_durasi`
--

LOCK TABLES `ref_ekgQrs_durasi` WRITE;
/*!40000 ALTER TABLE `ref_ekgQrs_durasi` DISABLE KEYS */;
INSERT INTO `ref_ekgQrs_durasi` VALUES (1,'Normal'),(2,'Lebar'),(3,'Sempit');
/*!40000 ALTER TABLE `ref_ekgQrs_durasi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekgQrs_konfig`
--

DROP TABLE IF EXISTS `ref_ekgQrs_konfig`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekgQrs_konfig` (
  `id` int(11) NOT NULL auto_increment,
  `konfig` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekgQrs_konfig`
--

LOCK TABLES `ref_ekgQrs_konfig` WRITE;
/*!40000 ALTER TABLE `ref_ekgQrs_konfig` DISABLE KEYS */;
INSERT INTO `ref_ekgQrs_konfig` VALUES (1,'I, AVL'),(2,'II,III, AVF'),(3,'V1,V2'),(4,'V1,V2,V3'),(5,'V1,V2,V3,V4'),(6,'V5,V6'),(7,'V1,V2,V3,V4,V5,V6');
/*!40000 ALTER TABLE `ref_ekgQrs_konfig` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekgSt_depresi`
--

DROP TABLE IF EXISTS `ref_ekgSt_depresi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekgSt_depresi` (
  `id` int(11) NOT NULL auto_increment,
  `depresi` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekgSt_depresi`
--

LOCK TABLES `ref_ekgSt_depresi` WRITE;
/*!40000 ALTER TABLE `ref_ekgSt_depresi` DISABLE KEYS */;
/*!40000 ALTER TABLE `ref_ekgSt_depresi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekg_denyut_jantung`
--

DROP TABLE IF EXISTS `ref_ekg_denyut_jantung`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekg_denyut_jantung` (
  `id` int(11) NOT NULL auto_increment,
  `denyut_jantung` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=8 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekg_denyut_jantung`
--

LOCK TABLES `ref_ekg_denyut_jantung` WRITE;
/*!40000 ALTER TABLE `ref_ekg_denyut_jantung` DISABLE KEYS */;
INSERT INTO `ref_ekg_denyut_jantung` VALUES (1,'< 60 x/menit'),(2,'60 - 80 x/menit'),(3,'81 - 100 x/menit'),(4,'101 - 120 x/menit'),(5,'121 - 140 x/menit'),(6,'141 - 160 x/menit'),(7,'> 160 x/menit');
/*!40000 ALTER TABLE `ref_ekg_denyut_jantung` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekg_gelombangP`
--

DROP TABLE IF EXISTS `ref_ekg_gelombangP`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekg_gelombangP` (
  `id` int(11) NOT NULL auto_increment,
  `gelombangP` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekg_gelombangP`
--

LOCK TABLES `ref_ekg_gelombangP` WRITE;
/*!40000 ALTER TABLE `ref_ekg_gelombangP` DISABLE KEYS */;
INSERT INTO `ref_ekg_gelombangP` VALUES (1,'P Mitral'),(2,'P Pulmoral'),(3,'Normal');
/*!40000 ALTER TABLE `ref_ekg_gelombangP` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekg_gelombang_t`
--

DROP TABLE IF EXISTS `ref_ekg_gelombang_t`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekg_gelombang_t` (
  `id` int(11) NOT NULL auto_increment,
  `gelombang_t` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekg_gelombang_t`
--

LOCK TABLES `ref_ekg_gelombang_t` WRITE;
/*!40000 ALTER TABLE `ref_ekg_gelombang_t` DISABLE KEYS */;
/*!40000 ALTER TABLE `ref_ekg_gelombang_t` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekg_intervalPR`
--

DROP TABLE IF EXISTS `ref_ekg_intervalPR`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekg_intervalPR` (
  `id` int(11) NOT NULL auto_increment,
  `intervalPR` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekg_intervalPR`
--

LOCK TABLES `ref_ekg_intervalPR` WRITE;
/*!40000 ALTER TABLE `ref_ekg_intervalPR` DISABLE KEYS */;
INSERT INTO `ref_ekg_intervalPR` VALUES (1,'Normal (0,10\" - 0,22\")'),(2,'Memendek (< 0,10\")'),(3,'Memanjang (>= 0,24\")');
/*!40000 ALTER TABLE `ref_ekg_intervalPR` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekg_irama`
--

DROP TABLE IF EXISTS `ref_ekg_irama`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekg_irama` (
  `id` int(11) NOT NULL auto_increment,
  `irama` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekg_irama`
--

LOCK TABLES `ref_ekg_irama` WRITE;
/*!40000 ALTER TABLE `ref_ekg_irama` DISABLE KEYS */;
INSERT INTO `ref_ekg_irama` VALUES (1,'Sinus'),(2,'Atrium flutter'),(3,'Atrium fibrilasi'),(4,'Supra Ventricular Tachycardia'),(5,'Ventricular Tachycardia'),(6,'Junctional Rhytme'),(7,'Sinus Aritmia'),(8,'Heart block');
/*!40000 ALTER TABLE `ref_ekg_irama` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekg_q_interval`
--

DROP TABLE IF EXISTS `ref_ekg_q_interval`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekg_q_interval` (
  `id` int(11) NOT NULL auto_increment,
  `q_interval` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekg_q_interval`
--

LOCK TABLES `ref_ekg_q_interval` WRITE;
/*!40000 ALTER TABLE `ref_ekg_q_interval` DISABLE KEYS */;
INSERT INTO `ref_ekg_q_interval` VALUES (1,'Normal'),(2,'Memanjang');
/*!40000 ALTER TABLE `ref_ekg_q_interval` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekg_sandapan`
--

DROP TABLE IF EXISTS `ref_ekg_sandapan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekg_sandapan` (
  `id` int(11) NOT NULL auto_increment,
  `sandapan` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekg_sandapan`
--

LOCK TABLES `ref_ekg_sandapan` WRITE;
/*!40000 ALTER TABLE `ref_ekg_sandapan` DISABLE KEYS */;
INSERT INTO `ref_ekg_sandapan` VALUES (2,'I, AVL'),(3,'II,III, AVF'),(4,'V1,V2'),(5,'V1,V2,V3'),(6,'V1,V2,V3,V4'),(7,'V5,V6'),(8,'V1,V2,V3,V4,V5,V6'),(1,'-------------');
/*!40000 ALTER TABLE `ref_ekg_sandapan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_ekg_segment`
--

DROP TABLE IF EXISTS `ref_ekg_segment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_ekg_segment` (
  `id` int(11) NOT NULL auto_increment,
  `segment` varchar(20) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_ekg_segment`
--

LOCK TABLES `ref_ekg_segment` WRITE;
/*!40000 ALTER TABLE `ref_ekg_segment` DISABLE KEYS */;
INSERT INTO `ref_ekg_segment` VALUES (1,'1mm - 2mm'),(2,'>2mm - 3mm'),(3,'>3mm');
/*!40000 ALTER TABLE `ref_ekg_segment` ENABLE KEYS */;
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
INSERT INTO `ref_extermitas_inspections` VALUES (1,'Udema'),(2,'Ikterus'),(3,'Sianosis'),(4,'Petichian');
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
-- Table structure for table `ref_faseLatihan_dihentikan`
--

DROP TABLE IF EXISTS `ref_faseLatihan_dihentikan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_faseLatihan_dihentikan` (
  `id` int(11) NOT NULL auto_increment,
  `dihentikan` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_faseLatihan_dihentikan`
--

LOCK TABLES `ref_faseLatihan_dihentikan` WRITE;
/*!40000 ALTER TABLE `ref_faseLatihan_dihentikan` DISABLE KEYS */;
INSERT INTO `ref_faseLatihan_dihentikan` VALUES (1,'Nyeri dada'),(2,'Kecapean'),(3,'THR tercapai'),(4,'Aritmia'),(5,'Dyspnoe'),(6,'Pusing');
/*!40000 ALTER TABLE `ref_faseLatihan_dihentikan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_faseLatihan_konfig_rekaman`
--

DROP TABLE IF EXISTS `ref_faseLatihan_konfig_rekaman`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_faseLatihan_konfig_rekaman` (
  `id` int(11) NOT NULL auto_increment,
  `konfig_rekaman` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_faseLatihan_konfig_rekaman`
--

LOCK TABLES `ref_faseLatihan_konfig_rekaman` WRITE;
/*!40000 ALTER TABLE `ref_faseLatihan_konfig_rekaman` DISABLE KEYS */;
/*!40000 ALTER TABLE `ref_faseLatihan_konfig_rekaman` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_faseLatihan_perubahan_gelombang`
--

DROP TABLE IF EXISTS `ref_faseLatihan_perubahan_gelombang`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_faseLatihan_perubahan_gelombang` (
  `id` int(11) NOT NULL auto_increment,
  `perubahan_gelombang` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_faseLatihan_perubahan_gelombang`
--

LOCK TABLES `ref_faseLatihan_perubahan_gelombang` WRITE;
/*!40000 ALTER TABLE `ref_faseLatihan_perubahan_gelombang` DISABLE KEYS */;
INSERT INTO `ref_faseLatihan_perubahan_gelombang` VALUES (1,'Menetap'),(2,'Meninggi'),(3,'Menurun');
/*!40000 ALTER TABLE `ref_faseLatihan_perubahan_gelombang` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_faseLatihan_protokol`
--

DROP TABLE IF EXISTS `ref_faseLatihan_protokol`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_faseLatihan_protokol` (
  `id` int(11) NOT NULL auto_increment,
  `protokol` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_faseLatihan_protokol`
--

LOCK TABLES `ref_faseLatihan_protokol` WRITE;
/*!40000 ALTER TABLE `ref_faseLatihan_protokol` DISABLE KEYS */;
INSERT INTO `ref_faseLatihan_protokol` VALUES (1,'Bruce stage');
/*!40000 ALTER TABLE `ref_faseLatihan_protokol` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_faseLatihan_respon_jantung`
--

DROP TABLE IF EXISTS `ref_faseLatihan_respon_jantung`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_faseLatihan_respon_jantung` (
  `id` int(11) NOT NULL auto_increment,
  `respon_jantung` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_faseLatihan_respon_jantung`
--

LOCK TABLES `ref_faseLatihan_respon_jantung` WRITE;
/*!40000 ALTER TABLE `ref_faseLatihan_respon_jantung` DISABLE KEYS */;
INSERT INTO `ref_faseLatihan_respon_jantung` VALUES (1,'Normal'),(2,'Abnormal');
/*!40000 ALTER TABLE `ref_faseLatihan_respon_jantung` ENABLE KEYS */;
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
INSERT INTO `ref_headface_expression` VALUES (1,'Normal'),(2,'Sianosis'),(3,'Pucat'),(4,'Kuning Kepucatan'),(5,'Keabu-abuan'),(6,'Facies leontina');
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
INSERT INTO `ref_headface_hair` VALUES (1,'Alpecia'),(2,'Hitam'),(3,'Putih'),(4,'Pirang');
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
INSERT INTO `ref_hearth_auscultation_sound` VALUES (1,'Bising'),(2,'Gesekan pericard');
/*!40000 ALTER TABLE `ref_hearth_auscultation_sound` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_hearth_inspection`
--

DROP TABLE IF EXISTS `ref_hearth_inspection`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_hearth_inspection` (
  `id` int(11) NOT NULL auto_increment,
  `inspection` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
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
INSERT INTO `ref_hearth_intencity` VALUES (1,'Tingkat I'),(2,'Tingkat II'),(3,'Tingkat III'),(4,'Tingkat IV'),(5,'Tingkat V'),(6,'Tingkat VI'),(7,'Tingkat VII');
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
INSERT INTO `ref_hearth_palpation` VALUES (1,'pulsasi'),(2,'Kuat angkat'),(3,'Frekuensi'),(4,'Mengelombang'),(5,'Pukulan-pukulan serentak'),(6,'Thrill');
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
INSERT INTO `ref_hearth_penjalaran` VALUES (1,'tidak menjalar daerah sekitar'),(2,'ke daerah karotis'),(3,'batas sternum kiri'),(4,'ke aksila'),(5,'punggung dan seluruh precordium');
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
INSERT INTO `ref_hearth_percussion_bottom` VALUES (1,'Thoracal 10'),(2,'Thoracal 11'),(3,'Thoracal 12');
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
INSERT INTO `ref_hearth_percussion_left` VALUES (1,'Thoracal 10'),(2,'Thoracal 11'),(3,'Thoracal 12');
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
INSERT INTO `ref_hearth_percussion_right` VALUES (1,'Sonor'),(2,'Hipersonor'),(3,'Pekak'),(4,'Timpani');
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
INSERT INTO `ref_hearth_percussion_top` VALUES (1,'Sonor'),(2,'Hipersonor'),(3,'Pekak'),(4,'Timpani');
/*!40000 ALTER TABLE `ref_hearth_percussion_top` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_holterref_AF`
--

DROP TABLE IF EXISTS `ref_holterref_AF`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_holterref_AF` (
  `id` int(11) NOT NULL auto_increment,
  `AF` varchar(40) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_holterref_AF`
--

LOCK TABLES `ref_holterref_AF` WRITE;
/*!40000 ALTER TABLE `ref_holterref_AF` DISABLE KEYS */;
INSERT INTO `ref_holterref_AF` VALUES (1,'Rapid'),(2,'Normal'),(3,'Slow');
/*!40000 ALTER TABLE `ref_holterref_AF` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_holterref_SVT`
--

DROP TABLE IF EXISTS `ref_holterref_SVT`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_holterref_SVT` (
  `id` int(11) NOT NULL auto_increment,
  `SVT` varchar(40) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_holterref_SVT`
--

LOCK TABLES `ref_holterref_SVT` WRITE;
/*!40000 ALTER TABLE `ref_holterref_SVT` DISABLE KEYS */;
INSERT INTO `ref_holterref_SVT` VALUES (1,'Biasa'),(2,'Aberant');
/*!40000 ALTER TABLE `ref_holterref_SVT` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_holterref_VES`
--

DROP TABLE IF EXISTS `ref_holterref_VES`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_holterref_VES` (
  `id` int(11) NOT NULL auto_increment,
  `VES` varchar(40) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_holterref_VES`
--

LOCK TABLES `ref_holterref_VES` WRITE;
/*!40000 ALTER TABLE `ref_holterref_VES` DISABLE KEYS */;
INSERT INTO `ref_holterref_VES` VALUES (1,'Bigemini'),(2,'Dupleks'),(3,'Tripleks');
/*!40000 ALTER TABLE `ref_holterref_VES` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_holterref_heartblock`
--

DROP TABLE IF EXISTS `ref_holterref_heartblock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_holterref_heartblock` (
  `id` int(11) NOT NULL auto_increment,
  `heartblock` varchar(40) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_holterref_heartblock`
--

LOCK TABLES `ref_holterref_heartblock` WRITE;
/*!40000 ALTER TABLE `ref_holterref_heartblock` DISABLE KEYS */;
INSERT INTO `ref_holterref_heartblock` VALUES (1,'Mobitz I'),(2,'Mobita II');
/*!40000 ALTER TABLE `ref_holterref_heartblock` ENABLE KEYS */;
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
INSERT INTO `ref_punggung_bunyi_pernafasan` VALUES (1,'Vesicular'),(2,'Bronchovesiculer'),(3,'Bronciar'),(4,'Amphoric'),(5,'Astamatic');
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
INSERT INTO `ref_punggung_bunyi_tambahan` VALUES (1,'Tidak ada'),(2,'Ronchi'),(3,'Wheezing'),(4,'Repitasi'),(5,'Gesekan pleura'),(6,'Suctio hipocrates'),(7,'Falling drop sound'),(8,'Coin sign');
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
INSERT INTO `ref_punggung_inspections` VALUES (1,'Kyposis'),(2,'Lordosis'),(3,'Skoliosis');
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
INSERT INTO `ref_punggung_others` VALUES (1,'Nyeri ketok'),(2,'Gerakan');
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
INSERT INTO `ref_punggung_palpations` VALUES (1,'Massa tumor'),(2,'Nyeri tekan');
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
-- Table structure for table `ref_threadKesimpulanSaran_Ulib`
--

DROP TABLE IF EXISTS `ref_threadKesimpulanSaran_Ulib`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_threadKesimpulanSaran_Ulib` (
  `id` int(11) NOT NULL auto_increment,
  `Ulib` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_threadKesimpulanSaran_Ulib`
--

LOCK TABLES `ref_threadKesimpulanSaran_Ulib` WRITE;
/*!40000 ALTER TABLE `ref_threadKesimpulanSaran_Ulib` DISABLE KEYS */;
INSERT INTO `ref_threadKesimpulanSaran_Ulib` VALUES (1,'Positif'),(2,'Negatif'),(3,'Meragukan'),(4,'Tidak dapat diinterpretasi');
/*!40000 ALTER TABLE `ref_threadKesimpulanSaran_Ulib` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_threadKesimpulanSaran_fungsional`
--

DROP TABLE IF EXISTS `ref_threadKesimpulanSaran_fungsional`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_threadKesimpulanSaran_fungsional` (
  `id` int(11) NOT NULL auto_increment,
  `fungsional` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=4 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_threadKesimpulanSaran_fungsional`
--

LOCK TABLES `ref_threadKesimpulanSaran_fungsional` WRITE;
/*!40000 ALTER TABLE `ref_threadKesimpulanSaran_fungsional` DISABLE KEYS */;
INSERT INTO `ref_threadKesimpulanSaran_fungsional` VALUES (1,'I (Normal)'),(2,'II'),(3,'III');
/*!40000 ALTER TABLE `ref_threadKesimpulanSaran_fungsional` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_threadKesimpulanSaran_kesegaran`
--

DROP TABLE IF EXISTS `ref_threadKesimpulanSaran_kesegaran`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_threadKesimpulanSaran_kesegaran` (
  `id` int(11) NOT NULL auto_increment,
  `kesegaran` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=6 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_threadKesimpulanSaran_kesegaran`
--

LOCK TABLES `ref_threadKesimpulanSaran_kesegaran` WRITE;
/*!40000 ALTER TABLE `ref_threadKesimpulanSaran_kesegaran` DISABLE KEYS */;
INSERT INTO `ref_threadKesimpulanSaran_kesegaran` VALUES (1,'Rendah'),(2,'Baik'),(3,'Kurang'),(4,'Baik sekali'),(5,'rata-rata');
/*!40000 ALTER TABLE `ref_threadKesimpulanSaran_kesegaran` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ref_threadKesimpulanSaran_tekananDarah`
--

DROP TABLE IF EXISTS `ref_threadKesimpulanSaran_tekananDarah`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ref_threadKesimpulanSaran_tekananDarah` (
  `id` int(11) NOT NULL auto_increment,
  `tekananDarah` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=5 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ref_threadKesimpulanSaran_tekananDarah`
--

LOCK TABLES `ref_threadKesimpulanSaran_tekananDarah` WRITE;
/*!40000 ALTER TABLE `ref_threadKesimpulanSaran_tekananDarah` DISABLE KEYS */;
INSERT INTO `ref_threadKesimpulanSaran_tekananDarah` VALUES (1,'Respon Kurang < 140 mmHg'),(2,'Respon hipertensi'),(3,'Respon hipertensip'),(4,'Respon menetap');
/*!40000 ALTER TABLE `ref_threadKesimpulanSaran_tekananDarah` ENABLE KEYS */;
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
-- Table structure for table `rencana`
--

DROP TABLE IF EXISTS `rencana`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `rencana` (
  `id` int(11) NOT NULL,
  `keluhan` varchar(255) default NULL,
  `intervensi` varchar(255) default NULL,
  `implementasi` varchar(255) default NULL,
  `perawatan` int(11) NOT NULL,
  `tgl` datetime NOT NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `rencana`
--

LOCK TABLES `rencana` WRITE;
/*!40000 ALTER TABLE `rencana` DISABLE KEYS */;
INSERT INTO `rencana` VALUES (1,'Masuk angin','emboh','raweruh',1,'2009-12-19 20:12:36',0,'2009-12-19 20:14:38',NULL);
/*!40000 ALTER TABLE `rencana` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `riwayat_kesehatan`
--

DROP TABLE IF EXISTS `riwayat_kesehatan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `riwayat_kesehatan` (
  `id` int(11) NOT NULL,
  `perawatan` int(11) NOT NULL,
  `tgl` datetime NOT NULL,
  `cara_masuk` varchar(255) default NULL,
  `keluhan` varchar(255) default NULL,
  `pernah_diopname` varchar(255) default NULL,
  `pernah_berobat` tinyint(1) default NULL,
  `berat_sebelum_sakit` varchar(255) default NULL,
  `berat_sekarang` varchar(255) default NULL,
  `pernah_dioperasi` tinyint(1) default NULL,
  `hari_pasca_operasi` int(11) default NULL,
  `kesadaran` varchar(255) default NULL,
  `pengertian_klien` tinyint(1) default NULL,
  `r_haid_menarche` varchar(255) default NULL,
  `r_haid_dys_menarche` varchar(255) default NULL,
  `r_haid_siklus` varchar(255) default NULL,
  `r_haid_lamanya` varchar(255) default NULL,
  `r_haid_alat_kb` varchar(255) default NULL,
  `r_hamil_hamil` varchar(255) default NULL,
  `r_hamil_hpht` date default NULL,
  `r_hamil_taksiran_pantas` varchar(255) default NULL,
  `r_hamil_usia` varchar(255) default NULL,
  `inputer` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `updated` varchar(100) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `riwayat_kesehatan`
--

LOCK TABLES `riwayat_kesehatan` WRITE;
/*!40000 ALTER TABLE `riwayat_kesehatan` DISABLE KEYS */;
INSERT INTO `riwayat_kesehatan` VALUES (1,1,'2009-12-18 14:49:44','','','',NULL,'','',NULL,0,'',NULL,'','','','','','','2009-12-18','','',0,'2009-12-18 14:49:50',NULL),(2,1,'2009-12-18 15:01:28','UGD','','',NULL,'','',NULL,0,'',NULL,'','','','','','','2009-12-18','','',0,'2009-12-18 15:01:45',NULL);
/*!40000 ALTER TABLE `riwayat_kesehatan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ruang`
--

DROP TABLE IF EXISTS `ruang`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ruang` (
  `id` int(11) NOT NULL,
  `ruang` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ruang`
--

LOCK TABLES `ruang` WRITE;
/*!40000 ALTER TABLE `ruang` DISABLE KEYS */;
INSERT INTO `ruang` VALUES (1,'A'),(2,'B'),(3,'C'),(4,'D');
/*!40000 ALTER TABLE `ruang` ENABLE KEYS */;
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
  `jabatan` varchar(255) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `stafs`
--

LOCK TABLES `stafs` WRITE;
/*!40000 ALTER TABLE `stafs` DISABLE KEYS */;
INSERT INTO `stafs` VALUES (0,'1234567890','admin',1,NULL,'1975-04-10',NULL,'Makassar','Sulawesi Selatan','Indonesia',NULL,0,'denicwibowo@gmail.com','de551978f5fe6b7a8bab5591e5a6588fdcad0cb6114ea5',NULL,NULL),(1,'12345678','Denic Wibowo',1,'Kediri','1975-04-10','Jl. RSI Faisal XI No. 42','Makassar','Sulawesi Selatan','Indonesia','1234567890',0,'denicwibowo@gmail.com','de551978f5fe6b7a8bab5591e5a6588fdcad0cb6114ea5',NULL,NULL),(2,'234234','peter',2,NULL,NULL,NULL,'Makassar',NULL,NULL,NULL,NULL,NULL,'de551978f5fe6b7a8bab5591e5a6588fdcad0cb6114ea5',NULL,NULL),(3,'123123','dr.Pendrik Tandean, SpPD',2,NULL,NULL,NULL,'Makassar',NULL,NULL,NULL,NULL,NULL,'de551978f5fe6b7a8bab5591e5a6588fdcad0cb6114ea5',NULL,'dokter'),(4,'435435','dr.Muzakkir Amir, SpJP',2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,'de551978f5fe6b7a8bab5591e5a6588fdcad0cb6114ea5',NULL,'dokter');
/*!40000 ALTER TABLE `stafs` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `superior`
--

DROP TABLE IF EXISTS `superior`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `superior` (
  `id` int(11) NOT NULL,
  `artery_brachialis` varchar(150) default NULL,
  `artery_radialis` varchar(150) default NULL,
  `artery_ulmaris` varchar(150) default NULL,
  `vena` varchar(150) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `superior`
--

LOCK TABLES `superior` WRITE;
/*!40000 ALTER TABLE `superior` DISABLE KEYS */;
/*!40000 ALTER TABLE `superior` ENABLE KEYS */;
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
INSERT INTO `thorax` VALUES (1,NULL,1),(2,NULL,1),(3,NULL,1),(4,NULL,1);
/*!40000 ALTER TABLE `thorax` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `thr`
--

DROP TABLE IF EXISTS `thr`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `thr` (
  `no` int(11) NOT NULL auto_increment,
  `umur` varchar(3) NOT NULL,
  `nadi_85` varchar(3) NOT NULL,
  PRIMARY KEY  (`no`)
) ENGINE=MyISAM AUTO_INCREMENT=42 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `thr`
--

LOCK TABLES `thr` WRITE;
/*!40000 ALTER TABLE `thr` DISABLE KEYS */;
INSERT INTO `thr` VALUES (1,'35','157'),(2,'36','156'),(3,'37','156'),(4,'38','155'),(5,'39','154'),(6,'40','153'),(7,'41','152'),(8,'42','151'),(9,'43','150'),(10,'44','150'),(11,'45','149'),(12,'46','148'),(13,'47','147'),(14,'48','146'),(15,'49','145'),(16,'50','145'),(17,'51','144'),(18,'52','143'),(19,'53','142'),(20,'54','141'),(21,'55','140'),(22,'56','139'),(23,'57','139'),(24,'58','138'),(25,'59','137'),(26,'60','136'),(27,'61','135'),(28,'62','134'),(29,'63','133'),(30,'64','133'),(31,'65','132'),(32,'66','131'),(33,'67','130'),(34,'68','129'),(35,'69','128'),(36,'70','128'),(37,'71','127'),(38,'72','126'),(39,'73','125'),(40,'74','124'),(41,'75','123');
/*!40000 ALTER TABLE `thr` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tindakan`
--

DROP TABLE IF EXISTS `tindakan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `tindakan` (
  `id` int(11) NOT NULL,
  `tgl_tindakan` datetime NOT NULL,
  `tindakan` int(11) NOT NULL,
  `jenis_tindakan` int(11) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tindakan`
--

LOCK TABLES `tindakan` WRITE;
/*!40000 ALTER TABLE `tindakan` DISABLE KEYS */;
/*!40000 ALTER TABLE `tindakan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `treadmill`
--

DROP TABLE IF EXISTS `treadmill`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `treadmill` (
  `id` int(11) NOT NULL,
  `patients` int(11) NOT NULL,
  `kunjungan` int(11) NOT NULL,
  `inputtime` datetime NOT NULL,
  `inputer` int(11) NOT NULL,
  `updated` varchar(50) NOT NULL,
  `tgl` date NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `treadmill`
--

LOCK TABLES `treadmill` WRITE;
/*!40000 ALTER TABLE `treadmill` DISABLE KEYS */;
INSERT INTO `treadmill` VALUES (1,11,25,'2009-12-13 11:03:44',0,'','2009-12-13');
/*!40000 ALTER TABLE `treadmill` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `vascabdomen`
--

DROP TABLE IF EXISTS `vascabdomen`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `vascabdomen` (
  `id` int(11) NOT NULL,
  `artery_abdominalis` varchar(150) default NULL,
  `artery_renalis` varchar(150) default NULL,
  `vena` varchar(150) default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `vascabdomen`
--

LOCK TABLES `vascabdomen` WRITE;
/*!40000 ALTER TABLE `vascabdomen` DISABLE KEYS */;
/*!40000 ALTER TABLE `vascabdomen` ENABLE KEYS */;
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
  `type` int(11) default '0',
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
INSERT INTO `vital_sign` VALUES (1,'','',0,1,0,1,'','','',1),(2,'','',0,1,0,1,'','','',1),(3,'','',0,1,0,1,'','','',1),(4,'','',0,1,0,1,'','','',1);
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

-- Dump completed on 2009-12-22 16:32:27
