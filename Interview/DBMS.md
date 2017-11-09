#### NoSQL vs SQL
1. Scalability
2. Flexibility - like facebook post may include pics or comments while others not.
3. Distributed system-


#### BASE property
1. Basically Available
2. Soft State - State may change without any input.(Synchronize with other machines)
3. Eventual Consistency - Database may not be consistent but after some time the update machines transfert the update to other machines.


#### NoSQL Database
1. Columnar Family - Normally(row based) all attributes of tuples are stored then next tuples are stored. While in Columnar Database First attribute of all tuples is stored than next attribute so on so forth. Column Family store some set of column in one disk block(1 attribute or set of related attribute). If two or more tuples share some attribute then compresssing is possible. Faster query and Faster Join on 1 tuple because 1 disk block contains more tuples. Updates are bad.

2. Key Value Pair- Schema(Key,Value) , Query is only on key.
Index is build on key (Cassandra,Couch,Reddish). Map reduce framwork can be used.

3. Document Database - XML, JSON. Tree structure. Insert one but read many. Mongo DB, Couch DB. Map reduce framwork can be used.

4. Graph Database - Entire tuples are represented as graph. Nodes represented entity and edges represented relationship. Titan , Neo4j.   
