---
date: Sep 24 2025, Wed - 1:21:34am
---
Compose SQL queries to retrieve the following data from the University database.  
  
The diagram can be found in the file: [Schema Diagram for University Database](https://elearn.tntech.edu/content/enforced/8458269-11680.202110/R_Diagram_university_db1.pdf).   
Schema for the database can be found in the file: [university_schema_MySQL.sql](https://elearn.tntech.edu/content/enforced/9083084-80744.202280/university_schema_MySQL1.sql).  
Database instance can be found in the file: [smallRelationsInsertFile_MySQL.sql](https://elearn.tntech.edu/content/enforced/9083084-80744.202280/smallRelationsInsertFile_MySQL1.sql).

**Part 1 Prompts**
```sql
-- Grades assigned to students.
-- Course IDs and titles of courses offered during the Spring semester of the year 2010.
-- Course IDs of courses that serve as prerequisites for other courses.
-- IDs and names of students who received an A grade for the course CS-190 in the Spring 2009 semester.
-- Buildings where students with the last name Brown had classes in the Spring 2010 semester.
-- Names and IDs of students taught by instructors with the last name Gold.
-- Names and IDs of students who received an A grade for both courses CS-315 and CS-347.
-- IDs of courses that have prerequisites.
-- Course IDs and titles along with their prerequisites IDs and titles.
-- IDs of instructors who serve as advisors.
```

**Part 2 Prompts**
```sql
-- 1. Retrieve the IDs and names of students taught by the instructor with ID '15151'. Include the course titles and the grades these students received.
-- 2. For each instructor, retrieve their ID along with the count of advisees. If an instructor does not have any advisees, include their ID in the result with a count of 0.
-- 3. Retrieve the course ID, title, semester, and year for each course that was taught by two or more instructors in the same semester and year.
-- 4. Retrieve the IDs and names of students, along with the IDs and names of instructors who taught them in three or more different course sections.
-- 5. Retrieve the IDs and names of students who enrolled in a course taught by their current advisor.
-- 6. Retrieve the IDs and names of students, along with information about courses (course IDs) they have taken more than once.
-- 7. Retrieve the credit hours each instructor taught in the Fall semester of 2009. Exclude instructors who did not teach during that semester.
-- 8. Include the course ID, title, and department name for each course, along with the corresponding prerequisite course ID, title, and department name.
-- 9. For each department (department name) the average number of credits they offer per year.
-- 10. Building and room number of classrooms with the smallest capacity.
```

*Code in TTU repo*
