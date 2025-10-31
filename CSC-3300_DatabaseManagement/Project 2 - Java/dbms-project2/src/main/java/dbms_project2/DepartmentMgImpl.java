import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DepartmentMgImpl implements DepartmentMg {

    /**
     * Retrieves departments.
     * 
     * @param connection a connection with a specific database
     * @return object that contains information about all departments
     * @throws SQLException if a database error occurs
     */
    public ResultSet retrieveDepartments(Connection connection) throws SQLException {
        Statement statement = connection.createStatement();
        return statement.executeQuery("SELECT * FROM departments");
    }

    /**
     * Adds a department.
     * 
     * @param connection a connection with a specific database
     * @param dept_name  name of the department; string of length not greater than
     *                   20 characters
     * @param building   value for the main location of the office of the
     *                   department; string of length not greater than 15 characters
     * @param budget     budget of the department; value not greater than
     *                   9999999999.99 and not smaller than 1
     * @return (1) 1 if the department was added or (2) 0 otherwise
     * @throws SQLException if a database error occurs
     */
    public int addDepartment(Connection connection, String dept_name, String building, BigDecimal budget)
            throws SQLException {
        // These are technically redundant checks since they are already done in the
        // view layer
        if (dept_name == null || dept_name.length() > 20) {
            throw new IllegalArgumentException("Department name must be 20 characters or less");
        }
        if (building == null || building.length() > 15) {
            throw new IllegalArgumentException("Building name must be 15 characters or less");
        }
        if (budget == null || budget.intValue() < 1 || budget.intValue() > 10000000000L) {
            throw new IllegalArgumentException("Budget must be between 1 and 10000000000.00");
        }

        PreparedStatement statement = connection.prepareStatement("INSERT INTO department VALUES (?, ?, ?)");
        statement.setString(1, dept_name);
        statement.setString(2, building);
        statement.setBigDecimal(3, budget);
        statement.executeUpdate();

        return 1;
    }

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
    public int updateDepartmentBuilding(Connection connection, String dept_name, String building) throws SQLException {
        // These are technically redundant checks since they are already done in the
        // view layer
        if (dept_name == null || dept_name.length() > 20) {
            throw new IllegalArgumentException("Department name must be 20 characters or less");
        }
        if (building == null || building.length() > 15) {
            throw new IllegalArgumentException("Building name must be 15 characters or less");
        }

        PreparedStatement statement = connection
                .prepareStatement("UPDATE department SET building = ? WHERE dept_name = ?");
        statement.setString(1, building);
        statement.setString(2, dept_name);
        statement.executeUpdate();

        return 1;
    };

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
    public int updateDepartmentBudget(Connection connection, String dept_name, BigDecimal budget) throws SQLException {
        // These are technically redundant checks since they are already done in the
        // view layer
        if (dept_name == null || dept_name.length() > 20) {
            throw new IllegalArgumentException("Department name must be 20 characters or less");
        }
        if (budget == null || budget.intValue() < 1 || budget.intValue() > 10000000000L) {
            throw new IllegalArgumentException("Budget must be between 1 and 10000000000.00");
        }

        PreparedStatement statement = connection
                .prepareStatement("UPDATE department SET budget = ? WHERE dept_name = ?");
        statement.setBigDecimal(1, budget);
        statement.setString(2, dept_name);
        statement.executeUpdate();

        return 1;
    }

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
            BigDecimal budget) throws SQLException {
        // These are technically redundant checks since they are already done in the
        // view layer
        if (dept_name == null || dept_name.length() > 20) {
            throw new IllegalArgumentException("Department name must be 20 characters or less");
        }
        if (building == null || building.length() > 15) {
            throw new IllegalArgumentException("Building name must be 15 characters or less");
        }
        if (budget == null || budget.intValue() < 1 || budget.intValue() > 10000000000L) {
            throw new IllegalArgumentException("Budget must be between 1 and 10000000000.00");
        }

        PreparedStatement statement = connection
                .prepareStatement("UPDATE department SET budget = ?, building = ? WHERE dept_name = ?");
        statement.setBigDecimal(1, budget);
        statement.setString(2, building);
        statement.setString(3, dept_name);
        statement.executeUpdate();

        return 1;

    }

    /**
     * Removes department from the university database.
     * 
     * @param connection a connection with a specific database
     * @param dept_name  name of the department to be removed
     * @return (1) 1 if the department was removed or (2) 0 if no department was
     *         removed
     * @throws SQLException if a database error occurs
     */
    public int removeDepartment(Connection connection, String dept_name) throws SQLException {
        // These are technically redundant checks since they are already done in the
        // view layer
        if (dept_name == null || dept_name.length() > 20) {
            throw new IllegalArgumentException("Department name must be 20 characters or less");
        }
        if (building == null || building.length() > 15) {
            throw new IllegalArgumentException("Building name must be 15 characters or less");
        }
        if (budget == null || budget.intValue() < 1 || budget.intValue() > 10000000000L) {
            throw new IllegalArgumentException("Budget must be between 1 and 10000000000.00");
        }

        PreparedStatement statement = connection.prepareStatement("DELETE FROM department WHERE dept_name = ?");
        statement.setString(1, dept_name);
        statement.executeUpdate();

        return 1;
    }
}
