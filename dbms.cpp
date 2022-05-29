
Database - Consistent logical collection of data that can be easily update, accessed and managed. 
Contains set of tables or objects which consists of records and fields.  


-------------------------------------------------------------------------------------
DBMS 

Set of applications of programs that enables users to create and maintain a database.   
They provide various tools for performing operations such as insert, delete and updating into database. 

-----------------------------------------------------------------------------------

File system vs database 

Indexing is absent in file system, hard time to search for something.
Redundancy and inconsistency.  
Lack of concurrency control.  
ACID properties in a file system are not present.   

--------------------------------------------------------------------------------------

Advantages of DBMS 

- Data sharing
- Integrity constraints. 
- Controlling Redundancy in database. 
- Data security - authentication at different levels. 

-----------------------------------------------------------------------------------------

Database languages 

- DDL - Data definition language commands - create, alter, drop, truncate and rename
- DML - Data manipulation language commands  - select, insert, update
- DCL - Data control language commands  - grant and revoke
- TCL - Transaction control language commands  - commit, rollback 

------------------------------------------------------------------------------------------

ACID properties

1. Atomicity - Concept of either executing the complete query or not executing anything at all. 
2. Consistency - Data remains consistent before and after performing the transaction. 
3. Isolation - The state of one transaction does not affect the state of other ongoing transactions, that each transaction is occuring independently of the others. 
4. Durability - Data is not lost in case of system failure, database remains in same state before and afer system failure.  


------------------------------------------------------------------------------------------

Data abstraction levels 

1. Physical level 
2. Logical level
3. View level 

---------------------------------------------------------------------------------------

Locks in database 

Used to lock data in database so that one user can have write access to it
They are used in order to avoid inconsistency. 

Locks are of two types - Shared lock and Exclusive lock    

---------------------------------------------------------------------------------------

Deadlock 

A state where two processes are waiting indefinitely for each other to give up resources so
that can they begin their execution.   

Example - Bf / gf fight

--------------------------------------------------------------------------------------

Normalization  

Process of reducing redundancy in the database by organizing data into multiple tables. 
Leads to better usage of disk spaces and makes it easier to maintain the integrity of database 

First Normal Form  - multi-valued attributes should be split and written in seperate rows. 
Second Normal Form - 1NF + every non-prime attribute must be fully functionally dependent on primary key. 
Third Normal Form  - 2NF + no transitive dependency on any two attributes in the same relation. 
Boyce Codd Normal Form  - 3NF + for every A->B  functional dependency A must be the super key. 


------------------------------------------------------------------------------------------

Keys in database 

Candidate key - set of attributes that can uniquely identify a row. 
Primary key  - one of the candidate keys chosen as primary key 
Super Key - superset of candidate keys   
Unique key  - same as primary key but it also allows null values. 
Foreign key  - column of relation which is same as primary key of some other relation (referencing table)
Alternate key - all candidate keys which are not primary keys. 

-----------------------------------------------------------------------------------------

CREATE TABLE STUDENT (ID INT NOT NULL, NAME VARCHAR2(255), PRIMARY KEY(ID))
CREATE TABLE STUDENTS(ID INT, NAME VARCHAR2(255), LIBRARY_ID INT, FOREIGN KEY(LIBRARY_ID)
						REFERENCES LIBRARY(LIBRARY_ID))

-----------------------------------------------------------------------------------------

Joins 

Used to combine rows from two or more tables based on some column. 

Inner Join - retreives records that have matching values in both the tables. 
Left outer join  - on common column retreives rows on left table and matched rows on right table. 
Right outer join - on common column retreives rows on right table and matched rows on left table. 
Full join  - retreives all records whether there is a match on the left side or on right side. 


select * from table_1 left join table_2 on table_1.col = table_2.col;
select * from table_1 right join table_2 on table_1.col = table_2.col; 
select * from table_1 full joino table_2 on table_1.col = table_2.col; 

----------------------------------------------------------------------------------------

Triggers, procedures and functions 

Procedures - set of code written in order to avoid code rewriting. [ code reusability ]
Triggers - special kind of procedure that executes only when some triggering event such as insert, update or delete takes place.  
SQL functions - A function is a database object in SQL server. Takes in some parameters and produce output in a single value form or tabular form. 

-------------------------------------------------------------------------------------

What is indexing ? 


Indexing is a data structure technique which allows you to quickly retreive record from a database
file. 

It has two columns, the first column has the value of primary key and the second column has a 
pointer to where the actual specific record is stored.  

An index takes search key as an input and efficiently returns set of matching records.  

____________________
|				    |
| Types of indexing |
|___________________|

1. Primary indexing - Dense and sparse.
Dense - a record is created for each search key in the database. Helps for searching faster
 But requires more space. 

Sparse - index record that appears only for some of the values in file. Helps issue of dense indexing 
in dbms,

2. Secondary indexing - two level indexing technique, 
3. Clustering indexing  - pointer to a block and not a specific record, 

-----------------------------------------------------------------------------------------------




























































