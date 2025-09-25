-- Grades assigned to students.
SELECT t.ID, s.name, t.course_id, t.grade
FROM takes t 
JOIN student s ON t.ID = s.ID
WHERE t.grade IS NOT NULL

-- Course IDs and titles of courses offered during the Spring semester of the year 2010.
SELECT c.course_id, c.title 
FROM course c 
JOIN section s ON c.course_id = s.course_id 
WHERE s.year = "2010"
AND s.semester = "Spring"

-- Course IDs of courses that serve as prerequisites for other courses.
SELECT p.prereq_id 
FROM prereq p 
WHERE p.prereq_id <> p.course_id 

-- IDs and names of students who received an A grade for the course CS-190 in the Spring 2009 semester.
SELECT s.ID, s.name 
FROM student s 
JOIN takes t ON s.ID = t.ID
WHERE t.grade = "A"
AND t.course_id = "CS-190"
AND t.semester = "Spring"
AND t.year = "2009"

-- Buildings where students with the last name Brown had classes in the Spring 2010 semester.
SELECT s.building
FROM section s 
JOIN takes t ON s.sec_id = t.sec_id
JOIN student st ON t.ID = st.ID
WHERE st.name = "Brown"
AND s.semester = "Spring"
AND s.year = "2010" 

-- Names and IDs of students taught by instructors with the last name Gold.
SELECT s.name, s.ID
FROM student s
JOIN takes t ON s.ID = t.ID
JOIN teaches te ON t.course_id = te.course_id
JOIN instructor i ON te.ID = i.id
WHERE i.name = "Gold"

-- Names and IDs of students who received an A grade for both courses CS-315 and CS-347.
SELECT s.ID, s.name
FROM student s
JOIN takes t ON s.ID = t.ID
WHERE t.grade = 'A'
AND t.course_id IN ('CS-315', 'CS-347')
GROUP BY s.id, s.name
HAVING COUNT(DISTINCT t.course_id) = 2

-- IDs of courses that have prerequisites.
SELECT p.course_id 
FROM prereq p 
WHERE p.prereq_id <> p.course_id 

-- Course IDs and titles along with their prerequisites IDs and titles.
SELECT c1.course_id AS "Course ID", c1.title AS "Course Title", p.prereq_id "Prereq Course", c2.title AS "Prereq Course Title"
FROM course c1
JOIN prereq p ON c1.course_id = p.course_id 
JOIN course c2 ON p.prereq_id = c2.course_id
WHERE p.prereq_id <> p.course_id

-- IDs of instructors who serve as advisors.
SELECT DISTINCT a.i_ID 
FROM advisor a

