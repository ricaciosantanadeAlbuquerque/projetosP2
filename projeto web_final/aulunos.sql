-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Tempo de geração: 14-Dez-2021 às 06:22
-- Versão do servidor: 10.4.20-MariaDB
-- versão do PHP: 7.3.29

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Banco de dados: `usuários`
--

-- --------------------------------------------------------

--
-- Estrutura da tabela `aulunos`
--

CREATE TABLE `aulunos` (
  `nome` varchar(45) NOT NULL,
  `matricula` int(5) NOT NULL,
  `nota1` float NOT NULL,
  `nota2` float NOT NULL,
  `media` float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8mb4;

--
-- Extraindo dados da tabela `aulunos`
--

INSERT INTO `aulunos` (`nome`, `matricula`, `nota1`, `nota2`, `media`) VALUES
('ricacio', 4, 4, 4, 4),
('sara', 7, 9, 10, 9.5),
('carlos', 8, 1, 2, 1.5),
('luerdes', 777, 10, 9.5, 9.75),
('niel', 778, 8, 9, 8.5),
('suelen', 22, 3, 3, 3);

--
-- Índices para tabelas despejadas
--

--
-- Índices para tabela `aulunos`
--
ALTER TABLE `aulunos`
  ADD PRIMARY KEY (`matricula`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
