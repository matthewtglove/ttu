import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;

public interface DepartmentMg {

	/**
	 * Retrieves departments.
	 * 
	 * @param connection a connection with a specific database
	 * @return object that contains information about all departments
	 * @throws SQLException if a database error occurs
	 */
	public ResultSet retrieveDepartments(Connection connection) throws SQLException;

	/**
	 * Adds a department.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department; string of length not greater than 20 characters
	 * @param building   value for the main location of the office of the
	 *                   department; string of length not greater than 15 characters
	 * @param budget     budget of the department; value not greater than
	 *                   9999999999.99 and not smaller than 1
	 * @return (1) 1 if the department was added or (2) 0 otherwise
	 * @throws SQLException if a database error occurs
	 */
	public int addDepartment(Connection connection, String dept_name, String building, BigDecimal budget)
			throws SQLException;

	/**
	 * Updates building of a department.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department to be updated
	 * @param building   new value for the main location of the office of the
	 *                   department; string of length not greater than 15 characters
	 * @return (1) 1 if the building of the department was updated or (2) 0
	 *         otherwise
	 * @throws SQLException if a database error occurs
	 */
	public int updateDepartmentBuilding(Connection connection, String dept_name, String building) throws SQLException;

	/**
	 * Updates budget of a department.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department to be updated
	 * @param budget     new budget of the department; value not greater than
	 *                   9999999999.99 and not smaller than 1
	 * @return (1) 1 if the budget of the department was updated or (2) 0 otherwise
	 * @throws SQLException if a database error occurs
	 */
	public int updateDepartmentBudget(Connection connection, String dept_name, BigDecimal budget) throws SQLException;

	/**
	 * Updates building and budget of a department.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department to be updated
	 * @param building   new value for the main location of the office of the
	 *                   department; string of length not greater than 15 characters
	 * @param budget     new budget of the department; value not greater than
	 *                   9999999999.99 and not smaller than 1
	 * @return (1) 1 if the building and budget of the department were updated or
	 *         (2) 0 otherwise
	 * @throws SQLException if a database error occurs
	 */
	public int updateDepartmentBuildingAndBudget(Connection connection, String dept_name, String building,
			BigDecimal budget) throws SQLException;

	/**
	 * Removes department from the university database.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department to be removed
	 * @return (1) 1 if the department was removed or (2) 0 if no department was
	 *         removed
	 * @throws SQLException if a database error occurs
	 */
	public int removeDepartment(Connection connection, String dept_name) throws SQLException;
}
