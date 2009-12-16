-- MySQL dump 10.13  Distrib 5.1.31, for debian-linux-gnu (i486)
--
-- Host: localhost    Database: layanan_kesehatan
-- ------------------------------------------------------
-- Server version	5.1.31-1ubuntu2

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
-- Table structure for table `rencana`
--

DROP TABLE IF EXISTS `rencana`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `rencana` (
  `id` int(11) NOT NULL,
  `keluhan` varchar(150) NOT NULL,
  `intervensi` varchar(150) NOT NULL,
  `implementasi` varchar(150) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `rencana`
--

LOCK TABLES `rencana` WRITE;
/*!40000 ALTER TABLE `rencana` DISABLE KEYS */;
/*!40000 ALTER TABLE `rencana` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pemeriksaan`
--

DROP TABLE IF EXISTS `pemeriksaan`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
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
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `pemeriksaan`
--

LOCK TABLES `pemeriksaan` WRITE;
/*!40000 ALTER TABLE `pemeriksaan` DISABLE KEYS */;
INSERT INTO `pemeriksaan` VALUES (1,'2009-12-05 21:00:14','60','100','nps','sys','peni','oral','muntah');
/*!40000 ALTER TABLE `pemeriksaan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tindakan`
--

DROP TABLE IF EXISTS `tindakan`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
CREATE TABLE `tindakan` (
  `id` int(11) NOT NULL,
  `tgl_tindakan` datetime NOT NULL,
  `tindakan` int(11) NOT NULL,
  `jenis_tindakan` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `tindakan`
--

LOCK TABLES `tindakan` WRITE;
/*!40000 ALTER TABLE `tindakan` DISABLE KEYS */;
/*!40000 ALTER TABLE `tindakan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pemberian`
--

DROP TABLE IF EXISTS `pemberian`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
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
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `pemberian`
--

LOCK TABLES `pemberian` WRITE;
/*!40000 ALTER TABLE `pemberian` DISABLE KEYS */;
/*!40000 ALTER TABLE `pemberian` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `perkembangan`
--

DROP TABLE IF EXISTS `perkembangan`;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
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
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
SET character_set_client = @saved_cs_client;

--
-- Dumping data for table `perkembangan`
--

LOCK TABLES `perkembangan` WRITE;
/*!40000 ALTER TABLE `perkembangan` DISABLE KEYS */;
/*!40000 ALTER TABLE `perkembangan` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2009-12-07  3:45:28
