# Library management system

This mini project is built using data structures in C programming by using singly linked list.

In this program, the user is first directed to the login page where three choices are given :
1.	Login as an administrator
2.	Login as a student
3.	Exit

1] As an administrator : If the user chooses to login as an administrator he/she is asked for a password and will be allowed control of the admin panel only if the password is correct else they will be redirected back to the login page.
The admin can do the following operations:
i) createRecord() : This function allows the admin to create a new record whenever a book is issued. The following details are required while creating a new record :
1.	Book ID - every book in the library has a unique identity to distinguish them from other books. This Id is also required while returning the book.
2.	Issue duration - the period for which the student wants to issue the book.
3.	Branch - the branch in which the student is studying.
4.	Roll number - the student's roll number.
5.	Mobile number - the mobile number of the student.
6.	Date - the date of issue is also recorded.
ii)deleteRecord() : This function is used to delete a record when the student returns the book.
iii)displayRecords() : This function can be used by the admin to see all the books issued till date with all the details.
iv) changePassword() : the administrator can also change the password. When the admin changes the password they will be redirected to the login page and have to login again using the new password.

2] As a student : If the user chooses to login as a student,records of all the books issued by them can be viewed by entering their roll number. Students are only allowed to view their record and cannot alter it.

3] Exit : this option will take the user out of the program i.e., the program gets terminated.

![1](https://drive.google.com/file/d/1uUeEp6q-MaIEnOAU4mYvlodcYWsw6--f/view?usp=sharing)
![2](https://drive.google.com/file/d/1ebQeaDAHxZXKq2JbiUvB_IyF8fzLjsE-/view?usp=sharing)
![3](https://drive.google.com/file/d/1l36Nf3OyEJzQXKSjOgnyC-jzsQlVuWwZ/view?usp=sharing)
![4](https://drive.google.com/file/d/1FbBlPQVSzMQ1_8-CaeiWwlyQlHBam7jL/view?usp=sharing)
![5](https://drive.google.com/file/d/1On-kL9u4JClXOC0i9rZPU8CRtxXNGyat/view?usp=sharing)
![image](https://drive.google.com/uc?export=view&id=1uUeEp6q-MaIEnOAU4mYvlodcYWsw6--f)

