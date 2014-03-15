CREATE DATABASE tnotes;

USE tnotes;

CREATE TABLE user(
    username varchar(80) NOT NULL,
    pass varchar(80) NOT NULL,
    salt varchar(30) NOT NULL,
    PRIMARY KEY(username)
)CHARSET=utf8;

CREATE TABLE node(
    nodeID int(11) NOT NULL AUTO_INCREMENT,
    parentID int(11) NOT NULL DEFAULT 0,
    username varchar(80) NOT NULL,
    name varchar(80) NOT NULL,
    createTime timestamp DEFAULT CURRENT_TIMESTAMP,
    modifiedTime timestamp DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY(nodeID)
)AUTO_INCREMENT = 10000;


CREATE TABLE article()(
    articleID int(11) NOT NULL AUTO_INCREMENT,
    name varchar(80) NOT NULL,
    context LONGTEXT,
    PRIMARY KEY(articleID)
);

CREATE TABLE articleLocation(
    articleID int(11) NOT NULL,
    nodeID int (11) NOT NULL,
);

CREATE TABLE tmpArticle(
    articleID int(11) NOT NULL,
    name varchar(80) NOT NULL,
    context LONGTEXT,
    PRIMARY KEY(articleID)
);
