import static org.junit.jupiter.api.Assertions.*;

import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.SQLIntegrityConstraintViolationException;

import org.junit.jupiter.api.Test;

class DepartmentMgTester {

	Connection conn;
	DepartmentMg d = new DepartmentMgImpl();

	{
		try {
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/university?user=root&password=db123");
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}

	/**
	 * Tests if the department is successfully added.
	 */
	@Test
	void testAddDepartment1() throws SQLException {
		assertTrue(1 == d.addDepartment(conn, "Engineering", "Bruner Hall", new BigDecimal(150000)));
	}

	/**
	 * Tests if the department is successfully added. Name ''' for the department
	 * could reveal possibility of the SQL injection attack.
	 */
	@Test
	void testAddDepartment2() throws SQLException {
		assertTrue(1 == d.addDepartment(conn, "'", "Foundation Hall", new BigDecimal(50000)));
	}

	/**
	 * Tests if the department is successfully added. Name '' or true -- ' for the
	 * building could reveal possibility of the SQL injection attack.
	 */
	@Test
	void testAddDepartment3() throws SQLException {
		assertTrue(1 == d.addDepartment(conn, "Chemistry", "' or true -- ", new BigDecimal(50000)));
	}

	/**
	 * Tests if the department is NOT added, since such a department already
	 * exists.There already exists department 'Comp. Sci.'.
	 */
	@Test
	void testAddDepartment4() throws SQLException {
		try {
			d.addDepartment(conn, "Comp. Sci.", "Bruner Hall", new BigDecimal(150000));
		} catch (SQLIntegrityConstraintViolationException e) {
			assertTrue(true);
		}
	}

	/**
	 * Tests if the building in which the main office of the department is located
	 * is successfully changed. There is a 'Comp. Sci.' department.
	 */
	@Test
	void testUpdateDepartmentBuilding1() throws SQLException {
		assertTrue(1 == d.updateDepartmentBuilding(conn, "Comp. Sci.", "Taylor"));
	}

	/**
	 * Tests if the building in which the main office of the department is located
	 * is NOT changed. There is no 'Sanitation' department.
	 */
	@Test
	void testUpdateDepartmentBuilding2() throws SQLException {
		assertTrue(0 == d.updateDepartmentBuilding(conn, "Sanitation", "Taylor"));
	}

	@Test
	/**
	 * Tests if the budget of the department is successfully changed. There is a
	 * 'Comp. Sci.' department.
	 */
	void testUpdateDepartmentBudget1() throws SQLException {
		assertTrue(1 == d.updateDepartmentBudget(conn, "Comp. Sci.", new BigDecimal(200000)));
	}

	@Test
	/**
	 * Tests if the budget of the department is NOT changed. There is no 'Logistics'
	 * department.
	 */
	void testUpdateDepartmentBudget2() throws SQLException {
		assertTrue(0 == d.updateDepartmentBudget(conn, "Logistics", new BigDecimal(200000)));
	}
}
