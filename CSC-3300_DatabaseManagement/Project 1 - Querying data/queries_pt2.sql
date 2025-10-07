-- 1. Retrieve the IDs and names of students taught by the instructor with ID '15151'. Include the course titles and the grades these students received.
SELECT 
	s.ID AS StudentID, 
	s.name AS StudentName, 
	c.title AS CourseTitle, 
	tk.grade AS Grade
FROM student s
JOIN takes tk ON s.ID = tk.ID
JOIN course c ON tk.course_id = c.course_id
JOIN teaches te ON tk.course_id = te.course_id
WHERE te.ID = '15151'

-- 2. For each instructor, retrieve their ID along with the count of advisees. If an instructor does not have any advisees, include their ID in the result with a count of 0.
SELECT 
	i.id AS InstructorID, 
	COUNT(a.s_ID) AS AdviseeCount
FROM instructor i
LEFT JOIN advisor a ON i.id = a.i_ID
GROUP BY i.id

-- 3. Retrieve the course ID, title, semester, and year for each course that was taught by two or more instructors in the same semester and year.
SELECT
	c.course_id AS CourseID,
	c.title AS CourseTitle,
	s.semester AS Semester,
	s.year AS Year,
	COUNT(t.ID)
FROM teaches t
JOIN course c ON t.course_id = c.course_id
JOIN section s ON t.course_id = s.course_id AND t.sec_id = s.sec_id AND t.year = s.year AND t.semester = s.semester
GROUP BY s.course_id, s.year, s.semester
HAVING COUNT(t.ID) >= 2

-- 4. Retrieve the IDs and names of students, along with the IDs and names of instructors who taught them in three or more different course sections.
SELECT
	s.ID AS StudentID,
	s.name AS StudentName,
	COUNT(i.id) AS InstructorCount
FROM student s
JOIN takes tk ON s.ID = tk.ID
JOIN teaches te ON tk.course_id = te.course_id AND tk.sec_id = te.sec_id AND tk.year = te.year AND tk.semester = te.semester
JOIN instructor i ON te.ID = i.id
GROUP BY s.ID
HAVING COUNT(i.id) >= 3

-- 5. Retrieve the IDs and names of students who enrolled in a course taught by their current advisor.
SELECT DISTINCT
	s.ID, 
	s.name
FROM student s
JOIN takes tk ON s.ID = tk.ID
JOIN teaches te ON tk.course_id = te.course_id
JOIN instructor i ON te.ID = i.id
JOIN advisor a ON s.ID = a.s_ID

-- 6. Retrieve the IDs and names of students, along with information about courses (course IDs) they have taken more than once.
SELECT 
	s.ID, 
	s.name,
	tk.course_id
FROM student s 
JOIN takes tk ON s.ID = tk.ID
GROUP BY s.ID, s.name, tk.course_id
HAVING COUNT(tk.course_id) > 1

-- 7. Retrieve the credit hours each instructor taught in the Fall semester of 2009. Exclude instructors who did not teach during that semester.
SELECT i.id, i.name, SUM(c.credits)
FROM instructor i
JOIN teaches te ON i.id = te.ID
JOIN course c ON te.course_id = c.course_id
WHERE te.year = '2009'
AND te.semester = 'Fall'
GROUP BY i.id

-- 8. Include the course ID, title, and department name for each course, along with the corresponding prerequisite course ID, title, and department name.
SELECT c.course_id AS Course, c.title AS Title, c.dept_name AS Department, p.prereq_id AS PrereqID
FROM course c
LEFT JOIN prereq p ON c.course_id = p.course_id

-- 9. For each department (department name) the average number of credits they offer per year.

-- 10. Building and room number of classrooms with the smallest capacity.
