/*********/
/*       */
/* q.SQL */
/*       */
/*********/

/* Disable Foreign Keys */
pragma foreign_keys = off;
/* Begin Transaction */
begin transaction;

/* Database [Words] */
pragma auto_vacuum=0;
pragma encoding='UTF-8';
pragma page_size=1024;

/* Drop table [blah] */
drop table if exists [blah];

/* Table structure [blah] */
CREATE TABLE [blah] (
  [firstname] VARCHAR(10) NOT NULL ON CONFLICT IGNORE, 
  [lastname] VARCHAR(10) NOT NULL ON CONFLICT IGNORE);

/* Data [blah] */
insert into [blah] values('blah', 'sheep');
insert into [blah] values('sadf', 'asdf');
insert into [blah] values('test', 'test2');


/* Commit Transaction */
commit transaction;

/* Enable Foreign Keys */
pragma foreign_keys = on;
