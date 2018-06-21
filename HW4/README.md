# Hash_Table

### Spec :

    In this homework, you have to implement a hash table (class) to store the patients' data in a hospital. 
    As the attached file, each row indicates the index (key), gender, height, and weight of a patient. 
    The goal is to retrieve data from the table efficiently. 
    To achieve this, you can choose any hash function you want and tune the parameters. 
    Just do your best to make the hash as fast as possible. 
    You can start your program from the attached main.cpp file, 
    and implement HashTable.h and HashTable.cpp files to make the whole project works.

    Since performance plays an important role in this homework, 
    you will get only 80% of the scores if your hash function can retrieve all the test data correctly. 
    The performance score 20% should be earned by making your program fast! 
    In other words, 
    you get full 20% if your program is the fastest among the homeworks; but get 0% if it is the slowest. 
    The performance score of a program, in which its performance is in between the fastest and the slowest, 
    will be determined by linear interpolation.

### Introduction :

    Assume the hash table has 10,000 slots, using the BKDR-hash function to get the index of the key.
    
    While insert a data into the table[index], we insert it from the head to avoid time-waste. 
