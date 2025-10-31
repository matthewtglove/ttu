import java.sql.Connection;
import java.sql.SQLException;

public interface DepartmentView {

	public void retrieveDepartments(Connection conn) throws SQLException;

	/**
	 * Adds a department.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department
	 * @param building   value for the main location of the office of the department
	 * @param budget     budget of the department
	 * @return (1) 1 if the department was added or (2) 0 if the department was not
	 *         added or (3) -1 if any of the values for department name, building,
	 *         or budget are invalid
	 * @throws SQLException if a database error occurs
	 */
	public int addDepartment(Connection conn, String dept_name, String building, String budget) throws SQLException;

	/**
	 * Updates building of a department.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department to be updated
	 * @param building   new value for the main location of the office of the
	 *                   department
	 * @return (1) 1 if the building of the department was updated or (2) 0 if the
	 *         building of the department was not updated or (3) -1 if the value for
	 *         the building is invalid
	 * @throws SQLException if a database error occurs
	 */
	public int updateDepartmentBuilding(Connection conn, String dept_name, String building) throws SQLException;

	/**
	 * Updates budget of a department.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department to be updated
	 * @param budget     new budget of the department
	 * @return (1) 1 if the budget of the department was updated or (2) 0 if the
	 *         budget of the department was not updated or (3) -1 if the value for
	 *         the budget is invalid
	 * @throws SQLException if a database error occurs
	 */
	public int updateDepartmentBudget(Connection conn, String dept_name, String budget) throws SQLException;

	/**
	 * Updates building and budget of a department.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department to be updated
	 * @param building   new value for the main location of the office of the
	 *                   department
	 * @param budget     new budget of the department
	 * @return (1) 1 if the building and budget of the department were updated or
	 *         (2) 0 if the building and budget of the department were not updated
	 *         cause the department is not there or (3) -1 if the value for either
	 *         building or budget is invalid
	 * @throws SQLException if a database error occurs
	 */
	public int updateDepartmentBuildingAndBudget(Connection conn, String dept_name, String building, String budget)
			throws SQLException;

	/**
	 * Removes department from the university database.
	 * 
	 * @param connection a connection with a specific database
	 * @param dept_name  name of the department to be removed
	 * @return (1) 1 if the department was removed or (2) 0 if no department was
	 *         removed
	 * @throws SQLException if a database error occurs
	 */
	public int removeDepartment(Connection conn, String dept_name) throws SQLException;
}
