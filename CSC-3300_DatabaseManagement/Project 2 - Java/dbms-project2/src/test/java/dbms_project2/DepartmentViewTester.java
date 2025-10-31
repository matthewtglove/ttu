import static org.junit.jupiter.api.Assertions.*;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import org.junit.jupiter.api.Test;

class DepartmentViewTester {

	Connection conn;
	DepartmentView dv = new DepartmentViewImpl();

	{
		try {
			conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/university?user=root&password=db123");
		} catch (SQLException e) {
			e.printStackTrace();
		}

	}

	/**
	 * Tests if the department is successfully added. 'Engineering' is a valid name
	 * for the department. 'Bruner Hall' is a valid value for the building. '150000'
	 * is a valid value for the budget.
	 */
	@Test
	void testAddDepartment1() throws SQLException {
		assertFalse(-1 == dv.addDepartment(conn, "Spanish", "Bruner Hall", "150000"));
	}

	/**
	 * Tests if the department is NOT added. Name 'Computer Science Department' for
	 * the department is too long. 'Bruner Hall' is a valid value for the building.
	 * '150000' is a valid value for the budget.
	 */
	@Test
	void testAddDepartment2() throws SQLException {
		assertTrue(-1 == dv.addDepartment(conn, "Computer Science Department", "Bruner Hall", "150000"));
	}

	/**
	 * Tests if the department is NOT added. 'Fine Arts' is a valid name for the
	 * department. Name 'Renaissance Hall' for the building is too long. '150000' is
	 * a valid value for the budget.
	 */
	@Test
	void testAddDepartment5() throws SQLException {
		assertTrue(-1 == dv.addDepartment(conn, "Communications", "Renaissance Hall", "150000"));
	}

	/**
	 * Tests if the department is NOT added. 'Fine Arts' is a valid name for the
	 * department. 'Bruner Hall' is a valid value for the building. '99999999999' is
	 * too big of a value for the budget.
	 */
	@Test
	void testAddDepartment6() throws SQLException {
		assertTrue(-1 == dv.addDepartment(conn, "Fine Arts", "Bruner Hall", "99999999999"));
	}

	/**
	 * Tests if the department is NOT added. 'Fine Arts' is a valid name for the
	 * department. 'Bruner Hall' is a valid value for the building. '0' is too small
	 * of a value for the budget.
	 */
	@Test
	void testAddDepartment7() throws SQLException {
		assertTrue(-1 == dv.addDepartment(conn, "Literature", "Bruner Hall", "0"));
	}
}
